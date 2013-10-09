package main

import (
"fmt"
"runtime"
"strings"
)

func blub() {
    pc, file, line, _ := runtime.Caller(1)
    
    var fqViewName string = runtime.FuncForPC(pc).Name()
    fmt.Println("last index: ",strings.LastIndex(fqViewName, "."))
	var viewName string = fqViewName[strings.LastIndex(fqViewName, ".") + 1 : len(fqViewName)]
    
    fmt.Println("pc:   ", pc)   // programm counter
    fmt.Println("line: ", line)
    fmt.Println("file: ", file)
    fmt.Println("name: ", fqViewName)
    fmt.Println("name: ", viewName)
    
    fmt.Println("-------------------------------------------------------")
}

func aaa() {
    blub()
}

func main() {

    blub()
    aaa()    
    
    runtime.GC()  // run runtime garbage collector

}
