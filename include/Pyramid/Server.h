#include <iostream>
#include <SDL.h>
#include <SDL_net.h>

namespace Pyramid {
  class Server {
  private:
    int port;
    TCPsocket server, client;
    IPaddress ip, *remote_ip;		
    int quit, quit2;
  
  public:
    Server(int);
    ~Server();
    void Run();
  };
}
