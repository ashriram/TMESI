/** \file L2Cache_Entry.C
  * 
  * Auto generated C++ code started by symbols/Type.C:479
  */

#include "L2Cache_Entry.h"

/** \brief Print the state of this object */
void L2Cache_Entry::print(ostream& out) const
{
  out << "[L2Cache_Entry: ";
  out << "CacheState=" << m_CacheState << " ";
  out << "Sharers=" << m_Sharers << " ";
  out << "Exclusive=" << m_Exclusive << " ";
  out << "DataBlk=" << m_DataBlk << " ";
  out << "Dirty=" << m_Dirty << " ";
  out << "Trans=" << m_Trans << " ";
  out << "Read=" << m_Read << " ";
  out << "Write=" << m_Write << " ";
  out << "L2Miss=" << m_L2Miss << " ";
  out << "L1PutsPending=" << m_L1PutsPending << " ";
  out << "]";
}
