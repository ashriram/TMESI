/** \file RequestMsg.C
  * 
  * Auto generated C++ code started by symbols/Type.C:479
  */

#include "RequestMsg.h"

Allocator<RequestMsg>* RequestMsg::s_allocator_ptr = NULL;
/** \brief Print the state of this object */
void RequestMsg::print(ostream& out) const
{
  out << "[RequestMsg: ";
  out << "Address=" << m_Address << " ";
  out << "PhysicalAddress=" << m_PhysicalAddress << " ";
  out << "Type=" << m_Type << " ";
  out << "AccessMode=" << m_AccessMode << " ";
  out << "Requestor=" << m_Requestor << " ";
  out << "Destination=" << m_Destination << " ";
  out << "MessageSize=" << m_MessageSize << " ";
  out << "DataBlk=" << m_DataBlk << " ";
  out << "Dirty=" << m_Dirty << " ";
  out << "ConflictType=" << m_ConflictType << " ";
  out << "Prefetch=" << m_Prefetch << " ";
  out << "Timestamp=" << m_Timestamp << " ";
  out << "Time=" << getTime() << " ";
  out << "]";
}
