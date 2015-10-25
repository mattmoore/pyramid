#include <iostream>
#include "Pyramid/Server.h"

int main(int argc, char* argv[]) {
	if (argc > 1) {
		int port = atoi(argv[1]);

		Pyramid::Server server(port);
		server.Run();
	}
	return EXIT_SUCCESS;	
}
