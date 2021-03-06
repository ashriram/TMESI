/** Auto generated C++ code started by symbols/Func.C:125 */

#include "Types.h"
#include "Chip.h"
#include "L1Cache_Controller.h"

L1Cache_State L1Cache_Controller::L1Cache_getState(Address param_addr)
{
  if ((((((*(m_chip_ptr->m_L1Cache_L1DcacheMemory_vec[m_version]))).isTagPresent(param_addr)) && (((*(m_chip_ptr->m_L1Cache_L1IcacheMemory_vec[m_version]))).isTagPresent(param_addr))) == (true))) {
    DEBUG_SLICC(MedPrio, "../protocols/MESI_SCMP_bankdirectory-L1cache.sm:216: ", m_chip_ptr->getID());
;
    DEBUG_SLICC(MedPrio, "../protocols/MESI_SCMP_bankdirectory-L1cache.sm:217: ", param_addr);
;
  }
    if (ASSERT_FLAG && !((((((*(m_chip_ptr->m_L1Cache_L1DcacheMemory_vec[m_version]))).isTagPresent(param_addr)) && (((*(m_chip_ptr->m_L1Cache_L1IcacheMemory_vec[m_version]))).isTagPresent(param_addr))) == (false)))) {
    cerr << "Runtime Error at ../protocols/MESI_SCMP_bankdirectory-L1cache.sm:219, Ruby Time: " << g_eventQueue_ptr->getTime() << ": " << "assert failure" << ", PID: " << getpid() << endl;
char c; cerr << "press return to continue." << endl; cin.get(c); abort();

  }
;
  if ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).isPresent(param_addr))) {
    return ((((*(m_chip_ptr->m_L1Cache_L1_TBEs_vec[m_version]))).lookup(param_addr))).m_TBEState;
  } else {
    if ((L1Cache_isL1CacheTagPresent(param_addr))) {
      if ((((L1Cache_getL1CacheEntry(param_addr))).m_CacheState == L1Cache_State_TM)) {
        if ((((L1Cache_getL1CacheEntry(param_addr))).m_Trans == (true))) {
          return L1Cache_State_TM;
        } else {
          if (((((L1Cache_getL1CacheEntry(param_addr))).m_Trans == (false)) && (((L1Cache_getL1CacheEntry(param_addr))).m_Abort == (true)))) {
            ((L1Cache_getL1CacheEntry(param_addr))).m_CacheState = L1Cache_State_I;
            return L1Cache_State_I;
          } else {
            if (((((L1Cache_getL1CacheEntry(param_addr))).m_Trans == (false)) && (((L1Cache_getL1CacheEntry(param_addr))).m_Abort == (false)))) {
              ((L1Cache_getL1CacheEntry(param_addr))).m_CacheState = L1Cache_State_M;
              return L1Cache_State_M;
            }
          }
        }
      } else {
        if (((((L1Cache_getL1CacheEntry(param_addr))).m_Trans == (true)) && (((L1Cache_getL1CacheEntry(param_addr))).m_CacheState == L1Cache_State_I))) {
          return L1Cache_State_S;
        } else {
          return ((L1Cache_getL1CacheEntry(param_addr))).m_CacheState;
        }
      }
    }
  }
  return L1Cache_State_NP;
}

