package main

import "fmt"

func blub(id int, names ...interface {}) {
    for _, name := range names {
        fmt.Println("id: ", id, "  name: ", name)
    }
}

func main() {
    blub(1, "ab")
    blub(2, "aa",23)
    blub(3, 4.7, "balu", 2)
}
