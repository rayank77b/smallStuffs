package main

import (
    . "fmt"
    "reflect"
)

type Invoice struct {
    Id          int64
    Created     int64
    Updated     int64
}



func out(i interface {}) {
    t := reflect.TypeOf(i)
    Println("Type: ", t)
    Println("Name: ",t.Name())
    n := t.NumField()
    Println("NumField: ",n)
    for i := 0; i < n; i++ {
        f := t.Field(i)
        Println("   f:    ", f)
        Println("   type: ", f.Type)
        Println("   name: ", f.Name)
        //Println("   kind: ", f.Kind())
    }
}

func main() {
    inv := Invoice{Id: 99, Created: 100, Updated: 200}
    out(Invoice{})
    Println("--------------------------------")
    out(inv)

}
