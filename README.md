# CS428Project1
Before I go into the details of my project and it's current status, I would first like to thank Prof. Seetharam for the extension and to Di for offering his help if I had any questions. If I was not granted this extension my program would be nowhere near functional as I spent a majority of the time learning about the sockets before writing the code. I did not communicate with Di regarding questions because by the time that I actually got to coding, it was quite late in the day. Unfortunately even with the extension, I was unable to fully complete the project but I do understand the process that is supposed to occur in the code (explanation will be at the end)

I know that my code compiles with the given makefile and the code does run. For some reason on my virtual linux box I was unable to get both the server and the client to run at the same time so I was unable to properly debug/test my code. I'm very sorry that I was unable to complete the assignment fully even with an extension.

This is what the code for the client pinger should do.
1. Create a socket
2. Set the timeout for the newly created socket at 1 seconds and 0 nanoseconds
3. Send the message to the server
4. Wait for either the socket to timeout (1 second) or for the server to respond
5a. If the server responded successfully, meaning the packet was recieved and a response from the server sent, the Round Trip Time for the messaged sending, receiving, and acknowledgement response is calculated and printed to the screen
5b. If the server did not respond successfully, meaning the packet was not received (which in the context of the UDPPingServer code means a number less than 4 was generated), would result in just a message being printed to the console stating that the packet was lost. 
6. The socket is then closed. 

As I told the professor, I am currently getting professional help in the form of therapy in order to better manage my schoolwork and I plan to begin the next programming assignment as soon as possible. I hope that my documentation and this README is enough to earn partial credit for this programming assignment. If there are any questions about the assignment feel free to ask. 
