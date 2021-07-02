#  Register Stacks

One of Xita's core offerings to the status quo is its use of **Register Stacks**. 
Xita uses register stacks to manage CPU registers dynamically, rather than according
to a staticly-defined Application Binary Interface (ABI).

Xita treats most CPU registers as "Arbitrary Data Registers" (ADRs).  

### Serializing Active Registers

If less than four ADRs are being serialized for an OS function call (e.g. malloc),
the active registers are hashed into the Operating System Register (x16).  
Then the corresponding operating system call deserializes the data.

