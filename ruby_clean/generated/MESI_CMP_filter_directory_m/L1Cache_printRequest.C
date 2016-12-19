/** Auto generated C++ code started by symbols/Func.C:125 */

#include "Types.h"
#include "Chip.h"
#include "L1Cache_Controller.h"

void L1Cache_Controller::L1Cache_printRequest(CacheMsg param_in_msg)
{
  DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:327: ", ("Regquest msg: "));
;
  DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:328: ", m_machineID);
;
  DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:329: ", (param_in_msg).m_Address);
;
  DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:330: ", (param_in_msg).m_PhysicalAddress);
;
  DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:331: ", (param_in_msg).m_Type);
;
  DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:332: ", (param_in_msg).m_ProgramCounter);
;
  DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:333: ", (param_in_msg).m_AccessMode);
;
  DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:334: ", (param_in_msg).m_Size);
;
  DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:335: ", (param_in_msg).m_Prefetch);
;
  DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:336: ", (param_in_msg).m_Version);
;
  DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:337: ", (param_in_msg).m_LogicalAddress);
;
  DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:338: ", (param_in_msg).m_ThreadID);
;
  DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:339: ", (param_in_msg).m_Timestamp);
;
  DEBUG_SLICC(MedPrio, "../protocols/MESI_CMP_filter_directory-L1cache.sm:340: ", (param_in_msg).m_ExposedAction);
;
}

