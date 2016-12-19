/** \file Chip.h 
  * Auto generated C++ code started by symbols/SymbolTable.C:238
  */ 

#ifndef CHIP_H
#define CHIP_H

#include "Global.h"
#include "Types.h"
#include "AbstractChip.h"
class Network;

class L1Cache_Controller;
class Directory_Controller;
class Chip : public AbstractChip {
public:

  // Constructors
  Chip(NodeID chip_number, Network* net_ptr);

  // Destructor
  ~Chip();

  // Public Methods
  void recordCacheContents(CacheRecorder& tr) const;
  void dumpCaches(ostream& out) const;
  void dumpCacheData(ostream& out) const;
  static void printStats(ostream& out);
  static void clearStats();
  void printConfig(ostream& out);
  void print(ostream& out) const;
#ifdef CHECK_COHERENCE
  bool isBlockShared(const Address& addr) const;
  bool isBlockExclusive(const Address& addr) const;
#endif /* CHECK_COHERENCE */

private:
  // Private copy constructor and assignment operator
  Chip(const Chip& obj);
  Chip& operator=(const Chip& obj);

public: // FIXME - these should not be public
  // Data Members (m_ prefix)

  Chip* m_chip_ptr;

  // SLICC object variables

  Vector < MessageBuffer* >  m_L1Cache_requestFromCache_vec;
  Vector < MessageBuffer* >  m_L1Cache_responseFromCache_vec;
  Vector < MessageBuffer* >  m_L1Cache_forwardToCache_vec;
  Vector < MessageBuffer* >  m_L1Cache_responseToCache_vec;
  Vector < Set* >  m_L1Cache_Warps_vec;
  Vector < TBETable<L1Cache_TBE>* >  m_L1Cache_TBEs_vec;
  Vector < MessageBuffer* >  m_Directory_forwardFromDir_vec;
  Vector < MessageBuffer* >  m_Directory_responseFromDir_vec;
  Vector < MessageBuffer* >  m_Directory_requestToDir_vec;
  Vector < MessageBuffer* >  m_Directory_unblockToDir_vec;
  Vector < DirectoryMemory* >  m_Directory_directory_vec;

  // SLICC machine/controller variables
  Vector < L1Cache_Controller* > m_L1Cache_Controller_vec;
  Vector < Directory_Controller* > m_Directory_Controller_vec;

  // machine external SLICC function decls
};

#endif // CHIP_H
