package main

import "fmt"

type Bla int

func main() {

    var b Bla
    b=4
    
    fmt.Println(b)
    
    b2 := new(Bla)
    *b2=5
    fmt.Println(*b2)

}
