#ifndef __SOCKET_CLIENT
#define __SOCKET_CLIENT
//Structs and other things we need here are included in 'includes.h'

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

class client{
	private:
	    int sockfd, portno, n;
	    char buffer[256];
    	sockaddr_in serv_addr;
		hostent *server;
   		
	public:
		client(char*, int);
		bool socketConnect();
		char* send(char*);
		void socketClose();
};

#endif
