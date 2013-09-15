package main

import (
	"fmt"
)

// CONSTANTS
const (
	ERROR = -(1 + iota)
	SET 
	DELETE
)

func main() {
    fmt.Println(ERROR)
    fmt.Println(SET)
    fmt.Println(DELETE)
}
