# Ruby Samples/Tutorials

* ein Replace-programm für Datei erstellen.
* ein Wort durch ein anderen ersetzen

Solution:
```ruby
#!/usr/bin/ruby

puts "start"

if ARGV.length > 2
  datei=ARGV[0]
  muster=ARGV[1]
  ersetzen=ARGV[2]
else
  print "\n\tfile02.rb  file muster replacetext\n\n"
  Process.exit
end

puts "mustering file #{datei}"

f=File.open(datei, "r+")
    lines = f.readlines           # read into array of lines
    lines.each do |it|            # modify lines
        it.gsub!(/#{muster}/, ersetzen)
    end
    f.pos = 0                     # back to start
    f.print lines                 # write out modified lines
    f.truncate(f.pos)  
f.close
```

```ruby
items = [1,2,3,4]
items.each do |i|
  puts i
end

File.open('somefile.txt') do |f|
  puts f.readline
end

items = [1,2,3,4]
newitems = items.map{|i| i + 1 }

newitems = items.select{|i| i % 2 == 0 }.map{|i| i + 1 }
newitems = items.map{|i| i + 1 }.select{|i| i % 2 == 0 }
sentence.split.reverse.map{|word| word.capitalize }.join(' ')

sentence = 'a short sentence'
sentence.split.length
```
```ruby
class MyClass
  def initialize
    @n = 0
  end
end

def inc(n)
  n + 1
end
```

webseite runterladen und links ausgeben
```ruby
#!/usr/bin/ruby

require 'net/http'

if ARGV.length >0
  url=ARGV[0]
else
  p " url file"
  Process.exit
end

req = Net::HTTP.get_response(URI.parse(url))

line=req.body

lines=line.split(" ")

lines.each do |l|
  if l.include?("href=http") or l.include?("href=\"http")
    v1=l.split("\"")
    if v1.length>1
      puts v1[1]
    else
      puts v1[0]
    end
  end
 
end
```

ENV.each do |e|
    p e
end

ENV: array of arrays
p: something like print or puts but better, doesnt interpolate!
ENV.each: iterate in a block each item of array ENV
do .. end: blocks
|e|: pipe, there is the block parameters
example:
["SHELL", "/bin/bash"]
["TERM", "xterm"]


```ruby
#!/usr/bin/ruby
# put out file wiht numbers out
#

file=ARGV[0] 

begin
  lines=File.open(file, "r").readlines
  format="%0#{lines.size.to_s.size}d"
  lines.each_with_index { |l, i|
    puts "#{sprintf(format, i+1)}: #{l}"
  }
rescue
  puts "no file???   or errors"
end
```

install:
```shell
~# gem install getopt
Successfully installed getopt-1.3.7
1 gem installed
Installing ri documentation for getopt-1.3.7...
Installing RDoc documentation for getopt-1.3.7...
need: require 'getoptlong'
```

```ruby
#!/usr/bin/ruby

require 'getoptlong'

opts = GetoptLong.new(
   [ "--test",             "-t",   GetoptLong::REQUIRED_ARGUMENT ],
   [ "--blub",             "-b",   GetoptLong::OPTIONAL_ARGUMENT ],
   [ "--help",             "-h",   GetoptLong::NO_ARGUMENT ],
   [ "--usage",            "-u",   GetoptLong::NO_ARGUMENT ],
   [ "--version",          "-v",   GetoptLong::NO_ARGUMENT ]
)

opts.each do |opt, arg|
 case opt
   when "--test"
     puts "we must extract :#{arg}:"
   when "--blub"
     puts "blub blub : #{arg} :"
   when "--help"
     puts "help yourself"
   when "--usage"
     puts "getoiptlong.rb"
     puts " -t, -b, -h, -u , -v"
   when "--version"
     puts "version 0.01"
   else
     puts "upsala"
 end
end
```
```ruby
with #{ }
puts "Text is #{["Test 1", "Test 2"][1]}"
=>Text is Test 2
["Test 1", "Test 2"]
create array with "Test 1" and "Test 2"
["Test 1", "Test 2"][1]
choose second item [1]
print out as variable with #{}
simple outputs through strings objects
see info: ri String#%
format%argument => string
"%05d" % 123       fill with zero on numbers
=> "00123"
"%05s" % 123      do space
=> "  123"
"%-05s" % 123
=> "123  "
"%-5s: %08x" % [ "ID", self.object_id ]
=> "ID   : fdbe224ac"
"%10.3f" % 123
=> " 123.000"
"%-10.3f" % 123
=> "123.000 "
output with sprintf analog to sprintf in c
see info: ri sprintf
format(format_string [, arguments...] ) => string
sprintf(format_string [, arguments...] ) => string
sprintf("%d %04x", 123, 123)
=> "123 007b"
sprintf("%08b '%4s'", 123, 123)
=> "01111011 ' 123'"
sprintf("%1$*2$s %2$d %1$s", "hello", 8)
=> " hello 8 hello"
sprintf("%1$*2$s %2$d", "hello", -8)
=> "hello -8"
sprintf("%+g:% g:%-g", 1.23, 1.23, 1.23)
=> "+1.23: 1.23:1.23"
sprintf("%u", -123)
=> "..4294967173"
i,d integer
x hex
s string
b bit
e,f,g floating
%x$y x which argument, y what (i,d,s,..)
%1$*2$s argument 1 with length of argument 2 (string)
```

from "Ruby Cookbook" OReilly

for detailed information, look this book
```ruby
[1,2,3].each { |i| puts i }
[1,2,3].each do |i|
  if i%2 == 0
    puts "="
  else
    puts "!"
  end
end

1.upto 3 do |x|   # same 1.upto(3)

1.upto(3) { |x| ... }   # ok
1.upto 3 { |x| ... }    # error

log = lambda { |str| puts "[LOG] #{str}" }
log.call("A test log message.")
{1=>2, 2=>4}.each { |k,v| puts "Key #{k}, value #{v}" }

def times_n(n)
  lambda { |x| x * n }
end

times_ten = times_n(10)
times_ten.call(5)        # => 50

circumference = times_n(2*Math::PI)
[1, 2, 3].collect(&circumference)
# => [6.28318530717959, 12.5663706143592, 18.8495559215388]
```

Clousure:

Every Ruby block is also a closure.
```ruby
ceiling = 50
[1, 10, 49, 50.1, 200].select { |x| x <  ceiling }
# => [1, 10, 49]
```

the var celing is context depended.

Lambda and Proc

```ruby
block = { |x| puts x }                  # error
block = lambda { |x| puts x }           # ok
block.call "bla bla!"

def my_lambda(&aBlock)   # a block in function parameters
  aBlock
end

b = my_lambda { puts "Hello World My Way!" }
b.call
b.class   # => Proc

aBlock = Proc.new { |x| puts x }
aBlock = proc { |x| puts x }
aBlock = lambda { |x| puts x }


add_lambda = lambda { |x,y| x + y }
add_lambda.call(4,5,6)  # ArgumentError: wrong number of arguments (3 for 2)

add_procnew = Proc.new { |x,y| x + y }
add_procnew.call(4,5,6)     # => 9
```

Yielding

```ruby
def myfunc
  puts "1"
  yield
  puts "2"
  yield
end

myfunc("3")
# 1
# 3
# 2
# 3


def repeat(n)
  if block_given?
    n.times { yield }
  else
    raise ArgumentError.new("I can't repeat a block you don't give me!")
  end
end

repeat(4) { puts "Hello." }
# Hello.
# Hello.
# Hello.
# Hello.

repeat(4)
# ArgumentError: I can't repeat a block you don't give me!

require 'open-uri'

url="http://www.botva-online.ru/player.php?id=42946"

pattern='img src="images/ico_11.png"'
cnt=42954

cnt.upto(cnt+0) do |x|
  url="http://www.botva-online.ru/player.php?id=#{x}"
  print "URL: #{url}\n"

  arr=Array.new

  f=open(url)
  lines=f.readlines

  nr=0
  lines.each do |line|
    if line=~/#{pattern}/
      puts nr
      puts line
      puts lines[nr]
      puts lines[nr+2]
    end
    nr=nr+1
  end
sleep 2
end
```
