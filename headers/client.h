#ifndef __SOCKET_CLIENT
#define __SOCKET_CLIENT
//Structs and other things we need here are included in 'includes.h'
#include "includes.h"

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

class client{
	private:
	    int sockfd, portno, socketReturn;
	    char buffer[256];
    	sockaddr_in servAddr;
		hostent *server;
   		
	public:
		client(char*, int);
		bool socketConnect();
		char* send(char*);
		void socketClose();
};

#endif
