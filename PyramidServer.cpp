#include <iostream>
#include "Pyramid/Server.h"

int main(int argc, char* args[]) {
	Pyramid::Server server;
	server.Run();
	return EXIT_SUCCESS;	
}
