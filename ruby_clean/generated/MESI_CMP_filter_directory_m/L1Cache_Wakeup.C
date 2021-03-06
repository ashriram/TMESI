// Auto generated C++ code started by symbols/StateMachine.C:425
// L1Cache: MESI Directory L1 Cache CMP

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
    // L1CacheInPort triggerQueue_in
      if ((((*(m_chip_ptr->m_L1Cache_triggerQueue_vec[m_version]))).isReady())) {
        {
          TriggerMsg* in_msg_ptr;
          in_msg_ptr = dynamic_cast<TriggerMsg*>(((*(m_chip_ptr->m_L1Cache_triggerQueue_vec[m_version]))).peek());
          assert(in_msg_ptr != NULL);
          if ((((*in_msg_ptr)).m_Type == TriggerType_ALL_ACKS)) {
            if ((((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(((*in_msg_ptr)).m_Address))).m_nack == (true))) {
                            {
                Address addr = ((*in_msg_ptr)).m_Address;
                TransitionResult result = doTransition(L1Cache_Event_Nack_all, L1Cache_getState(addr), addr);
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
                TransitionResult result = doTransition(L1Cache_Event_Ack_all, L1Cache_getState(addr), addr);
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
          } else {
                        cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L1cache.sm:359, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << ("Unexpected message") << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

;
          }
        }
      }

    // L1CacheInPort responseIntraChipL1Network_in
      if ((((*(m_chip_ptr->m_L1Cache_responseToL1Cache_vec[m_version]))).isReady())) {
        {
          ResponseMsg* in_msg_ptr;
          in_msg_ptr = dynamic_cast<ResponseMsg*>(((*(m_chip_ptr->m_L1Cache_responseToL1Cache_vec[m_version]))).peek());
          assert(in_msg_ptr != NULL);
                    if (ASSERT_FLAG && !(((((*in_msg_ptr)).m_Destination).isElement(m_machineID)))) {
            cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L1cache.sm:369, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

          }
;
          if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_L2_DATA_EXCLUSIVE)) {
            if ((((*in_msg_ptr)).m_AckCount == (0))) {
                            {
                Address addr = ((*in_msg_ptr)).m_Address;
                TransitionResult result = doTransition(L1Cache_Event_L2_Exclusive_Data_all_Acks, L1Cache_getState(addr), addr);
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
                TransitionResult result = doTransition(L1Cache_Event_L2_Exclusive_Data, L1Cache_getState(addr), addr);
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
          } else {
            if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_L2_DATA)) {
              if ((((*in_msg_ptr)).m_AckCount == (0))) {
                                {
                  Address addr = ((*in_msg_ptr)).m_Address;
                  TransitionResult result = doTransition(L1Cache_Event_L2_Data_all_Acks, L1Cache_getState(addr), addr);
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
                  TransitionResult result = doTransition(L1Cache_Event_L2_Data, L1Cache_getState(addr), addr);
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
            } else {
              if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_DATA)) {
                if (((((L1Cache_getState(((*in_msg_ptr)).m_Address)) == L1Cache_State_IS) || ((L1Cache_getState(((*in_msg_ptr)).m_Address)) == L1Cache_State_IS_I)) && ((machineIDToMachineType(((*in_msg_ptr)).m_Sender)) == MachineType_L1Cache))) {
                                    {
                    Address addr = ((*in_msg_ptr)).m_Address;
                    TransitionResult result = doTransition(L1Cache_Event_DataS_fromL1, L1Cache_getState(addr), addr);
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
                  if (((((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(((*in_msg_ptr)).m_Address))).m_pendingAcks - ((*in_msg_ptr)).m_AckCount) == (0))) {
                                        {
                      Address addr = ((*in_msg_ptr)).m_Address;
                      TransitionResult result = doTransition(L1Cache_Event_Data_all_Acks, L1Cache_getState(addr), addr);
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
              } else {
                if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_ACK)) {
                                    {
                    Address addr = ((*in_msg_ptr)).m_Address;
                    TransitionResult result = doTransition(L1Cache_Event_Ack, L1Cache_getState(addr), addr);
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
                  if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_NACK)) {
                                        {
                      Address addr = ((*in_msg_ptr)).m_Address;
                      TransitionResult result = doTransition(L1Cache_Event_Nack, L1Cache_getState(addr), addr);
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
                    if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_WB_ACK)) {
                                            {
                        Address addr = ((*in_msg_ptr)).m_Address;
                        TransitionResult result = doTransition(L1Cache_Event_WB_Ack, L1Cache_getState(addr), addr);
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
                                            cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L1cache.sm:399, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << ("Invalid L1 response type") << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

;
                    }
                  }
                }
              }
            }
          }
        }
      }

    // L1CacheInPort requestIntraChipL1Network_in
      if ((((*(m_chip_ptr->m_L1Cache_requestToL1Cache_vec[m_version]))).isReady())) {
        {
          RequestMsg* in_msg_ptr;
          in_msg_ptr = dynamic_cast<RequestMsg*>(((*(m_chip_ptr->m_L1Cache_requestToL1Cache_vec[m_version]))).peek());
          assert(in_msg_ptr != NULL);
                    if (ASSERT_FLAG && !(((((*in_msg_ptr)).m_Destination).isElement(m_machineID)))) {
            cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L1cache.sm:409, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

          }
;
          if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_INV)) {
            if (((L1Cache_shouldNackStore(((*in_msg_ptr)).m_PhysicalAddress, ((*in_msg_ptr)).m_Timestamp, ((*in_msg_ptr)).m_Requestor)) == (false))) {
                            {
                Address addr = ((*in_msg_ptr)).m_Address;
                TransitionResult result = doTransition(L1Cache_Event_Inv, L1Cache_getState(addr), addr);
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
                TransitionResult result = doTransition(L1Cache_Event_Inv_X, L1Cache_getState(addr), addr);
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
          } else {
            if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_INV_ESCAPE)) {
                            {
                Address addr = ((*in_msg_ptr)).m_Address;
                TransitionResult result = doTransition(L1Cache_Event_Inv, L1Cache_getState(addr), addr);
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
              if (((((*in_msg_ptr)).m_Type == CoherenceRequestType_GETX) || (((*in_msg_ptr)).m_Type == CoherenceRequestType_UPGRADE))) {
                if (((L1Cache_shouldNackStore(((*in_msg_ptr)).m_PhysicalAddress, ((*in_msg_ptr)).m_Timestamp, ((*in_msg_ptr)).m_Requestor)) == (true))) {
                                    {
                    Address addr = ((*in_msg_ptr)).m_Address;
                    TransitionResult result = doTransition(L1Cache_Event_Fwd_GETX_X, L1Cache_getState(addr), addr);
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
                }
              } else {
                if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_GETX_ESCAPE)) {
                                    {
                    Address addr = ((*in_msg_ptr)).m_Address;
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
                  if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_GETS)) {
                    if (((L1Cache_shouldNackLoad(((*in_msg_ptr)).m_PhysicalAddress, ((*in_msg_ptr)).m_Timestamp, ((*in_msg_ptr)).m_Requestor)) == (true))) {
                                            {
                        Address addr = ((*in_msg_ptr)).m_Address;
                        TransitionResult result = doTransition(L1Cache_Event_Fwd_GETS_X, L1Cache_getState(addr), addr);
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
                        TransitionResult result = doTransition(L1Cache_Event_Fwd_GETS, L1Cache_getState(addr), addr);
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
                  } else {
                    if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_GETS_ESCAPE)) {
                                            {
                        Address addr = ((*in_msg_ptr)).m_Address;
                        TransitionResult result = doTransition(L1Cache_Event_Fwd_GETS, L1Cache_getState(addr), addr);
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
                      if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_GET_INSTR)) {
                        if (((L1Cache_shouldNackLoad(((*in_msg_ptr)).m_PhysicalAddress, ((*in_msg_ptr)).m_Timestamp, ((*in_msg_ptr)).m_Requestor)) == (true))) {
                                                    {
                            Address addr = ((*in_msg_ptr)).m_Address;
                            TransitionResult result = doTransition(L1Cache_Event_Fwd_GET_INSTR_X, L1Cache_getState(addr), addr);
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
                            TransitionResult result = doTransition(L1Cache_Event_Fwd_GET_INSTR, L1Cache_getState(addr), addr);
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
                      } else {
                        if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_GET_INSTR_ESCAPE)) {
                                                    {
                            Address addr = ((*in_msg_ptr)).m_Address;
                            TransitionResult result = doTransition(L1Cache_Event_Fwd_GET_INSTR, L1Cache_getState(addr), addr);
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
                          if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_REPLACE)) {
                                                        {
                              Address addr = ((*in_msg_ptr)).m_Address;
                              TransitionResult result = doTransition(L1Cache_Event_Replace, L1Cache_getState(addr), addr);
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
                            if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_CHECK_WRITE_FILTER)) {
                                                            {
                                Address addr = ((*in_msg_ptr)).m_Address;
                                TransitionResult result = doTransition(L1Cache_Event_Check_Write_Filter, L1Cache_getState(addr), addr);
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
                              if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_CHECK_READ_WRITE_FILTER)) {
                                                                {
                                  Address addr = ((*in_msg_ptr)).m_Address;
                                  TransitionResult result = doTransition(L1Cache_Event_Check_Read_Write_Filter, L1Cache_getState(addr), addr);
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
                                                                cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L1cache.sm:465, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << ("Invalid forwarded request type") << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }

    // L1CacheInPort mandatoryQueue_in
      if ((((*(m_chip_ptr->m_L1Cache_mandatoryQueue_vec[m_version]))).isReady())) {
        {
          CacheMsg* in_msg_ptr;
          in_msg_ptr = dynamic_cast<CacheMsg*>(((*(m_chip_ptr->m_L1Cache_mandatoryQueue_vec[m_version]))).peek());
          assert(in_msg_ptr != NULL);
          if ((((*in_msg_ptr)).m_Type == CacheRequestType_IFETCH)) {
            if ((((*(m_chip_ptr->m_L1Cache_L1DcacheMemory_vec[m_version]))).isTagPresent(((*in_msg_ptr)).m_Address))) {
              if (((L1Cache_checkReadWriteSignatures(((*in_msg_ptr)).m_Address)) == (true))) {
                                {
                  Address addr = ((*in_msg_ptr)).m_Address;
                  TransitionResult result = doTransition(L1Cache_Event_L1_Replacement_XACT, L1Cache_getState(addr), addr);
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
                  TransitionResult result = doTransition(L1Cache_Event_L1_Replacement, L1Cache_getState(addr), addr);
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
            if ((((*(m_chip_ptr->m_L1Cache_L1IcacheMemory_vec[m_version]))).isTagPresent(((*in_msg_ptr)).m_Address))) {
              (L1Cache_printRequest((*in_msg_ptr)));
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
            } else {
              if ((((*(m_chip_ptr->m_L1Cache_L1IcacheMemory_vec[m_version]))).cacheAvail(((*in_msg_ptr)).m_Address))) {
                (L1Cache_printRequest((*in_msg_ptr)));
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
              } else {
                if (((L1Cache_checkReadWriteSignatures((((*(m_chip_ptr->m_L1Cache_L1IcacheMemory_vec[m_version]))).cacheProbe(((*in_msg_ptr)).m_Address)))) == (true))) {
                                    {
                    Address addr = (((*(m_chip_ptr->m_L1Cache_L1IcacheMemory_vec[m_version]))).cacheProbe(((*in_msg_ptr)).m_Address));
                    TransitionResult result = doTransition(L1Cache_Event_L1_Replacement_XACT, L1Cache_getState(addr), addr);
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
                    Address addr = (((*(m_chip_ptr->m_L1Cache_L1IcacheMemory_vec[m_version]))).cacheProbe(((*in_msg_ptr)).m_Address));
                    TransitionResult result = doTransition(L1Cache_Event_L1_Replacement, L1Cache_getState(addr), addr);
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
          } else {
            if ((((*(m_chip_ptr->m_L1Cache_L1IcacheMemory_vec[m_version]))).isTagPresent(((*in_msg_ptr)).m_Address))) {
              if (((L1Cache_checkReadWriteSignatures(((*in_msg_ptr)).m_Address)) == (true))) {
                                {
                  Address addr = ((*in_msg_ptr)).m_Address;
                  TransitionResult result = doTransition(L1Cache_Event_L1_Replacement_XACT, L1Cache_getState(addr), addr);
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
                  TransitionResult result = doTransition(L1Cache_Event_L1_Replacement, L1Cache_getState(addr), addr);
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
            if ((((*(m_chip_ptr->m_L1Cache_L1DcacheMemory_vec[m_version]))).isTagPresent(((*in_msg_ptr)).m_Address))) {
              (L1Cache_printRequest((*in_msg_ptr)));
              if (((((L1Cache_getL1CacheEntry(((*in_msg_ptr)).m_Address))).m_CacheState == L1Cache_State_I) && (((*in_msg_ptr)).m_Type == CacheRequestType_LD_XACT))) {
                                {
                  Address addr = ((*in_msg_ptr)).m_Address;
                  TransitionResult result = doTransition(L1Cache_Event_TLoadHit, L1Cache_getState(addr), addr);
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
            } else {
              if ((((*(m_chip_ptr->m_L1Cache_L1DcacheMemory_vec[m_version]))).cacheAvail(((*in_msg_ptr)).m_Address))) {
                (L1Cache_printRequest((*in_msg_ptr)));
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
              } else {
                if (((L1Cache_checkReadWriteSignatures((((*(m_chip_ptr->m_L1Cache_L1DcacheMemory_vec[m_version]))).cacheProbe(((*in_msg_ptr)).m_Address)))) == (true))) {
                                    {
                    Address addr = (((*(m_chip_ptr->m_L1Cache_L1DcacheMemory_vec[m_version]))).cacheProbe(((*in_msg_ptr)).m_Address));
                    TransitionResult result = doTransition(L1Cache_Event_L1_Replacement_XACT, L1Cache_getState(addr), addr);
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
                    Address addr = (((*(m_chip_ptr->m_L1Cache_L1DcacheMemory_vec[m_version]))).cacheProbe(((*in_msg_ptr)).m_Address));
                    TransitionResult result = doTransition(L1Cache_Event_L1_Replacement, L1Cache_getState(addr), addr);
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
          }
        }
      }

    break;  // If we got this far, we have nothing left todo
  }
}

