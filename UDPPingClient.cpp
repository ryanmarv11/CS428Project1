#include <iostream>
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <time.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <ctime>


#define PORT 12000

using namespace std;

int main()
{
	//initialize variables
	int sock = 0, valread;
	struct sockaddr_in serv_addr, client_addr;
	char* message = (char*)"Ping";		//pretty weird that it will autocast in c but not c++
	char buffer[1024];

	if((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)	//attempt to create a socket
	{
		//if the program reachers here, the socket failed to create
		cout << "ERROR: SOCKET CANNOT BE CREATED. EXPLODING IN T-MINUS 5 SECONDS." << endl;
		return -1;
	}
	
	//Finishes creating of the socket
	memset(&serv_addr, 0, sizeof(serv_addr)); 
	memset(&client_addr, 0, sizeof(client_addr)); 
	
	//Fills in server information
	serv_addr.sin_family = AF_INET; // IPv4 
	serv_addr.sin_addr.s_addr = INADDR_ANY; // localhost
	serv_addr.sin_port = htons(PORT); // port number

	//Setting socket timeout by putting it in non-blocking mode
	struct timeval t;
	t.tv_sec = 0;
	t.tv_usec = 1000000;
	if(setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &t, sizeof(t)) < 0)
	{
		cout << "ERROR: Setting timeout has failed." << endl;
		return -1;
	}

	//Initialize variables for getting RTT
	time_t startTime, endTime;
	
	for(int i = 0; i < 10; i++)
	{
		//Send the message to the server
		time(&startTime);
		send(sock, message, strlen(message), 0);
		cout << "Ping sent." << endl;
		time(&endTime);
		//Read the message from the server
		valread = read(sock, buffer, 1024);
		if(valread < 0)
		{
			cout << "ERROR: Failed to read from socket." << endl;
		}
		cout << buffer << endl;
	}
	return 0;



}
