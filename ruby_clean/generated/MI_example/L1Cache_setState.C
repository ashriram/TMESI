/** Auto generated C++ code started by symbols/Func.C:125 */

#include "Types.h"
#include "Chip.h"
#include "L1Cache_Controller.h"

void L1Cache_Controller::L1Cache_setState(Address param_addr, L1Cache_State param_state)
{
  if ((((*(m_chip_ptr->m_L1Cache_TBEs_vec[m_version]))).isPresent(param_addr))) {
    ((((*(m_chip_ptr->m_L1Cache_TBEs_vec[m_version]))).lookup(param_addr))).m_TBEState = param_state;
  }
  if ((((*(m_chip_ptr->m_L1Cache_cacheMemory_vec[m_version]))).isTagPresent(param_addr))) {
    ((((*(m_chip_ptr->m_L1Cache_cacheMemory_vec[m_version]))).lookup(param_addr))).m_CacheState = param_state;
  }
}

