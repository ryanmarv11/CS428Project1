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

	if((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)	//Attempt to create a socket
	{
		//if the program reaches here, the socket failed to create
		cout << "ERROR: SOCKET CANNOT BE CREATED. EXPLODING IN T-MINUS 5 SECONDS." << endl;
		return -1;
	}
	
	//Finishes creating of the socket (step 1)
	memset(&serv_addr, 0, sizeof(serv_addr)); 
	memset(&client_addr, 0, sizeof(client_addr)); 
	
	//Fills in server information (step 1)
	serv_addr.sin_family = AF_INET; // IPv4 
	serv_addr.sin_addr.s_addr = INADDR_ANY;		// localhost
	serv_addr.sin_port = htons(PORT);		// port number

	//Setting socket timeout by putting it in non-blocking mode (step 2)
	struct timeval t;
	t.tv_sec = 1;	//whole seconds
	t.tv_usec = 0;	//nanoseconds
	if(setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &t, sizeof(t)) < 0) //this line actually does/attempts the timeout setup
	{
		//if the program reaches here, the socket timeout failed to set to 1 second 
		cout << "ERROR: Setting timeout has failed." << endl;
		return -1;
	}

	//Initialize variables for getting RTT
	time_t startTime, endTime;
	
	for(int i = 0; i < 10; i++)	//sending 10 messages
	{
			time(&startTime);	//start time is marked
			send(sock, message, strlen(message), 0);	//sends the message
			cout << "Ping sent." << endl;
			valread = read(sock, buffer, 1024);	//Read the message from the server
			time(&endTime);		//end time is marked
			if(valread < 0)	//checks if read was successful
			{
				//if the program gets here then the socket read failed (the packet was lost)
				cout << "No message recieved from socket, assuming lost packet." << endl;
				
			}
			else	//successful read from socket, the packet was not lost
			{
				cout << "Message recieved from socket: " << buffer << "." << endl;
				cout << "The RTT for trip " << i + 1 << " is: " << difftime(endTime, startTime) << endl;
			}

	}
	close(sock);
	return 0;
}
