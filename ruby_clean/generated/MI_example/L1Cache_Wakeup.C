// Auto generated C++ code started by symbols/StateMachine.C:425
// L1Cache: MI Example

#include "Global.h"
#include "RubySlicc_includes.h"
#include "L1Cache_Controller.h"
#include "L1Cache_State.h"
#include "L1Cache_Event.h"
#include "Types.h"
#include "System.h"
#include "Chip.h"

void L1Cache_Controller::wakeup()
{

int counter = 0;
  while (true) {
    // Some cases will put us into an infinite loop without this limit
    assert(counter <= RubyConfig::L1CacheTransitionsPerCycle());
    if (counter == RubyConfig::L1CacheTransitionsPerCycle()) {
      g_system_ptr->getProfiler()->controllerBusy(m_machineID); // Count how often we're fully utilized
      g_eventQueue_ptr->scheduleEvent(this, 1); // Wakeup in another cycle and try again
      break;
    }
    // L1CacheInPort forwardRequestNetwork_in
      if ((((*(m_chip_ptr->m_L1Cache_forwardToCache_vec[m_version]))).isReady())) {
        {
          RequestMsg* in_msg_ptr;
          in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L1Cache_forwardToCache_vec[m_version]))).peek());
          assert(in_msg_ptr != NULL);
          if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_GETX)) {
                        {
              Address addr = (makeDummyZero());
              TransitionResult result = doTransition(L1Cache_Event_Fwd_GETX, L1Cache_getState(addr), addr);
              if (result == TransitionResult_Valid) {
                counter++;
                continue; // Check the first port again
              }
              if (result == TransitionResult_ResourceStall) {
                g_eventQueue_ptr->scheduleEvent(this, 1);
                // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
              }
            }
;
          } else {
            if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_WB_ACK)) {
                            {
                Address addr = ((*in_msg_ptr)).m_Address;
                TransitionResult result = doTransition(L1Cache_Event_Writeback_Ack, L1Cache_getState(addr), addr);
                if (result == TransitionResult_Valid) {
                  counter++;
                  continue; // Check the first port again
                }
                if (result == TransitionResult_ResourceStall) {
                  g_eventQueue_ptr->scheduleEvent(this, 1);
                  // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                }
              }
;
            } else {
              if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_WB_NACK)) {
                                {
                  Address addr = ((*in_msg_ptr)).m_Address;
                  TransitionResult result = doTransition(L1Cache_Event_Writeback_Nack, L1Cache_getState(addr), addr);
                  if (result == TransitionResult_Valid) {
                    counter++;
                    continue; // Check the first port again
                  }
                  if (result == TransitionResult_ResourceStall) {
                    g_eventQueue_ptr->scheduleEvent(this, 1);
                    // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                  }
                }
;
              } else {
                                cerr << "Runtime Error at ../protocols/MI_example-cache.sm:142, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << ("Unexpected message") << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

;
              }
            }
          }
        }
      }

    // L1CacheInPort responseNetwork_in
      if ((((*(m_chip_ptr->m_L1Cache_responseToCache_vec[m_version]))).isReady())) {
        {
          ResponseMsg* in_msg_ptr;
          in_msg_ptr = dynamic_cast<ResponseMsg*>(((*(m_chip_ptr->m_L1Cache_responseToCache_vec[m_version]))).peek());
          assert(in_msg_ptr != NULL);
          if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_DATA)) {
                        {
              Address addr = ((*in_msg_ptr)).m_Address;
              TransitionResult result = doTransition(L1Cache_Event_Data, L1Cache_getState(addr), addr);
              if (result == TransitionResult_Valid) {
                counter++;
                continue; // Check the first port again
              }
              if (result == TransitionResult_ResourceStall) {
                g_eventQueue_ptr->scheduleEvent(this, 1);
                // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
              }
            }
;
          } else {
                        cerr << "Runtime Error at ../protocols/MI_example-cache.sm:155, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << ("Unexpected message") << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

;
          }
        }
      }

    // L1CacheInPort mandatoryQueue_in
      if ((((*(m_chip_ptr->m_L1Cache_mandatoryQueue_vec[m_version]))).isReady())) {
        {
          CacheMsg* in_msg_ptr;
          in_msg_ptr = dynamic_cast<CacheMsg*>(((*(m_chip_ptr->m_L1Cache_mandatoryQueue_vec[m_version]))).peek());
          assert(in_msg_ptr != NULL);
          if ((((((*(m_chip_ptr->m_L1Cache_cacheMemory_vec[m_version]))).isTagPresent(((*in_msg_ptr)).m_Address)) == (false)) && ((((*(m_chip_ptr->m_L1Cache_cacheMemory_vec[m_version]))).cacheAvail(((*in_msg_ptr)).m_Address)) == (false)))) {
            ((*in_msg_ptr)).m_Size = (5);
                        {
              Address addr = (((*(m_chip_ptr->m_L1Cache_cacheMemory_vec[m_version]))).cacheProbe(((*in_msg_ptr)).m_Address));
              TransitionResult result = doTransition(L1Cache_Event_Replacement, L1Cache_getState(addr), addr);
              if (result == TransitionResult_Valid) {
                counter++;
                continue; // Check the first port again
              }
              if (result == TransitionResult_ResourceStall) {
                g_eventQueue_ptr->scheduleEvent(this, 1);
                // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
              }
            }
;
          } else {
                        {
              Address addr = ((*in_msg_ptr)).m_Address;
              TransitionResult result = doTransition((L1Cache_mandatory_request_type_to_event(((*in_msg_ptr)).m_Type)), L1Cache_getState(addr), addr);
              if (result == TransitionResult_Valid) {
                counter++;
                continue; // Check the first port again
              }
              if (result == TransitionResult_ResourceStall) {
                g_eventQueue_ptr->scheduleEvent(this, 1);
                // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
              }
            }
;
          }
        }
      }

    break;  // If we got this far, we have nothing left todo
  }
}

