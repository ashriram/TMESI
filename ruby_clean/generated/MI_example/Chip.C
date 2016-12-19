// Auto generated C++ code started by symbols/SymbolTable.C:368

#include "Chip.h"
#include "Network.h"
#include "CacheRecorder.h"

// Includes for controllers
#include "L1Cache_Controller.h"
#include "Directory_Controller.h"

Chip::Chip(NodeID id, Network* net_ptr):AbstractChip(id, net_ptr)
{
  m_chip_ptr = this;
  // L1Cache_requestFromCache
  m_L1Cache_requestFromCache_vec.setSize(RubyConfig::numberOfL1CachePerChip(m_id));
  for (int i = 0; i < RubyConfig::numberOfL1CachePerChip(m_id); i++)  {
    m_L1Cache_requestFromCache_vec[i] = m_net_ptr->getToNetQueue(i+m_id*RubyConfig::numberOfL1CachePerChip()+MachineType_base_number(string_to_MachineType("L1Cache")), true, 0);
    assert(m_L1Cache_requestFromCache_vec[i] != NULL);
    m_L1Cache_requestFromCache_vec[i]->setOrdering(true);
    if (FINITE_BUFFERING) {
      m_L1Cache_requestFromCache_vec[i]->setSize(PROTOCOL_BUFFER_SIZE);
    }
  }
  // L1Cache_responseFromCache
  m_L1Cache_responseFromCache_vec.setSize(RubyConfig::numberOfL1CachePerChip(m_id));
  for (int i = 0; i < RubyConfig::numberOfL1CachePerChip(m_id); i++)  {
    m_L1Cache_responseFromCache_vec[i] = m_net_ptr->getToNetQueue(i+m_id*RubyConfig::numberOfL1CachePerChip()+MachineType_base_number(string_to_MachineType("L1Cache")), true, 1);
    assert(m_L1Cache_responseFromCache_vec[i] != NULL);
    m_L1Cache_responseFromCache_vec[i]->setOrdering(true);
    if (FINITE_BUFFERING) {
      m_L1Cache_responseFromCache_vec[i]->setSize(PROTOCOL_BUFFER_SIZE);
    }
  }
  // L1Cache_forwardToCache
  m_L1Cache_forwardToCache_vec.setSize(RubyConfig::numberOfL1CachePerChip(m_id));
  for (int i = 0; i < RubyConfig::numberOfL1CachePerChip(m_id); i++)  {
    m_L1Cache_forwardToCache_vec[i] = m_net_ptr->getFromNetQueue(i+m_id*RubyConfig::numberOfL1CachePerChip()+MachineType_base_number(string_to_MachineType("L1Cache")), true, 2);
    assert(m_L1Cache_forwardToCache_vec[i] != NULL);
    m_L1Cache_forwardToCache_vec[i]->setOrdering(true);
    if (FINITE_BUFFERING) {
      m_L1Cache_forwardToCache_vec[i]->setSize(PROTOCOL_BUFFER_SIZE);
    }
  }
  // L1Cache_responseToCache
  m_L1Cache_responseToCache_vec.setSize(RubyConfig::numberOfL1CachePerChip(m_id));
  for (int i = 0; i < RubyConfig::numberOfL1CachePerChip(m_id); i++)  {
    m_L1Cache_responseToCache_vec[i] = m_net_ptr->getFromNetQueue(i+m_id*RubyConfig::numberOfL1CachePerChip()+MachineType_base_number(string_to_MachineType("L1Cache")), true, 1);
    assert(m_L1Cache_responseToCache_vec[i] != NULL);
    m_L1Cache_responseToCache_vec[i]->setOrdering(true);
    if (FINITE_BUFFERING) {
      m_L1Cache_responseToCache_vec[i]->setSize(PROTOCOL_BUFFER_SIZE);
    }
  }
  // L1Cache_mandatoryQueue
  m_L1Cache_mandatoryQueue_vec.setSize(RubyConfig::numberOfL1CachePerChip(m_id));
  for (int i = 0; i < RubyConfig::numberOfL1CachePerChip(m_id); i++)  {
    m_L1Cache_mandatoryQueue_vec[i] = new MessageBuffer(this);

    assert(m_L1Cache_mandatoryQueue_vec[i] != NULL);
    m_L1Cache_mandatoryQueue_vec[i]->setOrdering(false);
    if (FINITE_BUFFERING) {
      m_L1Cache_mandatoryQueue_vec[i]->setSize(PROCESSOR_BUFFER_SIZE);
    }
  }

  // L1Cache_sequencer
  m_L1Cache_sequencer_vec.setSize(RubyConfig::numberOfL1CachePerChip(m_id));
  for (int i = 0; i < RubyConfig::numberOfL1CachePerChip(m_id); i++)  {
    m_L1Cache_sequencer_vec[i] = new Sequencer(this, i);

    assert(m_L1Cache_sequencer_vec[i] != NULL);
  }

  // L1Cache_Warps
  m_L1Cache_Warps_vec.setSize(RubyConfig::numberOfL1CachePerChip(m_id));
  for (int i = 0; i < RubyConfig::numberOfL1CachePerChip(m_id); i++)  {
    m_L1Cache_Warps_vec[i] = new Set;

    assert(m_L1Cache_Warps_vec[i] != NULL);
  }

  // L1Cache_cacheMemory
  m_L1Cache_cacheMemory_vec.setSize(RubyConfig::numberOfL1CachePerChip(m_id));
  for (int i = 0; i < RubyConfig::numberOfL1CachePerChip(m_id); i++)  {
    m_L1Cache_cacheMemory_vec[i] = new CacheMemory<L1Cache_Entry>(this, L1_CACHE_NUM_SETS_BITS, L1_CACHE_ASSOC, MachineType_L1Cache, int_to_string(i)+"_L1");

    assert(m_L1Cache_cacheMemory_vec[i] != NULL);
  }

  // L1Cache_TBEs
  m_L1Cache_TBEs_vec.setSize(RubyConfig::numberOfL1CachePerChip(m_id));
  for (int i = 0; i < RubyConfig::numberOfL1CachePerChip(m_id); i++)  {
    m_L1Cache_TBEs_vec[i] = new TBETable<L1Cache_TBE>(this);

    assert(m_L1Cache_TBEs_vec[i] != NULL);
  }

  // Directory_forwardFromDir
  m_Directory_forwardFromDir_vec.setSize(RubyConfig::numberOfDirectoryPerChip(m_id));
  for (int i = 0; i < RubyConfig::numberOfDirectoryPerChip(m_id); i++)  {
    m_Directory_forwardFromDir_vec[i] = m_net_ptr->getToNetQueue(i+m_id*RubyConfig::numberOfDirectoryPerChip()+MachineType_base_number(string_to_MachineType("Directory")), true, 2);
    assert(m_Directory_forwardFromDir_vec[i] != NULL);
    m_Directory_forwardFromDir_vec[i]->setOrdering(true);
    if (FINITE_BUFFERING) {
      m_Directory_forwardFromDir_vec[i]->setSize(PROTOCOL_BUFFER_SIZE);
    }
  }
  // Directory_responseFromDir
  m_Directory_responseFromDir_vec.setSize(RubyConfig::numberOfDirectoryPerChip(m_id));
  for (int i = 0; i < RubyConfig::numberOfDirectoryPerChip(m_id); i++)  {
    m_Directory_responseFromDir_vec[i] = m_net_ptr->getToNetQueue(i+m_id*RubyConfig::numberOfDirectoryPerChip()+MachineType_base_number(string_to_MachineType("Directory")), false, 1);
    assert(m_Directory_responseFromDir_vec[i] != NULL);
    m_Directory_responseFromDir_vec[i]->setOrdering(false);
    if (FINITE_BUFFERING) {
      m_Directory_responseFromDir_vec[i]->setSize(PROTOCOL_BUFFER_SIZE);
    }
  }
  // Directory_requestToDir
  m_Directory_requestToDir_vec.setSize(RubyConfig::numberOfDirectoryPerChip(m_id));
  for (int i = 0; i < RubyConfig::numberOfDirectoryPerChip(m_id); i++)  {
    m_Directory_requestToDir_vec[i] = m_net_ptr->getFromNetQueue(i+m_id*RubyConfig::numberOfDirectoryPerChip()+MachineType_base_number(string_to_MachineType("Directory")), true, 0);
    assert(m_Directory_requestToDir_vec[i] != NULL);
    m_Directory_requestToDir_vec[i]->setOrdering(true);
    if (FINITE_BUFFERING) {
      m_Directory_requestToDir_vec[i]->setSize(PROTOCOL_BUFFER_SIZE);
    }
  }
  // Directory_unblockToDir
  m_Directory_unblockToDir_vec.setSize(RubyConfig::numberOfDirectoryPerChip(m_id));
  for (int i = 0; i < RubyConfig::numberOfDirectoryPerChip(m_id); i++)  {
    m_Directory_unblockToDir_vec[i] = m_net_ptr->getFromNetQueue(i+m_id*RubyConfig::numberOfDirectoryPerChip()+MachineType_base_number(string_to_MachineType("Directory")), true, 3);
    assert(m_Directory_unblockToDir_vec[i] != NULL);
    m_Directory_unblockToDir_vec[i]->setOrdering(true);
    if (FINITE_BUFFERING) {
      m_Directory_unblockToDir_vec[i]->setSize(PROTOCOL_BUFFER_SIZE);
    }
  }
  // Directory_directory
  m_Directory_directory_vec.setSize(RubyConfig::numberOfDirectoryPerChip(m_id));
  for (int i = 0; i < RubyConfig::numberOfDirectoryPerChip(m_id); i++)  {
    m_Directory_directory_vec[i] = new DirectoryMemory(this, i);

    assert(m_Directory_directory_vec[i] != NULL);
  }

  m_L1Cache_Controller_vec.setSize(RubyConfig::numberOfL1CachePerChip(m_id));
  for (int i = 0; i < RubyConfig::numberOfL1CachePerChip(m_id); i++)  {
    m_L1Cache_Controller_vec[i] = new L1Cache_Controller(this, i);
    assert(m_L1Cache_Controller_vec[i] != NULL);
  }

  m_Directory_Controller_vec.setSize(RubyConfig::numberOfDirectoryPerChip(m_id));
  for (int i = 0; i < RubyConfig::numberOfDirectoryPerChip(m_id); i++)  {
    m_Directory_Controller_vec[i] = new Directory_Controller(this, i);
    assert(m_Directory_Controller_vec[i] != NULL);
  }

}

Chip::~Chip()
{
  for (int i = 0; i < RubyConfig::numberOfL1CachePerChip(m_id); i++)  {
    delete m_L1Cache_mandatoryQueue_vec[i];
  }
  for (int i = 0; i < RubyConfig::numberOfL1CachePerChip(m_id); i++)  {
    delete m_L1Cache_sequencer_vec[i];
  }
  for (int i = 0; i < RubyConfig::numberOfL1CachePerChip(m_id); i++)  {
    delete m_L1Cache_Warps_vec[i];
  }
  for (int i = 0; i < RubyConfig::numberOfL1CachePerChip(m_id); i++)  {
    delete m_L1Cache_cacheMemory_vec[i];
  }
  for (int i = 0; i < RubyConfig::numberOfL1CachePerChip(m_id); i++)  {
    delete m_L1Cache_TBEs_vec[i];
  }
  for (int i = 0; i < RubyConfig::numberOfDirectoryPerChip(m_id); i++)  {
    delete m_Directory_directory_vec[i];
  }
  for (int i = 0; i < RubyConfig::numberOfL1CachePerChip(m_id); i++)  {
    delete m_L1Cache_Controller_vec[i];
  }
  for (int i = 0; i < RubyConfig::numberOfDirectoryPerChip(m_id); i++)  {
    delete m_Directory_Controller_vec[i];
  }
}

void Chip::clearStats()
{
  L1Cache_Controller::clearStats();
  Directory_Controller::clearStats();
}

void Chip::printStats(ostream& out)
{
  out << endl;
  out << "Chip Stats" << endl;
  out << "----------" << endl << endl;
  L1Cache_Controller::dumpStats(out);
  Directory_Controller::dumpStats(out);
}

void Chip::printConfig(ostream& out)
{
  out << "Chip Config" << endl;
  out << "-----------" << endl;
  out << "Total_Chips: " << RubyConfig::numberOfChips() << endl;
  out << "\nL1Cache_mandatoryQueue numberPerChip: " << RubyConfig::numberOfL1CachePerChip() << endl;
  m_L1Cache_mandatoryQueue_vec[0]->printConfig(out);
  out << "\nL1Cache_sequencer numberPerChip: " << RubyConfig::numberOfL1CachePerChip() << endl;
  m_L1Cache_sequencer_vec[0]->printConfig(out);
  out << "\nL1Cache_cacheMemory numberPerChip: " << RubyConfig::numberOfL1CachePerChip() << endl;
  m_L1Cache_cacheMemory_vec[0]->printConfig(out);
  out << "\nL1Cache_TBEs numberPerChip: " << RubyConfig::numberOfL1CachePerChip() << endl;
  m_L1Cache_TBEs_vec[0]->printConfig(out);
  out << "\nDirectory_directory numberPerChip: " << RubyConfig::numberOfDirectoryPerChip() << endl;
  m_Directory_directory_vec[0]->printConfig(out);
  out << endl;
}

void Chip::print(ostream& out) const
{
  out << "Ruby Chip" << endl;
}
#ifdef CHECK_COHERENCE

bool Chip::isBlockShared(const Address& addr) const
{
  for (int i = 0; i < RubyConfig::numberOfL1CachePerChip(m_id); i++)  {
    if (m_L1Cache_Controller_vec[i]->L1Cache_isBlockShared(addr)) {
      return true; 
    }
  }
  for (int i = 0; i < RubyConfig::numberOfDirectoryPerChip(m_id); i++)  {
    if (m_Directory_Controller_vec[i]->Directory_isBlockShared(addr)) {
      return true; 
    }
  }
  return false;
}


bool Chip::isBlockExclusive(const Address& addr) const
{
  for (int i = 0; i < RubyConfig::numberOfL1CachePerChip(m_id); i++)  {
    if (m_L1Cache_Controller_vec[i]->L1Cache_isBlockExclusive(addr)) {
      return true; 
    }
  }
  for (int i = 0; i < RubyConfig::numberOfDirectoryPerChip(m_id); i++)  {
    if (m_Directory_Controller_vec[i]->Directory_isBlockExclusive(addr)) {
      return true; 
    }
  }
  return false;
}

#endif /* CHECK_COHERENCE */ 

void Chip::dumpCaches(ostream& out) const
{
  for (int i = 0; i < RubyConfig::numberOfL1CachePerChip(m_id); i++)  {
    m_L1Cache_cacheMemory_vec[i]->print(out);
  }
}

void Chip::dumpCacheData(ostream& out) const
{
  for (int i = 0; i < RubyConfig::numberOfL1CachePerChip(m_id); i++)  {
    m_L1Cache_cacheMemory_vec[i]->printData(out);
  }
}

void Chip::recordCacheContents(CacheRecorder& tr) const
{
  for (int i = 0; i < RubyConfig::numberOfL1CachePerChip(m_id); i++)  {
    m_L1Cache_cacheMemory_vec[i]->recordCacheContents(tr);
  }
}
