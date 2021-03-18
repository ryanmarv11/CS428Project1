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
	int sock = 0, valread;
	struct sockaddr_in serv_addr, client_addr;
	char* message= "Ping"
	char buffer[1024];
	if((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		cout << "ERROR: SOCKET CANNOT BE CREATED. EXPLODING IN T-MINUS 5 SECONDS." << endl;
		return -1;
	}
	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 
	
	servaddr.sin_family = AF_INET; // IPv4 
	servaddr.sin_addr.s_addr = INADDR_ANY; // localhost
	servaddr.sin_port = htons(PORT); // port number
	
	send(sock, mesage, strlen(message), 0);
	cout << "Ping sent." << endl;
	valread = read(sock, buffer, 1024);
	cout << buffer << endl;
}
