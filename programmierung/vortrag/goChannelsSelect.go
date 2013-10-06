package main

import (
    . "fmt"
    "time"
)

func sender1(c chan int) {
    for i := 1; i < 10; i++ {
        c <- i
    }   
    close(c)
}

func sender2(c chan string) {
    a:=""
    for i := 1; i < 10; i++ {
        a = a+"a"
        c <- a
    }   
    close(c)
}


func empfaenger(c1 chan int, c2 chan string) {
    c1_closed, c2_closed := false, false
    for {
        if (c1_closed && c2_closed) { return }
        Println("Waiting ...")
        select {
        case i, ok := <-c1:
            if (!ok) {
                c1_closed = true
                Println(" ... integer channel closed!")
            } else {
                Println("i: ", i)
            }   
        case a, ok := <-c2:
            if (!ok) {
                c2_closed = true
                Println(" ... string channel closed!")
            } else {
                Println("a: ", a)
            }   
        }   
    }   
}

func main() {
    c1 := make(chan int)
    c2 := make(chan string)

    go sender1(c1)
    go sender2(c2)

    go empfaenger(c1, c2)

    time.Sleep(2 * 1e9)
}
