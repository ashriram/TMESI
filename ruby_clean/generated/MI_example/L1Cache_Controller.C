/** \file L1Cache.C
  * 
  * Auto generated C++ code started by symbols/StateMachine.C:327
  * Created by slicc definition of Module "MI Example"
  */

#include "Global.h"
#include "RubySlicc_includes.h"
#include "L1Cache_Controller.h"
#include "L1Cache_State.h"
#include "L1Cache_Event.h"
#include "Types.h"
#include "System.h"
#include "Chip.h"

stringstream L1Cache_transitionComment;
#define APPEND_TRANSITION_COMMENT(str) (L1Cache_transitionComment << str)
/** \brief static profiler defn */
L1Cache_Profiler L1Cache_Controller::s_profiler;

/** \brief constructor */
L1Cache_Controller::L1Cache_Controller(Chip* chip_ptr, int version)
{
  m_chip_ptr = chip_ptr;
  m_id = m_chip_ptr->getID();
  m_version = version;
  m_machineID.type = MachineType_L1Cache;
  m_machineID.num = m_id*RubyConfig::numberOfL1CachePerChip()+m_version;
  (*(m_chip_ptr->m_L1Cache_forwardToCache_vec[m_version])).setConsumer(this);
  (*(m_chip_ptr->m_L1Cache_responseToCache_vec[m_version])).setConsumer(this);
  (*(m_chip_ptr->m_L1Cache_mandatoryQueue_vec[m_version])).setConsumer(this);

  (*(m_chip_ptr->m_L1Cache_forwardToCache_vec[m_version])).setDescription("[Chip " + int_to_string(m_chip_ptr->getID()) + " " + int_to_string(m_version) + ", L1Cache, forwardRequestNetwork_in]");
  (*(m_chip_ptr->m_L1Cache_responseToCache_vec[m_version])).setDescription("[Chip " + int_to_string(m_chip_ptr->getID()) + " " + int_to_string(m_version) + ", L1Cache, responseNetwork_in]");
  (*(m_chip_ptr->m_L1Cache_mandatoryQueue_vec[m_version])).setDescription("[Chip " + int_to_string(m_chip_ptr->getID()) + " " + int_to_string(m_version) + ", L1Cache, mandatoryQueue_in]");

  s_profiler.possibleTransition(L1Cache_State_M, L1Cache_Event_Store);
  s_profiler.possibleTransition(L1Cache_State_M, L1Cache_Event_Load);
  s_profiler.possibleTransition(L1Cache_State_M, L1Cache_Event_Ifetch);
  s_profiler.possibleTransition(L1Cache_State_I, L1Cache_Event_Store);
  s_profiler.possibleTransition(L1Cache_State_I, L1Cache_Event_Load);
  s_profiler.possibleTransition(L1Cache_State_I, L1Cache_Event_Ifetch);
  s_profiler.possibleTransition(L1Cache_State_IS, L1Cache_Event_Data);
  s_profiler.possibleTransition(L1Cache_State_IM, L1Cache_Event_Data);
  s_profiler.possibleTransition(L1Cache_State_M, L1Cache_Event_Fwd_GETX);
  s_profiler.possibleTransition(L1Cache_State_I, L1Cache_Event_Replacement);
  s_profiler.possibleTransition(L1Cache_State_M, L1Cache_Event_Replacement);
  s_profiler.possibleTransition(L1Cache_State_MI, L1Cache_Event_Writeback_Ack);
  s_profiler.possibleTransition(L1Cache_State_MI, L1Cache_Event_Fwd_GETX);
  s_profiler.possibleTransition(L1Cache_State_II, L1Cache_Event_Writeback_Nack);
}

void L1Cache_Controller::print(ostream& out) const { out << "[L1Cache_Controller " << m_chip_ptr->getID() << " " << m_version << "]"; }

// Actions

/** \brief Issue a request*/
void L1Cache_Controller::a_issueRequest(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg out_msg;
    (out_msg).m_Address = addr;
    (out_msg).m_Type = CoherenceRequestType_GETX;
    (out_msg).m_Requestor = m_machineID;
    (((out_msg).m_Destination).add((map_Address_to_Directory(addr))));
    (out_msg).m_MessageSize = MessageSizeType_Control;
    ((*(m_chip_ptr->m_L1Cache_requestFromCache_vec[m_version]))).enqueue(out_msg, ISSUE_LATENCY);
  }
}

/** \brief Issue a PUT request*/
void L1Cache_Controller::b_issuePUT(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg out_msg;
    (out_msg).m_Address = addr;
    (out_msg).m_Type = CoherenceRequestType_PUTX;
    (out_msg).m_Requestor = m_machineID;
    (((out_msg).m_Destination).add((map_Address_to_Directory(addr))));
    (out_msg).m_DataBlk = ((((*(m_chip_ptr->m_L1Cache_cacheMemory_vec[m_version]))).lookup(addr))).m_DataBlk;
    (out_msg).m_MessageSize = MessageSizeType_Data;
    ((*(m_chip_ptr->m_L1Cache_requestFromCache_vec[m_version]))).enqueue(out_msg, ISSUE_LATENCY);
  }
}

/** \brief Send data from cache to requestor*/
void L1Cache_Controller::e_sendData(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L1Cache_forwardToCache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      ResponseMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_Type = CoherenceResponseType_DATA;
      (out_msg).m_Sender = m_machineID;
      (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
      (out_msg).m_DataBlk = ((((*(m_chip_ptr->m_L1Cache_cacheMemory_vec[m_version]))).lookup(addr))).m_DataBlk;
      (out_msg).m_MessageSize = MessageSizeType_Response_Data;
      ((*(m_chip_ptr->m_L1Cache_responseFromCache_vec[m_version]))).enqueue(out_msg, CACHE_RESPONSE_LATENCY);
    }
  }
}

/** \brief Send data from TBE to requestor*/
void L1Cache_Controller::ee_sendDataFromTBE(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L1Cache_forwardToCache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      ResponseMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_Type = CoherenceResponseType_DATA;
      (out_msg).m_Sender = m_machineID;
      (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
      (out_msg).m_DataBlk = ((((*(m_chip_ptr->m_L1Cache_TBEs_vec[m_version]))).lookup(addr))).m_DataBlk;
      (out_msg).m_MessageSize = MessageSizeType_Response_Data;
      ((*(m_chip_ptr->m_L1Cache_responseFromCache_vec[m_version]))).enqueue(out_msg, CACHE_RESPONSE_LATENCY);
    }
  }
}

/** \brief Allocate a cache block*/
void L1Cache_Controller::i_allocateL1CacheBlock(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  if (((((*(m_chip_ptr->m_L1Cache_cacheMemory_vec[m_version]))).isTagPresent(addr)) == (false))) {
    (((*(m_chip_ptr->m_L1Cache_cacheMemory_vec[m_version]))).allocate(addr));
  }
}

/** \brief deallocate a cache block*/
void L1Cache_Controller::h_deallocateL1CacheBlock(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  if (((((*(m_chip_ptr->m_L1Cache_cacheMemory_vec[m_version]))).isTagPresent(addr)) == (true))) {
    (((*(m_chip_ptr->m_L1Cache_cacheMemory_vec[m_version]))).deallocate(addr));
  }
}

/** \brief Pop the mandatory request queue*/
void L1Cache_Controller::m_popMandatoryQueue(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (((*(m_chip_ptr->m_L1Cache_mandatoryQueue_vec[m_version]))).dequeue());
}

/** \brief Pop the response queue*/
void L1Cache_Controller::n_popResponseQueue(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (((*(m_chip_ptr->m_L1Cache_responseToCache_vec[m_version]))).dequeue());
}

/** \brief Pop the forwarded request queue*/
void L1Cache_Controller::o_popForwardedRequestQueue(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (((*(m_chip_ptr->m_L1Cache_forwardToCache_vec[m_version]))).dequeue());
}

/** \brief Notify sequencer the load completed.*/
void L1Cache_Controller::r_load_hit(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  DEBUG_SLICC(MedPrio, "../protocols/MI_example-cache.sm:256: ", ((((*(m_chip_ptr->m_L1Cache_cacheMemory_vec[m_version]))).lookup(addr))).m_DataBlk);
;
  ((*(dynamic_cast<Sequencer*>(m_chip_ptr->getSequencer(m_version)))).readCallback(addr, ((((*(m_chip_ptr->m_L1Cache_cacheMemory_vec[m_version]))).lookup(addr))).m_DataBlk));
}

/** \brief Notify sequencer that store completed.*/
void L1Cache_Controller::s_store_hit(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  DEBUG_SLICC(MedPrio, "../protocols/MI_example-cache.sm:261: ", ((((*(m_chip_ptr->m_L1Cache_cacheMemory_vec[m_version]))).lookup(addr))).m_DataBlk);
;
  ((*(dynamic_cast<Sequencer*>(m_chip_ptr->getSequencer(m_version)))).writeCallback(addr, ((((*(m_chip_ptr->m_L1Cache_cacheMemory_vec[m_version]))).lookup(addr))).m_DataBlk));
}

/** \brief Write data to the cache*/
void L1Cache_Controller::u_writeDataToCache(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<ResponseMsg*>(((*(m_chip_ptr->m_L1Cache_responseToCache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    ((((*(m_chip_ptr->m_L1Cache_cacheMemory_vec[m_version]))).lookup(addr))).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
  }
}

/** \brief Allocate TBE*/
void L1Cache_Controller::v_allocateTBE(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (((*(m_chip_ptr->m_L1Cache_TBEs_vec[m_version]))).allocate(addr));
}

/** \brief Deallocate TBE*/
void L1Cache_Controller::w_deallocateTBE(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (((*(m_chip_ptr->m_L1Cache_TBEs_vec[m_version]))).deallocate(addr));
}

/** \brief Copy data from cache to TBE*/
void L1Cache_Controller::x_copyDataFromCacheToTBE(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  ((((*(m_chip_ptr->m_L1Cache_TBEs_vec[m_version]))).lookup(addr))).m_DataBlk = ((((*(m_chip_ptr->m_L1Cache_cacheMemory_vec[m_version]))).lookup(addr))).m_DataBlk;
}

/** \brief stall*/
void L1Cache_Controller::z_stall(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
}

