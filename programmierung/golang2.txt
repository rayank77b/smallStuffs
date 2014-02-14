package main

import "fmt"
import "time"

func f(msg string) {
    fmt.Println(msg)
    return
}

func main() {
    go f("goroutine")

    go func(msg string) {
        fmt.Println(msg)
        return
    }("going")

    time.Sleep(1000*2)

    return
}
################################################################################
    var wg sync.WaitGroup
    
    conn, _ := net.Dial("tcp", "irc.freenode.net:6667")

    reader := bufio.NewReader(conn)
    
    wg.Add(1)
    
    go func() {
        defer wg.Done()
        str, err := reader.ReadString('\n')
        if err != nil {
            // handle it
            fmt.Println(err)
        }
        fmt.Println(str)
    }()

    wg.Wait()
################################################################################
type Pair struct {
	a int
	b int
}
type PairAndFreq struct {
	Pair
	Freq int
}

type PairSlice []PairAndFreq

type PairSliceSlice []PairSlice

func (pss PairSliceSlice) Weed() {
	fmt.Println(pss[0])
	weed(&pss[0])
	fmt.Println(pss[0])
}

func weed(ps *PairSlice) {

	m := make(map[Pair]int)

	for _, v := range *ps {
		m[v.Pair]++
	}
	*ps = (*ps)[:0]
	for k, v := range m {

		*ps = append(*ps, PairAndFreq{k, v})

	}
	fmt.Println(*ps)
}

func main() {

	pss := make(PairSliceSlice, 12)

	pss[0] = PairSlice{PairAndFreq{Pair{1, 1}, 1}, PairAndFreq{Pair{1, 1}, 1}}

	pss.Weed()
}
################################################################################
func handler(w http.ResponseWriter, r *http.Request) {
    fmt.Fprintf(w, "Hi there, I love %s!", r.URL.Path[1:])
}

func main() {
    http.HandleFunc("/", handler)
    http.ListenAndServe(":8080", nil)
}
################################################################################
package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
)

type Page struct {
    Title string
    Body  []byte
}

func (p *Page) save() error {
    filename := p.Title + ".txt"
    return ioutil.WriteFile(filename, p.Body, 0600)
}

func loadPage(title string) (*Page, error) {
    filename := title + ".txt"
    body, err := ioutil.ReadFile(filename)
    if err != nil {
        return nil, err
    }
    return &Page{Title: title, Body: body}, nil
}

func main() {
    p1 := &Page{Title: "TestPage", Body: []byte("This is a sample Page.")}
    p1.save()
    p2, _ := loadPage("TestPage")
    fmt.Println(string(p2.Body))
}
################################################################################



################################################################################

























