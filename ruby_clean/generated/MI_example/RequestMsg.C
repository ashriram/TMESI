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
  out << "Type=" << m_Type << " ";
  out << "Requestor=" << m_Requestor << " ";
  out << "Destination=" << m_Destination << " ";
  out << "Acks=" << m_Acks << " ";
  out << "DataBlk=" << m_DataBlk << " ";
  out << "MessageSize=" << m_MessageSize << " ";
  out << "Time=" << getTime() << " ";
  out << "]";
}
