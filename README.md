# TMESI
TMESI Directory Protocol (Local Build with no SIMICS dependencies)

# Dependencies

NONE. 
DO NOT REBUILD SLICC
To use in a TM program (requires Bloom filter and TM interaction
library from gems-2.1.1)

# SLICC

```
../slicc/amd64-linux/bin/slicc.exec generated/MESI_SCMP_bankdirectory
html/MESI_SCMP_bankdirectory MESI_SCMP_bankdirectory "html"
../protocols/RubySlicc_Exports.sm ../protocols/RubySlicc_Types.sm
../protocols/RubySlicc_Util.sm
../protocols/RubySlicc_ComponentMapping.sm
../protocols/RubySlicc_Profiler.sm ../protocols/RubySlicc_Defines.sm
../protocols/RubySlicc_MemControl.sm
../protocols/MESI_SCMP_bankdirectory-msg.sm
../protocols/MESI_SCMP_bankdirectory-L2cache.sm
../protocols/MESI_SCMP_bankdirectory-L1cache.sm
../protocols/MESI_SCMP_bankdirectory-mem.sm
../protocols/standard_CMP-protocol.sm
```

# PROTOCOL INTRICACIES
***L1 Cache***


1. TM is an explicit state.
2. TI is a implicit state (getState checks the Trans bit and if it is an
I state) simply returns S. getState is invoked on every protocol
transaction.

***L2 Cache***


1. TMT, TMT_B, TMT_B_MT. Transactional states. TMT means some line in
some L1 has it in either TM or not; you don't know. Only way to find
out is to probe the L1s on every Fwd request.
2. TMT_B blocks on fwd request. In the end could go to S; if the L2
eventually finds out that there are no TM lines. The requestor that
collects all the ACKS will no if any of the acks threatened. Look at
the L1 TBE for this. TMT_B could go either to SS if not threatened
(i.e., Unblock w/o any Threat). or TMT (i.e., Unblock w/ threat)
3. TMT_B_MT always goes to MT in the end (i.e., it got a Fwd GETX). If
there are any other TM lines they will abort.
4. More comments in the .sm files. 

