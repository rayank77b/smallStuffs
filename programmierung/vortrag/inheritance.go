package main
import . "fmt"

type Tier struct {
    fuesse int
}
func (t *Tier) getFuesse() int {
    return t.fuesse
}

type Hund struct {
    Tier  // anonymous field
}
func (h *Hund) say() string {
    return "Wau"
}

type Ente struct {
    Tier 
}
func (e *Ente) say() string {
    return "Krja"
}

func main() {
    hund := Hund{Tier{4}}

    Println("fuesse: ", hund.getFuesse())
    Println("say:    ", hund.say())
    
    ente := Ente{Tier{2}}
    Println("fuesse: ", ente.getFuesse())
    Println("say:    ", ente.say())
}
