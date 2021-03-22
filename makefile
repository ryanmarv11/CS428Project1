all: clean client

client: 
	g++ -o client UDPPingClient.cpp -Wall -Werror
clean:
	rm -rf client client.o
