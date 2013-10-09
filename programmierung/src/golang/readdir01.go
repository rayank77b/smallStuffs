package main

import (
"fmt"
"io/ioutil"
)



func main() {

    fi, _ := ioutil.ReadDir("/tmp")
    
    for _, f := range fi {
        fmt.Println("name: ", f.Name())
    }

}
