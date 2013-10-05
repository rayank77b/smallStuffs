package main

import "fmt"

type A struct {
  name string
}

func (a A) Out() {
    fmt.Println(a.name)
}
func (a A) Set(s string) {
    a.name=s
}
func (a *A) Set2(s string) {
    a.name=s
}

func main() {

    a:=A{name:"blub"}
    
    a.Out()
    a.Set2("aaaaa")
    a.Out()
    
}
