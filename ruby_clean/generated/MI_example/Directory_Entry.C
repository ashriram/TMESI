/** \file Directory_Entry.C
  * 
  * Auto generated C++ code started by symbols/Type.C:479
  */

#include "Directory_Entry.h"

/** \brief Print the state of this object */
void Directory_Entry::print(ostream& out) const
{
  out << "[Directory_Entry: ";
  out << "DirectoryState=" << m_DirectoryState << " ";
  out << "DataBlk=" << m_DataBlk << " ";
  out << "Sharers=" << m_Sharers << " ";
  out << "Owner=" << m_Owner << " ";
  out << "]";
}
