#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>

int main(int argc, char* argv[]) {
	TCPsocket server;
	IPaddress ip;		
	int quit;
	std::string command;

	if (argc > 1) {
		command = argv[1];
	}

	if (SDLNet_Init() < 0) {
		fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}

	if (SDLNet_ResolveHost(&ip, "127.0.0.1", 2000) < 0) {
		fprintf(stderr, "SDLNet_ResolveHost: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}

	if (!(server = SDLNet_TCP_Open(&ip))) {
		fprintf(stderr, "SDLNet_TCP_Open: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}

	quit = 0;

	int length = command.length();
	std::string lengthStr = std::to_string(length);
	SDLNet_TCP_Send(server, lengthStr.c_str(), 512);
	SDLNet_TCP_Send(server, command.c_str(), length);
	SDLNet_TCP_Close(server);
	SDLNet_Quit();

	return EXIT_SUCCESS;
}