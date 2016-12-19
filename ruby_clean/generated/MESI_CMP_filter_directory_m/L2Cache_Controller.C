/** \file L2Cache.C
  * 
  * Auto generated C++ code started by symbols/StateMachine.C:327
  * Created by slicc definition of Module "MESI Directory L2 Cache CMP"
  */

#include "Global.h"
#include "RubySlicc_includes.h"
#include "L2Cache_Controller.h"
#include "L2Cache_State.h"
#include "L2Cache_Event.h"
#include "Types.h"
#include "System.h"
#include "Chip.h"

stringstream L2Cache_transitionComment;
#define APPEND_TRANSITION_COMMENT(str) (L2Cache_transitionComment << str)
/** \brief static profiler defn */
L2Cache_Profiler L2Cache_Controller::s_profiler;

/** \brief constructor */
L2Cache_Controller::L2Cache_Controller(Chip* chip_ptr, int version)
{
  m_chip_ptr = chip_ptr;
  m_id = m_chip_ptr->getID();
  m_version = version;
  m_machineID.type = MachineType_L2Cache;
  m_machineID.num = m_id*RubyConfig::numberOfL2CachePerChip()+m_version;
  (*(m_chip_ptr->m_L2Cache_responseToL2Cache_vec[m_version])).setConsumer(this);
  (*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version])).setConsumer(this);
  (*(m_chip_ptr->m_L2Cache_unblockToL2Cache_vec[m_version])).setConsumer(this);

  (*(m_chip_ptr->m_L2Cache_responseToL2Cache_vec[m_version])).setDescription("[Chip " + int_to_string(m_chip_ptr->getID()) + " " + int_to_string(m_version) + ", L2Cache, responseIntraChipL2Network_in]");
  (*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version])).setDescription("[Chip " + int_to_string(m_chip_ptr->getID()) + " " + int_to_string(m_version) + ", L2Cache, L1RequestIntraChipL2Network_in]");
  (*(m_chip_ptr->m_L2Cache_unblockToL2Cache_vec[m_version])).setDescription("[Chip " + int_to_string(m_chip_ptr->getID()) + " " + int_to_string(m_version) + ", L2Cache, L1unblockNetwork_in]");

  s_profiler.possibleTransition(L2Cache_State_PB_MT, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_PB_MT, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_PB_MT, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_PB_MT, L2Cache_Event_L1_UPGRADE);
  s_profiler.possibleTransition(L2Cache_State_PB_MT, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_PB_MT, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_PB_MT, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_PB_MT, L2Cache_Event_L2_Replacement);
  s_profiler.possibleTransition(L2Cache_State_PB_MT, L2Cache_Event_L2_Replacement_clean);
  s_profiler.possibleTransition(L2Cache_State_PB_MT, L2Cache_Event_L2_Replacement_XACT);
  s_profiler.possibleTransition(L2Cache_State_PB_MT, L2Cache_Event_L2_Replacement_clean_XACT);
  s_profiler.possibleTransition(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_UPGRADE);
  s_profiler.possibleTransition(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_PB_MT_IB, L2Cache_Event_L2_Replacement);
  s_profiler.possibleTransition(L2Cache_State_PB_MT_IB, L2Cache_Event_L2_Replacement_clean);
  s_profiler.possibleTransition(L2Cache_State_PB_MT_IB, L2Cache_Event_L2_Replacement_XACT);
  s_profiler.possibleTransition(L2Cache_State_PB_MT_IB, L2Cache_Event_L2_Replacement_clean_XACT);
  s_profiler.possibleTransition(L2Cache_State_PB_SS, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_PB_SS, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_PB_SS, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_PB_SS, L2Cache_Event_L1_UPGRADE);
  s_profiler.possibleTransition(L2Cache_State_PB_SS, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_PB_SS, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_PB_SS, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_PB_SS, L2Cache_Event_L2_Replacement);
  s_profiler.possibleTransition(L2Cache_State_PB_SS, L2Cache_Event_L2_Replacement_clean);
  s_profiler.possibleTransition(L2Cache_State_PB_SS, L2Cache_Event_L2_Replacement_XACT);
  s_profiler.possibleTransition(L2Cache_State_PB_SS, L2Cache_Event_L2_Replacement_clean_XACT);
  s_profiler.possibleTransition(L2Cache_State_IM, L2Cache_Event_L2_Replacement);
  s_profiler.possibleTransition(L2Cache_State_IM, L2Cache_Event_L2_Replacement_clean);
  s_profiler.possibleTransition(L2Cache_State_IM, L2Cache_Event_L2_Replacement_XACT);
  s_profiler.possibleTransition(L2Cache_State_IM, L2Cache_Event_L2_Replacement_clean_XACT);
  s_profiler.possibleTransition(L2Cache_State_IS, L2Cache_Event_L2_Replacement);
  s_profiler.possibleTransition(L2Cache_State_IS, L2Cache_Event_L2_Replacement_clean);
  s_profiler.possibleTransition(L2Cache_State_IS, L2Cache_Event_L2_Replacement_XACT);
  s_profiler.possibleTransition(L2Cache_State_IS, L2Cache_Event_L2_Replacement_clean_XACT);
  s_profiler.possibleTransition(L2Cache_State_ISS, L2Cache_Event_L2_Replacement);
  s_profiler.possibleTransition(L2Cache_State_ISS, L2Cache_Event_L2_Replacement_clean);
  s_profiler.possibleTransition(L2Cache_State_ISS, L2Cache_Event_L2_Replacement_XACT);
  s_profiler.possibleTransition(L2Cache_State_ISS, L2Cache_Event_L2_Replacement_clean_XACT);
  s_profiler.possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L2_Replacement);
  s_profiler.possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L2_Replacement_clean);
  s_profiler.possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L2_Replacement_XACT);
  s_profiler.possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L2_Replacement_clean_XACT);
  s_profiler.possibleTransition(L2Cache_State_M_MB, L2Cache_Event_L2_Replacement);
  s_profiler.possibleTransition(L2Cache_State_M_MB, L2Cache_Event_L2_Replacement_clean);
  s_profiler.possibleTransition(L2Cache_State_M_MB, L2Cache_Event_L2_Replacement_XACT);
  s_profiler.possibleTransition(L2Cache_State_M_MB, L2Cache_Event_L2_Replacement_clean_XACT);
  s_profiler.possibleTransition(L2Cache_State_ISS_MB, L2Cache_Event_L2_Replacement);
  s_profiler.possibleTransition(L2Cache_State_ISS_MB, L2Cache_Event_L2_Replacement_clean);
  s_profiler.possibleTransition(L2Cache_State_ISS_MB, L2Cache_Event_L2_Replacement_XACT);
  s_profiler.possibleTransition(L2Cache_State_ISS_MB, L2Cache_Event_L2_Replacement_clean_XACT);
  s_profiler.possibleTransition(L2Cache_State_IS_SSB, L2Cache_Event_L2_Replacement);
  s_profiler.possibleTransition(L2Cache_State_IS_SSB, L2Cache_Event_L2_Replacement_clean);
  s_profiler.possibleTransition(L2Cache_State_IS_SSB, L2Cache_Event_L2_Replacement_XACT);
  s_profiler.possibleTransition(L2Cache_State_IS_SSB, L2Cache_Event_L2_Replacement_clean_XACT);
  s_profiler.possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L2_Replacement);
  s_profiler.possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L2_Replacement_clean);
  s_profiler.possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L2_Replacement_XACT);
  s_profiler.possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L2_Replacement_clean_XACT);
  s_profiler.possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L2_Replacement);
  s_profiler.possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L2_Replacement_clean);
  s_profiler.possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L2_Replacement_XACT);
  s_profiler.possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L2_Replacement_clean_XACT);
  s_profiler.possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L2_Replacement);
  s_profiler.possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L2_Replacement_clean);
  s_profiler.possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L2_Replacement_XACT);
  s_profiler.possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L2_Replacement_clean_XACT);
  s_profiler.possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L2_Replacement);
  s_profiler.possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L2_Replacement_clean);
  s_profiler.possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L2_Replacement_XACT);
  s_profiler.possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L2_Replacement_clean_XACT);
  s_profiler.possibleTransition(L2Cache_State_M_SSB, L2Cache_Event_L2_Replacement);
  s_profiler.possibleTransition(L2Cache_State_M_SSB, L2Cache_Event_L2_Replacement_clean);
  s_profiler.possibleTransition(L2Cache_State_M_SSB, L2Cache_Event_L2_Replacement_XACT);
  s_profiler.possibleTransition(L2Cache_State_M_SSB, L2Cache_Event_L2_Replacement_clean_XACT);
  s_profiler.possibleTransition(L2Cache_State_SS_SSB, L2Cache_Event_L2_Replacement);
  s_profiler.possibleTransition(L2Cache_State_SS_SSB, L2Cache_Event_L2_Replacement_clean);
  s_profiler.possibleTransition(L2Cache_State_SS_SSB, L2Cache_Event_L2_Replacement_XACT);
  s_profiler.possibleTransition(L2Cache_State_SS_SSB, L2Cache_Event_L2_Replacement_clean_XACT);
  s_profiler.possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L1_UPGRADE);
  s_profiler.possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_M_MB, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_M_MB, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_M_MB, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_M_MB, L2Cache_Event_L1_UPGRADE);
  s_profiler.possibleTransition(L2Cache_State_M_MB, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_M_MB, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_M_MB, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_ISS_MB, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_ISS_MB, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_ISS_MB, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_ISS_MB, L2Cache_Event_L1_UPGRADE);
  s_profiler.possibleTransition(L2Cache_State_ISS_MB, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_ISS_MB, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_ISS_MB, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_IS_SSB, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_IS_SSB, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_IS_SSB, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_IS_SSB, L2Cache_Event_L1_UPGRADE);
  s_profiler.possibleTransition(L2Cache_State_IS_SSB, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_IS_SSB, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_IS_SSB, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L1_UPGRADE);
  s_profiler.possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L1_UPGRADE);
  s_profiler.possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L1_UPGRADE);
  s_profiler.possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L1_UPGRADE);
  s_profiler.possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_M_SSB, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_M_SSB, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_M_SSB, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_M_SSB, L2Cache_Event_L1_UPGRADE);
  s_profiler.possibleTransition(L2Cache_State_M_SSB, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_M_SSB, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_M_SSB, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_SS_SSB, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_SS_SSB, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_SS_SSB, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_SS_SSB, L2Cache_Event_L1_UPGRADE);
  s_profiler.possibleTransition(L2Cache_State_SS_SSB, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_SS_SSB, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_SS_SSB, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_NP, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_NP, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_M, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_M, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_M_I, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_M_I, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_MT_I, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_MT_I, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_I_I, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_I_I, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_S_I, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_S_I, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_ISS, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_ISS, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_IS, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_IS, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_IM, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_IM, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_SS_SSB, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_SS_SSB, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_IS_SSB, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_IS_SSB, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_M_SSB, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_M_SSB, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_NP, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_NP, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_M_I, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_M_I, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_I_I, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_I_I, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_S_I, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_S_I, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_IS, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_IS, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_ISS, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_ISS, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_IM, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_IM, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_M, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_M, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_MT, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_MT, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_IS_SSB, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_IS_SSB, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_M_SSB, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_M_SSB, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_SS_SSB, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_SS_SSB, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_MT_I, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_MT_I, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_PUT_PENDING);
  s_profiler.possibleTransition(L2Cache_State_M, L2Cache_Event_L1_PUT_PENDING);
  s_profiler.possibleTransition(L2Cache_State_MT, L2Cache_Event_L1_PUT_PENDING);
  s_profiler.possibleTransition(L2Cache_State_NP, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_NP, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_NP, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_NP, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_NP, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_NP, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_ISS, L2Cache_Event_Mem_Data);
  s_profiler.possibleTransition(L2Cache_State_IS, L2Cache_Event_Mem_Data);
  s_profiler.possibleTransition(L2Cache_State_IM, L2Cache_Event_Mem_Data);
  s_profiler.possibleTransition(L2Cache_State_IS, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_IS, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_IS, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_IS, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_IS, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_IS, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_ISS, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_ISS, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_ISS, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_ISS, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_ISS, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_ISS, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_IM, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_IM, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_IM, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_IM, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_IM, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_IM, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_SS, L2Cache_Event_L1_UPGRADE);
  s_profiler.possibleTransition(L2Cache_State_SS, L2Cache_Event_L2_Replacement_clean);
  s_profiler.possibleTransition(L2Cache_State_SS, L2Cache_Event_L2_Replacement_clean_XACT);
  s_profiler.possibleTransition(L2Cache_State_SS, L2Cache_Event_L2_Replacement);
  s_profiler.possibleTransition(L2Cache_State_SS, L2Cache_Event_L2_Replacement_XACT);
  s_profiler.possibleTransition(L2Cache_State_M, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_M, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_M, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_M, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_M, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_M, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_M, L2Cache_Event_L2_Replacement);
  s_profiler.possibleTransition(L2Cache_State_M, L2Cache_Event_L2_Replacement_clean);
  s_profiler.possibleTransition(L2Cache_State_M, L2Cache_Event_L2_Replacement_XACT);
  s_profiler.possibleTransition(L2Cache_State_M, L2Cache_Event_L2_Replacement_clean_XACT);
  s_profiler.possibleTransition(L2Cache_State_MT, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_MT, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_MT, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_MT, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_MT, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_MT, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_MT, L2Cache_Event_L2_Replacement);
  s_profiler.possibleTransition(L2Cache_State_MT, L2Cache_Event_L2_Replacement_clean);
  s_profiler.possibleTransition(L2Cache_State_MT, L2Cache_Event_L2_Replacement_XACT);
  s_profiler.possibleTransition(L2Cache_State_MT, L2Cache_Event_L2_Replacement_clean_XACT);
  s_profiler.possibleTransition(L2Cache_State_MT, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_MT, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_Unblock_Cancel);
  s_profiler.possibleTransition(L2Cache_State_M_SSB, L2Cache_Event_Unblock_Cancel);
  s_profiler.possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_Unblock_Cancel);
  s_profiler.possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_Unblock_Cancel);
  s_profiler.possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_Unblock_Cancel);
  s_profiler.possibleTransition(L2Cache_State_ISS_MB, L2Cache_Event_Unblock_Cancel);
  s_profiler.possibleTransition(L2Cache_State_IS_SSB, L2Cache_Event_Unblock_Cancel);
  s_profiler.possibleTransition(L2Cache_State_M_MB, L2Cache_Event_Unblock_Cancel);
  s_profiler.possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_Exclusive_Unblock);
  s_profiler.possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_SS_MB, L2Cache_Event_Exclusive_Unblock_WaitPUTold);
  s_profiler.possibleTransition(L2Cache_State_PB_MT, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_PB_MT, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_PB_MT, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_PB_MT, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_SS_SSB, L2Cache_Event_Unblock);
  s_profiler.possibleTransition(L2Cache_State_M_SSB, L2Cache_Event_Unblock);
  s_profiler.possibleTransition(L2Cache_State_IS_SSB, L2Cache_Event_Unblock);
  s_profiler.possibleTransition(L2Cache_State_M_MB, L2Cache_Event_Exclusive_Unblock);
  s_profiler.possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_Exclusive_Unblock);
  s_profiler.possibleTransition(L2Cache_State_ISS_MB, L2Cache_Event_Exclusive_Unblock);
  s_profiler.possibleTransition(L2Cache_State_M_MB, L2Cache_Event_Exclusive_Unblock_WaitPUTold);
  s_profiler.possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_Exclusive_Unblock_WaitPUTold);
  s_profiler.possibleTransition(L2Cache_State_ISS_MB, L2Cache_Event_Exclusive_Unblock_WaitPUTold);
  s_profiler.possibleTransition(L2Cache_State_M_MB, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_M_MB, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_ISS_MB, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_ISS_MB, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_M_MB, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_M_MB, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_MT_MB, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_ISS_MB, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_ISS_MB, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_Unblock);
  s_profiler.possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_WB_Data);
  s_profiler.possibleTransition(L2Cache_State_MT_IB, L2Cache_Event_WB_Data_clean);
  s_profiler.possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_Unblock_WaitPUTold);
  s_profiler.possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_WB_Data);
  s_profiler.possibleTransition(L2Cache_State_MT_IIB, L2Cache_Event_WB_Data_clean);
  s_profiler.possibleTransition(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_PB_MT_IB, L2Cache_Event_WB_Data);
  s_profiler.possibleTransition(L2Cache_State_PB_MT_IB, L2Cache_Event_WB_Data_clean);
  s_profiler.possibleTransition(L2Cache_State_PB_SS, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_PB_SS, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_PB_SS, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_PB_SS, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_Unblock);
  s_profiler.possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_Unblock_WaitPUTold);
  s_profiler.possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L1_PUTX_old);
  s_profiler.possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L1_PUTS_old);
  s_profiler.possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L1_PUTX);
  s_profiler.possibleTransition(L2Cache_State_MT_SB, L2Cache_Event_L1_PUTS);
  s_profiler.possibleTransition(L2Cache_State_I_I, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_I_I, L2Cache_Event_L1_UPGRADE);
  s_profiler.possibleTransition(L2Cache_State_I_I, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_I_I, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_I_I, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_I_I, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_I_I, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_S_I, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_S_I, L2Cache_Event_L1_UPGRADE);
  s_profiler.possibleTransition(L2Cache_State_S_I, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_S_I, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_S_I, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_S_I, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_S_I, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_MT_I, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_MT_I, L2Cache_Event_L1_UPGRADE);
  s_profiler.possibleTransition(L2Cache_State_MT_I, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_MT_I, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_MT_I, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_MT_I, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_MT_I, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_L1_UPGRADE);
  s_profiler.possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_M_I, L2Cache_Event_L1_GETX);
  s_profiler.possibleTransition(L2Cache_State_M_I, L2Cache_Event_L1_UPGRADE);
  s_profiler.possibleTransition(L2Cache_State_M_I, L2Cache_Event_L1_GETS);
  s_profiler.possibleTransition(L2Cache_State_M_I, L2Cache_Event_L1_GET_INSTR);
  s_profiler.possibleTransition(L2Cache_State_M_I, L2Cache_Event_L1_GETX_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_M_I, L2Cache_Event_L1_GETS_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_M_I, L2Cache_Event_L1_GET_INSTR_ESCAPE);
  s_profiler.possibleTransition(L2Cache_State_I_I, L2Cache_Event_Ack);
  s_profiler.possibleTransition(L2Cache_State_I_I, L2Cache_Event_Ack_all);
  s_profiler.possibleTransition(L2Cache_State_MT_I, L2Cache_Event_WB_Data);
  s_profiler.possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_WB_Data);
  s_profiler.possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_WB_Data_clean);
  s_profiler.possibleTransition(L2Cache_State_MT_I, L2Cache_Event_Ack_all);
  s_profiler.possibleTransition(L2Cache_State_MCT_I, L2Cache_Event_Ack_all);
  s_profiler.possibleTransition(L2Cache_State_MT_I, L2Cache_Event_WB_Data_clean);
  s_profiler.possibleTransition(L2Cache_State_S_I, L2Cache_Event_Ack);
  s_profiler.possibleTransition(L2Cache_State_S_I, L2Cache_Event_Ack_all);
  s_profiler.possibleTransition(L2Cache_State_M_I, L2Cache_Event_Mem_Ack);
}

void L2Cache_Controller::print(ostream& out) const { out << "[L2Cache_Controller " << m_chip_ptr->getID() << " " << m_version << "]"; }

// Actions

/** \brief fetch data from memory*/
void L2Cache_Controller::a_issueFetchToMemory(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      RequestMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
      (out_msg).m_Type = CoherenceRequestType_GETS;
      (out_msg).m_Requestor = m_machineID;
      (((out_msg).m_Destination).add((map_Address_to_Directory(addr))));
      (out_msg).m_MessageSize = MessageSizeType_Control;
      ((*(m_chip_ptr->m_L2Cache_DirRequestFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_REQUEST_LATENCY);
    }
  }
}

/** \brief Forward request to the exclusive L1*/
void L2Cache_Controller::b_forwardRequestToExclusive(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      RequestMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
      (out_msg).m_Type = ((*in_msg_ptr)).m_Type;
      (out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
      (((out_msg).m_Destination).add(((((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).lookup(addr))).m_Exclusive));
      (out_msg).m_MessageSize = MessageSizeType_Request_Control;
      (out_msg).m_Timestamp = ((*in_msg_ptr)).m_Timestamp;
      APPEND_TRANSITION_COMMENT((" "));
;
      APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_PhysicalAddress);
;
      ((*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_TAG_LATENCY);
    }
  }
}

/** \brief Send data to memory*/
void L2Cache_Controller::c_exclusiveReplacement(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg out_msg;
    (out_msg).m_Address = addr;
    (out_msg).m_Type = CoherenceResponseType_MEMORY_DATA;
    (out_msg).m_Sender = m_machineID;
    (((out_msg).m_Destination).add((map_Address_to_Directory(addr))));
    (out_msg).m_DataBlk = ((L2Cache_getL2CacheEntry(addr))).m_DataBlk;
    (out_msg).m_Dirty = ((L2Cache_getL2CacheEntry(addr))).m_Dirty;
    (out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_RESPONSE_LATENCY);
  }
}

/** \brief Send data to memory*/
void L2Cache_Controller::ct_exclusiveReplacementFromTBE(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg out_msg;
    (out_msg).m_Address = addr;
    (out_msg).m_Type = CoherenceResponseType_MEMORY_DATA;
    (out_msg).m_Sender = m_machineID;
    (((out_msg).m_Destination).add((map_Address_to_Directory(addr))));
    (out_msg).m_DataBlk = ((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_DataBlk;
    (out_msg).m_Dirty = ((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_Dirty;
    (out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_RESPONSE_LATENCY);
  }
}

/** \brief Broadcast a Write Filter lookup request*/
void L2Cache_Controller::a_checkL1WriteFiltersExceptRequestor(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      RequestMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
      (out_msg).m_Type = CoherenceRequestType_CHECK_WRITE_FILTER;
      (out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
      (out_msg).m_Destination = (getLocalL1IDs(m_machineID));
      (((out_msg).m_Destination).remove(((*in_msg_ptr)).m_Requestor));
      (out_msg).m_MessageSize = MessageSizeType_Response_Control;
      (out_msg).m_Timestamp = ((*in_msg_ptr)).m_Timestamp;
      APPEND_TRANSITION_COMMENT((" "));
;
      APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_PhysicalAddress);
;
      ((*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_TAG_LATENCY);
    }
  }
}

/** \brief Broadcast a Read + Write Filter lookup request*/
void L2Cache_Controller::a_checkL1ReadWriteFiltersExceptRequestor(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      RequestMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
      (out_msg).m_Type = CoherenceRequestType_CHECK_READ_WRITE_FILTER;
      (out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
      (out_msg).m_Destination = (getLocalL1IDs(m_machineID));
      (((out_msg).m_Destination).remove(((*in_msg_ptr)).m_Requestor));
      (out_msg).m_MessageSize = MessageSizeType_Response_Control;
      (out_msg).m_Timestamp = ((*in_msg_ptr)).m_Timestamp;
      APPEND_TRANSITION_COMMENT((" "));
;
      APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_PhysicalAddress);
;
      ((*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_TAG_LATENCY);
    }
  }
}

/** \brief Broadcast a Write Filter lookup request*/
void L2Cache_Controller::a_checkNackerL1WriteFiltersExceptRequestor(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    if ((((L2Cache_getL2CacheEntry(addr))).m_L2Miss == (true))) {
      if ((((L2Cache_isSharer(addr, ((*in_msg_ptr)).m_Requestor)) == (true)) && ((L2Cache_isOneSharerLeft(addr, ((*in_msg_ptr)).m_Requestor)) == (true)))) {
        APPEND_TRANSITION_COMMENT(("L2 Miss: No need to check L1 write filter "));
;
        APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
;
      } else {
        {
          RequestMsg out_msg;
          (out_msg).m_Address = addr;
          (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
          (out_msg).m_Type = CoherenceRequestType_CHECK_WRITE_FILTER;
          (out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
                    if (ASSERT_FLAG && !((((((L2Cache_getL2CacheEntry(addr))).m_Sharers).count()) > (0)))) {
            cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L2cache.sm:613, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

          }
;
          (out_msg).m_Destination = ((L2Cache_getL2CacheEntry(addr))).m_Sharers;
          (((out_msg).m_Destination).remove(((*in_msg_ptr)).m_Requestor));
          (out_msg).m_MessageSize = MessageSizeType_Response_Control;
          (out_msg).m_Timestamp = ((*in_msg_ptr)).m_Timestamp;
          APPEND_TRANSITION_COMMENT((" "));
;
          APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_PhysicalAddress);
;
          APPEND_TRANSITION_COMMENT((" requestor: "));
;
          APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
;
          APPEND_TRANSITION_COMMENT((" dest: "));
;
          APPEND_TRANSITION_COMMENT((out_msg).m_Destination);
;
          ((*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_TAG_LATENCY);
        }
      }
    } else {
      if (((((((L2Cache_getL2CacheEntry(addr))).m_Sharers).count()) == (0)) && (((L2Cache_getL2CacheEntry(addr))).m_Exclusive != ((*in_msg_ptr)).m_Requestor))) {
        {
          RequestMsg out_msg;
          (out_msg).m_Address = addr;
          (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
          (out_msg).m_Type = CoherenceRequestType_CHECK_WRITE_FILTER;
          (out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
          (((out_msg).m_Destination).add(((L2Cache_getL2CacheEntry(addr))).m_Exclusive));
          (out_msg).m_MessageSize = MessageSizeType_Response_Control;
          (out_msg).m_Timestamp = ((*in_msg_ptr)).m_Timestamp;
          APPEND_TRANSITION_COMMENT((" "));
;
          APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_PhysicalAddress);
;
          APPEND_TRANSITION_COMMENT((" requestor: "));
;
          APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
;
          APPEND_TRANSITION_COMMENT((" dest: "));
;
          APPEND_TRANSITION_COMMENT((out_msg).m_Destination);
;
          ((*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_TAG_LATENCY);
        }
      } else {
        APPEND_TRANSITION_COMMENT(("L1 replacement: No need to check L1 write filter"));
;
        APPEND_TRANSITION_COMMENT((" requestor: "));
;
        APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
;
        APPEND_TRANSITION_COMMENT((" exclusive: "));
;
        APPEND_TRANSITION_COMMENT(((L2Cache_getL2CacheEntry(addr))).m_Exclusive);
;
                if (ASSERT_FLAG && !((((((L2Cache_getL2CacheEntry(addr))).m_Sharers).count()) == (0)))) {
          cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L2cache.sm:658, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

        }
;
      }
    }
  }
}

/** \brief Broadcast a Read + Write Filter lookup request*/
void L2Cache_Controller::a_checkNackerL1ReadWriteFiltersExceptRequestor(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    if ((((L2Cache_getL2CacheEntry(addr))).m_L2Miss == (true))) {
      if ((((L2Cache_isSharer(addr, ((*in_msg_ptr)).m_Requestor)) == (true)) && ((L2Cache_isOneSharerLeft(addr, ((*in_msg_ptr)).m_Requestor)) == (true)))) {
        APPEND_TRANSITION_COMMENT(("L2 Miss: No need to check L1 read/write filter"));
;
        APPEND_TRANSITION_COMMENT((" requestor: "));
;
        APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
;
      } else {
        {
          RequestMsg out_msg;
          (out_msg).m_Address = addr;
          (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
          (out_msg).m_Type = CoherenceRequestType_CHECK_READ_WRITE_FILTER;
          (out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
                    if (ASSERT_FLAG && !((((((L2Cache_getL2CacheEntry(addr))).m_Sharers).count()) > (0)))) {
            cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L2cache.sm:682, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

          }
;
          (out_msg).m_Destination = ((L2Cache_getL2CacheEntry(addr))).m_Sharers;
          (((out_msg).m_Destination).remove(((*in_msg_ptr)).m_Requestor));
          (out_msg).m_MessageSize = MessageSizeType_Response_Control;
          (out_msg).m_Timestamp = ((*in_msg_ptr)).m_Timestamp;
          APPEND_TRANSITION_COMMENT((" "));
;
          APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_PhysicalAddress);
;
          APPEND_TRANSITION_COMMENT((" requestor: "));
;
          APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
;
          APPEND_TRANSITION_COMMENT((" dest: "));
;
          APPEND_TRANSITION_COMMENT((out_msg).m_Destination);
;
          ((*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_TAG_LATENCY);
        }
      }
    } else {
      if (((((((L2Cache_getL2CacheEntry(addr))).m_Sharers).count()) == (0)) && (((L2Cache_getL2CacheEntry(addr))).m_Exclusive != ((*in_msg_ptr)).m_Requestor))) {
        {
          RequestMsg out_msg;
          (out_msg).m_Address = addr;
          (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
          (out_msg).m_Type = CoherenceRequestType_CHECK_READ_WRITE_FILTER;
          (out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
          (((out_msg).m_Destination).add(((L2Cache_getL2CacheEntry(addr))).m_Exclusive));
          (out_msg).m_MessageSize = MessageSizeType_Response_Control;
          (out_msg).m_Timestamp = ((*in_msg_ptr)).m_Timestamp;
          APPEND_TRANSITION_COMMENT((" "));
;
          APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_PhysicalAddress);
;
          APPEND_TRANSITION_COMMENT((" requestor: "));
;
          APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
;
          APPEND_TRANSITION_COMMENT((" dest: "));
;
          APPEND_TRANSITION_COMMENT((out_msg).m_Destination);
;
          ((*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_TAG_LATENCY);
        }
      } else {
        if ((((((L2Cache_getL2CacheEntry(addr))).m_Sharers).count()) > (0))) {
                    if (ASSERT_FLAG && !((false))) {
            cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L2cache.sm:722, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

          }
;
          if ((((L2Cache_isSharer(addr, ((*in_msg_ptr)).m_Requestor)) == (true)) && ((L2Cache_isOneSharerLeft(addr, ((*in_msg_ptr)).m_Requestor)) == (true)))) {
            APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
;
            APPEND_TRANSITION_COMMENT((" L1 replacement: No need to check L1 read/write filter - we are only reader"));
;
          } else {
            {
              RequestMsg out_msg;
              (out_msg).m_Address = addr;
              (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
              (out_msg).m_Type = CoherenceRequestType_CHECK_READ_WRITE_FILTER;
              (out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
              (out_msg).m_Destination = ((L2Cache_getL2CacheEntry(addr))).m_Sharers;
              (((out_msg).m_Destination).remove(((*in_msg_ptr)).m_Requestor));
              (out_msg).m_MessageSize = MessageSizeType_Response_Control;
              (out_msg).m_Timestamp = ((*in_msg_ptr)).m_Timestamp;
              APPEND_TRANSITION_COMMENT((" "));
;
              APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_PhysicalAddress);
;
              APPEND_TRANSITION_COMMENT((" requestor: "));
;
              APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
;
              APPEND_TRANSITION_COMMENT((" dest: "));
;
              APPEND_TRANSITION_COMMENT((out_msg).m_Destination);
;
              ((*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_TAG_LATENCY);
            }
          }
        } else {
          APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
;
          APPEND_TRANSITION_COMMENT((" "));
;
          APPEND_TRANSITION_COMMENT(((L2Cache_getL2CacheEntry(addr))).m_Sharers);
;
          APPEND_TRANSITION_COMMENT((" "));
;
          APPEND_TRANSITION_COMMENT(((L2Cache_getL2CacheEntry(addr))).m_Exclusive);
;
          APPEND_TRANSITION_COMMENT((" L1 replacement: No need to check L1 read/write filter"));
;
        }
      }
    }
  }
}

/** \brief Send data from cache to reqeustor*/
void L2Cache_Controller::f_sendDataToGetSRequestor(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg out_msg;
    (out_msg).m_Address = addr;
    (out_msg).m_PhysicalAddress = ((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_PhysicalAddress;
    (out_msg).m_Type = CoherenceResponseType_L2_DATA;
    (out_msg).m_Sender = m_machineID;
    (out_msg).m_Destination = ((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_L1_GetS_IDs;
    (out_msg).m_DataBlk = ((L2Cache_getL2CacheEntry(addr))).m_DataBlk;
    (out_msg).m_Dirty = ((L2Cache_getL2CacheEntry(addr))).m_Dirty;
    (out_msg).m_MessageSize = MessageSizeType_Response_Data;
    (out_msg).m_AckCount = ((0) - ((numberOfL1CachePerChip()) - (1)));
    ((*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_RESPONSE_LATENCY);
  }
}

/** \brief Send data from cache to reqeustor*/
void L2Cache_Controller::f_sendExclusiveDataToGetSRequestor(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg out_msg;
    (out_msg).m_Address = addr;
    (out_msg).m_PhysicalAddress = ((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_PhysicalAddress;
    (out_msg).m_Type = CoherenceResponseType_L2_DATA_EXCLUSIVE;
    (out_msg).m_Sender = m_machineID;
    (out_msg).m_Destination = ((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_L1_GetS_IDs;
    (out_msg).m_DataBlk = ((L2Cache_getL2CacheEntry(addr))).m_DataBlk;
    (out_msg).m_Dirty = ((L2Cache_getL2CacheEntry(addr))).m_Dirty;
    (out_msg).m_MessageSize = MessageSizeType_Response_Data;
    (out_msg).m_AckCount = ((0) - ((numberOfL1CachePerChip()) - (1)));
    ((*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_RESPONSE_LATENCY);
  }
}

/** \brief Send data from cache to reqeustor*/
void L2Cache_Controller::f_sendDataToGetXRequestor(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg out_msg;
    (out_msg).m_Address = addr;
    (out_msg).m_PhysicalAddress = ((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_PhysicalAddress;
    (out_msg).m_Type = CoherenceResponseType_L2_DATA;
    (out_msg).m_Sender = m_machineID;
    (((out_msg).m_Destination).add(((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_L1_GetX_ID));
    (out_msg).m_DataBlk = ((L2Cache_getL2CacheEntry(addr))).m_DataBlk;
    (out_msg).m_Dirty = ((L2Cache_getL2CacheEntry(addr))).m_Dirty;
    (out_msg).m_MessageSize = MessageSizeType_Response_Data;
    (out_msg).m_AckCount = ((0) - ((numberOfL1CachePerChip()) - (1)));
    ((*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_RESPONSE_LATENCY);
  }
}

/** \brief Send data from cache to reqeustor*/
void L2Cache_Controller::f_sendDataToRequestor(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      ResponseMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
      (out_msg).m_Type = CoherenceResponseType_L2_DATA;
      (out_msg).m_Sender = m_machineID;
      (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
      (out_msg).m_DataBlk = ((L2Cache_getL2CacheEntry(addr))).m_DataBlk;
      (out_msg).m_Dirty = ((L2Cache_getL2CacheEntry(addr))).m_Dirty;
      (out_msg).m_MessageSize = MessageSizeType_Response_Data;
      if (((((*in_msg_ptr)).m_Type == CoherenceRequestType_GET_INSTR_ESCAPE) || (((*in_msg_ptr)).m_Type == CoherenceRequestType_GETX_ESCAPE))) {
        (out_msg).m_AckCount = (0);
      } else {
        if ((false)) {
          (out_msg).m_AckCount = ((0) - ((numberOfL1CachePerChip()) - (1)));
        } else {
          if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_GET_INSTR)) {
            if ((((L2Cache_getL2CacheEntry(addr))).m_L2Miss == (true))) {
              if ((((L2Cache_isSharer(addr, ((*in_msg_ptr)).m_Requestor)) == (true)) && ((L2Cache_isOneSharerLeft(addr, ((*in_msg_ptr)).m_Requestor)) == (true)))) {
                APPEND_TRANSITION_COMMENT(("We are only sharer"));
;
                (out_msg).m_AckCount = (0);
              } else {
                (out_msg).m_AckCount = ((0) - ((((L2Cache_getL2CacheEntry(addr))).m_Sharers).count()));
                if ((L2Cache_isSharer(addr, ((*in_msg_ptr)).m_Requestor))) {
                  (out_msg).m_AckCount = ((out_msg).m_AckCount + (1));
                }
                APPEND_TRANSITION_COMMENT(("Nackers exist"));
;
              }
            } else {
              if (((((((L2Cache_getL2CacheEntry(addr))).m_Sharers).count()) == (0)) && (((L2Cache_getL2CacheEntry(addr))).m_Exclusive != ((*in_msg_ptr)).m_Requestor))) {
                (out_msg).m_AckCount = ((0) - (1));
                APPEND_TRANSITION_COMMENT((" Writer exists "));
;
                APPEND_TRANSITION_COMMENT(((L2Cache_getL2CacheEntry(addr))).m_Exclusive);
;
              } else {
                                if (ASSERT_FLAG && !((((((L2Cache_getL2CacheEntry(addr))).m_Sharers).count()) == (0)))) {
                  cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L2cache.sm:869, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

                }
;
                                if (ASSERT_FLAG && !((((L2Cache_getL2CacheEntry(addr))).m_Exclusive == ((*in_msg_ptr)).m_Requestor))) {
                  cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L2cache.sm:870, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

                }
;
                APPEND_TRANSITION_COMMENT((" Sharers or we are writer exist, ok to read "));
;
                APPEND_TRANSITION_COMMENT((" sharers: "));
;
                APPEND_TRANSITION_COMMENT(((L2Cache_getL2CacheEntry(addr))).m_Sharers);
;
                APPEND_TRANSITION_COMMENT((" exclusive: "));
;
                APPEND_TRANSITION_COMMENT(((L2Cache_getL2CacheEntry(addr))).m_Exclusive);
;
                (out_msg).m_AckCount = (0);
              }
            }
          } else {
            if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_GETX)) {
              if ((((L2Cache_getL2CacheEntry(addr))).m_L2Miss == (true))) {
                if ((((L2Cache_isSharer(addr, ((*in_msg_ptr)).m_Requestor)) == (true)) && ((L2Cache_isOneSharerLeft(addr, ((*in_msg_ptr)).m_Requestor)) == (true)))) {
                  APPEND_TRANSITION_COMMENT((" L2Miss and we are only sharer "));
;
                  (out_msg).m_AckCount = (0);
                } else {
                  (out_msg).m_AckCount = ((0) - ((((L2Cache_getL2CacheEntry(addr))).m_Sharers).count()));
                  if ((L2Cache_isSharer(addr, ((*in_msg_ptr)).m_Requestor))) {
                    (out_msg).m_AckCount = ((out_msg).m_AckCount + (1));
                  }
                  APPEND_TRANSITION_COMMENT(("Nackers exist"));
;
                }
              } else {
                if (((((((L2Cache_getL2CacheEntry(addr))).m_Sharers).count()) == (0)) && (((L2Cache_getL2CacheEntry(addr))).m_Exclusive != ((*in_msg_ptr)).m_Requestor))) {
                  (out_msg).m_AckCount = ((0) - (1));
                  APPEND_TRANSITION_COMMENT((" Writer exists "));
;
                  APPEND_TRANSITION_COMMENT(((L2Cache_getL2CacheEntry(addr))).m_Exclusive);
;
                } else {
                  if ((((((L2Cache_getL2CacheEntry(addr))).m_Sharers).count()) > (0))) {
                                        if (ASSERT_FLAG && !((false))) {
                      cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L2cache.sm:911, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

                    }
;
                    if ((((L2Cache_isSharer(addr, ((*in_msg_ptr)).m_Requestor)) == (true)) && ((L2Cache_isOneSharerLeft(addr, ((*in_msg_ptr)).m_Requestor)) == (true)))) {
                      APPEND_TRANSITION_COMMENT((" L1 replacement: No need to check L1 read/write filter - we are only reader"));
;
                      (out_msg).m_AckCount = (0);
                    } else {
                      (out_msg).m_AckCount = ((0) - ((((L2Cache_getL2CacheEntry(addr))).m_Sharers).count()));
                      if ((L2Cache_isSharer(addr, ((*in_msg_ptr)).m_Requestor))) {
                        (out_msg).m_AckCount = ((out_msg).m_AckCount + (1));
                      }
                      APPEND_TRANSITION_COMMENT((" Readers exist "));
;
                      APPEND_TRANSITION_COMMENT(((L2Cache_getL2CacheEntry(addr))).m_Sharers);
;
                    }
                  } else {
                                        if (ASSERT_FLAG && !((((((L2Cache_getL2CacheEntry(addr))).m_Sharers).count()) == (0)))) {
                      cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L2cache.sm:931, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

                    }
;
                                        if (ASSERT_FLAG && !((((L2Cache_getL2CacheEntry(addr))).m_Exclusive == ((*in_msg_ptr)).m_Requestor))) {
                      cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L2cache.sm:932, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

                    }
;
                    (out_msg).m_AckCount = (0);
                    APPEND_TRANSITION_COMMENT((" sharers: "));
;
                    APPEND_TRANSITION_COMMENT(((L2Cache_getL2CacheEntry(addr))).m_Sharers);
;
                    APPEND_TRANSITION_COMMENT((" exclusive: "));
;
                    APPEND_TRANSITION_COMMENT(((L2Cache_getL2CacheEntry(addr))).m_Exclusive);
;
                    APPEND_TRANSITION_COMMENT((" L1 replacement: No need to check L1 read/write filter"));
;
                  }
                }
              }
            } else {
              APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Type);
;
              APPEND_TRANSITION_COMMENT((" "));
;
              APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
;
                            if (ASSERT_FLAG && !((false))) {
                cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L2cache.sm:949, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

              }
;
            }
          }
        }
      }
      APPEND_TRANSITION_COMMENT((" requestor: "));
;
      APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
;
      APPEND_TRANSITION_COMMENT((" AckCount: "));
;
      APPEND_TRANSITION_COMMENT((out_msg).m_AckCount);
;
      ((*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_RESPONSE_LATENCY);
    }
  }
}

/** \brief Send data from cache to reqeustor*/
void L2Cache_Controller::f_sendExclusiveDataToRequestor(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      ResponseMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
      (out_msg).m_Type = CoherenceResponseType_L2_DATA_EXCLUSIVE;
      (out_msg).m_Sender = m_machineID;
      (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
      (out_msg).m_DataBlk = ((L2Cache_getL2CacheEntry(addr))).m_DataBlk;
      (out_msg).m_Dirty = ((L2Cache_getL2CacheEntry(addr))).m_Dirty;
      (out_msg).m_MessageSize = MessageSizeType_Response_Data;
      if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_GETS_ESCAPE)) {
        (out_msg).m_AckCount = (0);
      } else {
        if ((false)) {
          (out_msg).m_AckCount = ((0) - ((numberOfL1CachePerChip()) - (1)));
        } else {
          if ((((L2Cache_getL2CacheEntry(addr))).m_L2Miss == (true))) {
            if ((((L2Cache_isSharer(addr, ((*in_msg_ptr)).m_Requestor)) == (true)) && ((L2Cache_isOneSharerLeft(addr, ((*in_msg_ptr)).m_Requestor)) == (true)))) {
              APPEND_TRANSITION_COMMENT(("We are only sharer"));
;
              (out_msg).m_AckCount = (0);
            } else {
              (out_msg).m_AckCount = ((0) - ((((L2Cache_getL2CacheEntry(addr))).m_Sharers).count()));
              if ((L2Cache_isSharer(addr, ((*in_msg_ptr)).m_Requestor))) {
                (out_msg).m_AckCount = ((out_msg).m_AckCount + (1));
              }
              APPEND_TRANSITION_COMMENT(("Nackers exist"));
;
            }
          } else {
            if (((((((L2Cache_getL2CacheEntry(addr))).m_Sharers).count()) == (0)) && (((L2Cache_getL2CacheEntry(addr))).m_Exclusive != ((*in_msg_ptr)).m_Requestor))) {
              (out_msg).m_AckCount = ((0) - (1));
              APPEND_TRANSITION_COMMENT((" Writer exists "));
;
              APPEND_TRANSITION_COMMENT(((L2Cache_getL2CacheEntry(addr))).m_Exclusive);
;
            } else {
              APPEND_TRANSITION_COMMENT(addr);
;
              APPEND_TRANSITION_COMMENT((" requestor: "));
;
              APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
;
              APPEND_TRANSITION_COMMENT((" sharers: "));
;
              APPEND_TRANSITION_COMMENT(((L2Cache_getL2CacheEntry(addr))).m_Sharers);
;
              DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L2cache.sm:1022: ", addr);
;
              DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L2cache.sm:1023: ", (" requestor: "));
;
              DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L2cache.sm:1024: ", ((*in_msg_ptr)).m_Requestor);
;
              DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L2cache.sm:1025: ", (" sharers: "));
;
              DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L2cache.sm:1026: ", ((L2Cache_getL2CacheEntry(addr))).m_Sharers);
;
                            if (ASSERT_FLAG && !((((((L2Cache_getL2CacheEntry(addr))).m_Sharers).count()) == (0)))) {
                cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L2cache.sm:1028, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

              }
;
                            if (ASSERT_FLAG && !((((L2Cache_getL2CacheEntry(addr))).m_Exclusive == ((*in_msg_ptr)).m_Requestor))) {
                cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L2cache.sm:1029, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

              }
;
              APPEND_TRANSITION_COMMENT((" Sharers exist or we are writer, ok to read "));
;
              (out_msg).m_AckCount = (0);
            }
          }
        }
      }
      APPEND_TRANSITION_COMMENT((" requestor: "));
;
      APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
;
      APPEND_TRANSITION_COMMENT((" AckCount: "));
;
      APPEND_TRANSITION_COMMENT((out_msg).m_AckCount);
;
      ((*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_RESPONSE_LATENCY);
    }
  }
}

/** \brief Send ACKs to requestor*/
void L2Cache_Controller::f_sendAccumulatedAckToRequestor(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  if ((((numberOfL1CachePerChip()) - (1)) > (0))) {
    {
      RequestMsg* in_msg_ptr;
      in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
      assert(in_msg_ptr != NULL);
      {
        ResponseMsg out_msg;
        (out_msg).m_Address = addr;
        (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
        (out_msg).m_Type = CoherenceResponseType_ACK;
        (out_msg).m_Sender = m_machineID;
        (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
        (out_msg).m_MessageSize = MessageSizeType_Response_Control;
        (out_msg).m_AckCount = ((numberOfL1CachePerChip()) - (1));
        APPEND_TRANSITION_COMMENT((" Total L1s: "));
;
        APPEND_TRANSITION_COMMENT((numberOfL1CachePerChip()));
;
        APPEND_TRANSITION_COMMENT((" Total ACKS: "));
;
        APPEND_TRANSITION_COMMENT((out_msg).m_AckCount);
;
        APPEND_TRANSITION_COMMENT((" "));
;
        APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_PhysicalAddress);
;
        ((*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version]))).enqueue(out_msg, 1);
      }
    }
  }
}

/** \brief invalidate sharers for request, requestor is sharer*/
void L2Cache_Controller::fwm_sendFwdInvEscapeToSharersMinusRequestor(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      RequestMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
      (out_msg).m_Type = CoherenceRequestType_INV_ESCAPE;
      (out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
      (out_msg).m_Destination = ((((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).lookup(addr))).m_Sharers;
      (((out_msg).m_Destination).remove(((*in_msg_ptr)).m_Requestor));
      (out_msg).m_MessageSize = MessageSizeType_Request_Control;
      (out_msg).m_Timestamp = ((*in_msg_ptr)).m_Timestamp;
      ((*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version]))).enqueue(out_msg, 1);
    }
  }
}

/** \brief Profiles the requestor*/
void L2Cache_Controller::f_profileRequestor(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    APPEND_TRANSITION_COMMENT((" requestor: "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
;
  }
}

/** \brief Mark an L2 block as transactional*/
void L2Cache_Controller::f_markBlockTransIfTrans(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<ResponseMsg*>(((*(m_chip_ptr->m_L2Cache_unblockToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    if ((((*in_msg_ptr)).m_Transactional == (true))) {
      ((((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).lookup(addr))).m_Trans = (true);
    }
  }
}

/** \brief profile the overflowed block*/
void L2Cache_Controller::q_profileOverflow(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (profileOverflow(addr, m_machineID));
}

/** \brief Profile request msg*/
void L2Cache_Controller::p_profileRequest(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    APPEND_TRANSITION_COMMENT((" request: Timestamp: "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Timestamp);
;
    APPEND_TRANSITION_COMMENT((" Requestor: "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
;
    APPEND_TRANSITION_COMMENT((" Dest: "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Destination);
;
    APPEND_TRANSITION_COMMENT((" PA: "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_PhysicalAddress);
;
    APPEND_TRANSITION_COMMENT((" Type: "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Type);
;
    APPEND_TRANSITION_COMMENT((" Mode: "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_AccessMode);
;
    APPEND_TRANSITION_COMMENT((" PF: "));
;
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Prefetch);
;
  }
}

/** \brief Send data from cache to reqeustor*/
void L2Cache_Controller::d_sendDataToRequestor(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      ResponseMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
      (out_msg).m_Type = CoherenceResponseType_L2_DATA;
      (out_msg).m_Sender = m_machineID;
      (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
      (out_msg).m_DataBlk = ((L2Cache_getL2CacheEntry(addr))).m_DataBlk;
      (out_msg).m_Dirty = ((L2Cache_getL2CacheEntry(addr))).m_Dirty;
      (out_msg).m_MessageSize = MessageSizeType_Response_Data;
      (out_msg).m_AckCount = ((0) - ((((L2Cache_getL2CacheEntry(addr))).m_Sharers).count()));
      if (((((L2Cache_getL2CacheEntry(addr))).m_Sharers).isElement(((*in_msg_ptr)).m_Requestor))) {
        (out_msg).m_AckCount = ((out_msg).m_AckCount + (1));
      }
      APPEND_TRANSITION_COMMENT((" AckCount: "));
;
      APPEND_TRANSITION_COMMENT((out_msg).m_AckCount);
;
      ((*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_RESPONSE_LATENCY);
    }
  }
}

/** \brief Send data from cache to reqeustor*/
void L2Cache_Controller::ds_sendSharedDataToRequestor(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      ResponseMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_Type = CoherenceResponseType_L2_DATA;
      (out_msg).m_Sender = m_machineID;
      (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
      (out_msg).m_DataBlk = ((L2Cache_getL2CacheEntry(addr))).m_DataBlk;
      (out_msg).m_Dirty = ((L2Cache_getL2CacheEntry(addr))).m_Dirty;
      (out_msg).m_MessageSize = MessageSizeType_Response_Data;
      (out_msg).m_AckCount = (0);
      ((*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_RESPONSE_LATENCY);
    }
  }
}

/** \brief invalidate sharers for L2 replacement*/
void L2Cache_Controller::f_sendInvToSharers(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg out_msg;
    (out_msg).m_Address = addr;
    (out_msg).m_Type = CoherenceRequestType_REPLACE;
    (out_msg).m_Requestor = m_machineID;
    (out_msg).m_Destination = ((((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).lookup(addr))).m_Sharers;
    (out_msg).m_MessageSize = MessageSizeType_Request_Control;
    ((*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_TAG_LATENCY);
  }
}

/** \brief invalidate sharers for request, requestor is sharer*/
void L2Cache_Controller::fwm_sendFwdInvToSharersMinusRequestor(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      RequestMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
      (out_msg).m_Type = CoherenceRequestType_INV;
      (out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
      (out_msg).m_Destination = ((((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).lookup(addr))).m_Sharers;
      (((out_msg).m_Destination).remove(((*in_msg_ptr)).m_Requestor));
      (out_msg).m_MessageSize = MessageSizeType_Request_Control;
      (out_msg).m_Timestamp = ((*in_msg_ptr)).m_Timestamp;
      APPEND_TRANSITION_COMMENT((" Sharers: "));
;
      APPEND_TRANSITION_COMMENT(((((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).lookup(addr))).m_Sharers);
;
      ((*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_TAG_LATENCY);
    }
  }
}

/** \brief Allocate TBE for internal/external request(isPrefetch=0, number of invalidates=0)*/
void L2Cache_Controller::i_allocateTBE(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).allocate(addr));
  ((((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_L1_GetS_IDs).clear());
  ((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_DataBlk = ((L2Cache_getL2CacheEntry(addr))).m_DataBlk;
  ((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_Dirty = ((L2Cache_getL2CacheEntry(addr))).m_Dirty;
  ((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_pendingAcks = ((((L2Cache_getL2CacheEntry(addr))).m_Sharers).count());
}

/** \brief Sets the physical address field of the TBE*/
void L2Cache_Controller::i_setTBEPhysicalAddress(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    ((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
  }
}

/** \brief Deallocate external TBE*/
void L2Cache_Controller::s_deallocateTBE(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).deallocate(addr));
}

/** \brief Pop incoming L1 request queue*/
void L2Cache_Controller::jj_popL1RequestQueue(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (profileMsgDelay((0), (((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).dequeue_getDelayCycles())));
}

/** \brief Pop incoming unblock queue*/
void L2Cache_Controller::k_popUnblockQueue(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (profileMsgDelay((0), (((*(m_chip_ptr->m_L2Cache_unblockToL2Cache_vec[m_version]))).dequeue_getDelayCycles())));
}

/** \brief Pop Incoming Response queue*/
void L2Cache_Controller::o_popIncomingResponseQueue(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (profileMsgDelay((3), (((*(m_chip_ptr->m_L2Cache_responseToL2Cache_vec[m_version]))).dequeue_getDelayCycles())));
}

/** \brief Write data from response queue to cache*/
void L2Cache_Controller::m_writeDataToCache(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<ResponseMsg*>(((*(m_chip_ptr->m_L2Cache_responseToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    ((L2Cache_getL2CacheEntry(addr))).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
    ((L2Cache_getL2CacheEntry(addr))).m_Dirty = ((*in_msg_ptr)).m_Dirty;
    ((L2Cache_getL2CacheEntry(addr))).m_L2Miss = (false);
  }
}

/** \brief Set the entry's L2 Miss bit*/
void L2Cache_Controller::m_markL2MissBit(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  ((L2Cache_getL2CacheEntry(addr))).m_L2Miss = (true);
}

/** \brief Copy the NACKers list into our sharers list*/
void L2Cache_Controller::m_copyNackersIntoSharers(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<ResponseMsg*>(((*(m_chip_ptr->m_L2Cache_unblockToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
        if (ASSERT_FLAG && !((((((*in_msg_ptr)).m_Nackers).count()) > (0)))) {
      cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L2cache.sm:1245, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

    }
;
    ((((L2Cache_getL2CacheEntry(addr))).m_Sharers).clear());
    if ((((L2Cache_getL2CacheEntry(addr))).m_L2Miss == (true))) {
      ((L2Cache_getL2CacheEntry(addr))).m_Sharers = ((*in_msg_ptr)).m_Nackers;
      APPEND_TRANSITION_COMMENT((" Unblocker: "));
;
      APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Sender);
;
      APPEND_TRANSITION_COMMENT((" Nackers: "));
;
      APPEND_TRANSITION_COMMENT(((L2Cache_getL2CacheEntry(addr))).m_Sharers);
;
    }
  }
}

/** \brief Write data from response queue to cache*/
void L2Cache_Controller::mr_writeDataToCacheFromRequest(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    ((L2Cache_getL2CacheEntry(addr))).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
    ((L2Cache_getL2CacheEntry(addr))).m_Dirty = ((*in_msg_ptr)).m_Dirty;
    ((L2Cache_getL2CacheEntry(addr))).m_L2Miss = (false);
  }
}

/** \brief update pending ack count*/
void L2Cache_Controller::q_updateAck(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<ResponseMsg*>(((*(m_chip_ptr->m_L2Cache_responseToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    ((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_pendingAcks = (((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_pendingAcks - ((*in_msg_ptr)).m_AckCount);
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_AckCount);
;
    APPEND_TRANSITION_COMMENT((" p: "));
;
    APPEND_TRANSITION_COMMENT(((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_pendingAcks);
;
  }
}

/** \brief update pending ack count*/
void L2Cache_Controller::q_updateNack(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<ResponseMsg*>(((*(m_chip_ptr->m_L2Cache_responseToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    ((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_nack = (true);
    ((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_pendingAcks = (((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_pendingAcks - ((*in_msg_ptr)).m_AckCount);
    APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_AckCount);
;
    APPEND_TRANSITION_COMMENT((" p: "));
;
    APPEND_TRANSITION_COMMENT(((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_pendingAcks);
;
  }
}

/** \brief Write data from response queue to TBE*/
void L2Cache_Controller::qq_writeDataToTBE(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<ResponseMsg*>(((*(m_chip_ptr->m_L2Cache_responseToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    ((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
    ((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_Dirty = ((*in_msg_ptr)).m_Dirty;
  }
}

/** \brief Stall*/
void L2Cache_Controller::z_stall(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
}

/** \brief Record L1 GetS for load response*/
void L2Cache_Controller::ss_recordGetSL1ID(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    ((((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_L1_GetS_IDs).add(((*in_msg_ptr)).m_Requestor));
  }
}

/** \brief Record L1 GetX for store response*/
void L2Cache_Controller::xx_recordGetXL1ID(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    ((((*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version]))).lookup(addr))).m_L1_GetX_ID = ((*in_msg_ptr)).m_Requestor;
  }
}

/** \brief set the MRU entry*/
void L2Cache_Controller::set_setMRU(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).setMRU(addr));
}

/** \brief Set L2 cache tag equal to tag of block B.*/
void L2Cache_Controller::qq_allocateL2CacheBlock(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  if (((((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).isTagPresent(addr)) == (false))) {
    (((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).allocate(addr));
  }
}

/** \brief Deallocate L2 cache block.  Sets the cache to not present, allowing a replacement in parallel with a fetch.*/
void L2Cache_Controller::rr_deallocateL2CacheBlock(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  (((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).deallocate(addr));
}

/** \brief Send writeback ACK*/
void L2Cache_Controller::t_sendWBAck(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      ResponseMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_Type = CoherenceResponseType_WB_ACK;
      (out_msg).m_Sender = m_machineID;
      (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
      (out_msg).m_MessageSize = MessageSizeType_Response_Control;
      ((*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_TAG_LATENCY);
    }
  }
}

/** \brief Send ACK to upgrader*/
void L2Cache_Controller::ts_sendInvAckToUpgrader(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      ResponseMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
      (out_msg).m_Type = CoherenceResponseType_ACK;
      (out_msg).m_Sender = m_machineID;
      (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
      (out_msg).m_MessageSize = MessageSizeType_Response_Control;
      (out_msg).m_AckCount = (((0) - ((((L2Cache_getL2CacheEntry(addr))).m_Sharers).count())) + (1));
      APPEND_TRANSITION_COMMENT((" "));
;
      APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_PhysicalAddress);
;
      ((*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_TAG_LATENCY);
    }
  }
}

/** \brief Send NACK to upgrader*/
void L2Cache_Controller::ts_sendInvNackToUpgrader(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    {
      ResponseMsg out_msg;
      (out_msg).m_Address = addr;
      (out_msg).m_Type = CoherenceResponseType_NACK;
      (out_msg).m_Sender = m_machineID;
      (((out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
      (out_msg).m_MessageSize = MessageSizeType_Response_Control;
      (out_msg).m_AckCount = (((0) - ((((L2Cache_getL2CacheEntry(addr))).m_Sharers).count())) + (1));
      ((*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version]))).enqueue(out_msg, L2_TAG_LATENCY);
    }
  }
}

/** \brief Profile the demand miss*/
void L2Cache_Controller::uu_profileMiss(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    (profile_L2Cache_miss((m_chip_ptr->convertToGenericType(((*in_msg_ptr)).m_Type)), ((*in_msg_ptr)).m_AccessMode, (MessageSizeTypeToInt(((*in_msg_ptr)).m_MessageSize)), ((*in_msg_ptr)).m_Prefetch, (L1CacheMachIDToProcessorNum(((*in_msg_ptr)).m_Requestor))));
  }
}

/** \brief Profile this transition at the L2 because Dir won't see the request*/
void L2Cache_Controller::ww_profileMissNoDir(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
  }
}

/** \brief Add L1 sharer to list*/
void L2Cache_Controller::nn_addSharer(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    (L2Cache_addSharer(addr, ((*in_msg_ptr)).m_Requestor));
    APPEND_TRANSITION_COMMENT(((L2Cache_getL2CacheEntry(addr))).m_Sharers);
;
  }
}

/** \brief Add L1 sharer to list*/
void L2Cache_Controller::nnu_addSharerFromUnblock(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<ResponseMsg*>(((*(m_chip_ptr->m_L2Cache_unblockToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    (L2Cache_addSharer(addr, ((*in_msg_ptr)).m_Sender));
    if ((((*in_msg_ptr)).m_RemoveLastOwnerFromDir == (true))) {
      APPEND_TRANSITION_COMMENT(("Last owner removed, it was "));
;
      APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_LastOwnerID);
;
      ((((((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).lookup(addr))).m_Sharers).remove(((*in_msg_ptr)).m_LastOwnerID));
            if (ASSERT_FLAG && !((((*in_msg_ptr)).m_LastOwnerID == ((((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).lookup(addr))).m_Exclusive))) {
        cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L2cache.sm:1399, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

      }
;
    }
  }
}

/** \brief Remove L1 Request sharer from list*/
void L2Cache_Controller::kk_removeRequestSharer(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    ((((((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).lookup(addr))).m_Sharers).remove(((*in_msg_ptr)).m_Requestor));
  }
}

/** \brief Remove all L1 sharers from list*/
void L2Cache_Controller::ll_clearSharers(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  ((((((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).lookup(addr))).m_Sharers).clear());
}

/** \brief set the exclusive owner*/
void L2Cache_Controller::mmu_markExclusiveFromUnblock(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    ResponseMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<ResponseMsg*>(((*(m_chip_ptr->m_L2Cache_unblockToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    if ((((*in_msg_ptr)).m_RemoveLastOwnerFromDir == (true))) {
      APPEND_TRANSITION_COMMENT((" Last owner removed, it was "));
;
      APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_LastOwnerID);
;
            if (ASSERT_FLAG && !((((*in_msg_ptr)).m_LastOwnerID == ((((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).lookup(addr))).m_Exclusive))) {
        cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L2cache.sm:1421, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

      }
;
    }
    ((((((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).lookup(addr))).m_Sharers).clear());
    ((((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).lookup(addr))).m_Exclusive = ((*in_msg_ptr)).m_Sender;
    (L2Cache_addSharer(addr, ((*in_msg_ptr)).m_Sender));
  }
}

/** \brief recycle L1 request queue*/
void L2Cache_Controller::zz_recycleL1RequestQueue(const Address& addr)
{
  DEBUG_MSG(GENERATED_COMP, HighPrio,"executing");
  {
    RequestMsg* in_msg_ptr;
    in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).peek());
    assert(in_msg_ptr != NULL);
    if (((((*in_msg_ptr)).m_Type == CoherenceRequestType_PUTX) || (((*in_msg_ptr)).m_Type == CoherenceRequestType_PUTS))) {
      if ((((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).isTagPresent(((*in_msg_ptr)).m_Address))) {
        ((L2Cache_getL2CacheEntry(((*in_msg_ptr)).m_Address))).m_L1PutsPending = (((L2Cache_getL2CacheEntry(((*in_msg_ptr)).m_Address))).m_L1PutsPending + (1));
        DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L2cache.sm:1434: ", ("RECYCLE PutSPending "));
;
        DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L2cache.sm:1435: ", ((L2Cache_getL2CacheEntry(((*in_msg_ptr)).m_Address))).m_L1PutsPending);
;
        DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L2cache.sm:1436: ", ((*in_msg_ptr)).m_Type);
;
        DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L2cache.sm:1437: ", ((*in_msg_ptr)).m_Requestor);
;
      }
    }
  }
  (((*(m_chip_ptr->m_L2Cache_L1RequestToL2Cache_vec[m_version]))).recycle());
}

