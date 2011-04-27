#include "../headers/client.h"

client::client(char* host, int port){
	//Setting up the information
	
	portno = port; //Port number
	server = gethostbyname(host); //getting host, in machine readeble form
    
    /* Open a socket of AF_INET family and transport layer as TCP */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0)
        error("Error opening socket");

    if (server == NULL)
        error("Error, no such host");
    
    /* Putting zeros in servAddr */
    bzero((char *) &servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servAddr.sin_addr.s_addr, server->h_length);
    servAddr.sin_port = htons(portno);
    
}

bool client::socketConnect(){
    if (connect(sockfd,(struct sockaddr *) &servAddr,sizeof(servAddr)) < 0){
	    error("Error connecting");
	    return 0;
	}
	return true;
}

void client::socketClose(){
	close(sockfd);
}

char* client::send(char* msg){
    socketReturn = write(sockfd,msg,strlen(msg));
    if (socketReturn < 0) {
        error("ERROR writing to socket");
    	return 0;
    }
    bzero(buffer,256);
    socketReturn = read(sockfd,buffer,255);
    if (socketReturn < 0) {
		error("ERROR reading from socket");
		return 0;
    }
    return buffer;
}
