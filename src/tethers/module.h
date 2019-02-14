/*
  module.h
  Cody Fagley
  Authored on   February 14, 2019
  Last Modified February 14, 2019
*/

/*
  Contains functionality, specific to Tether Modules
*/

#ifndef TETHER_MODULE_H
#define TETHER_MODULE_H


int ipc_ask(char* module, char* ident)
{
  printf("%s requested from module: %s\n", ident, module);

  return 0;
}

int ipc_offer(char* ident)
{
  printf("Service Offered: %s\n", ident);

  return 0;
}



#endif
