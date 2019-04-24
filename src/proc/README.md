
#  XCS Process Management

CONTENT COMING SOON

###  Table of Contents

* [process/](#process-definitions)
* [tethers/](#process-tethers)
* [sched/](#process-scheduler)
* [ipc/](#interprocess-communication)

###  Process Definitions

The **Process** Sublibrary includes all functionality that affects individual
processes, such as:

* Check Status
* Get Active Process Tethers
* Check Message Queues

It includes the following backend libraries:

* operations.h
  * functionality/definitions for process internals

###  Process Tethers

* operations.h
  * Backend functionality for managing active process tethers
* parameters.h
  * Backend functionality for tether operands (module names)

###  Process Scheduler

* operations.h
  * Backend functionality for managing active processes
* queues.h
  * Definitions/functionality for process queues

###  Interprocess Communcation

* operations.h
  * Backend functionality for sending/receiving data between active processes

