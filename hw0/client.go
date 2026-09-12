package main

import (
	"io"
	"log"
	"net"
	"os"
)

func main() {
	conn, err := net.Dial("tcp", "localhost:8080")
	if err != nil {
		log.Println("Error with dial:", err)
		os.Exit(1)
	}
	defer conn.Close()
	data, err := io.ReadAll(conn)
	if err != nil {
		log.Println("Error with read:", err)
		os.Exit(2)
	}
	if string(data) != "OK\n" {
		log.Println("Wrong read value")
		os.Exit(3)
	}
}
