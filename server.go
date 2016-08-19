package main

import (
	"bufio"
	"fmt"
	"net"
	"time"
	"strings"
)

func handleConnection(conn net.Conn) {
	reader := bufio.NewReader(conn)
	for {
		messageTime := time.Now()
		message, err := reader.ReadString('\n')
		if err != nil {
			break
		} else {
			message = strings.Replace(message, "\n", "", -1)
			fmt.Println(messageTime, ": ", message)
			conn.Write([]byte(fmt.Sprintf("received\n")))
		}
	}
}

func main() {
	listen, _ := net.Listen("tcp", ":8080")

	for {
		conn, _ := listen.Accept()
		go handleConnection(conn)
	}
}
