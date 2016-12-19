/** \file ResponseMsg.h
  * 
  * Auto generated C++ code started by symbols/Type.C:227
  */

#ifndef ResponseMsg_H
#define ResponseMsg_H

#include "Global.h"
#include "Allocator.h"
#include "Address.h"
#include "Address.h"
#include "CoherenceResponseType.h"
#include "MachineID.h"
#include "NetDest.h"
#include "DataBlock.h"
#include "MessageSizeType.h"
#include "NetDest.h"
#include "MachineID.h"
#include "NetworkMessage.h"
class ResponseMsg :  public NetworkMessage {
public:
  ResponseMsg() 
  : NetworkMessage()
  {
    // m_Address has no default
    // m_PhysicalAddress has no default
    m_Type = CoherenceResponseType_NUM; // default value of CoherenceResponseType
    // m_Sender has no default
    // m_Destination has no default
    // m_DataBlk has no default
    m_Dirty = false; // default for this field 
    m_AckCount = 0; // default for this field 
    m_MessageSize = MessageSizeType_Undefined; // default value of MessageSizeType
    // m_Timestamp has no default
    // m_Nackers has no default
    m_Transactional = false; // default value of bool
    m_ConflictType = false; // default value of bool
    m_RemoveLastOwnerFromDir = false; // default value of bool
    // m_LastOwnerID has no default
  }
  ~ResponseMsg() { };
  ResponseMsg(const Address& local_Address, const Address& local_PhysicalAddress, const CoherenceResponseType& local_Type, const MachineID& local_Sender, const NetDest& local_Destination, const DataBlock& local_DataBlk, const bool& local_Dirty, const int& local_AckCount, const MessageSizeType& local_MessageSize, const uint64& local_Timestamp, const NetDest& local_Nackers, const bool& local_Transactional, const bool& local_ConflictType, const bool& local_RemoveLastOwnerFromDir, const MachineID& local_LastOwnerID)
  : NetworkMessage()
  {
    m_Address = local_Address;
    m_PhysicalAddress = local_PhysicalAddress;
    m_Type = local_Type;
    m_Sender = local_Sender;
    m_Destination = local_Destination;
    m_DataBlk = local_DataBlk;
    m_Dirty = local_Dirty;
    m_AckCount = local_AckCount;
    m_MessageSize = local_MessageSize;
    m_Timestamp = local_Timestamp;
    m_Nackers = local_Nackers;
    m_Transactional = local_Transactional;
    m_ConflictType = local_ConflictType;
    m_RemoveLastOwnerFromDir = local_RemoveLastOwnerFromDir;
    m_LastOwnerID = local_LastOwnerID;
  }
  Message* clone() const { checkAllocator(); return s_allocator_ptr->allocate(*this); }
  void destroy() { checkAllocator(); s_allocator_ptr->deallocate(this); }
  static Allocator<ResponseMsg>* s_allocator_ptr;
  static void checkAllocator() { if (s_allocator_ptr == NULL) { s_allocator_ptr = new Allocator<ResponseMsg>; }}
  // Const accessors methods for each field
/** \brief Const accessor method for Address field.
  * \return Address field
  */
  const Address& getAddress() const { return m_Address; }
/** \brief Const accessor method for PhysicalAddress field.
  * \return PhysicalAddress field
  */
  const Address& getPhysicalAddress() const { return m_PhysicalAddress; }
/** \brief Const accessor method for Type field.
  * \return Type field
  */
  const CoherenceResponseType& getType() const { return m_Type; }
/** \brief Const accessor method for Sender field.
  * \return Sender field
  */
  const MachineID& getSender() const { return m_Sender; }
/** \brief Const accessor method for Destination field.
  * \return Destination field
  */
  const NetDest& getDestination() const { return m_Destination; }
/** \brief Const accessor method for DataBlk field.
  * \return DataBlk field
  */
  const DataBlock& getDataBlk() const { return m_DataBlk; }
/** \brief Const accessor method for Dirty field.
  * \return Dirty field
  */
  const bool& getDirty() const { return m_Dirty; }
/** \brief Const accessor method for AckCount field.
  * \return AckCount field
  */
  const int& getAckCount() const { return m_AckCount; }
/** \brief Const accessor method for MessageSize field.
  * \return MessageSize field
  */
  const MessageSizeType& getMessageSize() const { return m_MessageSize; }
/** \brief Const accessor method for Timestamp field.
  * \return Timestamp field
  */
  const uint64& getTimestamp() const { return m_Timestamp; }
/** \brief Const accessor method for Nackers field.
  * \return Nackers field
  */
  const NetDest& getNackers() const { return m_Nackers; }
/** \brief Const accessor method for Transactional field.
  * \return Transactional field
  */
  const bool& getTransactional() const { return m_Transactional; }
/** \brief Const accessor method for ConflictType field.
  * \return ConflictType field
  */
  const bool& getConflictType() const { return m_ConflictType; }
/** \brief Const accessor method for RemoveLastOwnerFromDir field.
  * \return RemoveLastOwnerFromDir field
  */
  const bool& getRemoveLastOwnerFromDir() const { return m_RemoveLastOwnerFromDir; }
/** \brief Const accessor method for LastOwnerID field.
  * \return LastOwnerID field
  */
  const MachineID& getLastOwnerID() const { return m_LastOwnerID; }

  // Non const Accessors methods for each field
/** \brief Non-const accessor method for Address field.
  * \return Address field
  */
  Address& getAddress() { return m_Address; }
/** \brief Non-const accessor method for PhysicalAddress field.
  * \return PhysicalAddress field
  */
  Address& getPhysicalAddress() { return m_PhysicalAddress; }
/** \brief Non-const accessor method for Type field.
  * \return Type field
  */
  CoherenceResponseType& getType() { return m_Type; }
/** \brief Non-const accessor method for Sender field.
  * \return Sender field
  */
  MachineID& getSender() { return m_Sender; }
/** \brief Non-const accessor method for Destination field.
  * \return Destination field
  */
  NetDest& getDestination() { return m_Destination; }
/** \brief Non-const accessor method for DataBlk field.
  * \return DataBlk field
  */
  DataBlock& getDataBlk() { return m_DataBlk; }
/** \brief Non-const accessor method for Dirty field.
  * \return Dirty field
  */
  bool& getDirty() { return m_Dirty; }
/** \brief Non-const accessor method for AckCount field.
  * \return AckCount field
  */
  int& getAckCount() { return m_AckCount; }
/** \brief Non-const accessor method for MessageSize field.
  * \return MessageSize field
  */
  MessageSizeType& getMessageSize() { return m_MessageSize; }
/** \brief Non-const accessor method for Timestamp field.
  * \return Timestamp field
  */
  uint64& getTimestamp() { return m_Timestamp; }
/** \brief Non-const accessor method for Nackers field.
  * \return Nackers field
  */
  NetDest& getNackers() { return m_Nackers; }
/** \brief Non-const accessor method for Transactional field.
  * \return Transactional field
  */
  bool& getTransactional() { return m_Transactional; }
/** \brief Non-const accessor method for ConflictType field.
  * \return ConflictType field
  */
  bool& getConflictType() { return m_ConflictType; }
/** \brief Non-const accessor method for RemoveLastOwnerFromDir field.
  * \return RemoveLastOwnerFromDir field
  */
  bool& getRemoveLastOwnerFromDir() { return m_RemoveLastOwnerFromDir; }
/** \brief Non-const accessor method for LastOwnerID field.
  * \return LastOwnerID field
  */
  MachineID& getLastOwnerID() { return m_LastOwnerID; }

  // Mutator methods for each field
/** \brief Mutator method for Address field */
  void setAddress(const Address& local_Address) { m_Address = local_Address; }
/** \brief Mutator method for PhysicalAddress field */
  void setPhysicalAddress(const Address& local_PhysicalAddress) { m_PhysicalAddress = local_PhysicalAddress; }
/** \brief Mutator method for Type field */
  void setType(const CoherenceResponseType& local_Type) { m_Type = local_Type; }
/** \brief Mutator method for Sender field */
  void setSender(const MachineID& local_Sender) { m_Sender = local_Sender; }
/** \brief Mutator method for Destination field */
  void setDestination(const NetDest& local_Destination) { m_Destination = local_Destination; }
/** \brief Mutator method for DataBlk field */
  void setDataBlk(const DataBlock& local_DataBlk) { m_DataBlk = local_DataBlk; }
/** \brief Mutator method for Dirty field */
  void setDirty(const bool& local_Dirty) { m_Dirty = local_Dirty; }
/** \brief Mutator method for AckCount field */
  void setAckCount(const int& local_AckCount) { m_AckCount = local_AckCount; }
/** \brief Mutator method for MessageSize field */
  void setMessageSize(const MessageSizeType& local_MessageSize) { m_MessageSize = local_MessageSize; }
/** \brief Mutator method for Timestamp field */
  void setTimestamp(const uint64& local_Timestamp) { m_Timestamp = local_Timestamp; }
/** \brief Mutator method for Nackers field */
  void setNackers(const NetDest& local_Nackers) { m_Nackers = local_Nackers; }
/** \brief Mutator method for Transactional field */
  void setTransactional(const bool& local_Transactional) { m_Transactional = local_Transactional; }
/** \brief Mutator method for ConflictType field */
  void setConflictType(const bool& local_ConflictType) { m_ConflictType = local_ConflictType; }
/** \brief Mutator method for RemoveLastOwnerFromDir field */
  void setRemoveLastOwnerFromDir(const bool& local_RemoveLastOwnerFromDir) { m_RemoveLastOwnerFromDir = local_RemoveLastOwnerFromDir; }
/** \brief Mutator method for LastOwnerID field */
  void setLastOwnerID(const MachineID& local_LastOwnerID) { m_LastOwnerID = local_LastOwnerID; }

  void print(ostream& out) const;
//private:
  Address m_Address; /**< Line address for this request*/
  Address m_PhysicalAddress; /**< Physical address for this request*/
  CoherenceResponseType m_Type; /**< Type of response (Ack, Data, etc)*/
  MachineID m_Sender; /**< What component sent the data*/
  NetDest m_Destination; /**< Node to whom the data is sent*/
  DataBlock m_DataBlk; /**< Data for the cache line*/
  bool m_Dirty; /**< Dirty bit*/
  int m_AckCount; /**< number of acks in this message*/
  MessageSizeType m_MessageSize; /**< size category of the message*/
  uint64 m_Timestamp; /**< TLR-like Timestamp*/
  NetDest m_Nackers; /**< The nodes which sent NACKs to requestor*/
  bool m_Transactional; /**< Whether this address was transactional*/
  bool m_ConflictType; /**< Whether XACT was reading or writing*/
  bool m_RemoveLastOwnerFromDir; /**< To solve some races with PUTX/GETS*/
  MachineID m_LastOwnerID; /**< What component sent the data*/
};
// Output operator declaration
ostream& operator<<(ostream& out, const ResponseMsg& obj);

// Output operator definition
extern inline
ostream& operator<<(ostream& out, const ResponseMsg& obj)
{
  obj.print(out);
  out << flush;
  return out;
}

#endif // ResponseMsg_H
