/*
    boot.s
    Codeus Tech
    Authored on   March 11, 2019
    Last Modified March 11, 2019
*/

/*
    Contains initialization (bootloader) code for XCS AArch64 Kernel

    Code was retrieved from a mix of sources, but especially from osdev.org
*/
 
// To keep this in the first portion of the binary.
.section ".text.boot"
 

/*
  Register States after return from RaspPi boot: https://github.com/raspberrypi/tools/blob/master/armstubs/armstub8.S
    x0 -> 32 bit pointer to DTB in memory (primary core only) / 0 (secondary cores)
    x1 -> 0
    x2 -> 0
    x3 -> 0
    x4 -> 32 bit kernel entry point, _start location
*/
.globl _start
.org 0x80000
_start:
    // set stack before our code
    ldr     x5, =_start
    mov     sp, x5
 
    // clear bss (DEPRECATED)
    ldr     x5, =__bss_start
    ldr     w6, =__bss_size
3:  cbz     w6, 4f
    str     xzr, [x5], #8
    sub     w6, w6, #1
    cbnz    w6, 3b
 
    // branch to XCS kernel, logic should NOT return afterwards
4:  bl      __start
    //  In case code DOES return, halt main core (wait for event)
    wfe

