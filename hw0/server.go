package main

import (
	"fmt"
	"net"
	"os"
)

func main() {
	ln, err := net.Listen("tcp", "0.0.0.0:8080")
	if err != nil {
		fmt.Println("Error with listen:", err)
		os.Exit(1)
	}
	defer ln.Close()
	for {
		conn, err := ln.Accept()
		if err != nil {
			fmt.Println("Error with accept:", err)
			continue
		}
		conn.Write([]byte("OK\n"))
		conn.Close()
	}
}
