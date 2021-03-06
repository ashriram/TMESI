/** Auto generated C++ code started by symbols/Func.C:125 */

#include "Types.h"
#include "Chip.h"
#include "L2Cache_Controller.h"

L2Cache_Event L2Cache_Controller::L2Cache_L1Cache_request_type_to_event(CoherenceRequestType param_type, Address param_addr, MachineID param_requestor)
{
  if ((param_type == CoherenceRequestType_GETS)) {
    return L2Cache_Event_L1_GETS;
  } else {
    if ((param_type == CoherenceRequestType_GET_INSTR)) {
      return L2Cache_Event_L1_GET_INSTR;
    } else {
      if ((param_type == CoherenceRequestType_GETX)) {
        return L2Cache_Event_L1_GETX;
      } else {
        if ((param_type == CoherenceRequestType_UPGRADE)) {
          if (((L2Cache_isL2CacheTagPresent(param_addr)) && ((((L2Cache_getL2CacheEntry(param_addr))).m_Sharers).isElement(param_requestor)))) {
            return L2Cache_Event_L1_UPGRADE;
          } else {
            return L2Cache_Event_L1_GETX;
          }
        } else {
          if ((param_type == CoherenceRequestType_PUTX)) {
            if ((L2Cache_isSharer(param_addr, param_requestor))) {
              return L2Cache_Event_L1_PUTX;
            } else {
              return L2Cache_Event_L1_PUTX_old;
            }
          } else {
            DEBUG_SLICC(MedPrio, "../protocols/MESI_SCMP_bankdirectory-L2cache.sm:296: ", param_addr);
;
            DEBUG_SLICC(MedPrio, "../protocols/MESI_SCMP_bankdirectory-L2cache.sm:297: ", param_type);
;
                        cerr << "Runtime Error at ../protocols/MESI_SCMP_bankdirectory-L2cache.sm:298, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << ("Invalid L1 forwarded request type") << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

;
          }
        }
      }
    }
  }
}

