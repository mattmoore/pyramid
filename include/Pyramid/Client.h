#include <iostream>
#include <SDL.h>
#include <SDL_net.h>

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
