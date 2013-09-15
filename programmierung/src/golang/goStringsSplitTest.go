package main

import (
	"fmt"
	"strings"
	"path"
)


func main() {
    currPath := "/"
    
    segments := strings.Split("/blub/asdo/asl.txt", "/")
    
    for _, segment := range segments {
        fmt.Println(segment)
        
        currPath := path.Join(currPath, segment)
        fmt.Println(currPath)
    }
    
    
}
