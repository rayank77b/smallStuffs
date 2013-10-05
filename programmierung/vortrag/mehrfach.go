package main

import "fmt"

type Camera struct { } 
func (_ Camera) takePicture() string {
    return "Click"
}

type Phone struct { } 
func (_ Phone ) call() string {
    return "Ring Ring"
}

type Blub struct { }
func (_ Blub) call() string {
    return "blubbuoolbubu"
}


type CameraPhone struct {
    Camera //has anonymous camera
//    Phone //has anonymous phone 
    Blub
}

func main() {
    cp := new (CameraPhone)
    fmt.Println("Our new CameraPhone exhibits multiple behaviors ...")
    fmt.Println("It can take a picture: ", cp.takePicture()) 
    fmt.Println("It can also make calls: ", cp.call()) 
}
