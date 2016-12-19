// Auto generated C++ code started by symbols/StateMachine.C:473
// L1Cache: MI Example

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
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Replacement):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Replacement):
  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Replacement):
  case HASH_FUN(L1Cache_State_II, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_II, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_II, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_II, L1Cache_Event_Replacement):
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Fwd_GETX):
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Fwd_GETX):
  {
    return TransitionResult_ProtocolStall;
  }
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Store):
  {
    s_store_hit(addr);
    m_popMandatoryQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Ifetch):
  {
    r_load_hit(addr);
    m_popMandatoryQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Store):
  {
    next_state = L1Cache_State_IM;
    if (!(*(m_chip_ptr->m_L1Cache_requestFromCache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    v_allocateTBE(addr);
    i_allocateL1CacheBlock(addr);
    a_issueRequest(addr);
    m_popMandatoryQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Ifetch):
  {
    next_state = L1Cache_State_IS;
    if (!(*(m_chip_ptr->m_L1Cache_requestFromCache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    v_allocateTBE(addr);
    i_allocateL1CacheBlock(addr);
    a_issueRequest(addr);
    m_popMandatoryQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_IS, L1Cache_Event_Data):
  {
    next_state = L1Cache_State_M;
    u_writeDataToCache(addr);
    r_load_hit(addr);
    w_deallocateTBE(addr);
    n_popResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_IM, L1Cache_Event_Data):
  {
    next_state = L1Cache_State_M;
    u_writeDataToCache(addr);
    s_store_hit(addr);
    w_deallocateTBE(addr);
    n_popResponseQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Fwd_GETX):
  {
    next_state = L1Cache_State_I;
    if (!(*(m_chip_ptr->m_L1Cache_responseFromCache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    e_sendData(addr);
    o_popForwardedRequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Replacement):
  {
    h_deallocateL1CacheBlock(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Replacement):
  {
    next_state = L1Cache_State_MI;
    if (!(*(m_chip_ptr->m_L1Cache_requestFromCache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    v_allocateTBE(addr);
    b_issuePUT(addr);
    x_copyDataFromCacheToTBE(addr);
    h_deallocateL1CacheBlock(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Writeback_Ack):
  case HASH_FUN(L1Cache_State_II, L1Cache_Event_Writeback_Nack):
  {
    next_state = L1Cache_State_I;
    w_deallocateTBE(addr);
    o_popForwardedRequestQueue(addr);
    return TransitionResult_Valid;
  }
  case HASH_FUN(L1Cache_State_MI, L1Cache_Event_Fwd_GETX):
  {
    next_state = L1Cache_State_II;
    if (!(*(m_chip_ptr->m_L1Cache_responseFromCache_vec[m_version])).areNSlotsAvailable(1)) {
      return TransitionResult_ResourceStall;
    }
    ee_sendDataFromTBE(addr);
    o_popForwardedRequestQueue(addr);
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
