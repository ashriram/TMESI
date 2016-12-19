/** \file RequestMsg.h
  * 
  * Auto generated C++ code started by symbols/Type.C:227
  */

#ifndef RequestMsg_H
#define RequestMsg_H

#include "Global.h"
#include "Allocator.h"
#include "Address.h"
#include "CoherenceRequestType.h"
#include "MachineID.h"
#include "NetDest.h"
#include "DataBlock.h"
#include "MessageSizeType.h"
#include "NetworkMessage.h"
class RequestMsg :  public NetworkMessage {
public:
  RequestMsg() 
  : NetworkMessage()
  {
    // m_Address has no default
    m_Type = CoherenceRequestType_NUM; // default value of CoherenceRequestType
    // m_Requestor has no default
    // m_Destination has no default
    m_Acks = 0; // default value of int
    // m_DataBlk has no default
    m_MessageSize = MessageSizeType_Undefined; // default value of MessageSizeType
  }
  ~RequestMsg() { };
  RequestMsg(const Address& local_Address, const CoherenceRequestType& local_Type, const MachineID& local_Requestor, const NetDest& local_Destination, const int& local_Acks, const DataBlock& local_DataBlk, const MessageSizeType& local_MessageSize)
  : NetworkMessage()
  {
    m_Address = local_Address;
    m_Type = local_Type;
    m_Requestor = local_Requestor;
    m_Destination = local_Destination;
    m_Acks = local_Acks;
    m_DataBlk = local_DataBlk;
    m_MessageSize = local_MessageSize;
  }
  Message* clone() const { checkAllocator(); return s_allocator_ptr->allocate(*this); }
  void destroy() { checkAllocator(); s_allocator_ptr->deallocate(this); }
  static Allocator<RequestMsg>* s_allocator_ptr;
  static void checkAllocator() { if (s_allocator_ptr == NULL) { s_allocator_ptr = new Allocator<RequestMsg>; }}
  // Const accessors methods for each field
/** \brief Const accessor method for Address field.
  * \return Address field
  */
  const Address& getAddress() const { return m_Address; }
/** \brief Const accessor method for Type field.
  * \return Type field
  */
  const CoherenceRequestType& getType() const { return m_Type; }
/** \brief Const accessor method for Requestor field.
  * \return Requestor field
  */
  const MachineID& getRequestor() const { return m_Requestor; }
/** \brief Const accessor method for Destination field.
  * \return Destination field
  */
  const NetDest& getDestination() const { return m_Destination; }
/** \brief Const accessor method for Acks field.
  * \return Acks field
  */
  const int& getAcks() const { return m_Acks; }
/** \brief Const accessor method for DataBlk field.
  * \return DataBlk field
  */
  const DataBlock& getDataBlk() const { return m_DataBlk; }
/** \brief Const accessor method for MessageSize field.
  * \return MessageSize field
  */
  const MessageSizeType& getMessageSize() const { return m_MessageSize; }

  // Non const Accessors methods for each field
/** \brief Non-const accessor method for Address field.
  * \return Address field
  */
  Address& getAddress() { return m_Address; }
/** \brief Non-const accessor method for Type field.
  * \return Type field
  */
  CoherenceRequestType& getType() { return m_Type; }
/** \brief Non-const accessor method for Requestor field.
  * \return Requestor field
  */
  MachineID& getRequestor() { return m_Requestor; }
/** \brief Non-const accessor method for Destination field.
  * \return Destination field
  */
  NetDest& getDestination() { return m_Destination; }
/** \brief Non-const accessor method for Acks field.
  * \return Acks field
  */
  int& getAcks() { return m_Acks; }
/** \brief Non-const accessor method for DataBlk field.
  * \return DataBlk field
  */
  DataBlock& getDataBlk() { return m_DataBlk; }
/** \brief Non-const accessor method for MessageSize field.
  * \return MessageSize field
  */
  MessageSizeType& getMessageSize() { return m_MessageSize; }

  // Mutator methods for each field
/** \brief Mutator method for Address field */
  void setAddress(const Address& local_Address) { m_Address = local_Address; }
/** \brief Mutator method for Type field */
  void setType(const CoherenceRequestType& local_Type) { m_Type = local_Type; }
/** \brief Mutator method for Requestor field */
  void setRequestor(const MachineID& local_Requestor) { m_Requestor = local_Requestor; }
/** \brief Mutator method for Destination field */
  void setDestination(const NetDest& local_Destination) { m_Destination = local_Destination; }
/** \brief Mutator method for Acks field */
  void setAcks(const int& local_Acks) { m_Acks = local_Acks; }
/** \brief Mutator method for DataBlk field */
  void setDataBlk(const DataBlock& local_DataBlk) { m_DataBlk = local_DataBlk; }
/** \brief Mutator method for MessageSize field */
  void setMessageSize(const MessageSizeType& local_MessageSize) { m_MessageSize = local_MessageSize; }

  void print(ostream& out) const;
//private:
  Address m_Address; /**< Physical address for this request*/
  CoherenceRequestType m_Type; /**< Type of request (GetS, GetX, PutX, etc)*/
  MachineID m_Requestor; /**< Node who initiated the request*/
  NetDest m_Destination; /**< Multicast destination mask*/
  int m_Acks; /**< How many acks to expect*/
  DataBlock m_DataBlk; /**< data for the cache line*/
  MessageSizeType m_MessageSize; /**< size category of the message*/
};
// Output operator declaration
ostream& operator<<(ostream& out, const RequestMsg& obj);

// Output operator definition
extern inline
ostream& operator<<(ostream& out, const RequestMsg& obj)
{
  obj.print(out);
  out << flush;
  return out;
}

#endif // RequestMsg_H
