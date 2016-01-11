# pyramid

Pyramid is a client/server data visualization tool for rendering data points over time in 3-dimensional space with the third dimension representing time. It is intended to function in real-time by receiving updates to the data set on the server and pushing those updates out to the connected clients who are viewing them. The server side only maintains the datasets and streams them to connected clients.

Rendering takes place on the client side via OpenGL. Clients with appropriate permissions will be able to update the data stream live.

Eventually, a WebGL renderer that can be embedded in web pages would be nice to have.

## Build Instructions:

1. Install SDL2/Net and SDL2/Image on your platform of choice.
1. Run "make clean" to ensure clean build.
1. Run "make server" to build server.
1. Run "make client" to build client.
