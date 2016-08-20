package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
)

func consoleReady() {
	fmt.Print("> ")
}

func main() {
	conn, err := net.Dial("tcp", fmt.Sprintf("%s:%s", os.Args[1], os.Args[2]))
	if err != nil {
		fmt.Println(err)
	}

	commandScanner := bufio.NewScanner(bufio.NewReader(os.Stdin))
	responseScanner := bufio.NewScanner(bufio.NewReader(conn))

	consoleReady()

	for commandScanner.Scan() {
		text := commandScanner.Text()
		fmt.Fprintf(conn, text+"\n")

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
