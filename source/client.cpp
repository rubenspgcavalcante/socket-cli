#include "../headers/client.h"
client::client(char* host, int port){
	//Setting up the information
	portno = port;
	server = gethostbyname(host);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0)
        error("Error opening socket");
	server = gethostbyname(host);
    if (server == NULL)
        error("Error, no such host");
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    
}

bool client::socketConnect(){
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0){
	    error("Error connecting");
	    return 0;
	}
	return true;
}

void client::socketClose(){
	close(sockfd);
}

char* client::send(char* msg){
    n = write(sockfd,msg,strlen(msg));
    if (n < 0) {
        error("ERROR writing to socket");
    	return 0;
    }
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) {
		error("ERROR reading from socket");
		return 0;
    }
    return buffer;
}
