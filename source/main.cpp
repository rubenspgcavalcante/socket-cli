#include "../headers/includes.h"
#include "client.cpp"

using namespace std;

int main(int argc, char** argv){
	int port;
	if(argc < 4){
		cout<<"Ussage:\n\tclient [host] [port] [message]\n\n";
		return 0;
		}
	else port = atoi(argv[2]);
	cout<<"Connecting to host in:"<<endl;
	cout << argv[1]; cout << ":" ; cout << port << endl;
	client c(argv[1], port);
	c.socketConnect();
	c.send(argv[3]);
	c.socketClose();
	return 1;
}
