package main

import (
	"fmt"
)

func main() {
    var m map[string]int     // define
    m = make(map[string]int) // init
    
    m["blub"]=2349;
    m["test"]=3494;
    m["dfo"]=2340;
    
	for key, value := range m {
        fmt.Println("Key:", key, "Value:", value)
    }
    fmt.Println()
    
    v, ok := m["test"]
    if ok {
        fmt.Println("v: ", v)
    }
}
