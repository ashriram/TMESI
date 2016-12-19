/** \file L1Cache.h
  * 
  * Auto generated C++ code started by symbols/StateMachine.C:252
  * Created by slicc definition of Module "MI Example"
  */

#ifndef L1Cache_CONTROLLER_H
#define L1Cache_CONTROLLER_H

#include "Global.h"
#include "Consumer.h"
#include "TransitionResult.h"
#include "Types.h"
#include "L1Cache_Profiler.h"

extern stringstream L1Cache_transitionComment;
class L1Cache_Controller : public Consumer {
#ifdef CHECK_COHERENCE
  friend class Chip;
#endif /* CHECK_COHERENCE */
public:
  L1Cache_Controller(Chip* chip_ptr, int version);
  void print(ostream& out) const;
  void wakeup();
  static void dumpStats(ostream& out) { s_profiler.dumpStats(out); }
  static void clearStats() { s_profiler.clearStats(); }
public:
  TransitionResult doTransition(L1Cache_Event event, L1Cache_State state, const Address& addr);  // in L1Cache_Transitions.C
  TransitionResult doTransitionWorker(L1Cache_Event event, L1Cache_State state, L1Cache_State& next_state, const Address& addr);  // in L1Cache_Transitions.C
  Chip* m_chip_ptr;
  NodeID m_id;
  NodeID m_version;
  MachineID m_machineID;
  static L1Cache_Profiler s_profiler;
  // Internal functions
  L1Cache_Event L1Cache_mandatory_request_type_to_event(CacheRequestType param_type);
  L1Cache_State L1Cache_getState(Address param_addr);
  void L1Cache_setState(Address param_addr, L1Cache_State param_state);
  // Actions
/** \brief Issue a request*/
  void a_issueRequest(const Address& addr);
/** \brief Issue a PUT request*/
  void b_issuePUT(const Address& addr);
/** \brief Send data from cache to requestor*/
  void e_sendData(const Address& addr);
/** \brief Send data from TBE to requestor*/
  void ee_sendDataFromTBE(const Address& addr);
/** \brief Allocate a cache block*/
  void i_allocateL1CacheBlock(const Address& addr);
/** \brief deallocate a cache block*/
  void h_deallocateL1CacheBlock(const Address& addr);
/** \brief Pop the mandatory request queue*/
  void m_popMandatoryQueue(const Address& addr);
/** \brief Pop the response queue*/
  void n_popResponseQueue(const Address& addr);
/** \brief Pop the forwarded request queue*/
  void o_popForwardedRequestQueue(const Address& addr);
/** \brief Notify sequencer the load completed.*/
  void r_load_hit(const Address& addr);
/** \brief Notify sequencer that store completed.*/
  void s_store_hit(const Address& addr);
/** \brief Write data to the cache*/
  void u_writeDataToCache(const Address& addr);
/** \brief Allocate TBE*/
  void v_allocateTBE(const Address& addr);
/** \brief Deallocate TBE*/
  void w_deallocateTBE(const Address& addr);
/** \brief Copy data from cache to TBE*/
  void x_copyDataFromCacheToTBE(const Address& addr);
/** \brief stall*/
  void z_stall(const Address& addr);
};
#endif // L1Cache_CONTROLLER_H
