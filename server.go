package main

import (
  "bufio"
  "fmt"
  "net"
  "os"
  "time"
)

func main() {
  listen, _ := net.Listen("tcp", fmt.Sprintf(":%s", os.Args[1]))
  fmt.Println(fmt.Sprintf("Pyramid server listening on port %s", os.Args[1]))
  for {
  	conn, _ := listen.Accept()
  	go handleConnection(conn)
  }
}

func handleConnection(conn net.Conn) {
  scanner := bufio.NewScanner(bufio.NewReader(conn))
  for scanner.Scan() {
  	messageTime := time.Now()
  	message := scanner.Text()
  	fmt.Println(messageTime, ": ", message)
  	executeCommand(message)
  	conn.Write([]byte(fmt.Sprintf("received\n")))
  }
}

func executeCommand(cmd string) {
  commands := map[string]func(){
  	"\\server q": execQuit,
  }
  if commands[cmd] != nil {
  	fmt.Println(fmt.Sprintf("Received command: %s", cmd))
  	commands[cmd]()
  }
}

func execQuit() {
  fmt.Println("Executing quit")
}
