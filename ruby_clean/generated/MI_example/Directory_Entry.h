/** \file Directory_Entry.h
  * 
  * Auto generated C++ code started by symbols/Type.C:227
  */

#ifndef Directory_Entry_H
#define Directory_Entry_H

#include "Global.h"
#include "Allocator.h"
#include "Directory_State.h"
#include "DataBlock.h"
#include "NetDest.h"
#include "NetDest.h"
class Directory_Entry {
public:
  Directory_Entry() 
  {
    m_DirectoryState = Directory_State_I; // default value of Directory_State
    // m_DataBlk has no default
    // m_Sharers has no default
    // m_Owner has no default
  }
  ~Directory_Entry() { };
  Directory_Entry(const Directory_State& local_DirectoryState, const DataBlock& local_DataBlk, const NetDest& local_Sharers, const NetDest& local_Owner)
  {
    m_DirectoryState = local_DirectoryState;
    m_DataBlk = local_DataBlk;
    m_Sharers = local_Sharers;
    m_Owner = local_Owner;
  }
  // Const accessors methods for each field
/** \brief Const accessor method for DirectoryState field.
  * \return DirectoryState field
  */
  const Directory_State& getDirectoryState() const { return m_DirectoryState; }
/** \brief Const accessor method for DataBlk field.
  * \return DataBlk field
  */
  const DataBlock& getDataBlk() const { return m_DataBlk; }
/** \brief Const accessor method for Sharers field.
  * \return Sharers field
  */
  const NetDest& getSharers() const { return m_Sharers; }
/** \brief Const accessor method for Owner field.
  * \return Owner field
  */
  const NetDest& getOwner() const { return m_Owner; }

  // Non const Accessors methods for each field
/** \brief Non-const accessor method for DirectoryState field.
  * \return DirectoryState field
  */
  Directory_State& getDirectoryState() { return m_DirectoryState; }
/** \brief Non-const accessor method for DataBlk field.
  * \return DataBlk field
  */
  DataBlock& getDataBlk() { return m_DataBlk; }
/** \brief Non-const accessor method for Sharers field.
  * \return Sharers field
  */
  NetDest& getSharers() { return m_Sharers; }
/** \brief Non-const accessor method for Owner field.
  * \return Owner field
  */
  NetDest& getOwner() { return m_Owner; }

  // Mutator methods for each field
/** \brief Mutator method for DirectoryState field */
  void setDirectoryState(const Directory_State& local_DirectoryState) { m_DirectoryState = local_DirectoryState; }
/** \brief Mutator method for DataBlk field */
  void setDataBlk(const DataBlock& local_DataBlk) { m_DataBlk = local_DataBlk; }
/** \brief Mutator method for Sharers field */
  void setSharers(const NetDest& local_Sharers) { m_Sharers = local_Sharers; }
/** \brief Mutator method for Owner field */
  void setOwner(const NetDest& local_Owner) { m_Owner = local_Owner; }

  void print(ostream& out) const;
//private:
  Directory_State m_DirectoryState; /**< Directory state*/
  DataBlock m_DataBlk; /**< data for the block*/
  NetDest m_Sharers; /**< Sharers for this block*/
  NetDest m_Owner; /**< Owner of this block*/
};
// Output operator declaration
ostream& operator<<(ostream& out, const Directory_Entry& obj);

// Output operator definition
extern inline
ostream& operator<<(ostream& out, const Directory_Entry& obj)
{
  obj.print(out);
  out << flush;
  return out;
}

#endif // Directory_Entry_H
