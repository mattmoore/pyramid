#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>

namespace Pyramid {
	class Client {
	private:
		TCPsocket server;
		IPaddress ip;		
		std::string command;
	public:
		Client();
		void Send(std::string message);
		~Client();
	};
}