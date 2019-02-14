/*
  ipc.h
  Cody Fagley
  Authored on   February 14, 2019
  Last Modified February 14, 2019
*/

/*
  Contains backend functionality for interprocess communication
*/

#ifndef TETHERS_IPC_H
#define TETHERS_IPC_H


int ipc_send(char* key)
{
  printf("Sending data through Channel, %s\n", key);

  return 0;
}

int ipc_receive(char* key)
{
  printf("Receiving data through Channel, %s\n", key);

  return 0;
}





#endif
