
#  General-Purpose Input/Output

The *GPIO* Library contains infrastructure functionality for handling communication via GPIO pins.  Specifically, this provides functionality that is required in the XCSL backend.  **NOTE:** XCSE has redundent definitions of each of these libraries.

###  GPIO Infrastructure

Files are provided with infrastructural GPIO constants and data structures.  These provide the backbone, which is then used by other GPIO firmwares (e.g. Random Number Generator, Real-Time Clock, etc).

It should be noted that the GPIO infrastructure assumes the XCS bootloader has already initialized the underlying layers.

###  Random Number Generator

Integer randomization is a major part of the XCSL backend (e.g. register stack randomization), so firmware is implemented within the backend of the XCSL cross-compiler for a hardware-connected **random number generator (RNG)**.  The RNG is used within several major subsystems including:
 
 * Register Stacks
 * Memory Allocation


### Real-Time Clock

Because process management is embedded within XCSL backend, the system's **real-time clock (RTC)** implementation is required.  In AArch64, the RTC is also handled through the GPIO infrastructure. This is used extensively within the process infrastructure.

