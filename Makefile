client:
	if [ ! -e "bin" ]; then mkdir bin; fi;
	g++ -Wall -std=c++11 -lSDL2 -lSDL2_image -lSDL2_net -I include Pyramid.cpp src/Pyramid/Client.cpp -o bin/pyramid

server:
	if [ ! -e "bin" ]; then mkdir bin; fi;
	g++ -Wall -std=c++11 -lSDL2 -lSDL2_image -lSDL2_net -I include PyramidServer.cpp src/Pyramid/Server.cpp -o bin/pyramid-server

clean:
	if [ -e "bin" ]; then rm -rf bin; fi;

