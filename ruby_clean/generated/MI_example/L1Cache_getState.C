/** Auto generated C++ code started by symbols/Func.C:125 */

#include "Types.h"
#include "Chip.h"
#include "L1Cache_Controller.h"

L1Cache_State L1Cache_Controller::L1Cache_getState(Address param_addr)
{
  if ((((*(m_chip_ptr->m_L1Cache_TBEs_vec[m_version]))).isPresent(param_addr))) {
    return ((((*(m_chip_ptr->m_L1Cache_TBEs_vec[m_version]))).lookup(param_addr))).m_TBEState;
  } else {
    if ((((*(m_chip_ptr->m_L1Cache_cacheMemory_vec[m_version]))).isTagPresent(param_addr))) {
      return ((((*(m_chip_ptr->m_L1Cache_cacheMemory_vec[m_version]))).lookup(param_addr))).m_CacheState;
    } else {
      return L1Cache_State_I;
    }
  }
}

