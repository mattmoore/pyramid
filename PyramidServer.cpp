#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>

int main(int argc, char* args[]) {
	TCPsocket server, client;
	IPaddress ip, *remoteIP;		
	int quit, quit2;

	if (SDLNet_Init() < 0) {
		fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}

	if (SDLNet_ResolveHost(&ip, NULL, 2000) < 0) {
		fprintf(stderr, "SDLNet_ResolveHost: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}

	if (!(server = SDLNet_TCP_Open(&ip))) {
		fprintf(stderr, "SDLNet_TCP_Open: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}

	quit = 0;
	while (!quit) {
		if ((client = SDLNet_TCP_Accept(server))) {
			if ((remoteIP = SDLNet_TCP_GetPeerAddress(client))) {
				printf("Host connected: %x %d\n", SDLNet_Read32(&remoteIP->host), SDLNet_Read16(&remoteIP->port));
				quit2 = 0;
				while (!quit2) {
					// Get buffer length
					char bufferLengthMsg[512];
					SDLNet_TCP_Recv(client, bufferLengthMsg, 512);
					int bufferLength = atoi(bufferLengthMsg);
					// Get message
					char buffer[bufferLength];
					SDLNet_TCP_Recv(client, buffer, bufferLength);
					// Print stats
					printf("Message length: %s\n", bufferLengthMsg);
					printf("Message content: %s\n", buffer);
					quit2 = 1;
				}
			} else {
				fprintf(stderr, "SDLNet_TCP_GetPeerAddress: %s\n", SDLNet_GetError());
			}
			SDLNet_TCP_Close(client);
		}
	}

	SDLNet_TCP_Close(server);
	SDLNet_Quit();
	return EXIT_SUCCESS;
}

std::string escape(std::string& str) {
	return str;
}
