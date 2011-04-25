#include "../headers/includes.h"
#include "client.cpp"

using namespace std;

int main(int argc, char** argv){
	int port;
	if(argc < 2){
		cout<<"Ussage:\n\tclient [host] [port]\n\n";
		return 0;
		}
	if(argc < 3) port = 8080;
	else port = atoi(argv[2]);
	cout<<"Connecting to host in:"<<endl;
	cout<<argv[1];	cout<<":"; cout<<port<<endl;
	
	client c(argv[1], port);
	c.socketConnect();
	c.socketClose();
	return 1;
}
