/** Auto generated C++ code started by symbols/Func.C:125 */

#include "Types.h"
#include "Chip.h"
#include "L1Cache_Controller.h"

GenericMachineType L1Cache_Controller::L1Cache_getNondirectHitMachType(Address param_addr, MachineID param_sender)
{
  if (((machineIDToMachineType(param_sender)) == MachineType_L1Cache)) {
    return GenericMachineType_L1Cache_wCC;
  } else {
    if (((machineIDToMachineType(param_sender)) == MachineType_L2Cache)) {
      return GenericMachineType_L2Cache;
    } else {
      return (ConvertMachToGenericMach((machineIDToMachineType(param_sender))));
    }
  }
}

