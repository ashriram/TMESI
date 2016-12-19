/** \file L1Cache.C
  * 
  * Auto generated C++ code started by symbols/StateMachine.C:327
  * Created by slicc definition of Module "MESI Directory L1 Cache CMP"
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
  (*(m_chip_ptr->m_L1Cache_triggerQueue_vec[m_version])).setConsumer(this);
  (*(m_chip_ptr->m_L1Cache_responseToL1Cache_vec[m_version])).setConsumer(this);
  (*(m_chip_ptr->m_L1Cache_requestToL1Cache_vec[m_version])).setConsumer(this);
  (*(m_chip_ptr->m_L1Cache_mandatoryQueue_vec[m_version])).setConsumer(this);

  (*(m_chip_ptr->m_L1Cache_triggerQueue_vec[m_version])).setDescription("[Chip " + int_to_string(m_chip_ptr->getID()) + " " + int_to_string(m_version) + ", L1Cache, triggerQueue_in]");
  (*(m_chip_ptr->m_L1Cache_responseToL1Cache_vec[m_version])).setDescription("[Chip " + int_to_string(m_chip_ptr->getID()) + " " + int_to_string(m_version) + ", L1Cache, responseIntraChipL1Network_in]");
  (*(m_chip_ptr->m_L1Cache_requestToL1Cache_vec[m_version])).setDescription("[Chip " + int_to_string(m_chip_ptr->getID()) + " " + int_to_string(m_version) + ", L1Cache, requestIntraChipL1Network_in]");
  (*(m_chip_ptr->m_L1Cache_mandatoryQueue_vec[m_version])).setDescription("[Chip " + int_to_string(m_chip_ptr->getID()) + " " + int_to_string(m_version) + ", L1Cache, mandatoryQueue_in]");

  s_profiler.possibleTransition(L1Cache_State_NP, L1Cache_Event_Check_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_I, L1Cache_Event_Check_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_S, L1Cache_Event_Check_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_E, L1Cache_Event_Check_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_M, L1Cache_Event_Check_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_IS, L1Cache_Event_Check_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_ITM, L1Cache_Event_Check_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_IM, L1Cache_Event_Check_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_SM, L1Cache_Event_Check_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_IS_I, L1Cache_Event_Check_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_IS_S, L1Cache_Event_Check_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_IS_E, L1Cache_Event_Check_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_IM_M, L1Cache_Event_Check_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_M_I, L1Cache_Event_Check_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_E_I, L1Cache_Event_Check_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_NP, L1Cache_Event_Check_Read_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_I, L1Cache_Event_Check_Read_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_S, L1Cache_Event_Check_Read_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_E, L1Cache_Event_Check_Read_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_M, L1Cache_Event_Check_Read_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_IS, L1Cache_Event_Check_Read_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_ITM, L1Cache_Event_Check_Read_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_IM, L1Cache_Event_Check_Read_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_SM, L1Cache_Event_Check_Read_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_IS_I, L1Cache_Event_Check_Read_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_IS_S, L1Cache_Event_Check_Read_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_IS_E, L1Cache_Event_Check_Read_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_IM_M, L1Cache_Event_Check_Read_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_M_I, L1Cache_Event_Check_Read_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_E_I, L1Cache_Event_Check_Read_Write_Filter);
  s_profiler.possibleTransition(L1Cache_State_IS, L1Cache_Event_Load);
  s_profiler.possibleTransition(L1Cache_State_IS, L1Cache_Event_Ifetch);
  s_profiler.possibleTransition(L1Cache_State_IS, L1Cache_Event_Store);
  s_profiler.possibleTransition(L1Cache_State_IS, L1Cache_Event_L1_Replacement);
  s_profiler.possibleTransition(L1Cache_State_IS, L1Cache_Event_L1_Replacement_XACT);
  s_profiler.possibleTransition(L1Cache_State_IM, L1Cache_Event_Load);
  s_profiler.possibleTransition(L1Cache_State_IM, L1Cache_Event_Ifetch);
  s_profiler.possibleTransition(L1Cache_State_IM, L1Cache_Event_Store);
  s_profiler.possibleTransition(L1Cache_State_IM, L1Cache_Event_L1_Replacement);
  s_profiler.possibleTransition(L1Cache_State_IM, L1Cache_Event_L1_Replacement_XACT);
  s_profiler.possibleTransition(L1Cache_State_ITM, L1Cache_Event_Load);
  s_profiler.possibleTransition(L1Cache_State_ITM, L1Cache_Event_Ifetch);
  s_profiler.possibleTransition(L1Cache_State_ITM, L1Cache_Event_Store);
  s_profiler.possibleTransition(L1Cache_State_ITM, L1Cache_Event_L1_Replacement);
  s_profiler.possibleTransition(L1Cache_State_ITM, L1Cache_Event_L1_Replacement_XACT);
  s_profiler.possibleTransition(L1Cache_State_IS_I, L1Cache_Event_Load);
  s_profiler.possibleTransition(L1Cache_State_IS_I, L1Cache_Event_Ifetch);
  s_profiler.possibleTransition(L1Cache_State_IS_I, L1Cache_Event_Store);
  s_profiler.possibleTransition(L1Cache_State_IS_I, L1Cache_Event_L1_Replacement);
  s_profiler.possibleTransition(L1Cache_State_IS_I, L1Cache_Event_L1_Replacement_XACT);
  s_profiler.possibleTransition(L1Cache_State_IS_S, L1Cache_Event_Load);
  s_profiler.possibleTransition(L1Cache_State_IS_S, L1Cache_Event_Ifetch);
  s_profiler.possibleTransition(L1Cache_State_IS_S, L1Cache_Event_Store);
  s_profiler.possibleTransition(L1Cache_State_IS_S, L1Cache_Event_L1_Replacement);
  s_profiler.possibleTransition(L1Cache_State_IS_S, L1Cache_Event_L1_Replacement_XACT);
  s_profiler.possibleTransition(L1Cache_State_IS_E, L1Cache_Event_Load);
  s_profiler.possibleTransition(L1Cache_State_IS_E, L1Cache_Event_Ifetch);
  s_profiler.possibleTransition(L1Cache_State_IS_E, L1Cache_Event_Store);
  s_profiler.possibleTransition(L1Cache_State_IS_E, L1Cache_Event_L1_Replacement);
  s_profiler.possibleTransition(L1Cache_State_IS_E, L1Cache_Event_L1_Replacement_XACT);
  s_profiler.possibleTransition(L1Cache_State_IM_M, L1Cache_Event_Load);
  s_profiler.possibleTransition(L1Cache_State_IM_M, L1Cache_Event_Ifetch);
  s_profiler.possibleTransition(L1Cache_State_IM_M, L1Cache_Event_Store);
  s_profiler.possibleTransition(L1Cache_State_IM_M, L1Cache_Event_L1_Replacement);
  s_profiler.possibleTransition(L1Cache_State_IM_M, L1Cache_Event_L1_Replacement_XACT);
  s_profiler.possibleTransition(L1Cache_State_M_I, L1Cache_Event_Load);
  s_profiler.possibleTransition(L1Cache_State_M_I, L1Cache_Event_Ifetch);
  s_profiler.possibleTransition(L1Cache_State_M_I, L1Cache_Event_Store);
  s_profiler.possibleTransition(L1Cache_State_M_I, L1Cache_Event_L1_Replacement);
  s_profiler.possibleTransition(L1Cache_State_M_I, L1Cache_Event_L1_Replacement_XACT);
  s_profiler.possibleTransition(L1Cache_State_E_I, L1Cache_Event_Load);
  s_profiler.possibleTransition(L1Cache_State_E_I, L1Cache_Event_Ifetch);
  s_profiler.possibleTransition(L1Cache_State_E_I, L1Cache_Event_Store);
  s_profiler.possibleTransition(L1Cache_State_E_I, L1Cache_Event_L1_Replacement);
  s_profiler.possibleTransition(L1Cache_State_E_I, L1Cache_Event_L1_Replacement_XACT);
  s_profiler.possibleTransition(L1Cache_State_NP, L1Cache_Event_L1_Replacement);
  s_profiler.possibleTransition(L1Cache_State_NP, L1Cache_Event_L1_Replacement_XACT);
  s_profiler.possibleTransition(L1Cache_State_I, L1Cache_Event_L1_Replacement);
  s_profiler.possibleTransition(L1Cache_State_I, L1Cache_Event_L1_Replacement_XACT);
  s_profiler.possibleTransition(L1Cache_State_NP, L1Cache_Event_Load);
  s_profiler.possibleTransition(L1Cache_State_I, L1Cache_Event_Load);
  s_profiler.possibleTransition(L1Cache_State_NP, L1Cache_Event_Ifetch);
  s_profiler.possibleTransition(L1Cache_State_I, L1Cache_Event_Ifetch);
  s_profiler.possibleTransition(L1Cache_State_NP, L1Cache_Event_Store);
  s_profiler.possibleTransition(L1Cache_State_I, L1Cache_Event_Store);
  s_profiler.possibleTransition(L1Cache_State_NP, L1Cache_Event_Inv);
  s_profiler.possibleTransition(L1Cache_State_I, L1Cache_Event_Inv);
  s_profiler.possibleTransition(L1Cache_State_NP, L1Cache_Event_Inv_X);
  s_profiler.possibleTransition(L1Cache_State_I, L1Cache_Event_Inv_X);
  s_profiler.possibleTransition(L1Cache_State_NP, L1Cache_Event_Replace);
  s_profiler.possibleTransition(L1Cache_State_I, L1Cache_Event_Replace);
  s_profiler.possibleTransition(L1Cache_State_S, L1Cache_Event_Load);
  s_profiler.possibleTransition(L1Cache_State_S, L1Cache_Event_Ifetch);
  s_profiler.possibleTransition(L1Cache_State_S, L1Cache_Event_Store);
  s_profiler.possibleTransition(L1Cache_State_S, L1Cache_Event_L1_Replacement);
  s_profiler.possibleTransition(L1Cache_State_S, L1Cache_Event_L1_Replacement_XACT);
  s_profiler.possibleTransition(L1Cache_State_S, L1Cache_Event_Inv);
  s_profiler.possibleTransition(L1Cache_State_S, L1Cache_Event_Inv_X);
  s_profiler.possibleTransition(L1Cache_State_S, L1Cache_Event_Replace);
  s_profiler.possibleTransition(L1Cache_State_E, L1Cache_Event_Load);
  s_profiler.possibleTransition(L1Cache_State_E, L1Cache_Event_Ifetch);
  s_profiler.possibleTransition(L1Cache_State_E, L1Cache_Event_Store);
  s_profiler.possibleTransition(L1Cache_State_E, L1Cache_Event_L1_Replacement);
  s_profiler.possibleTransition(L1Cache_State_E, L1Cache_Event_L1_Replacement_XACT);
  s_profiler.possibleTransition(L1Cache_State_E, L1Cache_Event_Inv);
  s_profiler.possibleTransition(L1Cache_State_E, L1Cache_Event_Inv_X);
  s_profiler.possibleTransition(L1Cache_State_E, L1Cache_Event_Replace);
  s_profiler.possibleTransition(L1Cache_State_E, L1Cache_Event_Fwd_GETX);
  s_profiler.possibleTransition(L1Cache_State_E, L1Cache_Event_Fwd_GETS);
  s_profiler.possibleTransition(L1Cache_State_E, L1Cache_Event_Fwd_GET_INSTR);
  s_profiler.possibleTransition(L1Cache_State_E, L1Cache_Event_Fwd_GETS_X);
  s_profiler.possibleTransition(L1Cache_State_E, L1Cache_Event_Fwd_GETX_X);
  s_profiler.possibleTransition(L1Cache_State_E, L1Cache_Event_Fwd_GET_INSTR_X);
  s_profiler.possibleTransition(L1Cache_State_M, L1Cache_Event_Load);
  s_profiler.possibleTransition(L1Cache_State_M, L1Cache_Event_Ifetch);
  s_profiler.possibleTransition(L1Cache_State_M, L1Cache_Event_Store);
  s_profiler.possibleTransition(L1Cache_State_M, L1Cache_Event_L1_Replacement);
  s_profiler.possibleTransition(L1Cache_State_M, L1Cache_Event_L1_Replacement_XACT);
  s_profiler.possibleTransition(L1Cache_State_M_I, L1Cache_Event_WB_Ack);
  s_profiler.possibleTransition(L1Cache_State_E_I, L1Cache_Event_WB_Ack);
  s_profiler.possibleTransition(L1Cache_State_M, L1Cache_Event_Inv);
  s_profiler.possibleTransition(L1Cache_State_M, L1Cache_Event_Replace);
  s_profiler.possibleTransition(L1Cache_State_M, L1Cache_Event_Inv_X);
  s_profiler.possibleTransition(L1Cache_State_E_I, L1Cache_Event_Inv);
  s_profiler.possibleTransition(L1Cache_State_E_I, L1Cache_Event_Inv_X);
  s_profiler.possibleTransition(L1Cache_State_M_I, L1Cache_Event_Replace);
  s_profiler.possibleTransition(L1Cache_State_E_I, L1Cache_Event_Replace);
  s_profiler.possibleTransition(L1Cache_State_M, L1Cache_Event_Fwd_GETX);
  s_profiler.possibleTransition(L1Cache_State_M, L1Cache_Event_Fwd_GETS);
  s_profiler.possibleTransition(L1Cache_State_M, L1Cache_Event_Fwd_GET_INSTR);
  s_profiler.possibleTransition(L1Cache_State_M, L1Cache_Event_Fwd_GETX_X);
  s_profiler.possibleTransition(L1Cache_State_M, L1Cache_Event_Fwd_GETS_X);
  s_profiler.possibleTransition(L1Cache_State_M, L1Cache_Event_Fwd_GET_INSTR_X);
  s_profiler.possibleTransition(L1Cache_State_E_I, L1Cache_Event_Fwd_GETX);
  s_profiler.possibleTransition(L1Cache_State_E_I, L1Cache_Event_Fwd_GETS);
  s_profiler.possibleTransition(L1Cache_State_E_I, L1Cache_Event_Fwd_GET_INSTR);
  s_profiler.possibleTransition(L1Cache_State_E_I, L1Cache_Event_Fwd_GETS_X);
  s_profiler.possibleTransition(L1Cache_State_E_I, L1Cache_Event_Fwd_GETX_X);
  s_profiler.possibleTransition(L1Cache_State_E_I, L1Cache_Event_Fwd_GET_INSTR_X);
  s_profiler.possibleTransition(L1Cache_State_M_I, L1Cache_Event_Fwd_GETX);
  s_profiler.possibleTransition(L1Cache_State_M_I, L1Cache_Event_Fwd_GETS);
  s_profiler.possibleTransition(L1Cache_State_M_I, L1Cache_Event_Fwd_GET_INSTR);
  s_profiler.possibleTransition(L1Cache_State_M_I, L1Cache_Event_Fwd_GETS_X);
  s_profiler.possibleTransition(L1Cache_State_M_I, L1Cache_Event_Fwd_GETX_X);
  s_profiler.possibleTransition(L1Cache_State_M_I, L1Cache_Event_Fwd_GET_INSTR_X);
  s_profiler.possibleTransition(L1Cache_State_IS, L1Cache_Event_Inv);
  s_profiler.possibleTransition(L1Cache_State_IS_I, L1Cache_Event_Inv);
  s_profiler.possibleTransition(L1Cache_State_IS, L1Cache_Event_L2_Data_all_Acks);
  s_profiler.possibleTransition(L1Cache_State_IS_I, L1Cache_Event_L2_Data_all_Acks);
  s_profiler.possibleTransition(L1Cache_State_IS, L1Cache_Event_Replace);
  s_profiler.possibleTransition(L1Cache_State_IS_I, L1Cache_Event_Replace);
  s_profiler.possibleTransition(L1Cache_State_IS, L1Cache_Event_Ack);
  s_profiler.possibleTransition(L1Cache_State_IS_I, L1Cache_Event_Ack);
  s_profiler.possibleTransition(L1Cache_State_IS, L1Cache_Event_Nack);
  s_profiler.possibleTransition(L1Cache_State_IS_I, L1Cache_Event_Nack);
  s_profiler.possibleTransition(L1Cache_State_IS, L1Cache_Event_L2_Data);
  s_profiler.possibleTransition(L1Cache_State_IS_I, L1Cache_Event_L2_Data);
  s_profiler.possibleTransition(L1Cache_State_IS_S, L1Cache_Event_Ack);
  s_profiler.possibleTransition(L1Cache_State_IS_S, L1Cache_Event_Nack);
  s_profiler.possibleTransition(L1Cache_State_IS_S, L1Cache_Event_Ack_all);
  s_profiler.possibleTransition(L1Cache_State_IS_S, L1Cache_Event_Nack_all);
  s_profiler.possibleTransition(L1Cache_State_IS, L1Cache_Event_L2_Exclusive_Data);
  s_profiler.possibleTransition(L1Cache_State_IS_I, L1Cache_Event_L2_Exclusive_Data);
  s_profiler.possibleTransition(L1Cache_State_IS, L1Cache_Event_L2_Exclusive_Data_all_Acks);
  s_profiler.possibleTransition(L1Cache_State_IS_I, L1Cache_Event_L2_Exclusive_Data_all_Acks);
  s_profiler.possibleTransition(L1Cache_State_IS_E, L1Cache_Event_Ack);
  s_profiler.possibleTransition(L1Cache_State_IS_E, L1Cache_Event_Nack);
  s_profiler.possibleTransition(L1Cache_State_IS_E, L1Cache_Event_Ack_all);
  s_profiler.possibleTransition(L1Cache_State_IS_E, L1Cache_Event_Nack_all);
  s_profiler.possibleTransition(L1Cache_State_IS, L1Cache_Event_Nack_all);
  s_profiler.possibleTransition(L1Cache_State_IS_I, L1Cache_Event_Nack_all);
  s_profiler.possibleTransition(L1Cache_State_IS, L1Cache_Event_Inv_X);
  s_profiler.possibleTransition(L1Cache_State_IS_I, L1Cache_Event_Inv_X);
  s_profiler.possibleTransition(L1Cache_State_IS, L1Cache_Event_DataS_fromL1);
  s_profiler.possibleTransition(L1Cache_State_IS_I, L1Cache_Event_DataS_fromL1);
  s_profiler.possibleTransition(L1Cache_State_IM, L1Cache_Event_Inv);
  s_profiler.possibleTransition(L1Cache_State_SM, L1Cache_Event_Inv);
  s_profiler.possibleTransition(L1Cache_State_IM, L1Cache_Event_Inv_X);
  s_profiler.possibleTransition(L1Cache_State_SM, L1Cache_Event_Inv_X);
  s_profiler.possibleTransition(L1Cache_State_IM, L1Cache_Event_Replace);
  s_profiler.possibleTransition(L1Cache_State_SM, L1Cache_Event_Replace);
  s_profiler.possibleTransition(L1Cache_State_IM, L1Cache_Event_Data_all_Acks);
  s_profiler.possibleTransition(L1Cache_State_IM, L1Cache_Event_L2_Data);
  s_profiler.possibleTransition(L1Cache_State_IM, L1Cache_Event_L2_Data_all_Acks);
  s_profiler.possibleTransition(L1Cache_State_IM_M, L1Cache_Event_Ack);
  s_profiler.possibleTransition(L1Cache_State_IM_M, L1Cache_Event_Nack);
  s_profiler.possibleTransition(L1Cache_State_IM_M, L1Cache_Event_Ack_all);
  s_profiler.possibleTransition(L1Cache_State_IM_M, L1Cache_Event_Nack_all);
  s_profiler.possibleTransition(L1Cache_State_SM, L1Cache_Event_Ack);
  s_profiler.possibleTransition(L1Cache_State_IM, L1Cache_Event_Ack);
  s_profiler.possibleTransition(L1Cache_State_SM, L1Cache_Event_Nack);
  s_profiler.possibleTransition(L1Cache_State_IM, L1Cache_Event_Nack);
  s_profiler.possibleTransition(L1Cache_State_SM, L1Cache_Event_Ack_all);
  s_profiler.possibleTransition(L1Cache_State_SM, L1Cache_Event_Nack_all);
  s_profiler.possibleTransition(L1Cache_State_IM, L1Cache_Event_Nack_all);
}

void L1Cache_Controller::print(ostream& out) const { out << "[L1Cache_Controller " << m_chip_ptr->getID() << " " << m_version << "]"; }

// Actions

/** \brief Issue GETS*/
void L1Cache_Controller::a_issueGETS(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    CacheMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<CacheMsg*>(((*(m_chip_ptr->m_L1Cache_mandatoryQueue_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      RequestMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
      if (((*in_msg_ptr)).m_ExposedAction) {
        (out_msg).m_Type = CoherenceRequestType_GETS_ESCAPE;
      } else {
        (out_msg).m_Type = CoherenceRequestType_GETS;
      }
      (out_msg).m_Requestor = m_machineID;
      (((out_msg).m_Destination).add((map_L1CacheMachId_to_L2Cache(addr, m_machineID))));
      DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:575: ", addr);
;
      DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:576: ", (out_msg).m_Destination);
;
      (out_msg).m_MessageSize = MessageSizeType_Control;
      (out_msg).m_Prefetch = ((*in_msg_ptr)).m_Prefetch;
      (out_msg).m_AccessMode = ((*in_msg_ptr)).m_AccessMode;
      (out_msg).m_Timestamp = ((*in_msg_ptr)).m_Timestamp;
      APPEND_TRANSITION_COMMENT((out_msg).m_Timestamp);
;
      ((*(m_chip_ptr->m_L1Cache_requestFromL1Cache_vec[m_version]))).enqueue(out_msg, L1_REQUEST_LATENCY);
    }
  }
}

/** \brief Issue GETINSTR*/
void L1Cache_Controller::ai_issueGETINSTR(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    CacheMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<CacheMsg*>(((*(m_chip_ptr->m_L1Cache_mandatoryQueue_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      RequestMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
      if (((*in_msg_ptr)).m_ExposedAction) {
        (out_msg).m_Type = CoherenceRequestType_GET_INSTR_ESCAPE;
      } else {
        (out_msg).m_Type = CoherenceRequestType_GET_INSTR;
      }
      (out_msg).m_Requestor = m_machineID;
      (((out_msg).m_Destination).add((map_L1CacheMachId_to_L2Cache(addr, m_machineID))));
      DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:600: ", addr);
;
      DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:601: ", (out_msg).m_Destination);
;
      (out_msg).m_MessageSize = MessageSizeType_Control;
      (out_msg).m_Prefetch = ((*in_msg_ptr)).m_Prefetch;
      (out_msg).m_AccessMode = ((*in_msg_ptr)).m_AccessMode;
      (out_msg).m_Timestamp = ((*in_msg_ptr)).m_Timestamp;
      APPEND_TRANSITION_COMMENT((out_msg).m_Timestamp);
;
      ((*(m_chip_ptr->m_L1Cache_requestFromL1Cache_vec[m_version]))).enqueue(out_msg, L1_REQUEST_LATENCY);
    }
  }
}

/** \brief Issue GETX*/
void L1Cache_Controller::b_issueGETX(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    CacheMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<CacheMsg*>(((*(m_chip_ptr->m_L1Cache_mandatoryQueue_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      RequestMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
      if (((*in_msg_ptr)).m_ExposedAction) {
        (out_msg).m_Type = CoherenceRequestType_GETX_ESCAPE;
      } else {
        (out_msg).m_Type = CoherenceRequestType_GETX;
      }
      (out_msg).m_Requestor = m_machineID;
      DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:625: ", m_machineID);
;
      (((out_msg).m_Destination).add((map_L1CacheMachId_to_L2Cache(addr, m_machineID))));
      DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:627: ", addr);
;
      DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:628: ", (out_msg).m_Destination);
;
      (out_msg).m_MessageSize = MessageSizeType_Control;
      (out_msg).m_Prefetch = ((*in_msg_ptr)).m_Prefetch;
      (out_msg).m_AccessMode = ((*in_msg_ptr)).m_AccessMode;
      (out_msg).m_Timestamp = ((*in_msg_ptr)).m_Timestamp;
      APPEND_TRANSITION_COMMENT((out_msg).m_Timestamp);
;
      ((*(m_chip_ptr->m_L1Cache_requestFromL1Cache_vec[m_version]))).enqueue(out_msg, L1_REQUEST_LATENCY);
    }
  }
}

/** \brief Issue GETX*/
void L1Cache_Controller::c_issueUPGRADE(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    CacheMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<CacheMsg*>(((*(m_chip_ptr->m_L1Cache_mandatoryQueue_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      RequestMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
      (out_msg).m_Type = CoherenceRequestType_UPGRADE;
      (out_msg).m_Requestor = m_machineID;
      (((out_msg).m_Destination).add((map_L1CacheMachId_to_L2Cache(addr, m_machineID))));
      DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:647: ", addr);
;
      DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:648: ", (out_msg).m_Destination);
;
      (out_msg).m_MessageSize = MessageSizeType_Control;
      (out_msg).m_Prefetch = ((*in_msg_ptr)).m_Prefetch;
      (out_msg).m_AccessMode = ((*in_msg_ptr)).m_AccessMode;
      (out_msg).m_Timestamp = ((*in_msg_ptr)).m_Timestamp;
      APPEND_TRANSITION_COMMENT((out_msg).m_Timestamp);
;
      ((*(m_chip_ptr->m_L1Cache_requestFromL1Cache_vec[m_version]))).enqueue(out_msg, L1_REQUEST_LATENCY);
    }
  }
}

/** \brief send nack to requestor (could be L2 or L1)*/
void L1Cache_Controller::e_sendNackToRequestor(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L1Cache_requestToL1Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      ResponseMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
      (out_msg).m_Type = CoherenceResponseType_NACK;
      (out_msg).m_Sender = m_machineID;
      (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
      (out_msg).m_MessageSize = MessageSizeType_Response_Control;
      APPEND_TRANSITION_COMMENT((out_msg).m_Timestamp);
;
      APPEND_TRANSITION_COMMENT((" "));
;
      APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Timestamp);
;
      APPEND_TRANSITION_COMMENT((" "));
;
      APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
;
      APPEND_TRANSITION_COMMENT((" "));
;
      APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_PhysicalAddress);
;
      ((*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version]))).enqueue(out_msg, L1_RESPONSE_LATENCY);
    }
  }
}

/** \brief send data to the L2 cache*/
void L1Cache_Controller::fi_sendInvNack(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L1Cache_requestToL1Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      ResponseMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
      (out_msg).m_Type = CoherenceResponseType_NACK;
      (out_msg).m_Sender = m_machineID;
      (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
      (out_msg).m_MessageSize = MessageSizeType_Response_Control;
      (out_msg).m_AckCount = (1);
      APPEND_TRANSITION_COMMENT((out_msg).m_Timestamp);
;
      APPEND_TRANSITION_COMMENT((" "));
;
      APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Timestamp);
;
      APPEND_TRANSITION_COMMENT((" "));
;
      APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
;
      APPEND_TRANSITION_COMMENT((" "));
;
      APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_PhysicalAddress);
;
      ((*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version]))).enqueue(out_msg, L1_RESPONSE_LATENCY);
    }
  }
}

/** \brief Check our write filter for conflicts*/
void L1Cache_Controller::a_checkWriteFilter(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L1Cache_requestToL1Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    if (((L1Cache_shouldNackLoad(((*in_msg_ptr)).m_PhysicalAddress, ((*in_msg_ptr)).m_Timestamp, ((*in_msg_ptr)).m_Requestor)) == (true))) {
      {
        ResponseMsg out_msg;
        (out_msg).m_Address = addr;
        (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
        (out_msg).m_Type = CoherenceResponseType_NACK;
        (out_msg).m_ConflictType = (true);
        (out_msg).m_Sender = m_machineID;
        (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
        (out_msg).m_MessageSize = MessageSizeType_Response_Control;
        (out_msg).m_AckCount = (1);
        APPEND_TRANSITION_COMMENT((out_msg).m_Timestamp);
;
        APPEND_TRANSITION_COMMENT((" "));
;
        APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Timestamp);
;
        APPEND_TRANSITION_COMMENT((" "));
;
        APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
;
        APPEND_TRANSITION_COMMENT((" "));
;
        APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_PhysicalAddress);
;
        ((*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version]))).enqueue(out_msg, L1_RESPONSE_LATENCY);
      }
    } else {
      {
        ResponseMsg out_msg;
        (out_msg).m_Address = addr;
        (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
        (out_msg).m_Type = CoherenceResponseType_ACK;
        (out_msg).m_Sender = m_machineID;
        (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
        (out_msg).m_MessageSize = MessageSizeType_Response_Control;
        (out_msg).m_AckCount = (1);
        APPEND_TRANSITION_COMMENT((" "));
;
        APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_PhysicalAddress);
;
        ((*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version]))).enqueue(out_msg, L1_RESPONSE_LATENCY);
      }
    }
  }
}

/** \brief Check our write filter for conflicts*/
void L1Cache_Controller::a_checkReadWriteFilter(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L1Cache_requestToL1Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    if (((L1Cache_shouldNackStore(((*in_msg_ptr)).m_PhysicalAddress, ((*in_msg_ptr)).m_Timestamp, ((*in_msg_ptr)).m_Requestor)) == (true))) {
      {
        ResponseMsg out_msg;
        (out_msg).m_Address = addr;
        (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
        (out_msg).m_Type = CoherenceResponseType_NACK;
        (out_msg).m_ConflictType = (true);
        (out_msg).m_Sender = m_machineID;
        (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
        (out_msg).m_MessageSize = MessageSizeType_Response_Control;
        (out_msg).m_AckCount = (1);
        APPEND_TRANSITION_COMMENT((out_msg).m_Timestamp);
;
        APPEND_TRANSITION_COMMENT((" "));
;
        APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Timestamp);
;
        APPEND_TRANSITION_COMMENT((" "));
;
        APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
;
        APPEND_TRANSITION_COMMENT((" "));
;
        APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_PhysicalAddress);
;
        ((*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version]))).enqueue(out_msg, L1_RESPONSE_LATENCY);
      }
    } else {
      {
        ResponseMsg out_msg;
        (out_msg).m_Address = addr;
        (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
        (out_msg).m_Type = CoherenceResponseType_ACK;
        (out_msg).m_Sender = m_machineID;
        (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
        (out_msg).m_MessageSize = MessageSizeType_Response_Control;
        (out_msg).m_AckCount = (1);
        APPEND_TRANSITION_COMMENT((" "));
;
        APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_PhysicalAddress);
;
        ((*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version]))).enqueue(out_msg, L1_RESPONSE_LATENCY);
      }
    }
  }
}

/** \brief Notify the driver when a nack is received*/
void L1Cache_Controller::r_notifyReceiveNack(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<ResponseMsg*>(((*(m_chip_ptr->m_L1Cache_responseToL1Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
  }
}

/** \brief Notify the driver when the final nack is received*/
void L1Cache_Controller::r_notifyReceiveNackFinal(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
}

/** \brief Set the prefetch bit in the TBE.*/
void L1Cache_Controller::x_tbeSetPrefetch(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    CacheMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<CacheMsg*>(((*(m_chip_ptr->m_L1Cache_mandatoryQueue_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    if ((((*in_msg_ptr)).m_Prefetch == PrefetchBit_No)) {
      ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_isPrefetch = (false);
    } else {
            if (ASSERT_FLAG && !((((*in_msg_ptr)).m_Prefetch == PrefetchBit_Yes))) {
        cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L1cache.sm:826, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

      }
;
      ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_isPrefetch = (true);
    }
  }
}

/** \brief Sets the physical address field of the TBE*/
void L1Cache_Controller::x_tbeSetPhysicalAddress(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    CacheMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<CacheMsg*>(((*(m_chip_ptr->m_L1Cache_mandatoryQueue_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
    ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_ThreadID = ((*in_msg_ptr)).m_ThreadID;
    ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_Timestamp = ((*in_msg_ptr)).m_Timestamp;
  }
}

/** \brief send unblock to the L2 cache*/
void L1Cache_Controller::jj_sendUnblockCancel(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg out_msg;
    (out_msg).m_Address = addr;
    (out_msg).m_Type = CoherenceResponseType_UNBLOCK_CANCEL;
    (out_msg).m_Sender = m_machineID;
    (((out_msg).m_Destination).add((map_L1CacheMachId_to_L2Cache(addr, m_machineID))));
    (out_msg).m_MessageSize = MessageSizeType_Response_Control;
    (out_msg).m_Nackers = ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_Nackers;
    ((*(m_chip_ptr->m_L1Cache_unblockFromL1Cache_vec[m_version]))).enqueue(out_msg, 1);
  }
}

/** \brief Update ack count*/
void L1Cache_Controller::q_updateNackCount(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<ResponseMsg*>(((*(m_chip_ptr->m_L1Cache_responseToL1Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_nack = (true);
    APPEND_TRANSITION_COMMENT((" before pendingAcks: "));
;
    APPEND_TRANSITION_COMMENT(((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_pendingAcks);
;
    ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_pendingAcks = (((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_pendingAcks - ((*in_msg_ptr)).m_AckCount);
    ((((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_Nackers).add(((*in_msg_ptr)).m_Sender));
    APPEND_TRANSITION_COMMENT((" "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_PhysicalAddress);
;
    APPEND_TRANSITION_COMMENT((" "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_AckCount);
;
    APPEND_TRANSITION_COMMENT((" after pendingAcks: "));
;
    APPEND_TRANSITION_COMMENT(((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_pendingAcks);
;
    APPEND_TRANSITION_COMMENT((" sender: "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Sender);
;
    if ((((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_pendingAcks == (0))) {
      {
        TriggerMsg out_msg;
        (out_msg).m_Address = addr;
        (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
        (out_msg).m_Type = TriggerType_ALL_ACKS;
        APPEND_TRANSITION_COMMENT((" Triggering All_Acks"));
;
        ((*(m_chip_ptr->m_L1Cache_triggerQueue_vec[m_version]))).enqueue(out_msg);
      }
    }
  }
}

/** \brief profile the overflowed block*/
void L1Cache_Controller::q_profileOverflow(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (profileOverflow(addr, m_machineID));
}

/** \brief replaced a transactional block*/
void L1Cache_Controller::qq_xactReplacement(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
}

/** \brief Profile request msg*/
void L1Cache_Controller::p_profileRequest(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    CacheMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<CacheMsg*>(((*(m_chip_ptr->m_L1Cache_mandatoryQueue_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    APPEND_TRANSITION_COMMENT((" request: Timestamp: "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Timestamp);
;
    APPEND_TRANSITION_COMMENT((" PA: "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_PhysicalAddress);
;
    APPEND_TRANSITION_COMMENT((" Type: "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Type);
;
    APPEND_TRANSITION_COMMENT((" VPC: "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_ProgramCounter);
;
    APPEND_TRANSITION_COMMENT((" Mode: "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_AccessMode);
;
    APPEND_TRANSITION_COMMENT((" PF: "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Prefetch);
;
    APPEND_TRANSITION_COMMENT((" VA: "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_LogicalAddress);
;
    APPEND_TRANSITION_COMMENT((" Thread: "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_ThreadID);
;
    APPEND_TRANSITION_COMMENT((" Exposed: "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_ExposedAction);
;
  }
}

/** \brief send data to requestor*/
void L1Cache_Controller::d_sendDataToRequestor(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L1Cache_requestToL1Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      ResponseMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_Type = CoherenceResponseType_DATA;
      (out_msg).m_DataBlk = ((L1Cache_getL1CacheEntry(addr))).m_DataBlk;
      (out_msg).m_Dirty = ((L1Cache_getL1CacheEntry(addr))).m_Dirty;
      (out_msg).m_Sender = m_machineID;
      (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
      (out_msg).m_MessageSize = MessageSizeType_Response_Data;
      ((*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version]))).enqueue(out_msg, L1_RESPONSE_LATENCY);
    }
  }
}

/** \brief send data to the L2 cache because of M downgrade*/
void L1Cache_Controller::d2_sendDataToL2(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg out_msg;
    (out_msg).m_Address = addr;
    (out_msg).m_Type = CoherenceResponseType_DATA;
    (out_msg).m_DataBlk = ((L1Cache_getL1CacheEntry(addr))).m_DataBlk;
    (out_msg).m_Dirty = ((L1Cache_getL1CacheEntry(addr))).m_Dirty;
    (out_msg).m_Sender = m_machineID;
    (((out_msg).m_Destination).add((map_L1CacheMachId_to_L2Cache(addr, m_machineID))));
    (out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version]))).enqueue(out_msg, L1_RESPONSE_LATENCY);
  }
}

/** \brief send data to requestor*/
void L1Cache_Controller::dt_sendDataToRequestor_fromTBE(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L1Cache_requestToL1Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      ResponseMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_Type = CoherenceResponseType_DATA;
      (out_msg).m_DataBlk = ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_DataBlk;
      (out_msg).m_Dirty = ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_Dirty;
      (out_msg).m_Sender = m_machineID;
      (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
      (out_msg).m_MessageSize = MessageSizeType_Response_Data;
      (out_msg).m_RemoveLastOwnerFromDir = (true);
      (out_msg).m_LastOwnerID = m_machineID;
      ((*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version]))).enqueue(out_msg, L1_RESPONSE_LATENCY);
    }
  }
}

/** \brief send data to the L2 cache*/
void L1Cache_Controller::d2t_sendDataToL2_fromTBE(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg out_msg;
    (out_msg).m_Address = addr;
    (out_msg).m_Type = CoherenceResponseType_DATA;
    (out_msg).m_DataBlk = ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_DataBlk;
    (out_msg).m_Dirty = ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_Dirty;
    (out_msg).m_Sender = m_machineID;
    (((out_msg).m_Destination).add((map_L1CacheMachId_to_L2Cache(addr, m_machineID))));
    (out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version]))).enqueue(out_msg, L1_RESPONSE_LATENCY);
  }
}

/** \brief send data to the L2 cache*/
void L1Cache_Controller::f_sendDataToL2(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg out_msg;
    (out_msg).m_Address = addr;
    (out_msg).m_Type = CoherenceResponseType_DATA;
    (out_msg).m_DataBlk = ((L1Cache_getL1CacheEntry(addr))).m_DataBlk;
    (out_msg).m_Dirty = ((L1Cache_getL1CacheEntry(addr))).m_Dirty;
    (out_msg).m_Sender = m_machineID;
    (((out_msg).m_Destination).add((map_L1CacheMachId_to_L2Cache(addr, m_machineID))));
    (out_msg).m_MessageSize = MessageSizeType_Writeback_Data;
    ((*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version]))).enqueue(out_msg, L1_RESPONSE_LATENCY);
  }
}

/** \brief send data to the L2 cache*/
void L1Cache_Controller::ft_sendDataToL2_fromTBE(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg out_msg;
    (out_msg).m_Address = addr;
    (out_msg).m_Type = CoherenceResponseType_DATA;
    (out_msg).m_DataBlk = ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_DataBlk;
    (out_msg).m_Dirty = ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_Dirty;
    (out_msg).m_Sender = m_machineID;
    (((out_msg).m_Destination).add((map_L1CacheMachId_to_L2Cache(addr, m_machineID))));
    (out_msg).m_MessageSize = MessageSizeType_Writeback_Data;
    ((*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version]))).enqueue(out_msg, L1_RESPONSE_LATENCY);
  }
}

/** \brief send data to the L2 cache*/
void L1Cache_Controller::fi_sendInvAck(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L1Cache_requestToL1Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      ResponseMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
      (out_msg).m_Type = CoherenceResponseType_ACK;
      (out_msg).m_Sender = m_machineID;
      (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
      (out_msg).m_MessageSize = MessageSizeType_Response_Control;
      (out_msg).m_AckCount = (1);
      APPEND_TRANSITION_COMMENT((" "));
;
      APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_PhysicalAddress);
;
      ((*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version]))).enqueue(out_msg, L1_RESPONSE_LATENCY);
    }
  }
}

/** \brief send data to the L2 cache*/
void L1Cache_Controller::g_issuePUTX(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg out_msg;
    (out_msg).m_Address = addr;
    (out_msg).m_Type = CoherenceRequestType_PUTX;
    (out_msg).m_DataBlk = ((L1Cache_getL1CacheEntry(addr))).m_DataBlk;
    (out_msg).m_Dirty = ((L1Cache_getL1CacheEntry(addr))).m_Dirty;
    (out_msg).m_Requestor = m_machineID;
    (((out_msg).m_Destination).add((map_L1CacheMachId_to_L2Cache(addr, m_machineID))));
    if (((L1Cache_getL1CacheEntry(addr))).m_Dirty) {
      (out_msg).m_MessageSize = MessageSizeType_Writeback_Data;
    } else {
      (out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    }
    ((*(m_chip_ptr->m_L1Cache_requestFromL1Cache_vec[m_version]))).enqueue(out_msg, L1_RESPONSE_LATENCY);
  }
}

/** \brief send clean data to the L2 cache*/
void L1Cache_Controller::g_issuePUTS(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg out_msg;
    (out_msg).m_Address = addr;
    (out_msg).m_Type = CoherenceRequestType_PUTS;
    (out_msg).m_DataBlk = ((L1Cache_getL1CacheEntry(addr))).m_DataBlk;
    (out_msg).m_Dirty = ((L1Cache_getL1CacheEntry(addr))).m_Dirty;
    (out_msg).m_Requestor = m_machineID;
    (((out_msg).m_Destination).add((map_L1CacheMachId_to_L2Cache(addr, m_machineID))));
    if (((L1Cache_getL1CacheEntry(addr))).m_Dirty) {
      (out_msg).m_MessageSize = MessageSizeType_Writeback_Data;
    } else {
      (out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    }
    ((*(m_chip_ptr->m_L1Cache_requestFromL1Cache_vec[m_version]))).enqueue(out_msg, L1_RESPONSE_LATENCY);
  }
}

/** \brief send data to the L2 cache*/
void L1Cache_Controller::g_issuePUTXorPUTS(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg out_msg;
    (out_msg).m_Address = addr;
    if (((L1Cache_checkWriteSignatures(addr)) == (true))) {
      (out_msg).m_Type = CoherenceRequestType_PUTX;
    } else {
      (out_msg).m_Type = CoherenceRequestType_PUTS;
    }
    (out_msg).m_DataBlk = ((L1Cache_getL1CacheEntry(addr))).m_DataBlk;
    (out_msg).m_Dirty = ((L1Cache_getL1CacheEntry(addr))).m_Dirty;
    (out_msg).m_Requestor = m_machineID;
    (((out_msg).m_Destination).add((map_L1CacheMachId_to_L2Cache(addr, m_machineID))));
    if (((L1Cache_getL1CacheEntry(addr))).m_Dirty) {
      (out_msg).m_MessageSize = MessageSizeType_Writeback_Data;
    } else {
      (out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    }
    ((*(m_chip_ptr->m_L1Cache_requestFromL1Cache_vec[m_version]))).enqueue(out_msg, L1_RESPONSE_LATENCY);
  }
}

/** \brief send unblock to the L2 cache*/
void L1Cache_Controller::j_sendUnblock(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg out_msg;
    (out_msg).m_Address = addr;
    (out_msg).m_Type = CoherenceResponseType_UNBLOCK;
    (out_msg).m_Sender = m_machineID;
    (((out_msg).m_Destination).add((map_L1CacheMachId_to_L2Cache(addr, m_machineID))));
    (out_msg).m_MessageSize = MessageSizeType_Response_Control;
    (out_msg).m_Transactional = (L1Cache_checkReadWriteSignatures(addr));
    (out_msg).m_RemoveLastOwnerFromDir = ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_RemoveLastOwnerFromDir;
    (out_msg).m_LastOwnerID = ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_LastOwnerID;
    ((*(m_chip_ptr->m_L1Cache_unblockFromL1Cache_vec[m_version]))).enqueue(out_msg, 1);
  }
}

/** \brief send unblock to the L2 cache*/
void L1Cache_Controller::jj_sendExclusiveUnblock(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg out_msg;
    (out_msg).m_Address = addr;
    (out_msg).m_Type = CoherenceResponseType_EXCLUSIVE_UNBLOCK;
    (out_msg).m_Sender = m_machineID;
    (((out_msg).m_Destination).add((map_L1CacheMachId_to_L2Cache(addr, m_machineID))));
    (out_msg).m_MessageSize = MessageSizeType_Response_Control;
    (out_msg).m_Transactional = (L1Cache_checkReadWriteSignatures(addr));
    (out_msg).m_RemoveLastOwnerFromDir = ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_RemoveLastOwnerFromDir;
    (out_msg).m_LastOwnerID = ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_LastOwnerID;
    ((*(m_chip_ptr->m_L1Cache_unblockFromL1Cache_vec[m_version]))).enqueue(out_msg, 1);
  }
}

/** \brief If not prefetch, notify sequencer the load completed.*/
void L1Cache_Controller::h_load_hit(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:1101: ", ((L1Cache_getL1CacheEntry(addr))).m_DataBlk);
;
  ((*(dynamic_cast<Sequencer*>(m_chip_ptr->getSequencer(m_version)))).readCallback(addr, ((L1Cache_getL1CacheEntry(addr))).m_DataBlk));
}

/** \brief If not prefetch, notify sequencer that store completed.*/
void L1Cache_Controller::hh_store_hit(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:1106: ", ((L1Cache_getL1CacheEntry(addr))).m_DataBlk);
;
  ((*(dynamic_cast<Sequencer*>(m_chip_ptr->getSequencer(m_version)))).writeCallback(addr, ((L1Cache_getL1CacheEntry(addr))).m_DataBlk));
  ((L1Cache_getL1CacheEntry(addr))).m_Dirty = (true);
}

/** \brief Notify sequencer of conflict on load*/
void L1Cache_Controller::h_load_conflict(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  ((*(dynamic_cast<Sequencer*>(m_chip_ptr->getSequencer(m_version)))).readConflictCallback(addr));
}

/** \brief If not prefetch, notify sequencer that store completed.*/
void L1Cache_Controller::hh_store_conflict(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  ((*(dynamic_cast<Sequencer*>(m_chip_ptr->getSequencer(m_version)))).writeConflictCallback(addr));
}

/** \brief Allocate TBE (isPrefetch=0, number of invalidates=0)*/
void L1Cache_Controller::i_allocateTBE(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).allocate(addr));
  ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_isPrefetch = (false);
  {
    CacheMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<CacheMsg*>(((*(m_chip_ptr->m_L1Cache_mandatoryQueue_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    if (((((*in_msg_ptr)).m_Type == CacheRequestType_LD_XACT) || (((*in_msg_ptr)).m_Type == CacheRequestType_ST_XACT))) {
      ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_Trans = (true);
    }
  }
  ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_Dirty = ((L1Cache_getL1CacheEntry(addr))).m_Dirty;
  ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_DataBlk = ((L1Cache_getL1CacheEntry(addr))).m_DataBlk;
}

/** \brief Pop mandatory queue.*/
void L1Cache_Controller::k_popMandatoryQueue(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (((*(m_chip_ptr->m_L1Cache_mandatoryQueue_vec[m_version]))).dequeue());
}

/** \brief Pop trigger queue.*/
void L1Cache_Controller::j_popTriggerQueue(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (((*(m_chip_ptr->m_L1Cache_triggerQueue_vec[m_version]))).dequeue());
}

/** \brief Pop incoming request queue and profile the delay within this virtual network*/
void L1Cache_Controller::l_popRequestQueue(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (profileMsgDelay((2), (((*(m_chip_ptr->m_L1Cache_requestToL1Cache_vec[m_version]))).dequeue_getDelayCycles())));
}

/** \brief Pop Incoming Response queue and profile the delay within this virtual network*/
void L1Cache_Controller::o_popIncomingResponseQueue(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (profileMsgDelay((3), (((*(m_chip_ptr->m_L1Cache_responseToL1Cache_vec[m_version]))).dequeue_getDelayCycles())));
}

/** \brief Deallocate TBE*/
void L1Cache_Controller::s_deallocateTBE(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).deallocate(addr));
}

/** \brief Write data to cache*/
void L1Cache_Controller::u_writeDataToL1Cache(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<ResponseMsg*>(((*(m_chip_ptr->m_L1Cache_responseToL1Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    ((L1Cache_getL1CacheEntry(addr))).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
    ((L1Cache_getL1CacheEntry(addr))).m_Dirty = ((*in_msg_ptr)).m_Dirty;
    if (((machineIDToMachineType(((*in_msg_ptr)).m_Sender)) == MachineType_L1Cache)) {
      ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_RemoveLastOwnerFromDir = ((*in_msg_ptr)).m_RemoveLastOwnerFromDir;
      ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_LastOwnerID = ((*in_msg_ptr)).m_LastOwnerID;
    }
  }
}

/** \brief Update ack count*/
void L1Cache_Controller::q_updateAckCount(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<ResponseMsg*>(((*(m_chip_ptr->m_L1Cache_responseToL1Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    APPEND_TRANSITION_COMMENT((" before pendingAcks: "));
;
    APPEND_TRANSITION_COMMENT(((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_pendingAcks);
;
    ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_pendingAcks = (((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_pendingAcks - ((*in_msg_ptr)).m_AckCount);
    APPEND_TRANSITION_COMMENT((" "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_PhysicalAddress);
;
    APPEND_TRANSITION_COMMENT((" "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_AckCount);
;
    APPEND_TRANSITION_COMMENT((" after pendingAcks: "));
;
    APPEND_TRANSITION_COMMENT(((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_pendingAcks);
;
    APPEND_TRANSITION_COMMENT((" sender: "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Sender);
;
    if ((((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(addr))).m_pendingAcks == (0))) {
      {
        TriggerMsg out_msg;
        (out_msg).m_Address = addr;
        (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
        (out_msg).m_Type = TriggerType_ALL_ACKS;
        APPEND_TRANSITION_COMMENT((" Triggering All_Acks"));
;
        ((*(m_chip_ptr->m_L1Cache_triggerQueue_vec[m_version]))).enqueue(out_msg);
      }
    }
  }
}

/** \brief Stall*/
void L1Cache_Controller::z_stall(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
}

/** \brief Deallocate L1 cache block.  Sets the cache to not present, allowing a replacement in parallel with a fetch.*/
void L1Cache_Controller::ff_deallocateL1CacheBlock(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  if ((((*(m_chip_ptr->m_L1Cache_L1DcacheMemory_vec[m_version]))).isTagPresent(addr))) {
    (((*(m_chip_ptr->m_L1Cache_L1DcacheMemory_vec[m_version]))).deallocate(addr));
  } else {
    (((*(m_chip_ptr->m_L1Cache_L1IcacheMemory_vec[m_version]))).deallocate(addr));
  }
}

/** \brief Set L1 D-cache tag equal to tag of block B.*/
void L1Cache_Controller::oo_allocateL1DCacheBlock(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  if (((((*(m_chip_ptr->m_L1Cache_L1DcacheMemory_vec[m_version]))).isTagPresent(addr)) == (false))) {
    (((*(m_chip_ptr->m_L1Cache_L1DcacheMemory_vec[m_version]))).allocate(addr));
  }
  {
    CacheMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<CacheMsg*>(((*(m_chip_ptr->m_L1Cache_mandatoryQueue_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    if (((((*in_msg_ptr)).m_Type == CacheRequestType_LD_XACT) || (((*in_msg_ptr)).m_Type == CacheRequestType_ST_XACT))) {
      ((((*(m_chip_ptr->m_L1Cache_L1DcacheMemory_vec[m_version]))).lookup(addr))).m_Trans = (true);
    }
  }
}

/** \brief Set L1 I-cache tag equal to tag of block B.*/
void L1Cache_Controller::pp_allocateL1ICacheBlock(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  if (((((*(m_chip_ptr->m_L1Cache_L1IcacheMemory_vec[m_version]))).isTagPresent(addr)) == (false))) {
    (((*(m_chip_ptr->m_L1Cache_L1IcacheMemory_vec[m_version]))).allocate(addr));
  }
}

/** \brief recycle L1 request queue*/
void L1Cache_Controller::zz_recycleRequestQueue(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (((*(m_chip_ptr->m_L1Cache_requestToL1Cache_vec[m_version]))).recycle());
}

/** \brief recycle L1 request queue*/
void L1Cache_Controller::z_recycleMandatoryQueue(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (((*(m_chip_ptr->m_L1Cache_mandatoryQueue_vec[m_version]))).recycle());
}

/** \brief Profile the demand miss*/
void L1Cache_Controller::uu_profileMiss(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    CacheMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<CacheMsg*>(((*(m_chip_ptr->m_L1Cache_mandatoryQueue_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    (profile_L1Cache_miss((*in_msg_ptr), m_chip_ptr->getID()));
  }
}

/** \brief Profile Miss*/
void L1Cache_Controller::uuu_profileTransactionLoadMiss(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
}

/** \brief Profile Miss*/
void L1Cache_Controller::uuu_profileTransactionStoreMiss(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
}

