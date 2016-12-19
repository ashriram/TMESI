// Auto generated C++ code started by symbols/StateMachine.C:473
// L2Cache: MESI Directory L2 Cache CMP

#include "Global.h"
#include "L2Cache_Controller.h"
#include "L2Cache_State.h"
#include "L2Cache_Event.h"
#include "Types.h"
#include "System.h"
#include "Chip.h"

#define HASH_FUN(state, event)  ((int(state)*L2Cache_Event_NUM)+int(event))

#define GET_TRANSITION_COMMENT() (L2Cache_transitionComment.str())
#define CLEAR_TRANSITION_COMMENT() (L2Cache_transitionComment.str(""))

TransitionResult L2Cache_Controller::doTransition(L2Cache_Event event, L2Cache_State state, const Address& addr
)
{
  L2Cache_State next_state = state;

  DEBUG_NEWLINE(GENERATED_COMP, MedPrio);
  DEBUG_MSG(GENERATED_COMP, MedPrio,*this);
  DEBUG_EXPR(GENERATED_COMP, MedPrio,g_eventQueue_ptr->getTime());
  DEBUG_EXPR(GENERATED_COMP, MedPrio,state);
  DEBUG_EXPR(GENERATED_COMP, MedPrio,event);
  DEBUG_EXPR(GENERATED_COMP, MedPrio,addr);

  TransitionResult result = doTransitionWorker(event, state, next_state, addr);

  if (result == TransitionResult_Valid) {
    DEBUG_EXPR(GENERATED_COMP, MedPrio, next_state);
    DEBUG_NEWLINE(GENERATED_COMP, MedPrio);
    s_profiler.countTransition(state, event);
    if (PROTOCOL_DEBUG_TRACE) {
      g_system_ptr->getProfiler()->profileTransition("L2Cache", m_chip_ptr->getID(), m_version, addr, 
        L2Cache_State_to_string(state), 
        L2Cache_Event_to_string(event), 
        L2Cache_State_to_string(next_state), GET_TRANSITION_COMMENT());
    }
    CLEAR_TRANSITION_COMMENT();
    L2Cache_setState(addr, next_state);
    
  } else if (result == TransitionResult_ResourceStall) {
    if (PROTOCOL_DEBUG_TRACE) {
      g_system_ptr->getProfiler()->profileTransition("L2Cache", m_chip_ptr->getID(), m_version, addr, 
        L2Cache_State_to_string(state), 
        L2Cache_Event_to_string(event), 
        L2Cache_State_to_string(next_state), 
        "Resource Stall");
    }
  } else if (result == TransitionResult_ProtocolStall) {
    DEBUG_MSG(GENERATED_COMP,HighPrio,"stalling");
    DEBUG_NEWLINE(GENERATED_COMP, MedPrio);
    if (PROTOCOL_DEBUG_TRACE) {
      g_system_ptr->getProfiler()->profileTransition("L2Cache", m_chip_ptr->getID(), m_version, addr, 
        L2Cache_State_to_string(state), 
        L2Cache_Event_to_string(event), 
        L2Cache_State_to_string(next_state), 
        "Protocol Stall");
    }
  }
  return result;
}

TransitionResult L2Cache_Controller::doTransitionWorker(L2Cache_Event event, L2Cache_State state, L2Cache_State& next_state, const Address& addr
)
{

  switch(HASH_FUN(state, event)) {
  case HASH_FUN(L2Cache_State_PB_MT, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_PB_MT, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_PB_MT, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_PB_MT, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_PB_MT, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_PB_MT, L2Cache_Event_L1_GETX_ESCAPE):
  case HASH_FUN(L2Cache_State_PB_MT, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  case HASH_FUN(L2Cache_State_PB_MT, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_PB_MT, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_PB_MT, L2Cache_Event_L2_Replacement_XACT):
  case HASH_FUN(L2Cache_State_PB_MT, L2Cache_Event_L2_Replacement_clean_XACT):
  case HASH_FUN(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_GETX_ESCAPE):
  case HASH_FUN(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  case HASH_FUN(L2Cache_State_PB_MT_IB, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_PB_MT_IB, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_PB_MT_IB, L2Cache_Event_L2_Replacement_XACT):
  case HASH_FUN(L2Cache_State_PB_MT_IB, L2Cache_Event_L2_Replacement_clean_XACT):
  case HASH_FUN(L2Cache_State_PB_SS, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_PB_SS, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_PB_SS, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_PB_SS, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_PB_SS, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_PB_SS, L2Cache_Event_L1_GETX_ESCAPE):
  case HASH_FUN(L2Cache_State_PB_SS, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  case HASH_FUN(L2Cache_State_PB_SS, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_PB_SS, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_PB_SS, L2Cache_Event_L2_Replacement_XACT):
  case HASH_FUN(L2Cache_State_PB_SS, L2Cache_Event_L2_Replacement_clean_XACT):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L1_GETX_ESCAPE):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  case HASH_FUN(L2Cache_State_M_MB, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_M_MB, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_M_MB, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_M_MB, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_M_MB, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_M_MB, L2Cache_Event_L1_GETX_ESCAPE):
  case HASH_FUN(L2Cache_State_M_MB, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  case HASH_FUN(L2Cache_State_ISS_MB, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_ISS_MB, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_ISS_MB, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_ISS_MB, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_ISS_MB, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_ISS_MB, L2Cache_Event_L1_GETX_ESCAPE):
  case HASH_FUN(L2Cache_State_ISS_MB, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  case HASH_FUN(L2Cache_State_IS_SSB, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IS_SSB, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_IS_SSB, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IS_SSB, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_IS_SSB, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_IS_SSB, L2Cache_Event_L1_GETX_ESCAPE):
  case HASH_FUN(L2Cache_State_IS_SSB, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L1_GETX_ESCAPE):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L1_GETX_ESCAPE):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L1_GETX_ESCAPE):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L1_GETX_ESCAPE):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  case HASH_FUN(L2Cache_State_M_SSB, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_M_SSB, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_M_SSB, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_M_SSB, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_M_SSB, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_M_SSB, L2Cache_Event_L1_GETX_ESCAPE):
  case HASH_FUN(L2Cache_State_M_SSB, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  case HASH_FUN(L2Cache_State_SS_SSB, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_SS_SSB, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_SS_SSB, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_SS_SSB, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_SS_SSB, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_SS_SSB, L2Cache_Event_L1_GETX_ESCAPE):
  case HASH_FUN(L2Cache_State_SS_SSB, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_M_I, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_M_I, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_SS_SSB, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_SS_SSB, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_IS_SSB, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_IS_SSB, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_M_SSB, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_M_SSB, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_PUT_PENDING):
  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L1_PUT_PENDING):
  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L1_PUT_PENDING):
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_L1_GETX_ESCAPE):
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_L1_GETX_ESCAPE):
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_L1_GETX_ESCAPE):
  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L1_PUTS_old):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_PB_MT, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_PB_MT, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_M_MB, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_M_MB, L2Cache_Event_L1_PUTS_old):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L1_PUTS_old):
  case HASH_FUN(L2Cache_State_ISS_MB, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_ISS_MB, L2Cache_Event_L1_PUTS_old):
  case HASH_FUN(L2Cache_State_M_MB, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_M_MB, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_ISS_MB, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_ISS_MB, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L1_PUTS_old):
  case HASH_FUN(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_PB_SS, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_PB_SS, L2Cache_Event_L1_PUTS):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L1_PUTS_old):
  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_L1_GETX_ESCAPE):
  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_L1_GETX_ESCAPE):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_L1_GETX_ESCAPE):
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_L1_GETX_ESCAPE):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  case HASH_FUN(L2Cache_State_M_I, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_M_I, L2Cache_Event_L1_UPGRADE):
  case HASH_FUN(L2Cache_State_M_I, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_M_I, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_M_I, L2Cache_Event_L1_GETX_ESCAPE):
  case HASH_FUN(L2Cache_State_M_I, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_M_I, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  {
    f_profileRequestor(addr);
    zz_recycleL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_L2_Replacement_XACT):
  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_L2_Replacement_clean_XACT):
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_L2_Replacement_XACT):
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_L2_Replacement_clean_XACT):
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_L2_Replacement_XACT):
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_L2_Replacement_clean_XACT):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L2_Replacement_XACT):
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_L2_Replacement_clean_XACT):
  case HASH_FUN(L2Cache_State_M_MB, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_M_MB, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_M_MB, L2Cache_Event_L2_Replacement_XACT):
  case HASH_FUN(L2Cache_State_M_MB, L2Cache_Event_L2_Replacement_clean_XACT):
  case HASH_FUN(L2Cache_State_ISS_MB, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_ISS_MB, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_ISS_MB, L2Cache_Event_L2_Replacement_XACT):
  case HASH_FUN(L2Cache_State_ISS_MB, L2Cache_Event_L2_Replacement_clean_XACT):
  case HASH_FUN(L2Cache_State_IS_SSB, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_IS_SSB, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_IS_SSB, L2Cache_Event_L2_Replacement_XACT):
  case HASH_FUN(L2Cache_State_IS_SSB, L2Cache_Event_L2_Replacement_clean_XACT):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L2_Replacement_XACT):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_L2_Replacement_clean_XACT):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L2_Replacement_XACT):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_L2_Replacement_clean_XACT):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L2_Replacement_XACT):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L2_Replacement_clean_XACT):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L2_Replacement_XACT):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L2_Replacement_clean_XACT):
  case HASH_FUN(L2Cache_State_M_SSB, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_M_SSB, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_M_SSB, L2Cache_Event_L2_Replacement_XACT):
  case HASH_FUN(L2Cache_State_M_SSB, L2Cache_Event_L2_Replacement_clean_XACT):
  case HASH_FUN(L2Cache_State_SS_SSB, L2Cache_Event_L2_Replacement):
  case HASH_FUN(L2Cache_State_SS_SSB, L2Cache_Event_L2_Replacement_clean):
  case HASH_FUN(L2Cache_State_SS_SSB, L2Cache_Event_L2_Replacement_XACT):
  case HASH_FUN(L2Cache_State_SS_SSB, L2Cache_Event_L2_Replacement_clean_XACT):
  {
    zz_recycleL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_L1_PUTS_old):
  case HASH_FUN(L2Cache_State_M_I, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_M_I, L2Cache_Event_L1_PUTS_old):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_L1_PUTS_old):
  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_L1_PUTS_old):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_L1_PUTS_old):
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_L1_PUTS_old):
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_L1_PUTS_old):
  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_L1_PUTS_old):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_PUTS_old):
  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L1_PUTS_old):
  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L1_PUTS_old):
  case HASH_FUN(L2Cache_State_IS_SSB, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_IS_SSB, L2Cache_Event_L1_PUTS_old):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_L1_PUTS_old):
  case HASH_FUN(L2Cache_State_M_SSB, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_M_SSB, L2Cache_Event_L1_PUTS_old):
  case HASH_FUN(L2Cache_State_SS_SSB, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_SS_SSB, L2Cache_Event_L1_PUTS_old):
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_L1_PUTS_old):
  {
    f_profileRequestor(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_L1_GETS):
  {
    next_state = L2Cache_State_ISS;
    if (!(*(m_chip_ptr->m_L2Cache_DirRequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    p_profileRequest(addr);
    f_profileRequestor(addr);
    qq_allocateL2CacheBlock(addr);
    ll_clearSharers(addr);
    i_allocateTBE(addr);
    i_setTBEPhysicalAddress(addr);
    ss_recordGetSL1ID(addr);
    a_issueFetchToMemory(addr);
    a_checkL1ReadWriteFiltersExceptRequestor(addr);
    uu_profileMiss(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_L1_GETS_ESCAPE):
  {
    next_state = L2Cache_State_ISS;
    if (!(*(m_chip_ptr->m_L2Cache_DirRequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    p_profileRequest(addr);
    f_profileRequestor(addr);
    qq_allocateL2CacheBlock(addr);
    ll_clearSharers(addr);
    i_allocateTBE(addr);
    i_setTBEPhysicalAddress(addr);
    ss_recordGetSL1ID(addr);
    a_issueFetchToMemory(addr);
    f_sendAccumulatedAckToRequestor(addr);
    uu_profileMiss(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_L1_GET_INSTR):
  {
    next_state = L2Cache_State_IS;
    if (!(*(m_chip_ptr->m_L2Cache_DirRequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    p_profileRequest(addr);
    f_profileRequestor(addr);
    qq_allocateL2CacheBlock(addr);
    ll_clearSharers(addr);
    nn_addSharer(addr);
    i_allocateTBE(addr);
    i_setTBEPhysicalAddress(addr);
    ss_recordGetSL1ID(addr);
    a_issueFetchToMemory(addr);
    a_checkL1ReadWriteFiltersExceptRequestor(addr);
    uu_profileMiss(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  {
    next_state = L2Cache_State_IS;
    if (!(*(m_chip_ptr->m_L2Cache_DirRequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    p_profileRequest(addr);
    f_profileRequestor(addr);
    qq_allocateL2CacheBlock(addr);
    ll_clearSharers(addr);
    nn_addSharer(addr);
    i_allocateTBE(addr);
    i_setTBEPhysicalAddress(addr);
    ss_recordGetSL1ID(addr);
    a_issueFetchToMemory(addr);
    f_sendAccumulatedAckToRequestor(addr);
    uu_profileMiss(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_L1_GETX):
  {
    next_state = L2Cache_State_IM;
    if (!(*(m_chip_ptr->m_L2Cache_DirRequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    p_profileRequest(addr);
    f_profileRequestor(addr);
    qq_allocateL2CacheBlock(addr);
    ll_clearSharers(addr);
    i_allocateTBE(addr);
    i_setTBEPhysicalAddress(addr);
    xx_recordGetXL1ID(addr);
    a_issueFetchToMemory(addr);
    a_checkL1ReadWriteFiltersExceptRequestor(addr);
    uu_profileMiss(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_NP, L2Cache_Event_L1_GETX_ESCAPE):
  {
    next_state = L2Cache_State_IM;
    if (!(*(m_chip_ptr->m_L2Cache_DirRequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    p_profileRequest(addr);
    f_profileRequestor(addr);
    qq_allocateL2CacheBlock(addr);
    ll_clearSharers(addr);
    i_allocateTBE(addr);
    i_setTBEPhysicalAddress(addr);
    xx_recordGetXL1ID(addr);
    a_issueFetchToMemory(addr);
    f_sendAccumulatedAckToRequestor(addr);
    uu_profileMiss(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_ISS, L2Cache_Event_Mem_Data):
  {
    next_state = L2Cache_State_ISS_MB;
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    m_writeDataToCache(addr);
    m_markL2MissBit(addr);
    f_sendExclusiveDataToGetSRequestor(addr);
    s_deallocateTBE(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_IS, L2Cache_Event_Mem_Data):
  {
    next_state = L2Cache_State_IS_SSB;
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    m_writeDataToCache(addr);
    m_markL2MissBit(addr);
    f_sendDataToGetSRequestor(addr);
    s_deallocateTBE(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_IM, L2Cache_Event_Mem_Data):
  {
    next_state = L2Cache_State_ISS_MB;
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    m_writeDataToCache(addr);
    m_markL2MissBit(addr);
    f_sendDataToGetXRequestor(addr);
    s_deallocateTBE(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  {
    next_state = L2Cache_State_SS_SSB;
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    p_profileRequest(addr);
    f_profileRequestor(addr);
    ds_sendSharedDataToRequestor(addr);
    nn_addSharer(addr);
    uu_profileMiss(addr);
    set_setMRU(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_GETX):
  {
    next_state = L2Cache_State_SS_MB;
    if (!(*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    p_profileRequest(addr);
    f_profileRequestor(addr);
    d_sendDataToRequestor(addr);
    fwm_sendFwdInvToSharersMinusRequestor(addr);
    uu_profileMiss(addr);
    set_setMRU(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_GETX_ESCAPE):
  {
    next_state = L2Cache_State_SS_MB;
    if (!(*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    p_profileRequest(addr);
    f_profileRequestor(addr);
    d_sendDataToRequestor(addr);
    fwm_sendFwdInvEscapeToSharersMinusRequestor(addr);
    uu_profileMiss(addr);
    set_setMRU(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L1_UPGRADE):
  {
    next_state = L2Cache_State_SS_MB;
    if (!(*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    f_profileRequestor(addr);
    fwm_sendFwdInvToSharersMinusRequestor(addr);
    ts_sendInvAckToUpgrader(addr);
    uu_profileMiss(addr);
    set_setMRU(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L2_Replacement_clean):
  {
    next_state = L2Cache_State_I_I;
    if (!(*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    i_allocateTBE(addr);
    f_sendInvToSharers(addr);
    rr_deallocateL2CacheBlock(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L2_Replacement_clean_XACT):
  {
    next_state = L2Cache_State_I_I;
    if (!(*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    q_profileOverflow(addr);
    i_allocateTBE(addr);
    f_sendInvToSharers(addr);
    rr_deallocateL2CacheBlock(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L2_Replacement):
  {
    next_state = L2Cache_State_S_I;
    if (!(*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    i_allocateTBE(addr);
    f_sendInvToSharers(addr);
    rr_deallocateL2CacheBlock(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_SS, L2Cache_Event_L2_Replacement_XACT):
  {
    next_state = L2Cache_State_S_I;
    if (!(*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    q_profileOverflow(addr);
    i_allocateTBE(addr);
    f_sendInvToSharers(addr);
    rr_deallocateL2CacheBlock(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L1_GETS):
  {
    next_state = L2Cache_State_M_MB;
    if (!(*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version])).areNSlotsAvailable(3)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    p_profileRequest(addr);
    f_profileRequestor(addr);
    f_sendExclusiveDataToRequestor(addr);
    a_checkNackerL1ReadWriteFiltersExceptRequestor(addr);
    uu_profileMiss(addr);
    set_setMRU(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L1_GETS_ESCAPE):
  {
    next_state = L2Cache_State_M_MB;
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    p_profileRequest(addr);
    f_profileRequestor(addr);
    f_sendExclusiveDataToRequestor(addr);
    uu_profileMiss(addr);
    set_setMRU(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L1_GET_INSTR):
  {
    next_state = L2Cache_State_M_SSB;
    if (!(*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version])).areNSlotsAvailable(3)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    p_profileRequest(addr);
    f_profileRequestor(addr);
    f_sendDataToRequestor(addr);
    a_checkNackerL1ReadWriteFiltersExceptRequestor(addr);
    nn_addSharer(addr);
    uu_profileMiss(addr);
    set_setMRU(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  {
    next_state = L2Cache_State_M_SSB;
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    p_profileRequest(addr);
    f_profileRequestor(addr);
    f_sendDataToRequestor(addr);
    nn_addSharer(addr);
    uu_profileMiss(addr);
    set_setMRU(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L1_GETX):
  {
    next_state = L2Cache_State_M_MB;
    if (!(*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version])).areNSlotsAvailable(3)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    p_profileRequest(addr);
    f_profileRequestor(addr);
    f_sendDataToRequestor(addr);
    a_checkNackerL1ReadWriteFiltersExceptRequestor(addr);
    uu_profileMiss(addr);
    set_setMRU(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L1_GETX_ESCAPE):
  {
    next_state = L2Cache_State_M_MB;
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    p_profileRequest(addr);
    f_profileRequestor(addr);
    f_sendDataToRequestor(addr);
    uu_profileMiss(addr);
    set_setMRU(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L2_Replacement):
  {
    next_state = L2Cache_State_M_I;
    if (!(*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    i_allocateTBE(addr);
    c_exclusiveReplacement(addr);
    rr_deallocateL2CacheBlock(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L2_Replacement_clean):
  {
    next_state = L2Cache_State_M_I;
    rr_deallocateL2CacheBlock(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L2_Replacement_XACT):
  {
    next_state = L2Cache_State_M_I;
    if (!(*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    q_profileOverflow(addr);
    i_allocateTBE(addr);
    c_exclusiveReplacement(addr);
    rr_deallocateL2CacheBlock(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_M, L2Cache_Event_L2_Replacement_clean_XACT):
  {
    next_state = L2Cache_State_M_I;
    q_profileOverflow(addr);
    rr_deallocateL2CacheBlock(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L1_GETX):
  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L1_GETX_ESCAPE):
  {
    next_state = L2Cache_State_MT_MB;
    if (!(*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    p_profileRequest(addr);
    f_profileRequestor(addr);
    b_forwardRequestToExclusive(addr);
    uu_profileMiss(addr);
    set_setMRU(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L1_GETS):
  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L1_GET_INSTR):
  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L1_GETS_ESCAPE):
  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L1_GET_INSTR_ESCAPE):
  {
    next_state = L2Cache_State_MT_IIB;
    if (!(*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    p_profileRequest(addr);
    f_profileRequestor(addr);
    b_forwardRequestToExclusive(addr);
    uu_profileMiss(addr);
    set_setMRU(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L2_Replacement):
  {
    next_state = L2Cache_State_MT_I;
    if (!(*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    i_allocateTBE(addr);
    f_sendInvToSharers(addr);
    rr_deallocateL2CacheBlock(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L2_Replacement_clean):
  {
    next_state = L2Cache_State_MCT_I;
    if (!(*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    i_allocateTBE(addr);
    f_sendInvToSharers(addr);
    rr_deallocateL2CacheBlock(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L2_Replacement_XACT):
  {
    next_state = L2Cache_State_MT_I;
    if (!(*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    q_profileOverflow(addr);
    i_allocateTBE(addr);
    f_sendInvToSharers(addr);
    rr_deallocateL2CacheBlock(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L2_Replacement_clean_XACT):
  {
    next_state = L2Cache_State_MCT_I;
    if (!(*(m_chip_ptr->m_L2Cache_L1RequestFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L2Cache_L2_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    q_profileOverflow(addr);
    i_allocateTBE(addr);
    f_sendInvToSharers(addr);
    rr_deallocateL2CacheBlock(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L1_PUTX):
  {
    next_state = L2Cache_State_M;
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    f_profileRequestor(addr);
    ll_clearSharers(addr);
    mr_writeDataToCacheFromRequest(addr);
    t_sendWBAck(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_MT, L2Cache_Event_L1_PUTS):
  {
    next_state = L2Cache_State_SS;
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    f_profileRequestor(addr);
    ll_clearSharers(addr);
    nn_addSharer(addr);
    mr_writeDataToCacheFromRequest(addr);
    t_sendWBAck(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_Unblock_Cancel):
  {
    next_state = L2Cache_State_SS;
    k_popUnblockQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_M_SSB, L2Cache_Event_Unblock_Cancel):
  {
    next_state = L2Cache_State_M;
    ll_clearSharers(addr);
    m_copyNackersIntoSharers(addr);
    k_popUnblockQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_Unblock_Cancel):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_Unblock_Cancel):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_Unblock_Cancel):
  {
    next_state = L2Cache_State_MT;
    k_popUnblockQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_ISS_MB, L2Cache_Event_Unblock_Cancel):
  case HASH_FUN(L2Cache_State_IS_SSB, L2Cache_Event_Unblock_Cancel):
  case HASH_FUN(L2Cache_State_M_MB, L2Cache_Event_Unblock_Cancel):
  {
    next_state = L2Cache_State_M;
    m_copyNackersIntoSharers(addr);
    k_popUnblockQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_Exclusive_Unblock):
  case HASH_FUN(L2Cache_State_M_MB, L2Cache_Event_Exclusive_Unblock):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_Exclusive_Unblock):
  case HASH_FUN(L2Cache_State_ISS_MB, L2Cache_Event_Exclusive_Unblock):
  {
    next_state = L2Cache_State_MT;
    mmu_markExclusiveFromUnblock(addr);
    f_markBlockTransIfTrans(addr);
    k_popUnblockQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_SS_MB, L2Cache_Event_Exclusive_Unblock_WaitPUTold):
  case HASH_FUN(L2Cache_State_M_MB, L2Cache_Event_Exclusive_Unblock_WaitPUTold):
  case HASH_FUN(L2Cache_State_MT_MB, L2Cache_Event_Exclusive_Unblock_WaitPUTold):
  case HASH_FUN(L2Cache_State_ISS_MB, L2Cache_Event_Exclusive_Unblock_WaitPUTold):
  {
    next_state = L2Cache_State_PB_MT;
    mmu_markExclusiveFromUnblock(addr);
    f_markBlockTransIfTrans(addr);
    k_popUnblockQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_PB_MT, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_PB_MT, L2Cache_Event_L1_PUTS_old):
  {
    next_state = L2Cache_State_MT;
    f_profileRequestor(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_SS_SSB, L2Cache_Event_Unblock):
  case HASH_FUN(L2Cache_State_M_SSB, L2Cache_Event_Unblock):
  case HASH_FUN(L2Cache_State_IS_SSB, L2Cache_Event_Unblock):
  {
    next_state = L2Cache_State_SS;
    f_markBlockTransIfTrans(addr);
    k_popUnblockQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_Unblock):
  {
    next_state = L2Cache_State_MT_IB;
    nnu_addSharerFromUnblock(addr);
    f_markBlockTransIfTrans(addr);
    k_popUnblockQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_WB_Data):
  case HASH_FUN(L2Cache_State_MT_IB, L2Cache_Event_WB_Data_clean):
  {
    next_state = L2Cache_State_SS;
    m_writeDataToCache(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_Unblock_WaitPUTold):
  {
    next_state = L2Cache_State_PB_MT_IB;
    nnu_addSharerFromUnblock(addr);
    f_markBlockTransIfTrans(addr);
    k_popUnblockQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_WB_Data):
  case HASH_FUN(L2Cache_State_MT_IIB, L2Cache_Event_WB_Data_clean):
  {
    next_state = L2Cache_State_MT_SB;
    m_writeDataToCache(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_PB_MT_IB, L2Cache_Event_L1_PUTS_old):
  {
    next_state = L2Cache_State_MT_IB;
    f_profileRequestor(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_PB_MT_IB, L2Cache_Event_WB_Data):
  case HASH_FUN(L2Cache_State_PB_MT_IB, L2Cache_Event_WB_Data_clean):
  {
    next_state = L2Cache_State_PB_SS;
    m_writeDataToCache(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_PB_SS, L2Cache_Event_L1_PUTX_old):
  case HASH_FUN(L2Cache_State_PB_SS, L2Cache_Event_L1_PUTS_old):
  {
    next_state = L2Cache_State_SS;
    f_profileRequestor(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_Unblock):
  {
    next_state = L2Cache_State_SS;
    nnu_addSharerFromUnblock(addr);
    f_markBlockTransIfTrans(addr);
    k_popUnblockQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_Unblock_WaitPUTold):
  {
    next_state = L2Cache_State_PB_SS;
    nnu_addSharerFromUnblock(addr);
    f_markBlockTransIfTrans(addr);
    k_popUnblockQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L1_PUTX):
  case HASH_FUN(L2Cache_State_MT_SB, L2Cache_Event_L1_PUTS):
  {
    kk_removeRequestSharer(addr);
    f_profileRequestor(addr);
    jj_popL1RequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_Ack):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_Ack):
  {
    q_updateAck(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_I_I, L2Cache_Event_Ack_all):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_WB_Data_clean):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_Ack_all):
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_WB_Data_clean):
  case HASH_FUN(L2Cache_State_M_I, L2Cache_Event_Mem_Ack):
  {
    next_state = L2Cache_State_NP;
    s_deallocateTBE(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_WB_Data):
  case HASH_FUN(L2Cache_State_MCT_I, L2Cache_Event_WB_Data):
  {
    next_state = L2Cache_State_M_I;
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    qq_writeDataToTBE(addr);
    ct_exclusiveReplacementFromTBE(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L2Cache_State_MT_I, L2Cache_Event_Ack_all):
  case HASH_FUN(L2Cache_State_S_I, L2Cache_Event_Ack_all):
  {
    next_state = L2Cache_State_M_I;
    if (!(*(m_chip_ptr->m_L2Cache_responseFromL2Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    ct_exclusiveReplacementFromTBE(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  default:
    WARN_EXPR(m_id);
    WARN_EXPR(m_version);
    WARN_EXPR(g_eventQueue_ptr->getTime());
    WARN_EXPR(addr);
    WARN_EXPR(event);
    WARN_EXPR(state);
    ERROR_MSG("Invalid transition");
  }
  return TransitionResult_Valid;
}
