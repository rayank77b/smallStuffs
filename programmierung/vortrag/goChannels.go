package main

import . "fmt"
import "time"

func sender(c chan int) {
    for i:=0; i<10; i++ {
        c<- i
    }
    c<- -1
}

func empfaenger(c chan int) {
    for {
        i:= <-c
        if i == -1 {
            break
        }
        Println("i: ", i)
    }
}

func main() {

    iCh:=make(chan int)
    go empfaenger(iCh)
    go sender(iCh)
    
    time.Sleep(5000000)
}
