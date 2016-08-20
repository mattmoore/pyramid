package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
	"time"
)

func handleConnection(conn net.Conn) {
	scanner := bufio.NewScanner(bufio.NewReader(conn))
	for scanner.Scan() {
		messageTime := time.Now()
		message := scanner.Text()
		fmt.Println(messageTime, ": ", message)
		conn.Write([]byte(fmt.Sprintf("received\n")))
	}
}

func main() {
	listen, _ := net.Listen("tcp", fmt.Sprintf(":%s", os.Args[1]))
	fmt.Println(fmt.Sprintf("Pyramid server listening on port %s", os.Args[1]))
	for {
		conn, _ := listen.Accept()
		go handleConnection(conn)
	}
}
