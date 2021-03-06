package main

import "fmt"

func main() {
    fmt.Println("Hello,blub")
}
---------------------------------
package main

import (
    "fmt"
    "net"
    "os"
    "time"
)

func main() {
    fmt.Println("Welcome to the playground!")

    fmt.Println("The time is", time.Now())

    fmt.Println("And if you try to open a file:")
    fmt.Println(os.Open("gotest01.go"))

    fmt.Println("Or access the network:")
    fmt.Println(net.Dial("tcp", "google.com:80"))
}
---------------------------------
fmt.Println("My favorite number is", rand.Intn(10))
math.Nextafter(2, 3)
math.Pi
---------------------------------
func split(sum int) (x, y int) {
    x = sum * 4 / 9
    y = sum - x
    return
}

bool
string
int  int8  int16  int32  int64
uint uint8 uint16 uint32 uint64 uintptr
byte // alias for uint8
rune // alias for int32
     // represents a Unicode code point
float32 float64
complex64 complex128

const Pi = 3.14

for i := 0; i < 10; i++ {
for ; sum < 1000; {
for sum < 1000 {    # kein while
for { }  # forever loop
if x < 0 {
if v := math.Pow(x, n); v < lim {

A struct is a collection of fields. 
type Vertex struct {
    X int
    Y int
}
func main() {
    v := Vertex{1, 2}
    v.X = 4
    fmt.Println(v.X)
}
Go has pointers, but no pointer arithmetic.
Struct fields can be accessed through a struct pointer. The indirection through the pointer is transparent. 

p = Vertex{1, 2}  // has type Vertex
q = &Vertex{1, 2} // has type *Vertex
r = Vertex{X: 1}  // Y:0 is implicit
s = Vertex{}      // X:0 and Y:0

The expression new(T) allocates a zeroed T value and returns a pointer to it. 
var t *T = new(T)
t := new(T)

A slice points to an array of values and also includes a length.
[]T is a slice with elements of type T. 
p := []int{2, 3, 5, 7, 11, 13}
for i := 0; i < len(p); i++ {
    fmt.Printf("p[%d] == %d\n", i, p[i])
}
s[lo:hi]
evaluates to a slice of the elements from lo through hi-1, inclusive. Thus
s[lo:lo]
is empty and
s[lo:lo+1]
has one element. 
p == [2 3 5 7 11 13]
p[1:4] == [3 5 7]
p[:3] == [2 3 5]
p[4:] == [11 13]

Slices are created with the make function. It works by allocating a zeroed array and returning a slice that refers to that array
a := make([]int, 5)  // len(a)=5
b := make([]int, 0, 5) // len(b)=0, cap(b)=5
b = b[:cap(b)] // len(b)=5, cap(b)=5
b = b[1:]      // len(b)=4, cap(b)=4

The zero value of a slice is nil.
A nil slice has a length and capacity of 0. 

The range form of the for loop iterates over a slice or map. 
var pow = []int{1, 2, 4, 8, 16, 32, 64, 128}
for i, v := range pow {
    fmt.Printf("2**%d = %d\n", i, v)
}

func Pic(dx, dy int) [][]uint8 {
    r := make([][]uint8, dx)
    for i := range r {
        r[i]=make([]uint8, dy)
        for j := range r[i] {
            r[i][j]=uint8(j)
        }
    }
    return r
}

A map maps keys to values.
Maps must be created with make (not new) before use; the nil map is empty and cannot be assigned to. 

type Vertex struct {
    Lat, Long float64
}

var m map[string]Vertex

func main() {
    m = make(map[string]Vertex)
    m["Bell Labs"] = Vertex{
        40.68433, -74.39967,
    }
    fmt.Println(m["Bell Labs"])

Map literals are like struct literals, but the keys are required. 
var m = map[string]Vertex{
    "Bell Labs": Vertex{
        40.68433, -74.39967,
    },
    "Google": Vertex{
        37.42202, -122.08408,
    },
}
var m = map[string]Vertex{
    "Bell Labs": {40.68433, -74.39967},
    "Google":    {37.42202, -122.08408},
}

Insert or update an element in map m:
m[key] = elem
Retrieve an element:
elem = m[key]
Delete an element:
delete(m, key)
Test that a key is present with a two-value assignment:
elem, ok = m[key]
If key is in m, ok is true. If not, ok is false and elem is the zero value for the map's element type. Similarly, when reading from a map if the key is not present the result is the zero value for the map's element type. 

 Fields splits the string s around each instance of one or more consecutive white space characters, as defined by unicode.IsSpace, returning an array of substrings of s or an empty list if s contains only white space.
fmt.Printf("Fields are: %q", strings.Fields("  foo bar  baz   "))

func WordCount(s string) map[string]int {
     
    var r map[string]int
    r = make(map[string]int)
    
    sa := strings.Fields(s)
    
    for _, key := range(sa) {
        elem, ok := r[key]
        if ok {
            r[key]=elem+1
        } else {
            r[key]=1
        }
    }
    return r
}

hypot := func(x, y float64) float64 {
   return math.Sqrt(x*x + y*y)
}
fmt.Println(hypot(3, 4))

Go functions may be closures. A closure is a function value that references variables from outside its body. The function may access and assign to the referenced variables; in this sense the function is "bound" to the variables. For example, the adder function returns a closure. Each closure is bound to its own sum variable. 

func adder() func(int) int {
    sum := 0
    return func(x int) int {
        sum += x
        return sum
    }
}

func main() {
    pos, neg := adder(), adder()
    for i := 0; i < 10; i++ {
        fmt.Println(
            pos(i),
            neg(-2*i),
        )
    }
}

switch os := runtime.GOOS; os {
    case "darwin":
        fmt.Println("OS X.")
    case "linux":
        fmt.Println("Linux.")
    default:
        // freebsd, openbsd,
        // plan9, windows...
        fmt.Printf("%s.", os)
}

today := time.Now().Weekday()
switch time.Saturday {
    case today + 0:
        fmt.Println("Today.")
    case today + 1:
        fmt.Println("Tomorrow.")
    case today + 2:
        fmt.Println("In two days.")
    default:
        fmt.Println("Too far away.")
    }

    t := time.Now()
    switch {
    case t.Hour() < 12:
        fmt.Println("Good morning!")
    case t.Hour() < 17:
        fmt.Println("Good afternoon.")
    default:
        fmt.Println("Good evening.")
    }

Go does not have classes. However, you can define methods on struct types. The method receiver appears in its own argument list between the func keyword and the method name. 

type Vertex struct {
    X, Y float64
}

func (v *Vertex) Abs() float64 {
    return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func main() {
    v := &Vertex{3, 4}
    fmt.Println(v.Abs())
}

In fact, you can define a method on any type you define in your package, not just structs. You cannot define a method on a type from another package, or on a basic type

There are two reasons to use a pointer receiver. First, to avoid copying the value on each method call (more efficient if the value type is a large struct). Second, so that the method can modify the value that its receiver points to. 

An interface type is defined by a set of methods. A value of interface type can hold any value that implements those methods. 

type Abser interface {
    Abs() float64
}

func main() {
    var a Abser
    f := MyFloat(-math.Sqrt2)
    v := Vertex{3, 4}

    a = f  // a MyFloat implements Abser
    a = &v // a *Vertex implements Abser
    a = v  // a Vertex, does NOT
    // implement Abser

A type implements an interface by implementing the methods. There is no explicit declaration of intent. 

type Reader interface {
    Read(b []byte) (n int, err error)
}
type Writer interface {
    Write(b []byte) (n int, err error)
}
type ReadWriter interface {
    Reader
    Writer
}
func main() {
    var w Writer

    // os.Stdout implements Writer
    w = os.Stdout

    fmt.Fprintf(w, "hello, writer\n")
}

 An error is anything that can describe itself as an error string. The idea is captured by the predefined, built-in interface type, error, with its single method, Error, returning a string:
type error interface {
    Error() string
}

"net/http"
type Hello struct{}

func (h Hello) ServeHTTP(w http.ResponseWriter,r *http.Request) {
    fmt.Fprint(w, "Hello!")
}

func main() {
    var h Hello
    http.ListenAndServe("localhost:4000", h)
}

package http
type Handler interface {
    ServeHTTP(w ResponseWriter, r *Request)
}

Package image defines the Image interface: 
m := image.NewRGBA(image.Rect(0, 0, 100, 100))
fmt.Println(m.Bounds())
fmt.Println(m.At(0, 0).RGBA())

A goroutine is a lightweight thread managed by the Go runtime.
go f(x, y, z)
starts a new goroutine running
f(x, y, z)
The evaluation of f, x, y, and z happens in the current goroutine and the execution of f happens in the new goroutine. Goroutines run in the same address space, so access to shared memory must be synchronized. The sync package provides useful primitives, although you won't need them much in Go as there are other primitives. 

func say(s string) {
    for i := 0; i < 5; i++ {
        time.Sleep(100 * time.Millisecond)
        fmt.Println(s)
    }
}

func main() {
    go say("world")
    say("hello")
}

Channels are a typed conduit through which you can send and receive values with the channel operator, <-.
ch <- v    // Send v to channel ch.
v := <-ch  // Receive from ch, and
           // assign value to v.
(The data flows in the direction of the arrow.)
Like maps and slices, channels must be created before use:
ch := make(chan int)
By default, sends and receives block until the other side is ready. This allows goroutines to synchronize without explicit locks or condition variables. 

func sum(a []int, c chan int) {
    sum := 0
    for _, v := range a {
        sum += v
    }
    c <- sum // send sum to c
}

func main() {
    a := []int{7, 2, 8, -9, 4, 0}

    c := make(chan int)
    go sum(a[:len(a)/2], c)
    go sum(a[len(a)/2:], c)
    x, y := <-c, <-c // receive from c

    fmt.Println(x, y, x+y)
}

Channels can be buffered. Provide the buffer length as the second argument to make to initialize a buffered channel:
ch := make(chan int, 100)
Sends to a buffered channel block only when the buffer is full. Receives block when the buffer is empty.

 A sender can close a channel to indicate that no more values will be sent. Receivers can test whether a channel has been closed by assigning a second parameter to the receive expression: after
v, ok := <-ch
ok is false if there are no more values to receive and the channel is closed.
Note: Only the sender should close a channel, never the receiver. Sending on a closed channel will cause a panic.
Another note: Channels aren't like files; you don't usually need to close them. Closing is only necessary when the receiver must be told there are no more values coming, such as to terminate a range loop. 

The select statement lets a goroutine wait on multiple communication operations. A select blocks until one of its cases can run, then it executes that case. It chooses one at random if multiple are ready. 

func fibonacci(c, quit chan int) {
    x, y := 0, 1
    for {
        select {
        case c <- x:    # sende x nach c
            x, y = y, x+y
        case <-quit:    # empfange von quit
            fmt.Println("quit")
            return
        }
    }
}

func main() {
    c := make(chan int)
    quit := make(chan int)
    go func() {
        for i := 0; i < 10; i++ {
            fmt.Println(<-c)
        }
        quit <- 0
    }()
    fibonacci(c, quit)
}
The default case in a select is run if no other case is ready. 
func main() {
    tick := time.Tick(100 * time.Millisecond)
    boom := time.After(500 * time.Millisecond)
    for {
        select {
        case <-tick:
            fmt.Println("tick.")
        case <-boom:
            fmt.Println("BOOM!")
            return
        default:
            fmt.Println("    .")
            time.Sleep(50 * time.Millisecond)
        }
    }
}

Channels
Like maps, channels are allocated with make, and the resulting value acts as a reference to an underlying data structure. If an optional integer parameter is provided, it sets the buffer size for the channel. The default is zero, for an unbuffered or synchronous channel. 
ci := make(chan int)            // unbuffered channel of integers
cj := make(chan int, 0)         // unbuffered channel of integers
cs := make(chan *os.File, 100)  // buffered channel of pointers to Files

 Unbuffered channels combine communication—the exchange of a value—with synchronization—guaranteeing that two calculations (goroutines) are in a known state.

There are lots of nice idioms using channels. Here's one to get us started. In the previous section we launched a sort in the background. A channel can allow the launching goroutine to wait for the sort to complete. 
c := make(chan int)  // Allocate a channel.
// Start the sort in a goroutine; when it completes, signal on the channel.
go func() {
    list.Sort()
    c <- 1  // Send a signal; value does not matter.
}()
doSomethingForAWhile()
<-c   // Wait for sort to finish; discard sent value.

 Receivers always block until there is data to receive. If the channel is unbuffered, the sender blocks until the receiver has received the value. If the channel has a buffer, the sender blocks only until the value has been copied to the buffer; if the buffer is full, this means waiting until some receiver has retrieved a value.

A buffered channel can be used like a semaphore, for instance to limit throughput. In this example, incoming requests are passed to handle, which receives a value from the channel, processes the request, and then sends a value back to the channel to ready the "semaphore" for the next consumer. The capacity of the channel buffer limits the number of simultaneous calls to process, so during initialization we prime the channel by filling it to capacity. 

var sem = make(chan int, MaxOutstanding)

func handle(r *Request) {
    <-sem          // Wait for active queue to drain.
    process(r)     // May take a long time.
    sem <- 1       // Done; enable next request to run.
}

func init() {
    for i := 0; i < MaxOutstanding; i++ {
        sem <- 1
    }
}

func Serve(queue chan *Request) {
    for {
        req := <-queue
        go handle(req)  // Don't wait for handle to finish.
    }
}

Because data synchronization occurs on a receive from a channel (that is, the send "happens before" the receive; see The Go Memory Model), acquisition of the semaphore must be on a channel receive, not a send.

This design has a problem, though: Serve creates a new goroutine for every incoming request, even though only MaxOutstanding of them can run at any moment. As a result, the program can consume unlimited resources if the requests come in too fast. We can address that deficiency by changing Serve to gate the creation of the goroutines. 
func Serve(queue chan *Request) {
    for req := range queue {
        <-sem
        go func() {
            process(req)
            sem <- 1
        }()
    }
}
Another solution that manages resources well is to start a fixed number of handle goroutines all reading from the request channel. The number of goroutines limits the number of simultaneous calls to process. This Serve function also accepts a channel on which it will be told to exit; after launching the goroutines it blocks receiving from that channel. 

func handle(queue chan *Request) {
    for r := range queue {
        process(r)
    }
}

func Serve(clientRequests chan *Request, quit chan bool) {
    // Start handlers
    for i := 0; i < MaxOutstanding; i++ {
        go handle(clientRequests)
    }
    <-quit  // Wait to be told to exit.
}


Channels of channels

One of the most important properties of Go is that a channel is a first-class value that can be allocated and passed around like any other. A common use of this property is to implement safe, parallel demultiplexing.

In the example in the previous section, handle was an idealized handler for a request but we didn't define the type it was handling. If that type includes a channel on which to reply, each client can provide its own path for the answer. Here's a schematic definition of type Request.

type Request struct {
    args        []int
    f           func([]int) int
    resultChan  chan int
}

The client provides a function and its arguments, as well as a channel inside the request object on which to receive the answer.

func sum(a []int) (s int) {
    for _, v := range a {
        s += v
    }
    return
}

request := &Request{[]int{3, 4, 5}, sum, make(chan int)}
// Send request
clientRequests <- request
// Wait for response.
fmt.Printf("answer: %d\n", <-request.resultChan)

On the server side, the handler function is the only thing that changes.

func handle(queue chan *Request) {
    for req := range queue {
        req.resultChan <- req.f(req.args)
    }
}

There's clearly a lot more to do to make it realistic, but this code is a framework for a rate-limited, parallel, non-blocking RPC system, and there's not a mutex in sight.
Parallelization

Another application of these ideas is to parallelize a calculation across multiple CPU cores. If the calculation can be broken into separate pieces that can execute independently, it can be parallelized, with a channel to signal when each piece completes.

Let's say we have an expensive operation to perform on a vector of items, and that the value of the operation on each item is independent, as in this idealized example.

type Vector []float64

// Apply the operation to v[i], v[i+1] ... up to v[n-1].
func (v Vector) DoSome(i, n int, u Vector, c chan int) {
    for ; i < n; i++ {
        v[i] += u.Op(v[i])
    }
    c <- 1    // signal that this piece is done
}

We launch the pieces independently in a loop, one per CPU. They can complete in any order but it doesn't matter; we just count the completion signals by draining the channel after launching all the goroutines.

const NCPU = 4  // number of CPU cores

func (v Vector) DoAll(u Vector) {
    c := make(chan int, NCPU)  // Buffering optional but sensible.
    for i := 0; i < NCPU; i++ {
        go v.DoSome(i*len(v)/NCPU, (i+1)*len(v)/NCPU, u, c)
    }
    // Drain the channel.
    for i := 0; i < NCPU; i++ {
        <-c    // wait for one task to complete
    }
    // All done.
}

The current implementation of the Go runtime will not parallelize this code by default. It dedicates only a single core to user-level processing. An arbitrary number of goroutines can be blocked in system calls, but by default only one can be executing user-level code at any time. It should be smarter and one day it will be smarter, but until it is if you want CPU parallelism you must tell the run-time how many goroutines you want executing code simultaneously. There are two related ways to do this. Either run your job with environment variable GOMAXPROCS set to the number of cores to use or import the runtime package and call runtime.GOMAXPROCS(NCPU). A helpful value might be runtime.NumCPU(), which reports the number of logical CPUs on the local machine. Again, this requirement is expected to be retired as the scheduling and run-time improve.

Be sure not to confuse the ideas of concurrency—structuring a program as independently executing components—and parallelism—executing calculations in parallel for efficiency on multiple CPUs. Although the concurrency features of Go can make some problems easy to structure as parallel computations, Go is a concurrent language, not a parallel one, and not all parallelization problems fit Go's model. For a discussion of the distinction, see the talk cited in this blog post.
A leaky buffer

The tools of concurrent programming can even make non-concurrent ideas easier to express. Here's an example abstracted from an RPC package. The client goroutine loops receiving data from some source, perhaps a network. To avoid allocating and freeing buffers, it keeps a free list, and uses a buffered channel to represent it. If the channel is empty, a new buffer gets allocated. Once the message buffer is ready, it's sent to the server on serverChan.

var freeList = make(chan *Buffer, 100)
var serverChan = make(chan *Buffer)

func client() {
    for {
        var b *Buffer
        // Grab a buffer if available; allocate if not.
        select {
        case b = <-freeList:
            // Got one; nothing more to do.
        default:
            // None free, so allocate a new one.
            b = new(Buffer)
        }
        load(b)              // Read next message from the net.
        serverChan <- b      // Send to server.
    }
}

The server loop receives each message from the client, processes it, and returns the buffer to the free list.

func server() {
    for {
        b := <-serverChan    // Wait for work.
        process(b)
        // Reuse buffer if there's room.
        select {
        case freeList <- b:
            // Buffer on free list; nothing more to do.
        default:
            // Free list full, just carry on.
        }
    }
}

The client attempts to retrieve a buffer from freeList; if none is available, it allocates a fresh one. The server's send to freeList puts b back on the free list unless the list is full, in which case the buffer is dropped on the floor to be reclaimed by the garbage collector. (The default clauses in the select statements execute when no other case is ready, meaning that the selects never block.) This implementation builds a leaky bucket free list in just a few lines, relying on the buffered channel and the garbage collector for bookkeeping.
Errors

Library routines must often return some sort of error indication to the caller. As mentioned earlier, Go's multivalue return makes it easy to return a detailed error description alongside the normal return value. By convention, errors have type error, a simple built-in interface.

type error interface {
    Error() string
}

A library writer is free to implement this interface with a richer model under the covers, making it possible not only to see the error but also to provide some context. For example, os.Open returns an os.PathError.

// PathError records an error and the operation and
// file path that caused it.
type PathError struct {
    Op string    // "open", "unlink", etc.
    Path string  // The associated file.
    Err error    // Returned by the system call.
}

func (e *PathError) Error() string {
    return e.Op + " " + e.Path + ": " + e.Err.Error()
}

PathError's Error generates a string like this:

open /etc/passwx: no such file or directory

Such an error, which includes the problematic file name, the operation, and the operating system error it triggered, is useful even if printed far from the call that caused it; it is much more informative than the plain "no such file or directory".

When feasible, error strings should identify their origin, such as by having a prefix naming the operation or package that generated the error. For example, in package image, the string representation for a decoding error due to an unknown format is "image: unknown format".

Callers that care about the precise error details can use a type switch or a type assertion to look for specific errors and extract details. For PathErrors this might include examining the internal Err field for recoverable failures.

for try := 0; try < 2; try++ {
    file, err = os.Create(filename)
    if err == nil {
        return
    }
    if e, ok := err.(*os.PathError); ok && e.Err == syscall.ENOSPC {
        deleteTempFiles()  // Recover some space.
        continue
    }
    return
}

The second if statement here is another type assertion. If it fails, ok will be false, and e will be nil. If it succeeds, ok will be true, which means the error was of type *os.PathError, and then so is e, which we can examine for more information about the error.
Panic

The usual way to report an error to a caller is to return an error as an extra return value. The canonical Read method is a well-known instance; it returns a byte count and an error. But what if the error is unrecoverable? Sometimes the program simply cannot continue.

For this purpose, there is a built-in function panic that in effect creates a run-time error that will stop the program (but see the next section). The function takes a single argument of arbitrary type—often a string—to be printed as the program dies. It's also a way to indicate that something impossible has happened, such as exiting an infinite loop.

// A toy implementation of cube root using Newton's method.
func CubeRoot(x float64) float64 {
    z := x/3   // Arbitrary initial value
    for i := 0; i < 1e6; i++ {
        prevz := z
        z -= (z*z*z-x) / (3*z*z)
        if veryClose(z, prevz) {
            return z
        }
    }
    // A million iterations has not converged; something is wrong.
    panic(fmt.Sprintf("CubeRoot(%g) did not converge", x))
}

This is only an example but real library functions should avoid panic. If the problem can be masked or worked around, it's always better to let things continue to run rather than taking down the whole program. One possible counterexample is during initialization: if the library truly cannot set itself up, it might be reasonable to panic, so to speak.

var user = os.Getenv("USER")

func init() {
    if user == "" {
        panic("no value for $USER")
    }
}

Recover

When panic is called, including implicitly for run-time errors such as indexing a slice out of bounds or failing a type assertion, it immediately stops execution of the current function and begins unwinding the stack of the goroutine, running any deferred functions along the way. If that unwinding reaches the top of the goroutine's stack, the program dies. However, it is possible to use the built-in function recover to regain control of the goroutine and resume normal execution.

A call to recover stops the unwinding and returns the argument passed to panic. Because the only code that runs while unwinding is inside deferred functions, recover is only useful inside deferred functions.

One application of recover is to shut down a failing goroutine inside a server without killing the other executing goroutines.

func server(workChan <-chan *Work) {
    for work := range workChan {
        go safelyDo(work)
    }
}

func safelyDo(work *Work) {
    defer func() {
        if err := recover(); err != nil {
            log.Println("work failed:", err)
        }
    }()
    do(work)
}

In this example, if do(work) panics, the result will be logged and the goroutine will exit cleanly without disturbing the others. There's no need to do anything else in the deferred closure; calling recover handles the condition completely.

Because recover always returns nil unless called directly from a deferred function, deferred code can call library routines that themselves use panic and recover without failing. As an example, the deferred function in safelyDo might call a logging function before calling recover, and that logging code would run unaffected by the panicking state.

With our recovery pattern in place, the do function (and anything it calls) can get out of any bad situation cleanly by calling panic. We can use that idea to simplify error handling in complex software. Let's look at an idealized version of a regexp package, which reports parsing errors by calling panic with a local error type. Here's the definition of Error, an error method, and the Compile function.

// Error is the type of a parse error; it satisfies the error interface.
type Error string
func (e Error) Error() string {
    return string(e)
}

// error is a method of *Regexp that reports parsing errors by
// panicking with an Error.
func (regexp *Regexp) error(err string) {
    panic(Error(err))
}

// Compile returns a parsed representation of the regular expression.
func Compile(str string) (regexp *Regexp, err error) {
    regexp = new(Regexp)
    // doParse will panic if there is a parse error.
    defer func() {
        if e := recover(); e != nil {
            regexp = nil    // Clear return value.
            err = e.(Error) // Will re-panic if not a parse error.
        }
    }()
    return regexp.doParse(str), nil
}

If doParse panics, the recovery block will set the return value to nil—deferred functions can modify named return values. It will then check, in the assignment to err, that the problem was a parse error by asserting that it has the local type Error. If it does not, the type assertion will fail, causing a run-time error that continues the stack unwinding as though nothing had interrupted it. This check means that if something unexpected happens, such as an index out of bounds, the code will fail even though we are using panic and recover to handle parse errors.

With error handling in place, the error method (because it's a method bound to a type, it's fine, even natural, for it to have the same name as the builtin error type) makes it easy to report parse errors without worrying about unwinding the parse stack by hand:

if pos == 0 {
    re.error("'*' illegal at start of expression")
}

Useful though this pattern is, it should be used only within a package. Parse turns its internal panic calls into error values; it does not expose panics to its client. That is a good rule to follow.

By the way, this re-panic idiom changes the panic value if an actual error occurs. However, both the original and new failures will be presented in the crash report, so the root cause of the problem will still be visible. Thus this simple re-panic approach is usually sufficient—it's a crash after all—but if you want to display only the original value, you can write a little more code to filter unexpected problems and re-panic with the original error. That's left as an exercise for the reader.
A web server

Let's finish with a complete Go program, a web server. This one is actually a kind of web re-server. Google provides a service at http://chart.apis.google.com that does automatic formatting of data into charts and graphs. It's hard to use interactively, though, because you need to put the data into the URL as a query. The program here provides a nicer interface to one form of data: given a short piece of text, it calls on the chart server to produce a QR code, a matrix of boxes that encode the text. That image can be grabbed with your cell phone's camera and interpreted as, for instance, a URL, saving you typing the URL into the phone's tiny keyboard.

Here's the complete program. An explanation follows.

package main

import (
    "flag"
    "html/template"
    "log"
    "net/http"
)

var addr = flag.String("addr", ":1718", "http service address") // Q=17, R=18

var templ = template.Must(template.New("qr").Parse(templateStr))

func main() {
    flag.Parse()
    http.Handle("/", http.HandlerFunc(QR))
    err := http.ListenAndServe(*addr, nil)
    if err != nil {
        log.Fatal("ListenAndServe:", err)
    }
}

func QR(w http.ResponseWriter, req *http.Request) {
    templ.Execute(w, req.FormValue("s"))
}

const templateStr = `
<html>
<head>
<title>QR Link Generator</title>
</head>
<body>
{{if .}}
<img src="http://chart.apis.google.com/chart?chs=300x300&cht=qr&choe=UTF-8&chl={{.}}" />
<br>
{{.}}
<br>
<br>
{{end}}
<form action="/" name=f method="GET"><input maxLength=1024 size=70
name=s value="" title="Text to QR Encode"><input type=submit
value="Show QR" name=qr>
</form>
</body>
</html>
`

The pieces up to main should be easy to follow. The one flag sets a default HTTP port for our server. The template variable templ is where the fun happens. It builds an HTML template that will be executed by the server to display the page; more about that in a moment.

The main function parses the flags and, using the mechanism we talked about above, binds the function QR to the root path for the server. Then http.ListenAndServe is called to start the server; it blocks while the server runs.

QR just receives the request, which contains form data, and executes the template on the data in the form value named s.

The template package html/template is powerful; this program just touches on its capabilities. In essence, it rewrites a piece of HTML text on the fly by substituting elements derived from data items passed to templ.Execute, in this case the form value. Within the template text (templateStr), double-brace-delimited pieces denote template actions. The piece from {{if .}} to {{end}} executes only if the value of the current data item, called . (dot), is non-empty. That is, when the string is empty, this piece of the template is suppressed.

The two snippets {{.}} say to show the data presented to the template—the query string—on the web page. The HTML template package automatically provides appropriate escaping so the text is safe to display.

The rest of the template string is just the HTML to show when the page loads. If this is too quick an explanation, see the documentation for the template package for a more thorough discussion.











import (
	"encoding/json"
	"fmt"
	"github.com/coreos/etcd/web"
	"io"
	"log"
	"net"
	"net/http"
	"net/url"
	"os"
	"os/signal"
	"runtime/pprof"
	"strconv"
	"time"
)

func durationToExpireTime(strDuration string) (time.Time, error) {

if strDuration != "" {
	duration, err := strconv.Atoi(strDuration)

return time.Now().Add(time.Second * (time.Duration)(duration)), nil
return time.Unix(0, 0), nil

type Store struct {
	// The string channel to send messages to the outside world
	// Now we use it to send changes to the hub of the web service
	messager chan<- string
	// A map to keep the recent response to the clients
	ResponseMap map[string]*Response
}

// Set the messager of the store
func (s *Store) SetMessager(messager chan<- string) {
	s.messager = messager
}

// create a channel
var storeMsg chan string
storeMsg = make(chan string)
etcdStore.SetMessager(storeMsg)
for {
    // transfer the new msg to webHub
    web.Hub().Send(<-storeMsg)
}

import "unsafe"
Package unsafe contains operations that step around the type safety of Go programs. 
Pointer represents a pointer to an arbitrary type. There are four special operations available for type Pointer that are not available for other types. 
1) A pointer value of any type can be converted to a Pointer.
2) A Pointer can be converted to a pointer value of any type.
3) A uintptr can be converted to a Pointer.
4) A Pointer can be converted to a uintptr.

Pointer therefore allows a program to defeat the type system and read and write arbitrary memory. It should be used with extreme care. 

import (
    "log";
)
log.Stdoutf("bla bla bla\n");
log.Exitf("connect faled! errno:[%s] error:[%s]\n", err["errno"], err["error"]);

Maps are a convenient and powerful built-in data structure that associate values of one type (the key) with values of another type (the element or value) The key can be of any type for which the equality operator is defined, such as integers, floating point and complex numbers, strings, pointers, interfaces (as long as the dynamic type supports equality), structs and arrays.

var timeZone = map[string]int{
    "UTC":  0*60*60,
    "EST": -5*60*60,
    "CST": -6*60*60,
    "MST": -7*60*60,
    "PST": -8*60*60,
}

type Store struct {
	Nodes map[string]string  `json:"nodes"`
}

func createStore() *Store{
	s := new(Store)
	s.Nodes = make(map[string]string)  # To initialize a map
	return s
}

Package path implements utility routines for manipulating slash-separated paths. 
Package errors implements functions to manipulate errors. 

b, err := json.Marshal(s)  #  []byte
err := json.Unmarshal(state, s)

c := make(chan int)  // Allocate a channel.
go func() {
    list.Sort()
    c <- 1  // Send a signal; value does not matter.
}()
<-c   // Wait for sort to finish; discard sent value.
Receivers always block until there is data to receive. 

s0 := []int{0, 0}
s1 := append(s0, 2)                // append a single element     s1 == []int{0, 0, 2}
s2 := append(s1, 3, 5, 7)          // append multiple elements    s2 == []int{0, 0, 2, 3, 5, 7}
s3 := append(s2, s0...)            // append a slice              s3 == []int{0, 0, 2, 3, 5, 7, 0, 0}
s4 := append(s3[3:6], s3[2:]...)   // append overlapping slice    s4 == []int{3, 5, 7, 2, 3, 5, 7, 0, 0}

const (  // iota is reset to 0
	c0 = iota  // c0 == 0
	c1 = iota  // c1 == 1
	c2 = iota  // c2 == 2
)

const (
	a = 1 << iota  // a == 1 (iota has been reset)
	b = 1 << iota  // b == 2
	c = 1 << iota  // c == 4
)

Here is some introduction to new Google programing language.

At first go has his design to build a fast compiling system programming language for fast application. There is no mess with Java or C#/C++. go has no inheritance, but interfaces.

simple tutorial can be found on golang.org

At first the question: why yet another language?

google need a language which is fast in compiling and runing. Has the advantages of typing but not overloaded wiht oop stuff.

simple example:


// define the namespace
package main

// import the formated print package
// import fmt "fmt";

// import a couple of packages
import (
    "flag";      // flag package is a good replacament for main(int argc, char **args) and 
                 // replace the argument calculation with getopt() and switch. then create
                 // a help function automatic.
    "fmt";
)

// create a boolean variable from package flag and set the values 
var blub = flag.Bool("g", false, "blub lubn blub")

// g => -g
// false => set it at first to false
// "blub..." => description in help switch

func main() {
  flag.Parse();  
  // parse the arguments

  // ask if the 
  if  *blub {
    fmt.Printf("blub was setted\n");
  } else {
    fmt.Printf("blub was not setted\n");
  }
}
as you has see variables are defined with var

var v1 int;
var v2 string;
var v3 float;

for printing is there the package fmt: fmt.Printf(..)
then exists other methods as in C.
to compile:
x64:
6g file.go
6l file.6 -o file
for x86
8g file.go
8l file.8 -o file
to be continued ...
...

we create first a file (package) Person

Person.go:


package Person

type Person struct { 
  vorname string;
  name string;
  alter int;
}

func NewPerson(v string, n string, a int) *Person {
  return &Person{v, n, a}
}

func (pers *Person) String() string {
  return "Name: "+pers.name+"  Vorname: "+pers.vorname;
}

then the main package with main()

Main.go


package main

import (
  prs "./Person";
  "fmt";
)


func main() {

  person := prs.NewPerson("blue", "blub", 42);


  fmt.Printf("person is: \n");
  fmt.Printf(person.String());
  fmt.Printf("\n");
}

compile and link:

6g Person.go

6g Main.go

6l -o Main Main.6

execute: ./Main

>person is:

>Name: blub Vorname: blue

At first we must import our file as "./Person"
At second the function that are created for outside must begin with Capitalized Character.

package Person
type Person struct { 
  vorname string;
  name string;
  alter int;
}

func newPerson(v string, n string, a int) *Person {
  return &Person{v, n, a}
}

Person.newPerson(...) doesnot work.
"For clients (importers) of the package, names must
be upper case to be visible: global variables,
functions, types, constants, plus methods and
structure fields for global variables and types.
const hello = "you smell" // package visible
const Hello = "you smell nice" // globally visible
const _Bye = "stinko!" // _ is not upper

Go doesn't have references.
all private functions begin with small character.
all public functions begin with big character.
To generate some Unit test:
name: mylib_test.go ( xxx_test.go )
the function must be called: TestXXX(t *testing.T) { ...
and import: "testing"
send Fatal error
if err != nil {
  t.Fatalf("Myerror %q: %s", path, err)
}
// or 
t.Errorf("bla bla %q ", path)
The T struct is:
type T struct {
 errors string;
 failed bool;
 ch chan *T;
}
There are some functions XXXf are with format string
Fail(), Failed(): set the failed variable or ask them. (don't exit)
FailNow() set the fail and exit.
Log()/Logf(): set the errors string.
Error()/Errorf(): Log with Fail
Fatal()/Fatalf(): Log with FailNow
To test a package, write a set of Go source files
within the same package; give the files names of the
form *_test.go.
testing tool: gotest
func TestXxxx(t *testing.T)
create the file. later call gotest my_test.go

"The defer statement executes a function (or method)
when the enclosing function returns. The arguments
are evaluated at the point of the defer; the function
call happens upon return." GocourseDay1.pdf
leet look folowing programm:
package main
import "fmt"
func b() {
  fmt.Printf("called b()\n");
}
func a() int {
  fmt.Printf("start a()\n");
  defer b();
  fmt.Printf("ended a()\n");
  return 0;
}
func main() {
  fmt.Printf("start main\n");
  fmt.Printf("call a()\n");
  a();
  fmt.Printf("after a()\n");
  fmt.Printf("\n");
}
a() call with defer b(). But the outprint show:
./6.out 
start main
call a()
start a()
ended a()
called b()
after a()

we can see that b() will be called before a() return.
=> defer is useful for closing fds, unlocking mutexes, etc.
defer is simmilar to atexit() for main() in C.
futher example:
package main
import "fmt"
func trace(s string) string {
 fmt.Print("entering:", s, "\n");
  return s
}
func un(s string) {
  fmt.Print("leaving:", s, "\n")
}
func a() {

 defer un(trace("a"));
  fmt.Print("in a\n")
}
func b() {

 defer un(trace("b"));
  fmt.Print("in b\n");
  a()
}
func main() { b() }
the output is:
./6.out 
entering:b
in b
entering:a
in a
leaving:a
leaving:b
as we can see: defer f1(f2()) f2() is called immediately but f1() is called at ending.

package is a collection of source files begining with "package nameofpackage".
import "fmt"
// now useable fmt outputs
fmt.Print(...)
import my "fmt"  // with my own name. (for purpose if namespace coliders ;)
my.Print(...)
each package can have an init() for initalization data (single threaded).
let see:
a.go
package a
import "fmt"
var A int
func init() {
    A = 4;
  fmt.Print("A init\n");
}
b.go
package b
import "fmt"
var B int
func init() {
  B=15;
  fmt.Print("B init\n");
}
mainab.go
package main
import (
  "fmt";
  "./a";
  "./b";
)
func main() {
  fmt.Print("call main()\n");
  var x= a.A;
  var y= b.B;
  var z = x + y;
  fmt.Print(z);
}
output:
./6.out 
B init
A init
call main()
at first there will be called init. later the main.
"To build a program, the packages, and the files within them, must be compiled in the correct order.
Package dependencies determine the order in which to build packages. "

Package Purpose Examples
fmt formatted I/OPrintf, Sprintf
os OS interfaceOpen, Read, Write
str convnumbers &lt;-&gt; strings<!----->Atoi, Atof, Itoa
io generic I/O Copy, Pipe
flag flags: --help etc.Bool, String
log event logging Log, Logf, Stderr
regexp regular expressions Compile, Match
template HTML, etc.Parse, Execute
bytes byte arraysCompare, Buffer

further libs: bignum, crypto, encoding, exec, hash, http, image, json, net, math, rand, regexp, sort, syscall, xml, time, unicode,

so there will be some golang tips.

 
type My struct {
    a, b int;
    name string;
}

create a struct with three variables, a and b are integers. name is a string. The struct name is My.


m := My{1,2,"ray"};
fmt.Println(m);

m:= XXX{inputs} create and initialize the struct to variable m.

Println(m) print out: {1 2 ray}.

to create you own methods for the stuct do: func (v *Mystruct) method(...) returntyps { ... }


func (m *My) String() string {
    ret := fmt.Sprintf("a: %d, b: %d, name: %s\n", m.a, m.b, m.name);
    return ret;
}

here we create the String() method for printing our struct as a string. Access variables are done through m.var.

to define a simple array of integers: a:=[3]int{1,2,3}

if you don't know the length: a:=[]int{1,2,3,4,5,1,2,3}

create an assoziative array or dictionary or hash: hash := map[string]int{"eins":1, "zwei":2, "drei":3}; where map[keytyp]valuetyp.


    hash2 := map[string]string{"blub":"aodu", "a":"ousdf", "ouew":"gofdu"};

    // iterate through the hash, range return the key and value of the hash.
    for k, v := range hash2 {
        fmt.Println("key: ",k,"   value: ",v);
    }

print out:

key: blub value: aodu

key: ouew value: gofdu

key: a value: ousdf

Read a directory:


package main

import (
    "io";
    "fmt";
)

func main() {
    dir, err := io.ReadDir("/home/ray/daten");

    fmt.Println("err: ", err);
    fmt.Println(dir);

    for _, v := range dir {
        fmt.Println(">>", v);
    }
}

let look the source on src/pkg/io/utils.go:


// ReadDir reads the directory named by dirname and returns
// a list of sorted directory entries.
func ReadDir(dirname string) ([]*os.Dir, os.Error) {
    f, err := os.Open(dirname, os.O_RDONLY, 0);  // open you directory
    if err != nil {
        return nil, err
    }
    list, err := f.Readdir(-1);    // f is a file handler
    f.Close();
    if err != nil {
        return nil, err
    }
    dirs := make(dirList, len(list));
    for i := range list {
        dirs[i] = &list[i]
    }
    sort.Sort(dirs);
    return dirs, nil;
}

func ReadDir(dirname string) ([]*os.Dir, os.Error) : ReadDir reads the directory named by dirname and returns a list of sorted directory entries.

func Open(name string, flag int, perm int) (file *File, err Error): Open opens the named file with specified flag (O_RDONLY etc.) and perm, (0666 etc.) if applicable. If successful, methods on the returned File can be used for I/O. It returns the File and an Error, if any.

Open return a File pointer. internal Open called a syscall to open

func (file *File) Readdir(count int) (dirs []Dir, err Error): Readdir reads the contents of the directory associated with file and returns an array of up to count Dir structures, as would be returned by Stat, in directory order. Subsequent calls on the same file will yield further Dirs. A negative count means to read until EOF. Readdir returns the array and an Error, if any.

our io.ReadDir() open the dir, read it through the file, create a list, sort and return the dir list.


    for _, v := range dir {
        if v.IsDirectory() {
            fmt.Println(v.Name," is directory");
        }
    }

print out all direcotries name.

more info about dir is in: src/pkg/os/types.go or http://golang.org/pkg/os/#Dir

Read a file


    fileObj, err := os.Open( "echo.go", os.O_RDONLY, 0666 );
    if err != nil {
        log.Stderr( err );
        return;
    }

  //open the file and test for errors. log.Stderr print the message with a timestamp as a log.

  // create a buffered reader
  r := bufio.NewReader( fileObj );

  // read each line 
  for {
      line, err := r.ReadString('\n');

a simple get for http:


package main

import (
 "io";
 "strings";
  "log";
  "http";
  "fmt";
)

func main() {
 r, _, err := http.Get("http://www.google.com/robots.txt");
 var b []byte;
 if err == nil {
  b, err = io.ReadAll(r.Body);
  r.Body.Close();
 }

 if err != nil {
  log.Stderr(err)
 } else {
    fmt.Println(string(b));
  }
}

ok, it was not very simple.

r, _, err := http.Get("http://www.google.com/robots.txt");

get the Response in r. Response has: a StatusCode, Body and Header.


type Response struct {
    Status     string; // e.g. "200 OK"
    StatusCode int;    // e.g. 200
    Header map[string]string;
    Body io.ReadCloser;
}

Header is a simple string hash. Body is an interface to ReadCloser: all structures with Read and Close.

func Get(url string) (r *Response, finalURL string, err os.Error) is doing followings:

- do a redirection loop (maximal 10 times)

- parse the url

- send the request

- if should redirect, get the new location in header

- if should not redirect: return the result from send()

b, err = io.ReadAll(r.Body);

read the data from response body (which has a reader from connection) in a byte array.

fmt.Println(string(b));

printout the bytes as string

create a simple webserver


package main

import (
 "http";
 "io";
)

// hello world, the web server
func HelloServer(c *http.Conn, req *http.Request) {
 io.WriteString(c, "hello, world!\n");
}

// call a html page
func MyServerPage(c *http.Conn, req *http.Request) {
 http.ServeFile(c, req, "myhtml.html");
}

func main() {
 http.Handle("/hello", http.HandlerFunc(HelloServer));
 http.Handle("/my.html", http.HandlerFunc(MyServerPage));
 err := http.ListenAndServe(":8080", nil);
 if err != nil {
  panic("ListenAndServe: ", err.String())
 }
}

http.Handle("/hello", http.HandlerFunc(HelloServer));

set the hadler function HelloServer with "/hello".

err := http.ListenAndServe(":8080", nil);

start the TCP server on port 8080, that handle the registered handler.

io.WriteString(c, "hello, world!\n"); write a simple string.

http.ServeFile(c, req, "myhtml.html"); read the file and print it out.

package main

import "fmt"
import "time"

func main() {
    
    fmt.Println("time in seconds    : ", time.Seconds());
    fmt.Println("time in nanoseconds: ", time.Nanoseconds());
    
    fmt.Println("sleep 1 second.");

    time.Sleep(1*1000*1000*1000);

    fmt.Println("time in seconds    : ", time.Seconds());
    fmt.Println("time in nanoseconds: ", time.Nanoseconds());

    fmt.Println("wait sleep 1 second.");
    before := time.Nanoseconds();
    time.Sleep(1*1000*1000*1000);
    after := time.Nanoseconds();
    fmt.Println("difference of nanoseconds: ", (after-before));
    
    t:=time.LocalTime();
    fmt.Println("time.String(): ", t.String());
}

time.Seconds() get the time as unix time in seconds

time.Nanoseconds() dito

time.Sleep(x) sleep for x nanoseconds

to sleep 1 second do time.Sleep(1e9)

to get any type back from function

let look:


package main

import "fmt"
import "rand"
import "time"

func my() interface{} {

    rand.Seed(time.Nanoseconds()/1000000);

    switch rand.Intn(3) {
        case 0: var i int; i=4; return i;
        case 1: var f float; f=2.3; return f;
        case 2: var s string; s="blub"; return s;
    }
    var b byte;
    b='c';
    return b;
}

func main() {
    fmt.Println(my());
    time.Sleep(1e9);
    fmt.Println(my());
    time.Sleep(1e9);
    fmt.Println(my());
    time.Sleep(1e9);
    fmt.Println(my());
    time.Sleep(1e9);
    fmt.Println(my());
}

/*
with func my() interface{} {...} we declare a function which return an interface. This is a void interface, which can implement all types. Thus we can back every typ back. The my() function simple init the rand and get randomly different types back.
*/
package main

import (
  "encoding/base64";
  "bytes";
  "fmt";
)

func main() {
  // create the buffer
  bb := &bytes.Buffer{};
  bbURL := &bytes.Buffer{};

  // create two base64 encoder (standard and for url)
  encoder := base64.NewEncoder(base64.StdEncoding, bb);
  encoderURL := base64.NewEncoder(base64.URLEncoding, bbURL);

  data := "hallo this is a test, a=23&var2=blabla+-?!%$/\\";
  fmt.Println("data       : ", data);

  // to encode data, use Write([]bytes),
  // therefore you must convert string to bytes 
  // with string.Bytes(d string)
  encoder.Write([]byte(data));
  encoder.Close();

  encoderURL.Write([]byte(data));
  encoderURL.Close();

  // voila
  fmt.Println("encoded Std: ", bb.String());
  fmt.Println("encoded URL: ", bbURL.String());
}

package main

import (
  "strings";
  "fmt";
)

func main() {
  data := "bla blu blub";
  fmt.Println(data);
  // return: bla blu blub
  
  // convert string in bytes 
  b := strings.Bytes(data);
  fmt.Println(b);  // print every byte as array
  // return: [98 108 97 32 98 108 117 32 98 108 117 98]


  // test if the string begin with the prefix
  if strings.HasPrefix(data, "bl") {
    fmt.Println("data: \"", data, "\" begin with the prefix \"bl\"");
  }

  // test if the string end with the suffix
  if strings.HasSuffix(data, "blub") {
    fmt.Println("data: \"", data, "\" end with \"blub\"");
  }

  // Index returns the index of the first instance of sep in s, 
  // or -1 if sep is not present in s. 
  fmt.Println("index: ", strings.Index(data, "blu"));
  // return: index:  4

  fmt.Println("index: ", strings.Index(data, "b"));
  // return: index:  0
  fmt.Println("last index: ", strings.LastIndex(data, "b"));
  // return: last index:  11
  // LastIndex return the last occurency of seeking string

  // with Repeat you can repeat ;)
  fmt.Println("r: ", strings.Repeat("x", 10));
  // return: r:  xxxxxxxxxx

  // split the string in array of string
  as := strings.Split("root:alsdfjl:230:/blub/blub:lalalala", ":", 0);

  fmt.Println(as);
  // return: [root alsdfjl 230 /blub/blub lalalala]

  fmt.Println(strings.Join(as, "|"));
  // return: root|alsdfjl|230|/blub/blub|lalalala

  fmt.Println(strings.ToLower("UASFalsdfuADSFWE$$"));
  // return: uasfalsdfuadsfwe$$

  fmt.Println(strings.ToUpper("owenadsfoadsfj"));
  // return: OWENADSFOADSFJ

  fmt.Println("<", strings.TrimSpace("  asdf sdowe   "), ">");
  // return: < asdf sdowe >
}

//----------------------------------------
package main
import (
  "io";
  "fmt";
  "os";
  "strings";
)
func main() {
  // read the file in bytes array
  b, err := io.ReadFile("readfile.go");
  if err!=nil {
    fmt.Println("error on read file");
    os.Exit(-1);
  } 
  
  // convert from bytes to string
  strbuffer := string(b);

  // split into lines
  lines := strings.Split(strbuffer, "\n", 0);

  // iterate each
  for i, line := range lines {
    fmt.Printf("%d:  %s\n", i, line);
  }
}
//----------------------------------------
  url := "http://blub.org/b.html?v1=23&v2=bla&v=sdl+sdo";
  surl := http.URLEscape(url);

  fmt.Println(url);
  fmt.Println(surl);

  url2 := "http://это.порусс.ки/здесь.хтмл";
  surl2 := http.URLEscape(url2);

  fmt.Println(url2);
  fmt.Println(surl2);
/*
output:

http://blub.org/b.html?v1=23&v2=bla&v=sdl+sdo
http://blub.org/b.html%3fv1%3d23%26v2%3dbla%26v%3dsdl%2bsdo

http://это.порусс.ки/здесь.хтмл
http://%d1%8d%d1%82%d0%be.%d0%bf%d0%be%d1%80%d1%83%d1%81%d1%81.%d0%ba%d0%b8/%d0%b7%d0%b4%d0%b5%d1%81%d1%8c.%d1%85%d1%82%d0%bc%d0%bb

http.URLUnescape(url string) do it back.*/
//------------------------------------------------------
package main
import (
    "os"; "fmt"; "bufio";
)
func main() {

    fmt.Print("input your name: ");

    br := bufio.NewReader(os.Stdin);

    name, _ := br.ReadString('\n');

    fmt.Println();
    fmt.Println("your name is: ", name);

}
/*
func NewReader(rd io.Reader) *Reader NewReader returns a new Reader whose buffer has the default size.
func (b *Reader) ReadString(delim byte) (line string, err os.Error) read until delim byte.
here we read until enter. */
//------------------------------------------------------
path.Walk(p.String(), pathIter(c), nil);
/*you can think pathIter(c) is a function. but:
type pathIter chan
pathIter is a typedefinition. Therefore is pathIter(c) not a function with parameter c, rahter a casting from c (is a Path channel) to pathIter.
*/
/* List: (a doubly linked list)
The list is a double linked list of Elements. Element is an element in the linked list with Next() and Prev() pointer to other elements. Begining and ending of Elements are nil.*/
package main

import (
  . "fmt";
  "container/list";
  "strings";
  "bytes";
)

// print the elements of the list 
func PrintList(l *list.List) {
  Println("------------------------------");
  for value := range l.Iter() {
    Println("element: ", value);
  }
  Println("------------------------------");
}

func main() {
  // create a new list
  li := list.New();

  // add elements at end
  li.PushBack("list1");
  li.PushBack("list2");

  // add elements at begining
  li.PushFront("list3");
  
  PrintList(li);

  // get the first element from the list
  element := li.Front();
  str := element.Value;
  Println("value: ", str);

  // add a element before the first element
  li.InsertBefore("list4", element);

  // add after the element
  li.InsertAfter("list5", element);

  PrintList(li);

  // get the next element
  element = element.Next();
  Println("value: ", element.Value);

  // move the first element to back
  element = li.Front();
  li.MoveToBack(element);

  PrintList(li);

  // remove the first element
  element = li.Front();
  li.Remove(element);

  PrintList(li);
  
  // find the element with "list2" and remove it
  for element := li.Front(); element != nil; element = element.Next() {
  // don't use li.Iter(), because the interface chanel 
  // is geting the Value from the element back. not the element.
    value := element.Value.(string);

    if bytes.Equal(strings.Bytes(value),strings.Bytes("list2")) {
      li.Remove(element);
    }
  }

  PrintList(li);

}
/*  Ring:

A Ring is an element of a circular list, or ring. Rings do not have a beginning or end; a pointer to any ring element serves as reference to the entire ring. Empty rings are represented as nil Ring pointers. The zero value for a Ring is a one-element ring with a nil Value. */
package main
import (
  . "fmt";
  "container/ring";
  "bytes";
)
// print the elements of the ring 
func PrintRing(r *ring.Ring) {
  Println("------------------------------");
  i, n := 0, r.Len()
  for p := r; i < n; p = p.Next() {
    Println("value: ", p.Value);
    i++
  }
  Println("------------------------------");
}
func main() {
  // create a new ring with 10 items
  r := ring.New(10);

  Println("len of ring: ", r.Len());
  PrintRing(r);

  // set some value
  r.Value = "value 1";
  // take the next
  
  r = r.Next();
  r.Value = "value 2";

  r = r.Next();
  r.Value = "value 3";

  r = r.Next();
  r.Value = "value 4";

  PrintRing(r);


  // create a second ring with 3 item and set his value
  r2 := ring.New(3);
  r2.Value = "r2 value 1";
  r2 = r2.Next();
  r2.Value = "r2 value 2";
  r2 = r2.Next();
  r2.Value = "r2 value 3";
  PrintRing(r2);

  // merge ring2 into ring 1
  r = r.Link(r2);
  PrintRing(r);

  // remove a value in ring
  for p:=r.Next(); p!=r; p=p.Next() {
    if p.Value != nil {
      value := p.Value.(string);
      if bytes.Equal([]byte(value),[]byte("r2 value 2")) {
        p.Value=nil;
      }
    }
  }

  PrintRing(r);
}
/*
Here we test the golang aes encryption decryption. We simple encrypt and decrypt a text message with AES-128. That is a key with 16 byte length.

"NewCipher creates and returns a new Cipher. The key argument should be the AES key, either 16, 24, or 32 bytes to select AES-128, AES-192, or AES-256."
*/
package main

import (
    "crypto/aes";
    . "fmt";
    "os";
)

func main() {
    // a 32 byte long message
    msg := "This is long message text. len32";
    // some key, 16 Byte long
    key := []byte{0x2c, 0x88, 0x25, 0x1a, 0xaa, 0xae, 0xc2, 0xa2, 0xaf, 0xe7, 0x84, 0x8a, 0x10, 0xcf, 0xe3, 0x2a};

    Println("len of message: ", len(msg));
    Println("len of key: ", len(key));
    // create the new cipher
    c, err := aes.NewCipher(key);
    if err != nil {
       Println("Error: NewCipher(%d bytes) = %s", len(key), err);
       os.Exit(-1);
    }

    // now we convert our string into 32 long byte array
    msgbuf :=[]byte(msg);
    Println("msgbuf >> ", msgbuf);
    out := make([]byte, len(msg));
    Println("out >> ", out);
    
    c.Encrypt(out[0:16], msgbuf[0:16]);   // encrypt the first half
    c.Encrypt(out[16:32], msgbuf[16:32]); // encrypt the second half

    Println("len of encrypted: ", len(out));
    Println("out >> ", out);

    // now we decrypt our encrypted text
    plain := make([]byte, len(out));
    c.Decrypt(plain[0:16], out[0:16]);   // decrypt the first half
    c.Decrypt(plain[16:32], out[16:32]); // decrypt the second half

    Println("msg: ", string(plain));
}
/*output:
len of message:  32
len of key:  16
msgbuf >>  [84 104 105 115 32 105 115 32 108 111 110 103 32 109 101 115 115 97 103 101 32 116 101 120 116 46 32 108 101 110 51 50]
out >>  [0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0]
len of encrypted:  32
out >>  [0 173 125 174 152 165 226 181 32 25 196 177 81 243 134 79 55 152 215 72 239 85 123 219 82 30 231 89 185 194 67 203]
msg:  This is long message text. len32   */
//------------------------------------------------
/* a simple server and client in golang.
server wait for a client and handle him, simple read and write, then close.
client connect to server, write then read to/from server.*/
//server:
package main

import (
    . "fmt";
    "net";
    "os"; "log";
    "strings";
)

func test(err os.Error, mesg string) {
    if err!=nil {
        log.Stderr("SERVER: ERROR: ", mesg);
         os.Exit(-1);
    } else
        log.Stdout("SERVER: OK: ", mesg);
}


func main() {
    buf := make([] byte, 1500);

    Println("starting server...");

    netlisten, err := net.Listen("tcp", "127.0.0.1:9988");
    test(err, "Listen");
    defer netlisten.Close();
    
    for{
        Println("server wait for client ...");
        con, err := netlisten.Accept();
        test(err, "Accept for client");
        Println("client has connect to server");

        con.Read(buf);
           
        Println("readed: ", string(buf));

        con.Write(strings.Bytes("response from server"));
    }
}
// client:
package main

import (
    . "fmt";
    "net";
    "os"; "log";
)

func test(err os.Error, mesg string) {
    if err!=nil {
        log.Stderr("CLIENT: ERROR: ", mesg);
         os.Exit(-1);
    } else
        log.Stdout("CLIENT: OK: ", mesg);
}

func main() {
    buf := make([] byte, 1500);

    Println("starting client");
    con, err := net.Dial("tcp", "", "127.0.0.1:9988");
    test(err, "dialing");
    defer con.Close();
    Println("client has connected to server");
    
    con.Write(strings.Bytes("das ist ein test"));

    con.Read(buf);
           
    Println("readed: ", string(buf));
}

//-------------------------------------------
//server:
package main

import (
    "fmt";
    "net";
    "log";
    "os";
    "container/list";
    "strings";
    "bytes";
    "flag";
)

// flag for debuging info. or a simple log
var debug = flag.Bool("d", false, "set the debug modus( print informations )")

type ClientChat struct {
    Name string;        // name of user
    IN chan string;     // input channel for to send to user
    OUT chan string;    // input channel from user to all
    Con *net.Conn;      // connection of client
    Quit chan bool;     // quit channel for all goroutines
    ListChain *list.List;    // reference to list
}

// read from connection and return true if ok
func (c *ClientChat) Read(buf []byte) bool{
    nr, err := c.Con.Read(buf);
    if err!=nil {
        c.Close();
        return false;
    }
    Log("Read():  ", nr, " bytes");
    return true;
}

// close the connection and send quit to sender
func (c *ClientChat) Close() {
    c.Quit<-true data-blogger-escaped-br="">    c.Con.Close();
    c.deleteFromList();
}

// compare two clients: name and network connection
func (c *ClientChat) Equal(cl *ClientChat) bool {
    if bytes.Equal(strings.Bytes(c.Name), strings.Bytes(cl.Name)) {
        if c.Con == cl.Con {
            return true;
        }
    }
    return false;
}

// delete the client from list
func (c *ClientChat) deleteFromList() {
    for e := c.ListChain.Front(); e != nil; e = e.Next() {
        client := e.Value.(ClientChat);
        if c.Equal(&client) {
            Log("deleteFromList(): ", c.Name);
            c.ListChain.Remove(e);
        }
    }
}

// func Log(v ...): loging. give log information if debug is true
func Log(v ...) {
    if *debug == true {
        ret := fmt.Sprint(v);
        log.Stdoutf("SERVER: %s", ret);
    }
}

// func test(): testing for error
func test(err os.Error, mesg string) {
    if err!=nil {
        log.Stderr("SERVER: ERROR: ", mesg);
         os.Exit(-1);
    } else
        Log("Ok: ", mesg);
}

// handlingINOUT(): handle inputs from client, and send it to all other client via channels.
func handlingINOUT(IN <-chan data-blogger-escaped-br="" data-blogger-escaped-list.list="" data-blogger-escaped-lst="" data-blogger-escaped-string="">    for {
        Log("handlingINOUT(): wait for input");
        input := <-in data-blogger-escaped-br="" data-blogger-escaped-client="" data-blogger-escaped-from="" data-blogger-escaped-get="" data-blogger-escaped-input="">        // send to all client back
        Log("handlingINOUT(): handling input: ", input);
        for value := range lst.Iter() {
            client := value.(ClientChat);
            Log("handlingINOUT(): send to client: ", client.Name);
            client.IN<- data-blogger-escaped-br="" data-blogger-escaped-input="">        }  
    }
}



// clientreceiver wait for an input from network, after geting data it send to
// handlingINOUT via a channel.
func clientreceiver(client *ClientChat) {
    buf := make([]byte, 2048);

    Log("clientreceiver(): start for: ", client.Name);
    for client.Read(buf) {
        
        if bytes.Equal(buf, strings.Bytes("/quit")) {
            client.Close();
            break;
        }
        Log("clientreceiver(): received from ",client.Name, " (", string(buf), ")");
        send := client.Name+"> "+string(buf);
        client.OUT<- data-blogger-escaped-br="" data-blogger-escaped-send="">        for i:=0; i<2048 data-blogger-escaped-br="" data-blogger-escaped-i="">            buf[i]=0x00;
        }
    }    

    client.OUT <- data-blogger-escaped-br="" data-blogger-escaped-chat="" data-blogger-escaped-client.name="" data-blogger-escaped-has="" data-blogger-escaped-left="">    Log("clientreceiver(): stop for: ", client.Name);
}

// clientsender(): get the data from handlingINOUT via channel (or quit signal from
// clientreceiver) and send it via network
func clientsender(client *ClientChat) {
    Log("clientsender(): start for: ", client.Name);
    for {
        Log("clientsender(): wait for input to send");
        select {
            case buf := <- data-blogger-escaped-br="" data-blogger-escaped-client.in:="">                Log("clientsender(): send to \"", client.Name, "\": ", string(buf));
                client.Con.Write(strings.Bytes(buf));
            case <-client data-blogger-escaped-.quit:="" data-blogger-escaped-br="">                Log("clientsender(): client want to quit");
                client.Con.Close();
                break;
        }
    }
    Log("clientsender(): stop for: ", client.Name);
}

// clientHandling(): get the username and create the clientsturct
// start the clientsender/receiver, add client to list.
func clientHandling(con *net.Conn, ch chan string, lst *list.List) {
    buf := make([]byte, 1024);
    con.Read(buf);
    name := string(buf);
    newclient := &ClientChat{name, make(chan string), ch, con, make(chan bool), lst};

    Log("clientHandling(): for ", name);
    go clientsender(newclient);
    go clientreceiver(newclient);
    lst.PushBack(*newclient);
    ch<- data-blogger-escaped-br="" data-blogger-escaped-chat="" data-blogger-escaped-has="" data-blogger-escaped-joinet="" data-blogger-escaped-name="" data-blogger-escaped-the="">}

func main() {
    flag.Parse();
    Log("main(): start");

    // create the list of clients
    clientlist := list.New();
    in := make(chan string);
    Log("main(): start handlingINOUT()");
    go handlingINOUT(in, clientlist);
    
    // create the connection
    netlisten, err := net.Listen("tcp", "127.0.0.1:9988");
    test(err, "main Listen");
    defer netlisten.Close();

    for {
        // wait for clients
        Log("main(): wait for client ...");
        conn, err := netlisten.Accept();
        test(err, "main: Accept for client");
        go clientHandling(&conn, in, clientlist);
    }
}

/*
Server has three part which are running as goroutines and communicate via channels.

1) handlingINOUT() simple wait for input of clientreceiver() and send to all clientsender() which are in the list.

2) clientreceiver() wait for his data from client via networkconnection and send it to a inputchannel to handlingINOUT

3) clientsender() wait for data from channel and send it to client

every client connection get a his own clientreceiver/sender and a list entry. on disconnection the list entry will be deleted.
*/
//  --  --  --
//client:
package main

import (
    "fmt";
    "net";
    "log";
    "os";
    "bytes";
    "bufio";
    "strings";
    "time";
    "flag";
)

var running bool;  // global variable if client is running

var debug = flag.Bool("d", false, "set the debug modus( print informations )")

// func Log(v ...): loging. give log information if debug is true
func Log(v ...) {
    if *debug == true {
        ret := fmt.Sprint(v);
        log.Stdoutf("CLIENT: %s", ret);
    }
}

// func test(): testing for error
func test(err os.Error, mesg string) {
    if err!=nil {
        log.Stderr("CLIENT: ERROR: ", mesg);
         os.Exit(-1);
    } else
        Log("Ok: ", mesg);
}

// read from connection and return true if ok
func Read(con *net.Conn) string{
    var buf [4048]byte;
    _, err := con.Read(&buf);
    if err!=nil {
        con.Close();
        running=false;
        return "Error in reading!";
    }
    str := string(&buf);
    fmt.Println();
    return string(str);
}

// clientsender(): read from stdin and send it via network
func clientsender(cn *net.Conn) {
    reader := bufio.NewReader(os.Stdin);
    for {
        fmt.Print("you> ");
        input, _ := reader.ReadBytes('\n');
        if bytes.Equal(input, strings.Bytes("/quit\n")) {
            cn.Write(strings.Bytes("/quit"));
            running = false;
            break;
        }
        Log("clientsender(): send: ", string(input[0:len(input)-1]));
        cn.Write(input[0:len(input)-1]);
    }
}

// clientreceiver(): wait for input from network and print it out
func clientreceiver(cn *net.Conn) {
    for running {
        fmt.Println(Read(cn));
        fmt.Print("you> ");
    }
}

func main() {
    flag.Parse();
    running = true;
    Log("main(): start ");
    
    // connect
    destination := "127.0.0.1:9988";
    Log("main(): connecto to ", destination);
    cn, err := net.Dial("tcp", "", destination);
    test(err, "dialing");
    defer cn.Close();
    Log("main(): connected ");

    // get the user name
    fmt.Print("Please give you name: ");
    reader := bufio.NewReader(os.Stdin);
    name, _ := reader.ReadBytes('\n');

    //cn.Write(strings.Bytes("User: "));
    cn.Write(name[0:len(name)-1]);

    // start receiver and sender
    Log("main(): start receiver");
    go clientreceiver(&cn);
    Log("main(): start sender");
    go clientsender(&cn);
    
    // wait for quiting (/quit). run until running is true
    for ;running; {
        time.Sleep(1*1e9);
    }
    Log("main(): stoped");
}
/* client start two goroutines: for getting input from stdin and send it to network. and get from network and print it out. */

//----------------------------------------
// base64 encoding
package main

import (
  "encoding/base64";
  "io";
  "os";
)

func main() {
    e := base64.NewEncoder(base64.StdEncoding, os.Stdout)
    io.Copy(e, os.Stdin)
    e.Close()
}
//-------------------------------------------
scanner := bufio.NewScanner(os.Stdin)
for scanner.Scan() {
    fmt.Println(scanner.Text()) // Println will add back the final '\n'
}
if err := scanner.Err(); err != nil {
    fmt.Fprintln(os.Stderr, "reading standard input:", err)
}
//---------------------------------------
// An artificial input source.
const input = "Now is the winter of our discontent,\nMade glorious summer by this sun of York.\n"
scanner := bufio.NewScanner(strings.NewReader(input))
// Set the split function for the scanning operation.
scanner.Split(bufio.ScanWords)
// Count the words.
count := 0
for scanner.Scan() {
    count++
}
if err := scanner.Err(); err != nil {
    fmt.Fprintln(os.Stderr, "reading input:", err)
}
fmt.Printf("%d\n", count)


err := os.Mkdir(fs.RootFS, 0700); err != nil && !os.IsExist(err)


"os/exec"
exec.Command("umount", fs.RootFS).Run()

################################################################################
sync
Package sync provides basic synchronization primitives such as mutual exclusion locks. Other than the Once and WaitGroup types, most are intended for use by low-level library routines. Higher-level synchronization is better done via channels and communication. 

package main

import (
    "sync"
    "fmt"
    "time"
)

func rout(i int, m *sync.Mutex, c *sync.Cond) {

    fmt.Println("  rout(", i, ") start")
    m.Lock()
    c.Wait()
    m.Unlock()
    fmt.Println("  rout(", i, ") stop")
}

func main() {

    var m sync.Mutex

    cond := sync.NewCond(&m )

    fmt.Println("start")
    i:=0
    for i<15 {
        i=i+1
        go rout(i, &m, cond)
    }

    time.Sleep(100 * time.Millisecond)
    fmt.Println("send broadcast")
    m.Lock()
    cond.Broadcast()
    m.Unlock()
    fmt.Println("after broadcast")
    fmt.Println("befre sleep")
    time.Sleep(2000 * time.Millisecond)
    fmt.Println("end")
}
################################################################################
package main

import (
	"container/list"
	"fmt"
)

func main() {
	// Create a new list and put some numbers in it.
	l := list.New()
	e4 := l.PushBack(4)
	e1 := l.PushFront(1)
	l.InsertBefore(3, e4)
	l.InsertAfter(2, e1)

	// Iterate through list and and print its contents.
	for e := l.Front(); e != nil; e = e.Next() {
		fmt.Println(e.Value)
	}

}
################################################################################
package main

import (
    "io/ioutil"
    "fmt"
    "path"
)


func main() {

    dir, err := ioutil.ReadDir("/tmp/a")
	if err != nil {
		fmt.Println("eror")
		return 
	}
	
	for _, v := range dir {
		fmt.Println("name: ", v.Name())
	}
	
	
	v:= path.Join("/root", "containers")
	fmt.Println(v)

}
################################################################################
package main

import (
	"fmt"
	"log"
	"os/exec"
)

func main() {
	out, err := exec.Command("/bin/date").Output()
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("The date is %s\n", out)
}
################################################################################

slice = append(slice, elem1, elem2)
slice = append(slice, anotherSlice...)

slice = append([]byte("hello "), "world"...)


Package tabwriter implements a write filter (tabwriter.Writer) that translates tabbed columns in input into properly aligned text. 

	w := tabwriter.NewWriter(stdout, 20, 1, 3, ' ', 0)
	fmt.Fprintf(w, "ID\tNAME\tSIZE\tADDED\n")
	for _, layer := range docker.layers {
		fmt.Fprintf(w, "%s\t%s\t%.1fM\t%s ago\n", layer.Id, layer.Name, float32(layer.Size) / 1024 / 1024, humanDuration(time.Now().Sub(layer.Added)))
	}
	w.Flush()

################################################################################

/*
http://stackoverflow.com/questions/1821811/how-to-read-write-from-to-file
*/

func main() {
    // open input file
    fi, err := os.Open("/tmp/a/date.txt")
    if err != nil { panic(err) }

    // close fi on exit and check for its returned error
    defer fi.Close()
    /*defer func() {
        if err := fi.Close(); err != nil {
            panic(err)
        }
    }()*/
    
    // open output file
    fo, err := os.Create("/tmp/a/output.txt")
    if err != nil { panic(err) }
    // close fo on exit and check for its returned error
    defer func() {
        if err := fo.Close(); err != nil {
            panic(err)
        }
    }()
    
    // make a buffer to keep chunks that are read
    buf := make([]byte, 1024)

    for {
        // read a chunk
        n, err := fi.Read(buf)
        if err != nil && err != io.EOF { panic(err) }
        if n == 0 { break }

        // write a chunk
        if _, err := fo.Write(buf[:n]); err != nil {
            panic(err)
        }
    }

/*
Here I used os.Open and os.Create which are convenient wrappers around os.OpenFile. We usually don't need to call OpenFile directly.

Notice treating EOF. Read tries to fill buf on each call, and returns io.EOF as error if it reaches end of file in doing so. In this case buf will still hold data. Consequent calls to Read returns zero as the number of bytes read and same io.EOF as error. Any other error will lead to a panic.
*/


    // open input file
    fi, err := os.Open("/tmp/a/date.txt")
    if err != nil { panic(err) }
    // close fi on exit and check for its returned error
    defer func() {
        if err := fi.Close(); err != nil {
            panic(err)
        }
    }()
    // make a read buffer
    r := bufio.NewReader(fi)
    
    // open output file
    fo, err := os.Create("/tmp/a/output.txt")
    if err != nil { panic(err) }
    // close fo on exit and check for its returned error
    defer func() {
        if err := fo.Close(); err != nil {
            panic(err)
        }
    }()
    // make a write buffer
    w := bufio.NewWriter(fo)

    // make a buffer to keep chunks that are read
    buf := make([]byte, 1024)
    for {
        // read a chunk
        n, err := r.Read(buf)
        if err != nil && err != io.EOF { panic(err) }
        if n == 0 { break }

        // write a chunk
        if _, err := w.Write(buf[:n]); err != nil {
            panic(err)
        }
    }

    if err = w.Flush(); err != nil { panic(err) }

/*
bufio is just acting as a buffer here, because we don't have much to do with data. In most other situations (specially with text files) bufio is very useful by giving us a nice API for reading and writing easily and flexibly, while it handles buffering behind the scenes.
*/


    // read whole the file
    b, err := ioutil.ReadFile("/tmp/a/date.txt")
    if err != nil { panic(err) }

    // write whole the body
    err = ioutil.WriteFile("/tmp/a/output.txt", b, 0644)
    if err != nil { panic(err) }
/* Easy as pie! But use it only if you're sure you're not dealing with big files.*/

[]byte is a slice (similar to a substring) of all or part of a byte array. Think of the slice as a value structure with a hidden pointer field for the system to locate and access all or part of an array (the slice), plus fields for the length and capacity of the slice, which you can access using the len() and cap() functions.


    inName := "file-rw.bin";
    inPerm :=  0666;
    inFile, inErr := os.Open(inName, os.O_RDONLY, inPerm);
    if inErr == nil {
    	inBufLen := 16;
    	inBuf := make([]byte, inBufLen);
    	n, inErr := inFile.Read(inBuf);
    	for inErr == nil {
    		fmt.Println(n, inBuf[0:n]);
    		n, inErr = inFile.Read(inBuf);
    	}
    }
    inErr = inFile.Close();


// open files r and w
    r, err := os.Open("input.txt")
    if err != nil {
        panic(err)
    }
    defer r.Close()

    w, err := os.Create("output.txt")
    if err != nil {
        panic(err)
    }
    defer w.Close()

    // do the actual work
    n, err := io.Copy(w, r)
    if err != nil {
        panic(err)
    }
    log.Printf("Copied %v bytes\n", n)


Read reads up to len(b) bytes from the File. It returns the number of bytes read and an Error, if any. EOF is signaled by a zero count with err set to EOF.
################################################################################

    file, err := os.Open("/tmp/a")
    if err != nil {
        panic(err)
    }
    defer file.Close()
    
    stats, _ := file.Stat()

/*    
    type FileInfo interface {
        Name() string       // base name of the file
        Size() int64        // length in bytes for regular files; system-dependent for others
        Mode() FileMode     // file mode bits
        ModTime() time.Time // modification time
        IsDir() bool        // abbreviation for Mode().IsDir()
        Sys() interface{}   // underlying data source (can return nil)
}
*/
    
    fmt.Println("Name: ", stats.Name())
    fmt.Println("Size: ", stats.Size())
    fmt.Println("Mode: ", stats.Mode())
    fmt.Println("ModTime: ", stats.ModTime())
    fmt.Println("IsDir: ", stats.IsDir())
    fmt.Println("Sys: ", stats.Sys())

################################################################################

func nameReader(array [3]name) {
    ...
}

nameReader(a[:])

a := [3]int{1, 2, 3} // Array literal
b := a               // Copy the contents of a into b
a[0] = 0
fmt.Println(a)       // Prints "[0 2 3]"
fmt.Println(b)       // Prints "[1 2 3]"

a := []int{1, 2, 3} // Slice literal
b := a              // a and b now point to the same memory
a[0] = 0
fmt.Println(a)      // Prints "[0 2 3]"
fmt.Println(b)      // Prints "[0 2 3]"


Interface values are comparable. Two interface values are equal if they have identical dynamic types and equal dynamic values or if both have value nil.

start := time.Now()
elapsed := time.Since(start)
log.Printf("\nTook %s", elapsed)
time.Sleep(100 * time.Millisecond)


How about using a select statement with a default clause which will execute if the channel can't receive?
Loop:
   for {
      select {
          //check exitMessage to see whether to break out or not
          case <- exitMessage:
               break Loop
          //do something repeatedly very fast in the for loop
          default:
               // stuff
       }
   }  
################################################################################
package main

import (
    "fmt"
    "io/ioutil"
    "path"
    "crypto/md5"
)

func PrintMD5Sum(dir string, name string) {
    h := md5.New()
    
    b, err := ioutil.ReadFile(path.Join(dir, name))
    if err != nil { panic(err) }
    
    h.Write(b)
    
    fmt.Printf("%x   %s/%s\n", h.Sum(nil), dir,name)
}

func GetDir(dirname string) {
    v, err := ioutil.ReadDir(dirname)
    
    if err!=nil { panic(err) }
    
    for _,file := range v {
        if file.IsDir() {
            //fmt.Println("[+] dir:  ", file.Name())
            GetDir(path.Join(dirname, file.Name()))
        } else {
            //fmt.Println("[+] file: ", file.Name())
            PrintMD5Sum(dirname, file.Name())
        }
    }
    
}

func main() {
// open a directory, read all dirs(subdirs) and sum md5sum for all files/subfiles
    GetDir("/tmp/a") 
}

################################################################################

Package bytes implements functions for the manipulation of byte slices. 
It is analogous to the facilities of the strings package. 

var b bytes.Buffer // A Buffer needs no initialization.
b.Write([]byte("Hello "))
fmt.Fprintf(&b, "world!")
b.WriteTo(os.Stdout)


// A Buffer can turn a string or a []byte into an io.Reader.
buf := bytes.NewBufferString("R29waGVycyBydWxlIQ==")
dec := base64.NewDecoder(base64.StdEncoding, buf)
io.Copy(os.Stdout, dec)

	// Interpret Compare's result by comparing it to zero.
	var a, b []byte
	if bytes.Compare(a, b) < 0 {
		// a less b
	}
	if bytes.Compare(a, b) <= 0 {
		// a less or equal b
	}
	if bytes.Compare(a, b) > 0 {
		// a greater b
	}
	if bytes.Compare(a, b) >= 0 {
		// a greater or equal b
	}

	// Prefer Equal to Compare for equality comparisons.
	if bytes.Equal(a, b) {
		// a equal b
	}
	if !bytes.Equal(a, b) {
		// a not equal b
	}
	
	// Binary search to find a matching byte slice.
	var needle []byte
	var haystack [][]byte // Assume sorted
	i := sort.Search(len(haystack), func(i int) bool {
		// Return haystack[i] >= needle.
		return bytes.Compare(haystack[i], needle) >= 0
	})
	if i < len(haystack) && bytes.Equal(haystack[i], needle) {
		// Found it!
	}
	
	var b = []byte("Goodbye,, world!")
	b = bytes.TrimPrefix(b, []byte("Goodbye,"))
	b = bytes.TrimPrefix(b, []byte("See ya,"))
	fmt.Printf("Hello%s", b)
	
	var b = []byte("Hello, goodbye, etc!")
	b = bytes.TrimSuffix(b, []byte("goodbye, etc!"))
	b = bytes.TrimSuffix(b, []byte("gopher"))
	b = append(b, bytes.TrimSuffix([]byte("world!"), []byte("x!"))...)
	os.Stdout.Write(b)	

################################################################################

	u, err := url.Parse("http://bing.com/search?q=dotnet")
	if err != nil {
		log.Fatal(err)
	}
	u.Scheme = "https"
	u.Host = "google.com"
	q := u.Query()
	q.Set("q", "golang")
	u.RawQuery = q.Encode()
	fmt.Println(u)

    v := url.Values{}
	v.Set("name", "Ava")
	v.Add("friend", "Jess")
	v.Add("friend", "Sarah")
	v.Add("friend", "Zoe")
	// v.Encode() == "name=Ava&friend=Jess&friend=Sarah&friend=Zoe"
	fmt.Println(v.Get("name"))
	fmt.Println(v.Get("friend"))
	fmt.Println(v["friend"])

s := strings.Split("127.0.0.1:5432", ":")
s is an array/slice

ip, port := strings.Split("127.0.0.1:5432", ":")

################################################################################


func CallToURL(host string, cmd string, args []string) *url.URL {
    qValues := make(url.Values)
    for _, v := range args {
        qValues.Add("value", v)
    }
    return &url.URL{
	    Scheme:     "http",
	    Host:       host,
        Path:       "/" + cmd,
        RawQuery:   qValues.Encode(),
    }
}

func main () {

    s := strings.Split("127.0.0.1:5432", ":")
    
    u := CallToURL("blub.de", "asdf/index.html", s)

    fmt.Println("url")
    
    fmt.Println(u)
    
    resp, err := http.Get(u.String())
	if err != nil {
		panic(err)
	}
	io.Copy(os.Stdout, resp.Body)

################################################################################
func b(args ...string) {
    for _, v:=range args  {
        fmt.Println(v)
    }
}

func blub(a string, args ...string) {
    fmt.Println("a: ", a)
    b(args...)
}

func main() {
    blub("hallo", "a", "b", "c", "test")
    
}
################################################################################
    fmt.Fprintf(os.Stdout, "Usage: docker COMMAND [arg...]\n\nCommands:\n")
	for _, cmd := range [][]interface{}{
		{"run", "Run a command in a container"},
		{"list", "Display a list of containers"},
	} {
		fmt.Fprintf(os.Stdout, "    %-10.10s%s\n", cmd...)
	}
