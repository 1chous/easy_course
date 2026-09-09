package main

import (
	"fmt"
	"net"
	"os"
)

func main() {
	conn, err := net.Dial("tcp", "localhost:8080")
	if err != nil {
		fmt.Println("Error with dial:", err)
		os.Exit(1)
	}
	defer conn.Close()
	buf := make([]byte, 1024)
	n, err := conn.Read(buf)
	if err != nil {
		fmt.Println("Error with read:", err)
		os.Exit(2)
	}
	if n != 3  {
		fmt.Println("Wrong buffer size")
		os.Exit(3)
	}
	if string(buf[:n]) != "OK\n"  {
		fmt.Println("Wrong read value")
		os.Exit(4)
	}
}