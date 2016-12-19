/** Auto generated C++ code started by symbols/Func.C:125 */

#include "Types.h"
#include "Chip.h"
#include "L2Cache_Controller.h"

L2Cache_Event L2Cache_Controller::L2Cache_L1Cache_request_type_to_event(CoherenceRequestType param_type, Address param_addr, MachineID param_requestor)
{
  if ((((*(m_chip_ptr->m_L2Cache_L2cacheMemory_vec[m_version]))).isTagPresent(param_addr))) {
    if (((((L2Cache_getL2CacheEntry(param_addr))).m_L1PutsPending > (0)) && (((((L2Cache_getL2CacheEntry(param_addr))).m_CacheState == L2Cache_State_SS) || (((L2Cache_getL2CacheEntry(param_addr))).m_CacheState == L2Cache_State_MT)) || (((L2Cache_getL2CacheEntry(param_addr))).m_CacheState == L2Cache_State_M)))) {
      if (((param_type != CoherenceRequestType_PUTX) && (param_type != CoherenceRequestType_PUTS))) {
        return L2Cache_Event_L1_PUT_PENDING;
      }
    }
  }
  if ((param_type == CoherenceRequestType_GETS)) {
    return L2Cache_Event_L1_GETS;
  } else {
    if ((param_type == CoherenceRequestType_GETS_ESCAPE)) {
      return L2Cache_Event_L1_GETS_ESCAPE;
    } else {
      if ((param_type == CoherenceRequestType_GET_INSTR)) {
        return L2Cache_Event_L1_GET_INSTR;
      } else {
        if ((param_type == CoherenceRequestType_GET_INSTR_ESCAPE)) {
          return L2Cache_Event_L1_GET_INSTR_ESCAPE;
        } else {
          if ((param_type == CoherenceRequestType_GETX)) {
            return L2Cache_Event_L1_GETX;
          } else {
            if ((param_type == CoherenceRequestType_GETX_ESCAPE)) {
              return L2Cache_Event_L1_GETX_ESCAPE;
            } else {
              if ((param_type == CoherenceRequestType_UPGRADE)) {
                if (((L2Cache_isL2CacheTagPresent(param_addr)) && ((((L2Cache_getL2CacheEntry(param_addr))).m_Sharers).isElement(param_requestor)))) {
                  return L2Cache_Event_L1_UPGRADE;
                } else {
                  return L2Cache_Event_L1_GETX;
                }
              } else {
                if ((param_type == CoherenceRequestType_PUTX)) {
                  if (((L2Cache_isL2CacheTagPresent(param_addr)) && (((L2Cache_getL2CacheEntry(param_addr))).m_L1PutsPending > (0)))) {
                    ((L2Cache_getL2CacheEntry(param_addr))).m_L1PutsPending = (((L2Cache_getL2CacheEntry(param_addr))).m_L1PutsPending - (1));
                    DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L2cache.sm:329: ", ("PUTX PutSPending "));
;
                    DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L2cache.sm:330: ", ((L2Cache_getL2CacheEntry(param_addr))).m_L1PutsPending);
;
                  }
                  if ((L2Cache_isSharer(param_addr, param_requestor))) {
                    return L2Cache_Event_L1_PUTX;
                  } else {
                    return L2Cache_Event_L1_PUTX_old;
                  }
                } else {
                  if ((param_type == CoherenceRequestType_PUTS)) {
                    if (((L2Cache_isL2CacheTagPresent(param_addr)) && (((L2Cache_getL2CacheEntry(param_addr))).m_L1PutsPending > (0)))) {
                      ((L2Cache_getL2CacheEntry(param_addr))).m_L1PutsPending = (((L2Cache_getL2CacheEntry(param_addr))).m_L1PutsPending - (1));
                      DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L2cache.sm:340: ", ("PUTS PutSPending "));
;
                      DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L2cache.sm:341: ", ((L2Cache_getL2CacheEntry(param_addr))).m_L1PutsPending);
;
                    }
                    if ((L2Cache_isSharer(param_addr, param_requestor))) {
                      return L2Cache_Event_L1_PUTS;
                    } else {
                      return L2Cache_Event_L1_PUTS_old;
                    }
                  } else {
                    DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L2cache.sm:349: ", param_addr);
;
                    DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L2cache.sm:350: ", param_type);
;
                                        cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-L2cache.sm:351, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << ("Invalid L1 forwarded request type") << ", PID: " << getpid() << endl;
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

