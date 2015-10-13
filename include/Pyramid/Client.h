#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>

namespace Pyramid {
	class Client {
	private:
		std::string address;
		int port;
		TCPsocket server;
		IPaddress ip;
		std::string command;
	public:
		Client(std::string, int);
		void Send(std::string);
		~Client();
	};
}