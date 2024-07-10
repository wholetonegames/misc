https://www.codeproject.com/Articles/11740/A-simple-UDP-time-server-and-client-for-beginners

Compilation Command
To compile the above code using GCC for Windows (assuming you have MinGW installed), use the following command:

gcc -o timeserv timeserv.c -lws2_32
Here, -lws2_32 links the Winsock2 library, which is necessary for socket programming in Windows.

Running the Server
Once compiled, you can run the server from the command line:

timeserv 12345
Replace 12345 with the desired port number. If you also provide an IP address, use:

timeserv 192.168.1.100 12345
This will start the server on IP address 192.168.1.100 and port 12345.

## to run both programs
type `timeserv 127.0.0.1 5000`, and to run the client, type `timecli 127.0.0.1 5000 127.0.0.1` on the same computer.