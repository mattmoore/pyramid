package main

import (
  "bufio"
  "fmt"
  "net"
  "os"
)

func main() {
  conn, err := net.Dial("tcp", fmt.Sprintf("%s:%s", os.Args[1], os.Args[2]))
  if err != nil {
  	fmt.Println(err)
  }

  consoleScanner := bufio.NewScanner(bufio.NewReader(os.Stdin))
  responseScanner := bufio.NewScanner(bufio.NewReader(conn))

  consoleReady()
  for consoleScanner.Scan() {
		executeCommand(consoleScanner.Text())
  	fmt.Fprintf(conn, fmt.Sprintf("%s\n", consoleScanner.Text()))
  	responseScanner.Scan()
  	if err := responseScanner.Err(); err != nil {
  		conn.Close()
  		fmt.Println("Lost connection")
  		break
  	} else {
  		consoleReady()
  	}
  }
}

func consoleReady() {
  fmt.Print("> ")
}

func executeCommand(cmd string) {
  commands := map[string]func(){
  	"\\q": execQuit,
  }
  if commands[cmd] != nil {
  	fmt.Println(fmt.Sprintf("Received command: %s", cmd))
  	commands[cmd]()
  }
}

func execQuit() {
  fmt.Println("Executing quit")
	os.Exit(0)
}
