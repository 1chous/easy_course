package main

import (
	"io"
	"log"
	"net"
)

func main() {
	ln, err := net.Listen("tcp", "0.0.0.0:8080")
	if err != nil {
		log.Fatal("Error with listen:", err)
	}
	defer ln.Close()
	for {
		conn, err := ln.Accept()
		if err != nil {
			log.Println("Error with accept:", err)
			continue
		}
		cnt, err := io.WriteString(conn, "OK\n")
		if err != nil {
			log.Println("Error with write:", err)
		} else if cnt != len("OK\n") {
			log.Println("Error with cnt bytes:", cnt)
		}
		err = conn.Close()
		if err != nil {
			log.Println("Error with close descriptor:", err)
		}
	}
}
