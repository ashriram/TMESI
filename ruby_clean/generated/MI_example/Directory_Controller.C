/** \file Directory.C
  * 
  * Auto generated C++ code started by symbols/StateMachine.C:327
  * Created by slicc definition of Module "Directory protocol"
  */

#include "Global.h"
#include "RubySlicc_includes.h"
#include "Directory_Controller.h"
#include "Directory_State.h"
#include "Directory_Event.h"
#include "Types.h"
#include "System.h"
#include "Chip.h"

stringstream Directory_transitionComment;
#define APPEND_TRANSITION_COMMENT(str) (Directory_transitionComment << str)
/** \brief static profiler defn */
Directory_Profiler Directory_Controller::s_profiler;

/** \brief constructor */
Directory_Controller::Directory_Controller(Chip* chip_ptr, int version)
{
  m_chip_ptr = chip_ptr;
  m_id = m_chip_ptr->getID();
  m_version = version;
  m_machineID.type = MachineType_Directory;
  m_machineID.num = m_id*RubyConfig::numberOfDirectoryPerChip()+m_version;
  (*(m_chip_ptr->m_Directory_requestToDir_vec[m_version])).setConsumer(this);
  (*(m_chip_ptr->m_Directory_unblockToDir_vec[m_version])).setConsumer(this);

  (*(m_chip_ptr->m_Directory_requestToDir_vec[m_version])).setDescription("[Chip " + int_to_string(m_chip_ptr->getID()) + " " + int_to_string(m_version) + ", Directory, requestQueue_in]");
  (*(m_chip_ptr->m_Directory_unblockToDir_vec[m_version])).setDescription("[Chip " + int_to_string(m_chip_ptr->getID()) + " " + int_to_string(m_version) + ", Directory, unblockNetwork_in]");

  s_profiler.possibleTransition(Directory_State_I, Directory_Event_GETX);
  s_profiler.possibleTransition(Directory_State_M, Directory_Event_GETX);
  s_profiler.possibleTransition(Directory_State_M, Directory_Event_PUTX);
  s_profiler.possibleTransition(Directory_State_M, Directory_Event_PUTX_NotOwner);
  s_profiler.possibleTransition(Directory_State_I, Directory_Event_PUTX_NotOwner);
  s_profiler.possibleTransition(Directory_State_MI, Directory_Event_Unblock);
}

void Directory_Controller::print(ostream& out) const { out << "[Directory_Controller " << m_chip_ptr->getID() << " " << m_version << "]"; }

// Actions

/** \brief Send writeback ack to requestor*/
void Directory_Controller::a_sendWriteBackAck(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_Directory_requestToDir_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      RequestMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_Type = CoherenceRequestType_WB_ACK;
      (out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
      (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
      (out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
      ((*(m_chip_ptr->m_Directory_forwardFromDir_vec[m_version]))).enqueue(out_msg, DIRECTORY_LATENCY);
    }
  }
}

/** \brief Send writeback nack to requestor*/
void Directory_Controller::b_sendWriteBackNack(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_Directory_requestToDir_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      RequestMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_Type = CoherenceRequestType_WB_NACK;
      (out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
      (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
      (out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
      ((*(m_chip_ptr->m_Directory_forwardFromDir_vec[m_version]))).enqueue(out_msg, DIRECTORY_LATENCY);
    }
  }
}

/** \brief Clear the owner field*/
void Directory_Controller::c_clearOwner(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  ((((((*(m_chip_ptr->m_Directory_directory_vec[m_version]))).lookup(addr))).m_Owner).clear());
}

/** \brief Send data to requestor*/
void Directory_Controller::d_sendData(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_Directory_requestToDir_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      ResponseMsg out_msg;
      (out_msg).m_Address = addr;
      if (((((*in_msg_ptr)).m_Type == CoherenceRequestType_GETS) && (((((((*(m_chip_ptr->m_Directory_directory_vec[m_version]))).lookup(addr))).m_Sharers).count()) == (0)))) {
        (out_msg).m_Type = CoherenceResponseType_DATA;
      } else {
        (out_msg).m_Type = CoherenceResponseType_DATA;
      }
      (out_msg).m_Sender = m_machineID;
      (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
      (out_msg).m_DataBlk = ((((*(m_chip_ptr->m_Directory_directory_vec[m_version]))).lookup(((*in_msg_ptr)).m_Address))).m_DataBlk;
      (out_msg).m_Dirty = (false);
      (out_msg).m_Acks = ((((((*(m_chip_ptr->m_Directory_directory_vec[m_version]))).lookup(addr))).m_Sharers).count());
      if (((((((*(m_chip_ptr->m_Directory_directory_vec[m_version]))).lookup(addr))).m_Sharers).isElement(((*in_msg_ptr)).m_Requestor))) {
        (out_msg).m_Acks = ((out_msg).m_Acks - (1));
      }
      (out_msg).m_MessageSize = MessageSizeType_Response_Data;
      ((*(m_chip_ptr->m_Directory_responseFromDir_vec[m_version]))).enqueue(out_msg, MEMORY_LATENCY);
    }
  }
}

/** \brief The owner is now the requestor*/
void Directory_Controller::e_ownerIsRequestor(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_Directory_requestToDir_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    ((((((*(m_chip_ptr->m_Directory_directory_vec[m_version]))).lookup(addr))).m_Owner).clear());
    ((((((*(m_chip_ptr->m_Directory_directory_vec[m_version]))).lookup(addr))).m_Owner).add(((*in_msg_ptr)).m_Requestor));
  }
}

/** \brief Forward request to owner*/
void Directory_Controller::f_forwardRequest(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_Directory_requestToDir_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    APPEND_TRANSITION_COMMENT(("Own: "));
;
    APPEND_TRANSITION_COMMENT(((((*(m_chip_ptr->m_Directory_directory_vec[m_version]))).lookup(((*in_msg_ptr)).m_Address))).m_Owner);
;
    APPEND_TRANSITION_COMMENT(("Req: "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
;
    {
      RequestMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_Type = ((*in_msg_ptr)).m_Type;
      (out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
      (out_msg).m_Destination = ((((*(m_chip_ptr->m_Directory_directory_vec[m_version]))).lookup(((*in_msg_ptr)).m_Address))).m_Owner;
      (out_msg).m_Acks = ((((((*(m_chip_ptr->m_Directory_directory_vec[m_version]))).lookup(addr))).m_Sharers).count());
      if (((((((*(m_chip_ptr->m_Directory_directory_vec[m_version]))).lookup(addr))).m_Sharers).isElement(((*in_msg_ptr)).m_Requestor))) {
        (out_msg).m_Acks = ((out_msg).m_Acks - (1));
      }
      (out_msg).m_MessageSize = MessageSizeType_Forwarded_Control;
      ((*(m_chip_ptr->m_Directory_forwardFromDir_vec[m_version]))).enqueue(out_msg, DIRECTORY_LATENCY);
    }
  }
}

/** \brief Pop incoming request queue*/
void Directory_Controller::i_popIncomingRequestQueue(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (((*(m_chip_ptr->m_Directory_requestToDir_vec[m_version]))).dequeue());
}

/** \brief Pop incoming unblock queue*/
void Directory_Controller::j_popIncomingUnblockQueue(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (((*(m_chip_ptr->m_Directory_unblockToDir_vec[m_version]))).dequeue());
}

/** \brief Write PUTX/PUTO data to memory*/
void Directory_Controller::l_writeDataToMemory(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_Directory_requestToDir_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    ((((*(m_chip_ptr->m_Directory_directory_vec[m_version]))).lookup(((*in_msg_ptr)).m_Address))).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
    DEBUG_SLICC(MedPrio, "../protocols/MI_example-dir.sm:211: ", ((*in_msg_ptr)).m_Address);
;
    DEBUG_SLICC(MedPrio, "../protocols/MI_example-dir.sm:212: ", ((*in_msg_ptr)).m_DataBlk);
;
  }
}

