#include <stdlib.h>
#include <stdio.h>
//#include <jansson.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdbool.h>

#include <signal.h>

const int PORT = 8181;
bool verbose = false;
bool mustKill = false;

void help() {
	puts("CHATTY");
	puts("-h,--h \t \t \t Displays this help page");
	puts("-v,--v \t \t \t Turns on verbose mode");
	puts("");
}
void sigHandler(int signal) {
	printf("Called sigHandler with signal: %d and verbose: %d\n", signal, verbose);
	if (verbose) {
		printf("Recieved signal: %d\n", signal);
	}
	switch (signal) {
		case SIGHUP:
			if (verbose) puts("Requested hangup, ignoring.");
			break;
		case SIGINT:
			if (verbose) puts("Recieved intterupt request, killing server");
			mustKill = true;
			break;
		case SIGTERM:
			if (verbose) puts("Requested termination, killing server");
			mustKill = true;
			break;
		case SIGQUIT:
			if (verbose) puts("Requested quit, killing server");
			mustKill = true;
			break;
		case SIGTSTP:
			if (verbose) puts("Terminal requested stop, killing server");
			mustKill = true;
			break;
		default:
			if (verbose) printf("Unknown signal %d\n", signal);
			break;
	}
}

void setupSignals() {
	struct sigaction action;
	memset(&action, 0, sizeof(struct sigaction));
	action.sa_handler = sigHandler;
	sigaction(SIGTERM, &action, NULL);
	sigaction(SIGHUP, &action, NULL);
	sigaction(SIGQUIT, &action, NULL);
	sigaction(SIGTSTP, &action, NULL);
	sigaction(SIGINT, &action, NULL);
	mustKill = false;
}

int setup(bool verbose) {
	int status;
	struct addrinfo hints;
	struct addrinfo *serverInfo;			//Store results of getaddrinfo
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;				//Only support IPv4 for now
	hints.ai_socktype = SOCK_STREAM;		//use TCP Stream Sockets
	hints.ai_flags = AI_PASSIVE;			//Use local IP
	
	char IntToStr[5];
	sprintf(IntToStr, "%d", PORT);			//https://stackoverflow.com/questions/9655202/how-to-convert-integer-to-string-in-c
	printf("PORT as string %s\n", IntToStr);
	status = getaddrinfo("127.0.0.1", IntToStr, &hints, &serverInfo);
	if (status != 0) {
		printf("getaddrinfo error: %s\n", gai_strerror(status));
	}
	else {
		char ipstr[INET_ADDRSTRLEN];
		struct sockaddr_in *ipAddr = (struct sockaddr_in *)serverInfo->ai_addr;
		inet_ntop(serverInfo->ai_family, &(ipAddr->sin_addr), ipstr, sizeof(ipstr));
		printf("%s\n", ipstr);
		if (serverInfo->ai_next == NULL) {
			puts("ai_next is null");
		}
		else {
			puts("ai_next is not null");
		}
	}
	
	int sock = socket(serverInfo->ai_family, serverInfo->ai_socktype, serverInfo->ai_protocol);
	if (sock == -1) {
		printf("Unable to create socket, errno: %d - %s\n", errno, strerror(errno));
	}
	else {
		printf("created socket with descriptor: %d\n", sock);
	}
	int bindresult = bind(sock, serverInfo->ai_addr, serverInfo->ai_addrlen);
	if (bindresult == -1) {
		printf("Unable to bind to port %d, errno: %d - %s\n", PORT, errno, strerror(errno));
	}
	else {
		printf("Successfully binded to port: %d\n", PORT);
	}
	
	if (listen(sock, 5) == -1) {
		printf("Unable to listen(), errno: %d - %s\n", errno, strerror(errno));
	}
	else {
		puts("Successfully started listening");
	}
	return sock;
}

int main(int argc, char** argv) {
	if (argc > 1) {
		int i = 1;
		for (i = 1; i < argc; i++) {
			//printf("%d = %s\n", i, argv[i]);
			if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--h") == 0) {
				help();
				return -1;
			}
			if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--v") == 0) {
				verbose = true;
				puts("Verbose turned on");
			}
		}
	}
	setupSignals();
	puts("Chatty starting up!");
	int sock = setup(verbose);
	
	for (int i = 0; i < 5; i++) {
		printf("iter: %d\n", i);
		struct sockaddr_storage accepted;
		socklen_t acceptedSize = sizeof(accepted);
		int newSock = accept(sock, (struct sockaddr *)&accepted, &acceptedSize);
		if (newSock == -1) {
			printf("accept() failed with errno: %d - %s\n", errno, strerror(errno));
		}
		else {
			printf("accept() was successfull with descriptor %d\n", newSock);
		}
		//try and read data
		char buff[1024];
		int recieved = recv(newSock, &buff, 1024, 0);
		printf("recieved %s\n", buff);
		
		//Send Hello World back to the browser (testing in FF)
		char* message = "Hello world!";
		if (send(newSock, message, 12, 0) == -1) {
			printf("Hello World failed to send() with errno: %d - %s\n", errno, strerror(errno));
		}
		else {
			puts("Successfully sent Hello World!");
		}
		close(newSock);
	}
	
	
	//Close socket for further experimentation
	close(sock);
	return 1;
}