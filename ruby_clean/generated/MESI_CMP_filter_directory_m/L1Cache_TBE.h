/** \file L1Cache_TBE.h
  * 
  * Auto generated C++ code started by symbols/Type.C:227
  */

#ifndef L1Cache_TBE_H
#define L1Cache_TBE_H

#include "Global.h"
#include "Allocator.h"
#include "Address.h"
#include "Address.h"
#include "L1Cache_State.h"
#include "DataBlock.h"
#include "MachineID.h"
#include "NetDest.h"
class L1Cache_TBE {
public:
  L1Cache_TBE() 
  {
    // m_Address has no default
    // m_PhysicalAddress has no default
    m_TBEState = L1Cache_State_I; // default value of L1Cache_State
    // m_DataBlk has no default
    m_Dirty = false; // default for this field 
    m_isPrefetch = false; // default value of bool
    m_pendingAcks = 0; // default for this field 
    m_ThreadID = 0; // default for this field 
    m_Trans = false; // default for this field 
    m_RemoveLastOwnerFromDir = false; // default for this field 
    // m_LastOwnerID has no default
    m_Timestamp = 0; // default for this field 
    m_nack = false; // default for this field 
    // m_Nackers has no default
  }
  ~L1Cache_TBE() { };
  L1Cache_TBE(const Address& local_Address, const Address& local_PhysicalAddress, const L1Cache_State& local_TBEState, const DataBlock& local_DataBlk, const bool& local_Dirty, const bool& local_isPrefetch, const int& local_pendingAcks, const int& local_ThreadID, const bool& local_Trans, const bool& local_RemoveLastOwnerFromDir, const MachineID& local_LastOwnerID, const uint64& local_Timestamp, const bool& local_nack, const NetDest& local_Nackers)
  {
    m_Address = local_Address;
    m_PhysicalAddress = local_PhysicalAddress;
    m_TBEState = local_TBEState;
    m_DataBlk = local_DataBlk;
    m_Dirty = local_Dirty;
    m_isPrefetch = local_isPrefetch;
    m_pendingAcks = local_pendingAcks;
    m_ThreadID = local_ThreadID;
    m_Trans = local_Trans;
    m_RemoveLastOwnerFromDir = local_RemoveLastOwnerFromDir;
    m_LastOwnerID = local_LastOwnerID;
    m_Timestamp = local_Timestamp;
    m_nack = local_nack;
    m_Nackers = local_Nackers;
  }
  // Const accessors methods for each field
/** \brief Const accessor method for Address field.
  * \return Address field
  */
  const Address& getAddress() const { return m_Address; }
/** \brief Const accessor method for PhysicalAddress field.
  * \return PhysicalAddress field
  */
  const Address& getPhysicalAddress() const { return m_PhysicalAddress; }
/** \brief Const accessor method for TBEState field.
  * \return TBEState field
  */
  const L1Cache_State& getTBEState() const { return m_TBEState; }
/** \brief Const accessor method for DataBlk field.
  * \return DataBlk field
  */
  const DataBlock& getDataBlk() const { return m_DataBlk; }
/** \brief Const accessor method for Dirty field.
  * \return Dirty field
  */
  const bool& getDirty() const { return m_Dirty; }
/** \brief Const accessor method for isPrefetch field.
  * \return isPrefetch field
  */
  const bool& getisPrefetch() const { return m_isPrefetch; }
/** \brief Const accessor method for pendingAcks field.
  * \return pendingAcks field
  */
  const int& getpendingAcks() const { return m_pendingAcks; }
/** \brief Const accessor method for ThreadID field.
  * \return ThreadID field
  */
  const int& getThreadID() const { return m_ThreadID; }
/** \brief Const accessor method for Trans field.
  * \return Trans field
  */
  const bool& getTrans() const { return m_Trans; }
/** \brief Const accessor method for RemoveLastOwnerFromDir field.
  * \return RemoveLastOwnerFromDir field
  */
  const bool& getRemoveLastOwnerFromDir() const { return m_RemoveLastOwnerFromDir; }
/** \brief Const accessor method for LastOwnerID field.
  * \return LastOwnerID field
  */
  const MachineID& getLastOwnerID() const { return m_LastOwnerID; }
/** \brief Const accessor method for Timestamp field.
  * \return Timestamp field
  */
  const uint64& getTimestamp() const { return m_Timestamp; }
/** \brief Const accessor method for nack field.
  * \return nack field
  */
  const bool& getnack() const { return m_nack; }
/** \brief Const accessor method for Nackers field.
  * \return Nackers field
  */
  const NetDest& getNackers() const { return m_Nackers; }

  // Non const Accessors methods for each field
/** \brief Non-const accessor method for Address field.
  * \return Address field
  */
  Address& getAddress() { return m_Address; }
/** \brief Non-const accessor method for PhysicalAddress field.
  * \return PhysicalAddress field
  */
  Address& getPhysicalAddress() { return m_PhysicalAddress; }
/** \brief Non-const accessor method for TBEState field.
  * \return TBEState field
  */
  L1Cache_State& getTBEState() { return m_TBEState; }
/** \brief Non-const accessor method for DataBlk field.
  * \return DataBlk field
  */
  DataBlock& getDataBlk() { return m_DataBlk; }
/** \brief Non-const accessor method for Dirty field.
  * \return Dirty field
  */
  bool& getDirty() { return m_Dirty; }
/** \brief Non-const accessor method for isPrefetch field.
  * \return isPrefetch field
  */
  bool& getisPrefetch() { return m_isPrefetch; }
/** \brief Non-const accessor method for pendingAcks field.
  * \return pendingAcks field
  */
  int& getpendingAcks() { return m_pendingAcks; }
/** \brief Non-const accessor method for ThreadID field.
  * \return ThreadID field
  */
  int& getThreadID() { return m_ThreadID; }
/** \brief Non-const accessor method for Trans field.
  * \return Trans field
  */
  bool& getTrans() { return m_Trans; }
/** \brief Non-const accessor method for RemoveLastOwnerFromDir field.
  * \return RemoveLastOwnerFromDir field
  */
  bool& getRemoveLastOwnerFromDir() { return m_RemoveLastOwnerFromDir; }
/** \brief Non-const accessor method for LastOwnerID field.
  * \return LastOwnerID field
  */
  MachineID& getLastOwnerID() { return m_LastOwnerID; }
/** \brief Non-const accessor method for Timestamp field.
  * \return Timestamp field
  */
  uint64& getTimestamp() { return m_Timestamp; }
/** \brief Non-const accessor method for nack field.
  * \return nack field
  */
  bool& getnack() { return m_nack; }
/** \brief Non-const accessor method for Nackers field.
  * \return Nackers field
  */
  NetDest& getNackers() { return m_Nackers; }

  // Mutator methods for each field
/** \brief Mutator method for Address field */
  void setAddress(const Address& local_Address) { m_Address = local_Address; }
/** \brief Mutator method for PhysicalAddress field */
  void setPhysicalAddress(const Address& local_PhysicalAddress) { m_PhysicalAddress = local_PhysicalAddress; }
/** \brief Mutator method for TBEState field */
  void setTBEState(const L1Cache_State& local_TBEState) { m_TBEState = local_TBEState; }
/** \brief Mutator method for DataBlk field */
  void setDataBlk(const DataBlock& local_DataBlk) { m_DataBlk = local_DataBlk; }
/** \brief Mutator method for Dirty field */
  void setDirty(const bool& local_Dirty) { m_Dirty = local_Dirty; }
/** \brief Mutator method for isPrefetch field */
  void setisPrefetch(const bool& local_isPrefetch) { m_isPrefetch = local_isPrefetch; }
/** \brief Mutator method for pendingAcks field */
  void setpendingAcks(const int& local_pendingAcks) { m_pendingAcks = local_pendingAcks; }
/** \brief Mutator method for ThreadID field */
  void setThreadID(const int& local_ThreadID) { m_ThreadID = local_ThreadID; }
/** \brief Mutator method for Trans field */
  void setTrans(const bool& local_Trans) { m_Trans = local_Trans; }
/** \brief Mutator method for RemoveLastOwnerFromDir field */
  void setRemoveLastOwnerFromDir(const bool& local_RemoveLastOwnerFromDir) { m_RemoveLastOwnerFromDir = local_RemoveLastOwnerFromDir; }
/** \brief Mutator method for LastOwnerID field */
  void setLastOwnerID(const MachineID& local_LastOwnerID) { m_LastOwnerID = local_LastOwnerID; }
/** \brief Mutator method for Timestamp field */
  void setTimestamp(const uint64& local_Timestamp) { m_Timestamp = local_Timestamp; }
/** \brief Mutator method for nack field */
  void setnack(const bool& local_nack) { m_nack = local_nack; }
/** \brief Mutator method for Nackers field */
  void setNackers(const NetDest& local_Nackers) { m_Nackers = local_Nackers; }

  void print(ostream& out) const;
//private:
  Address m_Address; /**< Line address for this TBE*/
  Address m_PhysicalAddress; /**< Physical address for this TBE*/
  L1Cache_State m_TBEState; /**< Transient state*/
  DataBlock m_DataBlk; /**< Buffer for the data block*/
  bool m_Dirty; /**< data is dirty*/
  bool m_isPrefetch; /**< Set if this was caused by a prefetch*/
  int m_pendingAcks; /**< number of pending acks*/
  int m_ThreadID; /**< SMT thread issuing the request*/
  bool m_Trans; /**< Threatened data gets this set; TI state. We care if Is are hits*/
  bool m_RemoveLastOwnerFromDir; /**< The forwarded data was being replaced*/
  MachineID m_LastOwnerID; /**< What component forwarded (last owned) the data*/
  uint64 m_Timestamp; /**< Timestamp of request*/
  bool m_nack; /**< has this request been nacked?*/
  NetDest m_Nackers; /**< The nodes which sent a NACK to us*/
};
// Output operator declaration
ostream& operator<<(ostream& out, const L1Cache_TBE& obj);

// Output operator definition
extern inline
ostream& operator<<(ostream& out, const L1Cache_TBE& obj)
{
  obj.print(out);
  out << flush;
  return out;
}

#endif // L1Cache_TBE_H
