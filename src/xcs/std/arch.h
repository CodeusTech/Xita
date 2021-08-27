/*
  arch.h
  Codeus Tech
  Authored on   July 27, 2021
  Last Modified July 29, 2021
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






