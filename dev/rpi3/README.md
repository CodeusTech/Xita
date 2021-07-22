
#  boot directory

This subdirectory is new as of Xita v0.25

This sublibrary is intended to hold snippets of assembly to be used in Xita's bootloader.  
There are two files in this directory that are not C/C++:
*  rpi3-boot.s
*  rpi3-linker.ld

These are basic models derived from [osdev.org](https://wiki.osdev.org/ARM_RaspberryPi_Tutorial_C#Pi_3.2C_4).


##  How the bootloader works in Xita

Each time Xita cross-compiles a new device image, it retrieves the bootloader assembly file and the object linker file from this repository if it is avilable.  Users will ultimately be able to input their own boot files using a compiler flag (planned feature).

The bootloader is positioned within the chip's expected entry point in memory (e.g. 0x80000 in RPi3).  It sets up the chip's standard operating conditions for Xita Runtime Environment then chains to the user's main driver file.  


