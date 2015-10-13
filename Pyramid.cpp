#include <iostream>
#include "Pyramid/Client.h"

int main(int argc, char* argv[]) {
	if (argc > 1) {
		Pyramid::Client client;
		client.Send(argv[1]);
	}
	return EXIT_SUCCESS;
}
