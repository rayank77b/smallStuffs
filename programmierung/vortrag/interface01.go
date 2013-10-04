package main

import (
    "fmt"
    "math"
)

// definiere Figur
type Figur interface {
    Name() string
    Umfang() float64
    Flaeche() float64
}

// Kreis
type Kreis struct {
    r float64
}
func (k *Kreis) Name() string {
    return "Kreis"
}
func (k *Kreis) Umfang() float64 {
    return 2*math.Pi*k.r
}
func (k *Kreis) Flaeche() float64 {
    return math.Pi*k.r*k.r
}

// Quadrat
type Quadrat struct {
    a float64
}
func (q *Quadrat) Name() string {
    return "Quadrat"
}
func (q *Quadrat) Umfang() float64 {
    return 4*q.a
}
func (q *Quadrat) Flaeche() float64 {
    return q.a*q.a
}

// Rechteck
type Rechteck struct {
    a float64
    b float64
}
func (r *Rechteck) Name() string {
    return "Rechteck"
}
func (r *Rechteck) Umfang() float64 {
    return r.a*2 + r.b*2
}
func (r *Rechteck) Flaeche() float64 {
    return r.a*r.b
}

// Funktion fuer alle
func Ausgabe(f Figur) {
    fmt.Println("Name:    ", f.Name())
    fmt.Println("Umfang:  ", f.Umfang())
    fmt.Println("Flaeche: ", f.Flaeche())
    fmt.Println("---------------------------------------------------")
}

func main() {

    k:=&Kreis{r:1.2}
    r:=&Rechteck{a:2.2, b:49}
    q:=&Quadrat{a:43.23}
    
    Ausgabe(k)
    Ausgabe(q)
    Ausgabe(r)

}



