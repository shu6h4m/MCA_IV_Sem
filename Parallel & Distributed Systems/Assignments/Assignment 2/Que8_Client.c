#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include "mpi.h" 
int main( int argc, char **argv ) 
{ 
 MPI_Comm server; 
 MPI_Status status; //return status for send or receive
 char port_name[MPI_MAX_PORT_NAME],str[50],ch; 
 int i, tag,again; 
 if (argc < 2) 
 { 
  fprintf(stderr, "server port name required.\n"); 
  exit(EXIT_FAILURE); 
 } 
 MPI_Init(&argc, &argv); //Let the system do what it needs to start up MPI
 strcpy(port_name, argv[1]); 
 MPI_Comm_connect(port_name, MPI_INFO_NULL, 0, MPI_COMM_WORLD, &server); 

 // accept input string 
 printf("\nEnter the string :\n"); 
 scanf("%s",str); 

 //send string to server (character by character) 
 for (i = 0; i < strlen(str); i++) 
 { 
  if(str[i]!='\0') 
  ch=str[i]; 
  tag=2; //tag- used to classify messages

  MPI_Send(&ch, 1, MPI_CHAR, 0, tag, server); 
 }

 // done sending string to the server 
 MPI_Send(&i, 0, MPI_INT, 0, 1, server); 

 // Receive the reversed string from server and display it 
 i=0; 
 again=1; 
 while (again) 
 { 
  MPI_Recv(&ch, 1, MPI_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG, server, &status); 
  switch (status.MPI_TAG) 
  { 
   case 2: 
    str[i]=ch; 
    i++; 
    break; 
   case 1: again=0; 
    break; 
  } 
 } 
  printf("\nReversed string is : %s\n\n",str); 
  MPI_Comm_disconnect(&server); 
  MPI_Finalize(); //Once MPI_FINALIZE has been called, no other MPI routines may be called. 

  return 0; 
}

/*
# compile
mpicc server.c -o server
mpicc client.c -o client

# run server
mpirun -np 1 ./server

# it will display output similar to below (not necessarily the same)
Server available at port: 4290510848.0;tcp://192.168.1.101:35820;tcp://192.168.122.1:35820+4290510849.0;tcp://192.168.1.101:40208;tcp://192.168.122.1:40208:300

# copy the port-string from the terminal output (e.g. the highlighted portion above)

# we are going to supply this port-string as a first command line argument to the client

# open another terminal
mpirun -np 1 ./client '4290510848.0;tcp://192.168.1.101:35820;tcp://192.168.122.1:35820+4290510849.0;tcp://192.168. 1.101:40208;tcp://192.168.122.1:40208:300' 

# Don't forget to insert single quotes at the start & end of the port-string.
*/
