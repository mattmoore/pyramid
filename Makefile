CC=clang++
SDL_FLAGS=`sdl2-config --cflags --libs` -lSDL2_net -lSDL2_image

client:
	if [ ! -e "bin" ]; then mkdir bin; fi;
	$(CC) -Wall -std=c++14 -pthread $(SDL_FLAGS) -Iinclude Pyramid.cpp src/Pyramid/Client.cpp src/Pyramid/Renderer.cpp -o bin/pyramid

server:
	if [ ! -e "bin" ]; then mkdir bin; fi;
	$(CC) -Wall -std=c++14 -pthread $(SDL_FLAGS) -Iinclude PyramidServer.cpp src/Pyramid/Server.cpp -o bin/pyramid-server

clean:
	if [ -e "bin" ]; then rm -rf bin; fi;

