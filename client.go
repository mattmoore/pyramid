package main

import (
  "fmt"
  "net"
  "bufio"
  "os"
  "strings"
)

func main() {
  conn, err := net.Dial("tcp", "localhost:8080")
  if err != nil {
    fmt.Println(err)
  }

  command_reader := bufio.NewReader(os.Stdin)
  response_reader := bufio.NewReader(conn)

  for {
    fmt.Print("> ")
    text, _ := command_reader.ReadString('\n')
    text = strings.Replace(text, "\n", "", -1)
    fmt.Fprintf(conn, text + "\n")
    response, err := response_reader.ReadString('\n')
    if err != nil {
      conn.Close()
      fmt.Println("Lost connection")
      break
    } else {
      if response == "received\n" {
      }
    }
  }
}
