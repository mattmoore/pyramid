#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>

namespace Pyramid {
	class Server {
	private:
	  TCPsocket server, client;
	  IPaddress ip, *remoteIP;		
	  int quit, quit2;

	public:
		Server();
		~Server();
		void Run();
	};
}
