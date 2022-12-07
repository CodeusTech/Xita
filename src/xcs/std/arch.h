/*
  arch.h
  Codeus Tech
  Authored on      July 27, 2021
  Last Modified December 7, 2022
*/

/*
  Contains Cross-Compiler Metadata for Target CPU Architecture/Assembly Language
*/

#pragma once


/*
  Supported Chip Architecture/Assembly 
*/
enum XitaArchitecture
{
  Undefined,
  Arm64,
  Arm32,
  x86_64
};

#define NUM_SUPPORTED_ARCH          3

#define NUM_DATA_REGISTERS_Arm64   27
#define NUM_DATA_REGISTERS_Arm32   11
#define NUM_DATA_REGISTERS_x86_64  10

XitaArchitecture target_architecture = XitaArchitecture::Arm64;


XitaArchitecture get_arch(char* arch)
{
  if (strncmp(arch, "Arm64", 5))
    return XitaArchitecture::Arm64;
  else if (strncmp(arch, "Arm32", 5))
    return XitaArchitecture::Arm32;
  else if (strncmp(arch, "x86_64", 6))
    return XitaArchitecture::x86_64;
  else
    return XitaArchitecture::Undefined;
}




