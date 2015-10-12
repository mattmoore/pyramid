client:
	if [ ! -e "bin" ]; then mkdir bin; fi;
	g++ -Wall -std=c++11 -lSDL2 -lSDL2_image -lSDL2_net Pyramid.cpp -o bin/pyramid

server:
	if [ ! -e "bin" ]; then mkdir bin; fi;
	g++ -Wall -std=c++11 -lSDL2 -lSDL2_image -lSDL2_net PyramidServer.cpp -o bin/pyramid-server

clean:
	if [ -e "bin" ]; then rm -rf bin; fi;

