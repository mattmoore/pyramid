#include <iostream>
#include <SDL.h>

namespace Pyramid {
	class Renderer {
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;

    int posX = 100;
    int posY = 200;
    int sizeX = 300;
    int sizeY = 400;

    bool CreateWindow();
    bool CreateRenderer();
	public:
		Renderer();
		~Renderer();
	};
}