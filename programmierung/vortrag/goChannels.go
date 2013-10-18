package main

import . "fmt"
import "time"

func sender(c chan int) {
    for i:=0; i<100000; i++ {
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

func empfaenger2(c chan int) {
    for i := range c{
        Println("i: ", i)
    }
}

func main() {

    iCh:=make(chan int)
    go sender(iCh)
    time.Sleep(3000000000)
    go empfaenger(iCh)
    
    
    time.Sleep(5000000000)
}
