// Auto generated C++ code started by symbols/StateMachine.C:473
// L1Cache: MSI Directory L1 Cache CMP

#include "Global.h"
#include "L1Cache_Controller.h"
#include "L1Cache_State.h"
#include "L1Cache_Event.h"
#include "Types.h"
#include "System.h"
#include "Chip.h"

#define HASH_FUN(state, event)  ((int(state)*L1Cache_Event_NUM)+int(event))

#define GET_TRANSITION_COMMENT() (L1Cache_transitionComment.str())
#define CLEAR_TRANSITION_COMMENT() (L1Cache_transitionComment.str(""))

TransitionResult L1Cache_Controller::doTransition(L1Cache_Event event, L1Cache_State state, const Address& addr
)
{
  L1Cache_State next_state = state;

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
      g_system_ptr->getProfiler()->profileTransition("L1Cache", m_chip_ptr->getID(), m_version, addr, 
        L1Cache_State_to_string(state), 
        L1Cache_Event_to_string(event), 
        L1Cache_State_to_string(next_state), GET_TRANSITION_COMMENT());
    }
    CLEAR_TRANSITION_COMMENT();
    L1Cache_setState(addr, next_state);
    
  } else if (result == TransitionResult_ResourceStall) {
    if (PROTOCOL_DEBUG_TRACE) {
      g_system_ptr->getProfiler()->profileTransition("L1Cache", m_chip_ptr->getID(), m_version, addr, 
        L1Cache_State_to_string(state), 
        L1Cache_Event_to_string(event), 
        L1Cache_State_to_string(next_state), 
        "Resource Stall");
    }
  } else if (result == TransitionResult_ProtocolStall) {
    DEBUG_MSG(GENERATED_COMP,HighPrio,"stalling");
    DEBUG_NEWLINE(GENERATED_COMP, MedPrio);
    if (PROTOCOL_DEBUG_TRACE) {
      g_system_ptr->getProfiler()->profileTransition("L1Cache", m_chip_ptr->getID(), m_version, addr, 
        L1Cache_State_to_string(state), 
        L1Cache_Event_to_string(event), 
        L1Cache_State_to_string(next_state), 
        "Protocol Stall");
    }
  }
  return result;
}

TransitionResult L1Cache_Controller::doTransitionWorker(L1Cache_Event event, L1Cache_State state, L1Cache_State& next_state, const Address& addr
)
{

  switch(HASH_FUN(state, event)) {
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_TLoad):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_TStore):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_TLoad):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_TStore):
  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_TLoad):
  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_TStore):
  case HASH_FUN(L1Cache_State_M_I, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_M_I, L1Cache_Event_TLoad):
  case HASH_FUN(L1Cache_State_M_I, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_M_I, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_M_I, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_M_I, L1Cache_Event_TStore):
  case HASH_FUN(L1Cache_State_E_I, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_E_I, L1Cache_Event_TLoad):
  case HASH_FUN(L1Cache_State_E_I, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_E_I, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_E_I, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_E_I, L1Cache_Event_TStore):
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_TLoad):
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_TStore):
  {
    z_recycleMandatoryQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_NP, L1Cache_Event_L1_Replacement):
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_L1_Replacement):
  {
    ff_deallocateL1CacheBlock(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_NP, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Load):
  {
    next_state = L1Cache_State_IS;
    if (!(*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L1Cache_requestFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    oo_allocateL1DCacheBlock(addr);
    i_allocateTBE(addr);
    a_issueGETS(addr);
    k_popMandatoryQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_NP, L1Cache_Event_TLoad):
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_TLoad):
  {
    next_state = L1Cache_State_IS;
    if (!(*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L1Cache_requestFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    oo_allocateL1DCacheBlock(addr);
    i_allocateTBE(addr);
    s_setTBETrans(addr);
    a_issueGETS(addr);
    k_popMandatoryQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_NP, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Ifetch):
  {
    next_state = L1Cache_State_IS;
    if (!(*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L1Cache_requestFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    pp_allocateL1ICacheBlock(addr);
    i_allocateTBE(addr);
    ai_issueGETINSTR(addr);
    k_popMandatoryQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_NP, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Store):
  {
    next_state = L1Cache_State_IM;
    if (!(*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L1Cache_requestFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    oo_allocateL1DCacheBlock(addr);
    i_allocateTBE(addr);
    b_issueGETX(addr);
    k_popMandatoryQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_NP, L1Cache_Event_TStore):
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_TStore):
  {
    next_state = L1Cache_State_IM;
    if (!(*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L1Cache_requestFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    oo_allocateL1DCacheBlock(addr);
    i_allocateTBE(addr);
    s_setTBETrans(addr);
    s_setThreatBit(addr);
    b_issueGETX(addr);
    k_popMandatoryQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_NP, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_NP, L1Cache_Event_Fwd_GET_INSTR):
  case HASH_FUN(L1Cache_State_NP, L1Cache_Event_Fwd_TGETX):
  case HASH_FUN(L1Cache_State_NP, L1Cache_Event_Fwd_TGETS):
  case HASH_FUN(L1Cache_State_NP, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Fwd_GET_INSTR):
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Fwd_TGETX):
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Fwd_TGETS):
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Fwd_GET_INSTR):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Fwd_TGETX):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Fwd_TGETS):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Fwd_GET_INSTR):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Fwd_TGETX):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Fwd_TGETS):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_Fwd_GET_INSTR):
  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_Fwd_TGETX):
  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_Fwd_TGETS):
  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_NP, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_ITM, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_ITM, L1Cache_Event_Fwd_TGETS):
  case HASH_FUN(L1Cache_State_ITM, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_ITM, L1Cache_Event_Fwd_TGETX):
  case HASH_FUN(L1Cache_State_ITM, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_ITM, L1Cache_Event_Fwd_GET_INSTR):
  {
    if (!(*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    fi_sendInvAck(addr);
    l_popRequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Fwd_GET_INSTR):
  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Fwd_TGETS):
  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_E, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_TM, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_TM, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_TM, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_TM, L1Cache_Event_Fwd_GET_INSTR):
  {
    next_state = L1Cache_State_I;
    if (!(*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    fi_sendInvAck(addr);
    o_checkforTxAbort(addr);
    l_popRequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_S, L1Cache_Event_TLoad):
  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_E, L1Cache_Event_TLoad):
  case HASH_FUN(L1Cache_State_E, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_E, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_TLoad):
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Ifetch):
  {
    h_load_hit(addr);
    k_popMandatoryQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Store):
  {
    next_state = L1Cache_State_SM;
    if (!(*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L1Cache_requestFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    i_allocateTBE(addr);
    c_issueUPGRADE(addr);
    k_popMandatoryQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_S, L1Cache_Event_TStore):
  {
    next_state = L1Cache_State_ITM;
    if (!(*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L1Cache_requestFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    oo_allocateL1DCacheBlock(addr);
    i_allocateTBE(addr);
    s_setTBETrans(addr);
    s_setThreatBit(addr);
    b_issueGETX(addr);
    k_popMandatoryQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_S, L1Cache_Event_L1_Replacement):
  {
    next_state = L1Cache_State_I;
    ff_deallocateL1CacheBlock(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Fwd_TGETX):
  {
    next_state = L1Cache_State_I;
    if (!(*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    e_sendAckReadToRequestor(addr);
    o_checkForConflict(addr);
    l_popRequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_E, L1Cache_Event_Store):
  {
    next_state = L1Cache_State_M;
    hh_store_hit(addr);
    k_popMandatoryQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_E, L1Cache_Event_L1_Replacement):
  {
    next_state = L1Cache_State_M_I;
    if (!(*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L1Cache_requestFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    i_allocateTBE(addr);
    g_issuePUTX(addr);
    o_checkforTxAbort(addr);
    ff_deallocateL1CacheBlock(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_E, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_E, L1Cache_Event_Fwd_TGETX):
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Fwd_TGETX):
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Fwd_GETX):
  {
    next_state = L1Cache_State_I;
    if (!(*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version])).areNSlotsAvailable(2)) {
      return TransitionResult_ResourceStall;
    }
    d_sendDataToRequestor(addr);
    o_checkforTxAbort(addr);
    l_popRequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_E, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_E, L1Cache_Event_Fwd_TGETS):
  case HASH_FUN(L1Cache_State_E, L1Cache_Event_Fwd_GET_INSTR):
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Fwd_TGETS):
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Fwd_GET_INSTR):
  {
    next_state = L1Cache_State_S;
    if (!(*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version])).areNSlotsAvailable(2)) {
      return TransitionResult_ResourceStall;
    }
    d_sendDataToRequestor(addr);
    o_checkforTxAbort(addr);
    l_popRequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Store):
  {
    hh_store_hit(addr);
    k_popMandatoryQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_L1_Replacement):
  {
    next_state = L1Cache_State_M_I;
    if (!(*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    if (!(*(m_chip_ptr->m_L1Cache_requestFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    i_allocateTBE(addr);
    g_issuePUTX(addr);
    ff_deallocateL1CacheBlock(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_M_I, L1Cache_Event_WB_Ack):
  case HASH_FUN(L1Cache_State_E_I, L1Cache_Event_WB_Ack):
  {
    next_state = L1Cache_State_I;
    o_checkforTxAbort(addr);
    s_deallocateTBE(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Inv):
  {
    next_state = L1Cache_State_I;
    if (!(*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    f_sendDataToL2(addr);
    o_checkforTxAbort(addr);
    l_popRequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_M_I, L1Cache_Event_Inv):
  {
    next_state = L1Cache_State_I;
    if (!(*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    ft_sendDataToL2_fromTBE(addr);
    o_checkforTxAbort(addr);
    s_deallocateTBE(addr);
    l_popRequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_E_I, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_M_I, L1Cache_Event_Fwd_GETX):
  {
    next_state = L1Cache_State_I;
    if (!(*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version])).areNSlotsAvailable(2)) {
      return TransitionResult_ResourceStall;
    }
    dt_sendDataToRequestor_fromTBE(addr);
    o_checkforTxAbort(addr);
    s_deallocateTBE(addr);
    l_popRequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_E_I, L1Cache_Event_Fwd_TGETX):
  case HASH_FUN(L1Cache_State_M_I, L1Cache_Event_Fwd_TGETX):
  {
    next_state = L1Cache_State_I;
    if (!(*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version])).areNSlotsAvailable(2)) {
      return TransitionResult_ResourceStall;
    }
    dt_sendDataToRequestor_fromTBE(addr);
    o_checkForConflict(addr);
    s_deallocateTBE(addr);
    l_popRequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_M_I, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_M_I, L1Cache_Event_Fwd_GET_INSTR):
  case HASH_FUN(L1Cache_State_E_I, L1Cache_Event_Fwd_GETS):
  case HASH_FUN(L1Cache_State_E_I, L1Cache_Event_Fwd_GET_INSTR):
  {
    if (!(*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version])).areNSlotsAvailable(2)) {
      return TransitionResult_ResourceStall;
    }
    dt_sendDataToRequestor_fromTBE(addr);
    o_checkforTxAbort(addr);
    s_deallocateTBE(addr);
    l_popRequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_M_I, L1Cache_Event_Fwd_TGETS):
  case HASH_FUN(L1Cache_State_E_I, L1Cache_Event_Fwd_TGETS):
  {
    if (!(*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version])).areNSlotsAvailable(2)) {
      return TransitionResult_ResourceStall;
    }
    dt_sendDataToRequestor_fromTBE(addr);
    s_deallocateTBE(addr);
    l_popRequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Inv):
  {
    next_state = L1Cache_State_IS_I;
    if (!(*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    fi_sendInvAck(addr);
    l_popRequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Data_all_Acks):
  {
    next_state = L1Cache_State_S;
    if (!(*(m_chip_ptr->m_L1Cache_unblockFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    u_writeDataToL1Cache(addr);
    x_external_load_hit(addr);
    s_deallocateTBE(addr);
    j_sendUnblock(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_Data_all_Acks):
  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_Data_all_Acks_Threat):
  {
    next_state = L1Cache_State_I;
    if (!(*(m_chip_ptr->m_L1Cache_unblockFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    u_writeDataToL1Cache(addr);
    x_external_load_hit(addr);
    o_checkforTxAbort(addr);
    s_deallocateTBE(addr);
    j_sendUnblock(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Data_all_Acks_Threat):
  {
    next_state = L1Cache_State_I;
    if (!(*(m_chip_ptr->m_L1Cache_unblockFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    u_writeDataToL1Cache(addr);
    q_updateAckCount(addr);
    x_external_load_hit(addr);
    s_deallocateTBE(addr);
    j_sendUnblock(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_Data_Exclusive):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Data_Exclusive):
  {
    next_state = L1Cache_State_E;
    if (!(*(m_chip_ptr->m_L1Cache_unblockFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    u_writeDataToL1Cache(addr);
    x_external_load_hit(addr);
    jj_sendExclusiveUnblock(addr);
    s_deallocateTBE(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Data):
  {
    next_state = L1Cache_State_SM;
    u_writeDataToL1Cache(addr);
    q_updateAckCount(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Data):
  case HASH_FUN(L1Cache_State_IS_I, L1Cache_Event_Data):
  case HASH_FUN(L1Cache_State_ITM, L1Cache_Event_Data):
  {
    u_writeDataToL1Cache(addr);
    q_updateAckCount(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Data_Exclusive):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Data_all_Acks):
  {
    next_state = L1Cache_State_M;
    if (!(*(m_chip_ptr->m_L1Cache_unblockFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    u_writeDataToL1Cache(addr);
    xx_external_store_hit(addr);
    jj_sendExclusiveUnblock(addr);
    s_deallocateTBE(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_ITM, L1Cache_Event_Data_Exclusive):
  case HASH_FUN(L1Cache_State_ITM, L1Cache_Event_Data_all_Acks):
  case HASH_FUN(L1Cache_State_ITM, L1Cache_Event_Data_all_Acks_Threat):
  {
    next_state = L1Cache_State_TM;
    if (!(*(m_chip_ptr->m_L1Cache_unblockFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    u_writeDataToL1Cache(addr);
    xx_external_store_hit(addr);
    j_sendUnblockIM(addr);
    s_deallocateTBE(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Ack):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Ack):
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Ack):
  case HASH_FUN(L1Cache_State_ITM, L1Cache_Event_Ack):
  {
    q_updateAckCount(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Ack_all):
  {
    next_state = L1Cache_State_S;
    if (!(*(m_chip_ptr->m_L1Cache_unblockFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    q_updateAckCount(addr);
    j_sendUnblock(addr);
    xx_external_store_hit(addr);
    s_deallocateTBE(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Ack_all_Threat):
  {
    next_state = L1Cache_State_I;
    if (!(*(m_chip_ptr->m_L1Cache_unblockFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    q_updateAckCount(addr);
    j_sendUnblock(addr);
    xx_external_store_hit(addr);
    s_deallocateTBE(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_ITM, L1Cache_Event_Ack_all):
  case HASH_FUN(L1Cache_State_ITM, L1Cache_Event_Ack_all_Threat):
  {
    next_state = L1Cache_State_TM;
    if (!(*(m_chip_ptr->m_L1Cache_unblockFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    q_updateAckCount(addr);
    j_sendUnblockIM(addr);
    xx_external_store_hit(addr);
    s_deallocateTBE(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Ack_all):
  {
    next_state = L1Cache_State_M;
    if (!(*(m_chip_ptr->m_L1Cache_unblockFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    q_updateAckCount(addr);
    jj_sendExclusiveUnblock(addr);
    xx_external_store_hit(addr);
    s_deallocateTBE(addr);
    o_popIncomingResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Fwd_TGETX):
  {
    next_state = L1Cache_State_IM;
    if (!(*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    e_sendAckReadToRequestor(addr);
    l_popRequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_SM, L1Cache_Event_Fwd_GETX):
  {
    next_state = L1Cache_State_IM;
    if (!(*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    fi_sendInvAck(addr);
    o_checkforTxAbort(addr);
    l_popRequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_TM, L1Cache_Event_TLoad):
  {
    h_load_hit(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_TM, L1Cache_Event_TStore):
  {
    hh_store_hit(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_TM, L1Cache_Event_L1_Replacement):
  {
    next_state = L1Cache_State_I;
    o_checkforTxAbort(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_TM, L1Cache_Event_Fwd_TGETS):
  case HASH_FUN(L1Cache_State_TM, L1Cache_Event_Fwd_TGETX):
  {
    if (!(*(m_chip_ptr->m_L1Cache_responseFromL1Cache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    e_sendAckThreatToRequestor(addr);
    o_checkForConflict(addr);
    l_popRequestQueue(addr);
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
