#include <iostream>
#include "Pyramid/Client.h"

int main(int argc, char* argv[]) {
	if (argc > 2) {
		std::string address(argv[1]);
		int port = atoi(argv[2]);
		std::string message = argv[3];

		Pyramid::Client client(address, port);
		client.Send(message);
	}
	return EXIT_SUCCESS;
}
