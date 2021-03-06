# Scala Samples

* [`Tutorials`](http://www.simplyscala.com/)
* [`Book`](http://programming-scala.labs.oreilly.com/)
* [`further info`](http://www.scala-lang.org/)
* [`node 1305`](http://www.scala-lang.org/node/1305)

install scala, and type scala in console ;)
```shell
apt-get install scala
```

```scala
scala> 4/3.0
res5: Double = 1.3333333333333333

scala> 4/0
java.lang.ArithmeticException: / by zero
at .(:5)
at .()
at RequestResult$.(:3)
at RequestResult$.()
at RequestResult$result()
at sun.reflect.NativeMethodAccessorImpl.invoke0(Native Method)
at sun.reflect.NativeMethodAccessorImpl.invoke(NativeMethodAccessorImpl.java:39)
at sun.reflect.DelegatingMethodAcce...

scala> var a=3
a: Int = 3

scala> a
res7: Int = 3

scala> a=5
a: Int = 5

scala> val b=3
b: Int = 3

scala> b
res10: Int = 3

scala> b=5
<console>:5: error: reassignment to val
b=5

var and val define variables, val is immutable

For printing is here

Ascala> println(b)
3
```

operators and control sturctures (if, else, ...) are the same as in java.

```scala
scala> val isBook = 6>=3
isBook: Boolean = true

scala> val price=16
price: Int = 16

scala> val vol=10
vol: Int = 10

scala> val sale=if (isBook)price*vol else price/vol
sale: Int = 160

scala> sale
res13: Int = 160

scala> val try1=if (1==2) 8 else 9
try1: Int = 9

scala> var total=18
total: Int = 18
scala> while(total < 17) total+=3
scala> total
res15: Int = 18

scala> for(i hi five
hi five
hi five
hi five
```

hex, octal, bin is the same as in java

```scala
scala> val abyte: Byte = 27
abyte: Byte = 27

scala> var chr='A'
chr: Char = A
scala> chr=5
chr: Char =
scala> chr=66
chr: Char = B
```

define functions:

```scala
scala> def max(x: Int, y: Int): Int = {
| if (x > y) x
| else y
| }
max: (Int,Int)Int

scala> max(6,7)
res22: Int = 7

scala> max(3.6, 4)
:6: error: type mismatch;
found : Double(3.6)
required: Int
max(3.6, 4)
```

define a class

```scala
scala> class Point {
| var x=0
| var y=0
| }
defined class Point

scala> val p=new Point
p: Point = Point@18b62e0

scala> p.x=3
scala> p.y=4

scala> class Point( ix:Int,iy:Int){
| var x=ix
| var y=iy
| def vectorAdd(newpt:Point):Point={
| new Point(x+newpt.x,y+newpt.y)
| }
| }
defined class Point

scala> val p1=new Point(3,4)
p1: Point = Point@75455c
scala> val p2=new Point(7,2)
p2: Point = Point@1ba3523
scala> val p3=p1.vectorAdd(p2)
p3: Point = Point@1095c6c
scala> println(p3.x,p3.y)
(10,6)

scala> class Point( ix:Int,iy:Int){
| var x=ix
| var y=iy
| def +(newpt:Point):Point={
| new Point(x+newpt.x,y+newpt.y)
| }
| def -(newpt:Point):Point={
| new Point(x-newpt.x,y-newpt.y)
| }
| override def toString="Point("+x+","+y+")"
| }
defined class Point

scala> val p1=new Point(3,4)
p1: Point = Point(3,4)
scala> val p2=new Point(7,2)
p2: Point = Point(7,2)
scala> val p3=new Point(-2,2)
p3: Point = Point(-2,2)

scala> val p4=p1+p2-p3
p4: Point = Point(12,4)
scala> println(p4.x,p4.y)
(12,4)
```

there is no switch -> use match

```scala
scala> def decode(n:Int){
| n match {
| case 1 => println("One")
| case 2 => println("Two")
| case 5 => println("Five")
| case _ => println("Error")
| }
| }
decode: (Int)Unit
```

List:

```scala
scala> var lst = List(1, 7, 2, 8, 5, 6, 3, 9, 14, 12, 4, 10)
res29: List[Int] = List(1, 7, 2, 8, 5, 6, 3, 9, 14, 12, 4, 10)

scala> def odd(inLst:List[Int]):List[Int]={
| if(inLst==Nil) Nil
| else if(inLst.head%2==1) inLst.head::odd(inLst.tail)
| else odd(inLst.tail)
| }
odd: (List[Int])List[Int]

def define a function/method

od() name

inLst:List[Int] => inLst parameter name with a List type of Integers

:List[Int] return a List of Integers
Nil similar to none, None, null, void

inLst.head first element

inLst.tail all other elements after first element

scala> odd(lst)
res32: List[Int] = List(1, 7, 5, 3, 9)	
```

This tutorial based on:

http://www.scala-lang.org/docu/files/ScalaTutorial.pdf

http://www.thomasknierim.com/77/scala/scala-tutorial-2/


write a file s1.scala

```scala
object HelloWorld {
  def main(args: Array[String]) {
    println("Hello, world!")
  }
}
```

object -> declare a static singleton object

args: Array[String] -> a variable args as Array of Strings

compile and execute

```shell
$ scalac s1.scala 
$ ls
s1.class  s1$.class  s1.scala
```

you get created standard java class files, but you must use java interpreter with setted parameters.

```shell
$ java s1
Exception in thread "main" java.lang.NoClassDefFoundError: scala/ScalaObject
 at java.lang.ClassLoader.defineClass1(Native Method)
....

$ file /usr/bin/scala
$ /usr/bin/scala: POSIX shell script text executable
$ cat /usr/bin/scala
#!/bin/sh

JAVA_DIR=/usr/share/java
LIB_CLASSPATH=$JAVA_DIR/scala-library.jar:$JAVA_DIR/scala-compiler.jar:$JAVA_DIR/jline.jar

exec ${JAVACMD:=java} ${JAVA_OPTS:=-Xmx256M -Xms16M} \
  -Xbootclasspath/a:$LIB_CLASSPATH \
  -classpath .:$CLASSPATH:$LIB_CLASSPATH \
  scala.tools.nsc.MainGenericRunner \
  "$@"

$ scala s1
hallo
```

As you can see, the scala executable is a simple shell script, which start the java virtual machine with specific parameters and the scala library.

Create Date.scala

```scala
import java.util.{Date, Locale}
import java.text.DateFormat
import java.text.DateFormat._
object FrenchDate {
  def main(args: Array[String]) {
    val now = new Date
    val df = getDateInstance(LONG, Locale.FRANCE)
    println(df format now)
  }
}
```

```scala
import java.util.{Date, Locale}

import Date and Locale from java.util

import java.text.DateFormat._
```	

DateFormat._ is similar to DateFormat.* in java

val

declare an inmutable variable
```scala
val now = new Date
```

simmilar to "Date now = new Date();" in java

println(df format now)

"df format now" is similar to "df.format(now)"

In scala is everything an object. There is no primitive datatypes (that is similar to ruby).

Because scala based on functional programming functions are objects too.

```scala
object Timer {

  def oncePerSecond(callback: () => Unit) {
    while (true) { callback(); Thread sleep 1000 }
  }

  def timeFlies() {
    println("time flies like an arrow...")
  }

  def main(args: Array[String]) {
    oncePerSecond(timeFlies)
  }
}
```

with functions as object you can very simple code a callback.

timeFlies()

our callback function.

callback: () => Unit


parameter for a function. ()=>Unit is the type of all functions which take no arguments and return nothing.

Thread sleep 1000

is similar to Thread.sleep(1000)

rather the function timeFlies() you can use anonymous functions ala:

oncePerSecond(() => println("time flies like an arrow..."))

"() => code" declare an anonymous function

Clases:

```scala
class Complex(real: Double, imaginary: Double) {
   def re() = real
   def im() = imaginary
}
```

define class Complex with two arguments,

def re() and im() are getters. return type of these two methods is not given explicitly

```scala
object ComplexNumbers {
  def main(args: Array[String]) {
    val c = new Complex(1.2, 3.4)
    println("imaginary part: " + c.im())
  }
}
```

if you have no arguments in function, write: def re = real

```scala
class Complex(real: Double, imaginary: Double) {
  def re = real
  def im = imaginary
  override def toString() =
    "" + re + (if (im < 0) "" else "+") + im + "i"
}
```

class Complex(real: Double, imaginary: Double) -> primary constructor, which is part of the class declaration

override -> for overriding functions

(if (im < 0) "" else "+") have you see it ;)

```scala
class Rational(numerator: Int, denominator: Int) {
 
  require(denominator != 0)
 
  private val gcd = greatestCommonDivisor(numerator.abs,
    denominator.abs)
  val n = numerator / gcd
  val d = denominator / gcd
 
  def this(n: Int) = this(n, 1)
 
  private def greatestCommonDivisor(a: Int, b: Int): Int =
  if (b == 0) a else greatestCommonDivisor(b, a % b)
 
  def + (that: Rational): Rational =
  new Rational(n * that.d + d * that.n, d * that.d)
 
  def - (that: Rational): Rational =
  new Rational(n * that.d - d * that.n, d * that.d)
 
  def * (that: Rational): Rational =
  new Rational(n * that.n, d * that.d)
 
  def / (that: Rational): Rational =
  new Rational(n * that.d, d * that.n)
 
  override def toString = n + "/" + d
}
```

require(denominator != 0) -> look that variable is not null, throw exception

def this(n: Int) = this(n, 1) -> create from Rational(2) -> Rational(2,1)

you can see +-*/ are objects functions, which can be simple overrided


this tutorial based on:

http://www.thomasknierim.com/104/scala/scala-tutorial-1/
http://www.thomasknierim.com/104/scala/scala-tutorial-2/
http://www.thomasknierim.com/104/scala/scala-tutorial-3/

```scala
object Hello {
  def main(args: Array[String]) {
    for(val arg: String <- data-blogger-escaped-args="" data-blogger-escaped-br="">      System.out.println("Hello, " + arg + "!");
  }
}
```

for(val arg: String <- data-blogger-escaped--="" data-blogger-escaped-args=""> an array into each arg as String

similar: args.foreach(arg => println("Hello" + arg + "!"))
"=>" that can be read “with a given argument this do that”

args.foreach(println)

var decrease = (x: Int) => x - 1
decrease(11)

(x: Int) => x - 1 -> anonymous function declaration


var decrease = (x: Int) => x – something

something is not defined yet. decrease is depend on context -> clousure

In terms of computer science, a closure is a function that is evaluated and whose result depend on an outer context.

something = 10
decrease(100)


some examples for higher-order functions


scala> List("alpha", "beta", "crash").map(
  p => p.substring(0,1))
res0: List[java.lang.String] = List(a, b, c)
 
scala> List(1, 2, 3) map (_ * 2)
res1: List[Int] = List(2, 4, 6)
 
scala> List("Tango", "Mango", "Bobo", "Gogo")
    map (_.endsWith("go"))
res2: List[Boolean] = List(true, true, false, true)


List("alpha", "beta", "crash") -> create a list

map() -> map each list element to some condition/function

p => p.substring(0,1) p is the element p.substring(0,1) is the function

_ -> ist the element (similar to perl $_ )
(_*2) is equivalent to (i => i * 2)


```scala
object FileMatcher {
 
  private val filesHere=(new java.io.File(".")).listFiles
 
  private def filesMatching(matcher: String => Boolean)=
    for (file <- data-blogger-escaped-br="" data-blogger-escaped-file.getname="" data-blogger-escaped-fileshere="" data-blogger-escaped-if="" data-blogger-escaped-matcher="">      yield file
 
  def filesEnding(query: String)=
    filesMatching(_.endsWith(query))
  def filesContaining(query: String)=
    filesMatching(_.contains(query))
  def filesRegex(query: String)=
    filesMatching(_.matches(query))
}
 
object Main {
  def main(args: Array[String]) {
    val query = args(0);
    var matchingFiles = FileMatcher.filesEnding(query)
    matchingFiles = FileMatcher.filesContaining(query)
    matchingFiles = FileMatcher.filesRegex(query)
  }
}
```


let look:


scala> (new java.io.File(".")).listFiles
res2: Array[java.io.File] = Array(./FrenchDate$.class, ./FrenchDate.class, ./Complex.scala, ./s1.class, ./s1$.class, ./FrenchDate.scala, ./Timer$$anonfun$main$1.class, ./s1.scala, ./Timer$.class, ./Hello.class, ./ComplexNumbers.class, ./Hello.scala, ./Hello$$anonfun$main$1.class, ./blog_scala2.txt, ./Timer.class, ./Hello$.class, ./Complex.class, ./blog_scala1.txt, ./ComplexNumbers.sca...



new java.io.File(".") use the java api and create a file object File.
listFiles is the same as listFiles() in java. in scala you don't need brakes.

for (file <- data-blogger-escaped-br="" data-blogger-escaped-file.getname="" data-blogger-escaped-fileshere="" data-blogger-escaped-if="" data-blogger-escaped-matcher=""> yield file

iterate all filesHere (files in path "."). if name match to query, yield the file. the file get in an array.


scala> var matchingFiles = FileMatcher.filesEnding(query)
matchingFiles: Array[java.io.File] = Array(./Complex.scala, ./FrenchDate.scala, ./s1.scala, ./Hello.scala, ./Main.scala, ./ComplexNumbers.scala, ./Timer.scala)


def filesEnding(query: String)=
    filesMatching(_.endsWith(query))



define different functions


filesMatching(matcher: String => Boolean)

define the function with a matcher(String) which return Boolean

this tutorial based on:

http://www.artima.com/scalazine/articles/steps.html


def max(x: Int, y: Int): Int = if (x < y) y else x

def max(x: Int, y: Int) -> define a function, with 2 parameters (integer)

: Int -> return is integer.

if (x < y) y else x -> function body


scala> def greet() = println("Hello, world!")
greet: ()Unit

scala> greet()
Hello, world!

scala> greet
Hello, world!

greet save a Unit -> a function


args.foreach(arg => println(arg))
args.foreach((arg: String) => println(arg))
args.foreach(println)



val greetStrings: Array[String] = new Array[String](3)

create an array with 3 strings


greetStrings(0) = "Hello"
greetStrings(1) = ", "
greetStrings(2) = "world!\n"

important indexes are in brakes () not square brackets[]



read file in scala:


list a directory 

if (!file.isDirectory) {


ask is file not a directory

simple print out of a file


import scala.io.Source  
  
for {  
  (line) } print(line)  



read a file in an iterator


scala> val lines = scala.io.Source.fromFile("/var/log/syslog")
lines: scala.io.Source = non-empty iterator

scala> lines
res5: scala.io.Source = non-empty iterator



read a file in a string 


val lines = scala.io.Source.fromFile("/var/log/syslog").mkString

// for utf-8 encoding
val lines = scala.io.Source.fromFile("file.txt", "utf-8").getLines.mkString




or you can use Java API


val os = new BufferedOutputStream(new FileOutputStream("gen/" + file.getName))



