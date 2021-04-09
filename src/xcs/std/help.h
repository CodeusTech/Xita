/*
  help.h
  Codeus Tech
  Authored on   April 9, 2021
  Last Modified April 9, 2021
*/

/*
  Contains the help message for XCS cross-compiler
*/

#pragma once

#include <xcs/meta.h>
#include <stdio.h>

int help_msg()
{
printf(
"\nXita v%s \n\
Usage: xcs-aarch64 [options] file...\n\n\
General Options:  \n\
  --version         Display cross-compiler version information\n\
  -h || --help      Display this information\n\
  -v || --verbose   Print internal operations to Standard Output\n\
\n", XCSL_VERSION);

  return 1;
}
