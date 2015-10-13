#include "Pyramid/Client.h"

namespace Pyramid {
  Client::Client(std::string address, int port) {
    this->address = address;
    this->port = port;
  }
  
  void Client::Send(std::string message) {
    this->command = message;
    this->command += '\0';
    
    if (SDLNet_Init() < 0) {
      fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
      exit(EXIT_FAILURE);
    }
    
    if (SDLNet_ResolveHost(&ip, this->address.c_str(), this->port) < 0) {
      fprintf(stderr, "SDLNet_ResolveHost: %s\n", SDLNet_GetError());
      exit(EXIT_FAILURE);
    }
    
    if (!(server = SDLNet_TCP_Open(&ip))) {
      fprintf(stderr, "SDLNet_TCP_Open: %s\n", SDLNet_GetError());
      exit(EXIT_FAILURE);
    }
    
    int length = command.length();
    std::string length_str = std::to_string(length);

    SDLNet_TCP_Send(server, length_str.c_str(), 512);
    SDLNet_TCP_Send(server, command.c_str(), length);

    SDLNet_TCP_Close(server);
    SDLNet_Quit();
  }
  
  Client::~Client() {
 
  }
}
