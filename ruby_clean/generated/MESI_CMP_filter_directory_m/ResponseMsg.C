/** \file ResponseMsg.C
  * 
  * Auto generated C++ code started by symbols/Type.C:479
  */

#include "ResponseMsg.h"

Allocator<ResponseMsg>* ResponseMsg::s_allocator_ptr = NULL;
/** \brief Print the state of this object */
void ResponseMsg::print(ostream& out) const
{
  out << "[ResponseMsg: ";
  out << "Address=" << m_Address << " ";
  out << "PhysicalAddress=" << m_PhysicalAddress << " ";
  out << "Type=" << m_Type << " ";
  out << "Sender=" << m_Sender << " ";
  out << "Destination=" << m_Destination << " ";
  out << "DataBlk=" << m_DataBlk << " ";
  out << "Dirty=" << m_Dirty << " ";
  out << "AckCount=" << m_AckCount << " ";
  out << "MessageSize=" << m_MessageSize << " ";
  out << "Timestamp=" << m_Timestamp << " ";
  out << "Nackers=" << m_Nackers << " ";
  out << "Transactional=" << m_Transactional << " ";
  out << "ConflictType=" << m_ConflictType << " ";
  out << "RemoveLastOwnerFromDir=" << m_RemoveLastOwnerFromDir << " ";
  out << "LastOwnerID=" << m_LastOwnerID << " ";
  out << "Time=" << getTime() << " ";
  out << "]";
}
