/** Auto generated C++ code started by symbols/Func.C:125 */

#include "Types.h"
#include "Chip.h"

GenericRequestType Chip::convertToGenericType(CoherenceRequestType param_type)
{
  if ((param_type == CoherenceRequestType_PUTX)) {
    return GenericRequestType_PUTX;
  } else {
    if ((param_type == CoherenceRequestType_GETS)) {
      return GenericRequestType_GETS;
    } else {
      if ((param_type == CoherenceRequestType_GETS_ESCAPE)) {
        return GenericRequestType_GETS;
      } else {
        if ((param_type == CoherenceRequestType_GET_INSTR)) {
          return GenericRequestType_GET_INSTR;
        } else {
          if ((param_type == CoherenceRequestType_GET_INSTR_ESCAPE)) {
            return GenericRequestType_GET_INSTR;
          } else {
            if ((param_type == CoherenceRequestType_GETX)) {
              return GenericRequestType_GETX;
            } else {
              if ((param_type == CoherenceRequestType_GETX_ESCAPE)) {
                return GenericRequestType_GETX;
              } else {
                if ((param_type == CoherenceRequestType_UPGRADE)) {
                  return GenericRequestType_UPGRADE;
                } else {
                  if ((param_type == CoherenceRequestType_INV)) {
                    return GenericRequestType_INV;
                  } else {
                    if ((param_type == CoherenceRequestType_REPLACE)) {
                      return GenericRequestType_REPLACEMENT;
                    } else {
                      DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-msg.sm:175: ", param_type);
;
                                            cerr << "Runtime Error at ../protocols/MESI_CMP_filter_directory-msg.sm:176, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << ("invalid CoherenceRequestType") << ", PID: " << getpid() << endl;
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

