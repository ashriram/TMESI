/** Auto generated C++ code started by symbols/Func.C:125 */

#include "Types.h"
#include "Chip.h"
#include "Directory_Controller.h"

bool Directory_Controller::Directory_isGETRequest(CoherenceRequestType param_type)
{
  return (((param_type == CoherenceRequestType_GETS) || (param_type == CoherenceRequestType_GET_INSTR)) || (param_type == CoherenceRequestType_GETX));
}

