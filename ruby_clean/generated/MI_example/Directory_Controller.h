/** \file Directory.h
  * 
  * Auto generated C++ code started by symbols/StateMachine.C:252
  * Created by slicc definition of Module "Directory protocol"
  */

#ifndef Directory_CONTROLLER_H
#define Directory_CONTROLLER_H

#include "Global.h"
#include "Consumer.h"
#include "TransitionResult.h"
#include "Types.h"
#include "Directory_Profiler.h"

extern stringstream Directory_transitionComment;
class Directory_Controller : public Consumer {
#ifdef CHECK_COHERENCE
  friend class Chip;
#endif /* CHECK_COHERENCE */
public:
  Directory_Controller(Chip* chip_ptr, int version);
  void print(ostream& out) const;
  void wakeup();
  static void dumpStats(ostream& out) { s_profiler.dumpStats(out); }
  static void clearStats() { s_profiler.clearStats(); }
public:
  TransitionResult doTransition(Directory_Event event, Directory_State state, const Address& addr);  // in Directory_Transitions.C
  TransitionResult doTransitionWorker(Directory_Event event, Directory_State state, Directory_State& next_state, const Address& addr);  // in Directory_Transitions.C
  Chip* m_chip_ptr;
  NodeID m_id;
  NodeID m_version;
  MachineID m_machineID;
  static Directory_Profiler s_profiler;
  // Internal functions
  Directory_State Directory_getState(Address param_addr);
  void Directory_setState(Address param_addr, Directory_State param_state);
  // Actions
/** \brief Send writeback ack to requestor*/
  void a_sendWriteBackAck(const Address& addr);
/** \brief Send writeback nack to requestor*/
  void b_sendWriteBackNack(const Address& addr);
/** \brief Clear the owner field*/
  void c_clearOwner(const Address& addr);
/** \brief Send data to requestor*/
  void d_sendData(const Address& addr);
/** \brief The owner is now the requestor*/
  void e_ownerIsRequestor(const Address& addr);
/** \brief Forward request to owner*/
  void f_forwardRequest(const Address& addr);
/** \brief Pop incoming request queue*/
  void i_popIncomingRequestQueue(const Address& addr);
/** \brief Pop incoming unblock queue*/
  void j_popIncomingUnblockQueue(const Address& addr);
/** \brief Write PUTX/PUTO data to memory*/
  void l_writeDataToMemory(const Address& addr);
};
#endif // Directory_CONTROLLER_H
