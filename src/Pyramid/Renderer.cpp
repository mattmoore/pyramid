#include "Pyramid/Renderer.h"

namespace Pyramid {
	Renderer::Renderer() {

	}

  bool Renderer::CreateWindow() {
    this->window = SDL_CreateWindow("Pyramid", this->posX, this->posY, this->sizeX, this->sizeY, 0);
    if (this->window == nullptr) {
      std::cout << "Failed to create window : " << SDL_GetError();
      return false;
    }
    return true;
  }

  bool Renderer::CreateRenderer() {
    this->renderer = SDL_CreateRenderer(this->window, -1, 0);
    if (this->renderer == nullptr) {
      std::cout << "Failed to create renderer : " << SDL_GetError();
      return false;
    }
    return true;
  }

	Renderer::~Renderer() {

	}
}