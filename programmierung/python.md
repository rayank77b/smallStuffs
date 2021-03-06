# Python Samples/Tutorials

```python
def usage():
    print "bla"
    sys.exit(2)
```

```python
opts, args = getopt.getopt(sys.argv[1:], "hp:")
# h nur option
# p: option mit wert
for opt, arg in opts:
    if opt in ("-p"):
        port = arg
    else:
        usage()
```

Pack/Unpack
```python
port = pack('!H', int(port))
# i integer 4 byte
# h half    2 byte
# b byte
# ! network endian

values = (1, 'ab', 2.7)
s = struct.Struct('I 2s f')
packed_data = s.pack(*values)
print 'Packed Value   :', binascii.hexlify(packed_data)
>>> Packed Value   : 0100000061620000cdcc2c40
packed_data = binascii.unhexlify('0100000061620000cdcc2c40')
s = struct.Struct('I 2s f')
unpacked_data = s.unpack(packed_data)
print 'Unpacked Values:', unpacked_data
>>> Unpacked Values: (1, 'ab', 2.700000047683716)


endianness = [
    ('@', 'native, native'),
    ('=', 'native, standard'),
    ('<', 'little-endian'),
    ('>', 'big-endian'),
    ('!', 'network'),
    ]

idField, seqField, ackField, winField = unpack('!HIIH', packetData)

command = "/usr/sbin/hping3 -S -c 1 -p " + str(knockPort) + " -N " + str(idField) + " -w " + str(winField) + " -M " + str(seqField) + ' -L ' + str(ackField) + " " + host
command = command.split()
ret = subprocess.call(command, shell=False, stdout=open('/dev/null', 'w'), stderr=subprocess.STDOUT)

time.sleep(self.openDuration)

from Crypto.Cipher import AES
self.cipher    = AES.new(self.cipherKey, AES.MODE_ECB)
hmacSha = hmac.new(self.macKey, port, hashlib.sha1)
mac     = hmacSha.digest()
self.cipher.encrypt(counterBytes)
counterBytes = pack('!IIII', 0, 0, 0, counter)
encrypted += chr(ord(plaintextData[i]) ^ ord(counterCrypt[i]))
```

JSON
```python
import json
import requests

host_id = 

data = ("buildno=Dropbox-win-1.7.5&tag="
        "&uuid=123456&server_list=True&"
        "host_id=%s&hostname=random"
        % host_id)

base_url = ’https://client10.dropbox.com’
url = base_url + ’/register_host’

headers = {’content-type’: \
   ’application/x-www-form-urlencoded’, \
   ’User-Agent’: "Dropbox ARM" }

r = requests.post(url, data=data,
    headers=headers)

data = json.loads(r.text)
host_int = data["host_int"]
```
Hashlib
```python
import hashlib
import time
host_id = 
host_int = 
now = int(time.time())

fixed_secret = ’asdfdasfasdfin9’

h = hashlib.sha1(’%s%s%d’% (fixed_secret,
    host_id, now)).hexdigest()

url = ("https://www.dropbox.com/tray_login?"
       "i=%d&t=%d&v=%s&url=home&cl=en" %
        (host_int, now, h))
```

multiprocessing is a package that supports spawning processes using an API similar to the threading module. 
The multiprocessing package offers both local and remote concurrency, effectively side-stepping the Global Interpreter Lock by using subprocesses instead of threads. 
Due to this, the multiprocessing module allows the programmer to fully leverage multiple processors on a given machine. It runs on both Unix and Windows.
```python
from multiprocessing import Pool
p = Pool(5)
def f(x):
    return x*x
p.map(f, [1,2,3])
```
```python
from multiprocessing import Process

def f(name):
    print 'hello', name

if __name__ == '__main__':
    p = Process(target=f, args=('bob',))
    p.start()
    p.join()
```

```python
if hasattr(os, 'getppid'):  # only available on Unix
    print 'parent process:', os.getppid()
```

The Queue class is a near clone of Queue.Queue.
```python
from multiprocessing import Process, Queue

def f(q):
    q.put([42, None, 'hello'])

if __name__ == '__main__':
    q = Queue()
    p = Process(target=f, args=(q,))
    p.start()
    print q.get()    # prints "[42, None, 'hello']"
    p.join()
```

The Pipe() function returns a pair of connection objects connected by a pipe which by default is duplex (two-way). For example:
```python
from multiprocessing import Process, Pipe

def f(conn):
    conn.send([42, None, 'hello'])
    conn.close()

if __name__ == '__main__':
    parent_conn, child_conn = Pipe()
    p = Process(target=f, args=(child_conn,))
    p.start()
    print parent_conn.recv()   # prints "[42, None, 'hello']"
    p.join()
```

[`http://docs.python.org/2/library/multiprocessing.html`](http://docs.python.org/2/library/multiprocessing.html)

```python
>>> os.path.isfile('baum.c')
True
>>> os.path.isfile('bin')
False
```

so to open a file, process its contents, and make sure to close it, you can simply do:
```python
with open("x.txt") as f:
    data = f.read()
    do something with data

with open(STATE_FILENAME, 'w') as f:
    f.write('\n'.join([instance.id for instance in instances]))
```

ssh paramiko
```python
client = paramiko.SSHClient()
client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
client.connect(params['instance_name'], username='newsapps',
        key_filename='/Users/sk/.ssh/frakkingtoasters.pem')
stdin, stdout, stderr = client.exec_command('ab -r -n %(num_requests)s -c %(concurrent_requests)s -C "sessionid=NotARealSessionID" %(url)s' % params)
ab_results = stdout.read()
s = re.search('Time\ per\ request:\s+([0-9.]+)\ \[ms\]\ \(mean\)', ab_results)
ms_per_request = float(s.group(1))
client.close()
```
Fabric
```python
from fabric.api import run
from fabric.tasks import execute

def do_something():
    run("echo $RANDOM")

if __name__ == "__main__":
    execute(do_something, hosts=["username@host"])
```

```python
STATE_FILENAME = os.path.expanduser('~/.bees')

with open(STATE_FILENAME, 'r') as f: 
    username = f.readline().strip() 

os.path.expanduser('~/.ssh/%s.pem' % key) 

if not os.path.isfile(pem_path):
    print 'No key file found at %s' % pem_path
    return

urllib2.urlopen(url) 
```

* python-virtualenv - Python virtual environment creator
* virtualenvwrapper - extension to virtualenv for managing multiple virtual Python environments

```python
for i, instance in enumerate(instances):

# generator [ x for x in xlists], erzeugt eine liste mit x-werten aus xlists
Type "help", "copyright", "credits" or "license" for more information.
>>> l=[1,2,3,4,5]
>>> [x*x for x in l]
[1, 4, 9, 16, 25]

f.write('\n'.join([instance.id for instance in instances]))
```

```python
NO_TRAILING_SLASH_REGEX = re.compile(r'^.*?\.\w+$') 
# ^ anfang
# .*?  alles
# \.  punkt
# \w+ worter
# $ ende
```

```python
from urlparse import urlparse
parsed = urlparse(options.url)
if not parsed.scheme:
    parsed = urlparse("http://" + options.url)
If not parsed.path:
    print "error"

blub={}
blub['abc']="hallo"
blub['doof']="fisch"
print 'blub say: %(abc)s und %(doof)s ...'%(blub)

headers="blub:aodsfdshf;asd:4934349943;id:10010100"
d=h=dict(h.split(':') for h in headers.split(';'))
>>> d
{'asd': '4934349943', 'id': '10010100', 'blub': 'aodsfdshf'}
>>> h
{'asd': '4934349943', 'id': '10010100', 'blub': 'aodsfdshf'}

request = urllib2.Request(url, headers=dict_headers) 
request.add_header('Cookie', cookies) 
urllib2.urlopen(request).read() 
```

```python
from pprint import pprint
pprint(response) 

import math
tmin=23
tmax=243
map(math.log, [tmin,tmax])
[3.1354942159291497, 5.493061443340548]

>>> x = [1, 2, 3]
>>> y = [4, 5, 6]
>>> zipped = zip(x, y)
>>> zipped
[(1, 4), (2, 5), (3, 6)]

"turn a string into a hex sequence"
'.join(['%02X' % ord(c) for c in s])

os.environ['HOME']

l = logging.getLogger("secsh")
l.setLevel(logging.DEBUG)

try:
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((hostname, port))
except Exception, e:
    print '*** Connect failed: ' + str(e)
    traceback.print_exc()
    sys.exit(1)

# logging
FORMAT = "%(asctime)-15s %(clientip)s %(user)-8s %(message)s"
logging.basicConfig(format=FORMAT)
d = {'clientip': '192.168.0.1', 'user': 'fbloggs'}
logging.warning("Protocol problem: %s", "connection reset", extra=d)
# would print something like:
# 2006-02-08 22:20:02,165 192.168.0.1 fbloggs  Protocol problem: connection reset
```
```python
import struct
>>> n=0x41
>>> struct.pack('>I', n)
'\x00\x00\x00A'
>>> struct.pack('I', n)
'A\x00\x00\x00'

>>> [n[0] for n in locals().items()]
['sys', 'cmds', 'set', 'staging', 'get', '__builtins__', 'setup', 'deploy', '__package__', 'getpass', 'tail', 'production', 'ENV', '__name__', 'n', 'os', '__doc__']

cmds = dict([n for n in filter(lambda n: (n[0][0] != '_') and callable(n[1]), locals().items())])
dict() generiert ein dictionaery aus 2 werten
filter(f, d) filtert nach funktion f die wahr liefert, die d werte
reduce(function, iterable[, initializer])

>>> cmds.keys()
['set', 'staging', 'deploy', 'setup', 'get', 'tail', 'production']
>>> max_name_len = reduce(lambda a,b: max(a, len(b)), cmds.keys(), 0)
>>> max_name_len
10

if isinstance(v, types.StringTypes):

for name, obj in locals().items():
    if not name.startswith('_') and isinstance(obj, types.FunctionType):
        COMMANDS[name] = obj

>>> for name, obj in locals().items():
...     if not name.startswith('_') and isinstance(obj, types.FunctionType):
...             print name

>>> import os
>>> os.getcwd().split(os.sep)[-1]
'smallStuffs'
>>> os.getcwd()
'/home/ray/git/smallStuffs'

>>> name="test"
>>> name.ljust(10)
'test      '

>>> b={'a':"blub",'b':"fish"}
>>> d="hallo %(a)s und %(b)s .."
>>> d%b
'hallo blub und fish ..'

>>> import sys 
>>> import getpass 
>>> import paramiko
>>> client = paramiko.SSHClient()
>>> client.load_system_host_keys() 
>>> hostname="212.40.172.66"
>>> port=22
>>> username="ray"
>>> password = getpass.getpass() 
Password: 
>>> client.connect(hostname, port, username, password) 
>>> cmd="ps afux"
>>> stdin, stdout, stderr = client.exec_command(cmd) 
>>> stdout
<paramiko.ChannelFile from <paramiko.Channel 1 (closed) -> <paramiko.Transport at 0x7a7ae910L (cipher aes128-ctr, 128 bits) (active; 0 open channel(s))>>>
>>> for line in stdout: 
...     print line,
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root         2  0.0  0.0      0     0 ?        S<   Jul23   0:00 [kthreadd]
root         3  0.0  0.0      0     0 ?        S<   Jul23   0:00  \_ [migration/0]

imp — Access the import internals
This module provides an interface to the mechanisms used to implement the import statement.
fp, pathname, description = imp.find_module(name)
return imp.load_module(name, fp, pathname, description)
```

```python
# simple setup.py
from distutils.core import setup
import imp

fab = imp.load_source('fab', 'fab')

setup(
    name='Fabric',
    version=fab.__version__,
    description='Fabric is a simple pythonic remote deployment tool.',
    author=fab.__author__,
    author_email=fab.__author_email__,
    url=fab.__url__,
    requires=['paramiko (>=1.6, <2.0)'],
)

>>> ENV={}
>>> a="value of a"
>>> b="value of b:%(a)s:"
>>> c="value of c:%(b)s::%(a)s:"
>>> ENV['a']=a
>>> ENV['b']=b
>>> a
'value of a'
>>> b%ENV
'value of b:value of a:'
>>> c
'value of c:%(b)s::%(a)s:'
>>> c%ENV
'value of c:value of b:%(a)s:::value of a:'
>>> (c%ENV)%ENV
'value of c:value of b:value of a:::value of a:'

def _shell():
    "Start an interactive shell connection to the specified hosts."
    def lines():
        try:
            while True:
                yield raw_input("fab> ")
        except EOFError:
            # user pressed ctrl-d
            print
    for line in lines():
        if line == 'exit':
            break
        elif line.startswith('sudo'):
            print "we sudo it"
        else:
            print "runnnn cmd: ",line
>>> _shell()
fab> blub
runnnn cmd:  blub
fab> sudo
we sudo it
fab> exit


def _trap_sigint(signal, frame):
    "Trap ctrl-c and make sure we disconnect everything."
    _disconnect()
    exit(0) 

signal.signal(signal.SIGINT, _trap_sigint) 

default_value="blbu"
print("bla '%s'" % (value1 or default_value))) 

>>> import datetime 
>>> datetime.datetime.now().strftime('%F_%H-%M-%S')
'2012-01-11_19-48-02'
```


Decorators 

A decorator is the name used for a software design pattern. 
Decorators dynamically alter the functionality of a function, method 
or class without having to directly use subclasses or change the source code of the function being decorated. 
```python
def makebold(fn):
    def wrapped():
        return "<b>" + fn() + "</b>"
    return wrapped

def makeitalic(fn):
    def wrapped():
        return "<i>" + fn() + "</i>"
    return wrapped

@makebold
@makeitalic
def hello():
    return "hello world"

print hello() ## returns <b><i>hello world</i></b>
```

```python
>>> s="as sod 230   023  93  02 0230  4034          39"
>>> s.split(' ')
['as', 'sod', '230', '', '', '023', '', '93', '', '02', '0230', '', '4034', '', '', '', '', '', '', '', '', '', '39']
>>> filter(lambda s: s != '', s.split(' '))
['as', 'sod', '230', '023', '93', '02', '0230', '4034', '39']

print >>thefile, sometext
thefile.write(sometext)

"raw" string
big = r"This is a lo"

u or U to make it a Unicode string:
hello = u'Hello\u0020World'
```

Strings are immutable, which means that no matter what operation you do on a string, you will
always produce a new string object
```python
mystr = "my string"
mystr[0]  # 'm'
mystr[-2] # 'n'

mystr[1:4] # 'y s'
mystr[3:]  # 'string'
mystr[-3:] # 'ing'
```

Slices can be extended, that is, include a third parameter that is known as the stride or step of
the slice:
```python
mystr[:3:-1]  # 'gnirt'
mystr[1::2]   # 'ysrn'

list(mystr) # returns ['m','y',' ','s','t','r','i','n','g']
mystr+'oid' # 'my stringoid'
'xo'*3 # 'xoxoxo'
one_large_string = '\n'.join(list_of_lines)
s.isdigit( )
s.toupper( )
haystack.count('needle')
list_of_lines = one_large_string.splitlines( )

>>> passwd="osdoj"
>>> passwd and "sudo -S" or "sudo"
'sudo -S'
>>> passwd=""
>>> passwd and "sudo -S" or "sudo"
'sudo'

user = raw_input('Enter login name: ')

>>> a=input("> ")
> 23
>>> a
23
>>> a=input("> ")
> sdc
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
  File "<string>", line 1, in <module>
NameError: name 'sdc' is not defined

string.atoi()

four different numerical types
int(), long(), float(), complex()

file = open(filename, 'r')
allLines = file.readlines()
file.close()
for eachLine in allLines:
    print eachLine,

print 'My name is', self.__class__ # full class name

_xxx do not import with 'from module import *'
_xxx__ system-defined name
_xxx request private name mangling in classes

mutable:   lists, dictionaries
immutable: numbers, strings, tuples

random:  randint(),uniform(),random(),choice()

[i for i in range(10) if i % 2 == 0]

seq = ["one", "two", "three"]
for i, element in enumerate(seq):
    seq[i] = '%d: %s' % (i, seq[i])

def _treatment(pos, element):
    return '%d: %s' % (pos, element)
[_treatment(i, el) for i, el in enumerate(seq)]

for line in open("real.txt"):

Many functions consume an "iterable" object
• Reductions:
sum(s), min(s), max(s)
• Constructors
list(s), tuple(s), set(s), dict(s)
• in operator
item in s

>>> items = [1, 4, 5]
>>> it = iter(items)
>>> it.next()
1
>>> it.next()
4
>>> it.next()
5
>>> it.next()
Traceback (most recent call last):
File "<stdin>", line 1, in <module>
StopIteration

for x in obj:
    # statements

_iter = iter(obj)
while 1:
    try:
        x = _iter.next()
    except StopIteration:
        break
    # statements
```

Any object that supports iter() and next() is said to be "iterable."
```python
class countdown(object):
    def __init__(self,start):
        self.count = start
    def __iter__(self):
        return self
    def next(self):
        if self.count <= 0:
            raise StopIteration
        r = self.count
        self.count -= 1
        return r

>>> c =
>>> for
...
...
5 4 3 2
>>>
countdown(5)
i in c:
print i,
1
```

A generator is a function that produces a sequence of results instead of a single value
Instead of returning a value, you generate a series of values (using the yield statement)
```python
def countdown(n):
    while n > 0:
        yield n
        n -= 1
>>> for i in countdown(5):
...
print i,
...
5 4 3 2 1
>>>
```

Calling a generator function creates an generator object. However, it does not start running the function.
yield produces a value, but suspends the function, Function resumes on next call to next()

```python
def countdown(n):
    print "Counting down from", n
    while n > 0:
        yield n
        n -= 1
>>> x = countdown(10)
>>> x
<generator object at 0x58490>
>>> x.next()
Counting down from 10
10
>>>
When the generator returns, iteration stops
>>> x.next()
Traceback (most recent call last):
    File "<stdin>", line 1, in ?
StopIteration
```

A generator function is mainly a more convenient way of writing an iterator. You don't have to worry about the iterator protocol (.next, .__iter__, etc.)
A generator is a one-time operation. You can iterate over the generated data once, but if you want to do it again, you have to call the generator function again. This is different than a list (which you can iterate over as many times as you want)

A generated version of a list comprehension
```python
>>> a = [1,2,3,4]
>>> b = (2*x for x in a)
>>> b
<generator object at 0x58760>
>>> for i in b: print b,
...
2 4 6 8
>>>
This loops over a sequence of items and applies an operation to each item. However, results are produced one at a time using a generator

>>> a = [1,2,3,4]
>>> b = [2*x for x in a]
>>> b
[2, 4, 6, 8]
>>> c = (2*x for x in a)
<generator object at 0x58760>
>>>

General syntax
(expression for i in s if cond1
            for j in t if cond2
            ...
            if condfinal)
What it means
for i in s:
    if cond1:
        for j in t:
            if cond2:
                ...
                if condfinal: yield expression
```

The parens on a generator expression can dropped if used as a single function argument
sum(x*x for x in s)  <- Generator expression

Generator functions:
```python
def countdown(n):
    while n > 0:
        yield n
        n -= 1
```
Generator expressions
squares = (x*x for x in s)

In both cases, we get an object that generates values (which are typically consumed in a for loop)
```pyhton
# read the size from logs and sum
wwwlog = open("access-log")
total = 0
for line in wwwlog:
    bytestr = line.rsplit(None,1)[1]
    if bytestr != '-':
        total += int(bytestr)
print "Total", total

# generators
wwwlog     = open("access-log")
bytecolumn = (line.rsplit(None,1)[1] for line in wwwlog)
bytes      = (int(x) for x in bytecolumn if x != '-')
print "Total", sum(bytes)
```
access-log -> wwwlog -> bytecolumn ->  bytes -> sum() -> total


this is a simple scanner in python.

work: call a system ping (with popen() ) and look for ttl count.

if count ~64 -> linux, count ~128 -> windows, count ~255 -> BSD/Router

then it connect to well known ports and look for respond.

limits: only certain ports and only TCP

trace2.py
```python
#!/usr/bin/python

import sys, os, socket, re


class Scan:
  def __init__(self):
    #print "create socket ..."
    self.scanNew=None
    self.allPorts={"ftp-data":20, "ftp":21,"smtp":25, "http":80, "pop3":110, "imap3":220,  "https":443,
                    "ldap":389 }
    self.linuxPorts={"ssh":22, "dns":53, "snmp":161, "snmp-trap":162}
    self.windowPorts={"netbios-ns":137, "netbios-dgm":138, "netbios-ssn":139,"microsoft-ds":445 }

  def ping(self, ip):
    findttl = re.compile(r"ttl=(\d{1,3}) ")
    pingpipe = os.popen("ping -W 1 -c 1 "+ip,"r")
    for line in pingpipe.readlines():
      if "ttl" in line:
        result = re.findall(findttl,line)
        return int(result[0])
    return -1  

  def connectTCP(self, ip, port, portname):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.settimeout(1)
    try:
      s.connect((ip, port))
      print "connect to %s : %d (%s) was succesfull"%(ip, port, portname)
    except:
      pass
      #print "failing to connect %s : %d (%s)"%(ip, port, portname)
    s.close()

  def scann(self, ip):
    ttl=self.ping(ip)
    if( ttl==-1):
      print "IP %s not reachable"%ip
    elif( ttl==0 ):
      print "huch, ttl is zero"
    elif( ttl>0 and ttl<65 data-blogger-escaped-br="">      print " %s possible LINUX and is Alive"%ip
      for port in self.allPorts.keys():
        self.connectTCP(ip, self.allPorts[port], port)
      for port in self.linuxPorts.keys():
        self.connectTCP(ip, self.linuxPorts[port], port)
    elif( ttl>64 and ttl<129 data-blogger-escaped-br="">      print " %s possible WINDOWS and is Alive"%ip
      for port in self.allPorts.keys():
        self.connectTCP(ip, self.allPorts[port], port)
      for port in self.windowPorts.keys():
        self.connectTCP(ip, self.windowPorts[port], port)
    else:
      print " %s possible BSD or Router and is Alive"%ip
      for port in self.allPorts.keys():
        self.connectTCP(ip, self.allPorts[port], port)
      for port in self.linuxPorts.keys():
        self.connectTCP(ip, self.linuxPorts[port], port)

if( len(sys.argv) != 4):
  print "%s ip(first triple) begin end"%sys.argv[0]
  print "  example:"
  print "  %s 123.45.67  10 20"%sys.argv[0]
  sys.exit(2)

iptriple=sys.argv[1]
begin=int(sys.argv[2])
end=int(sys.argv[3])

scan=Scan()

for ip4 in range(begin, end):
  ip="%s.%d"%(iptriple,ip4)
  scan.scann(ip)
```


you can set your own exception handler, this is done by
sys.excepthook = your_func
for that you must define a function, with following parameters:
```python
def your_func(exc_type, exc_obj, exc_tb):
    print "whoaaa my exception"
```

then you can call an exception
5/0
=>
whoaaa my exception
```
def your_func(exc_type, exc_obj, exc_tb):
    import traceback
    l = traceback.format_exception(exc_type, exc_obj, exc_tb)
    print type(l)
    print l

=>
['Traceback (most recent call last):\n', ' File "./t1.py", line 37, in \n 5/0\n', 'ZeroDivisionError: integer division or modulo by zero\n']
traceback.format_exception(...) return us a list of information
as a normal exception traceback
```

functions numbers
```python
int(), long8), float(), round(), hex(), oct(), pow(), cmp()

s1+s2 merge

s1*n s1+s1+s1+s1+...
```
functions strings:
```python
org(), chr(), str(), repr(), unicode(), len()

s.count(), s.encode(), s.endswith(), s.find(), s.isalnum(), s.iksalpha(), s.isdigi(), s.islower(), s.isspace(), s.join(), s.lstrip(), s.replace(), s.rfind(), s.rstrip(), s.split(), s.startswith(), s.strip(), s.swapcase()
```

List:
```python
array=[1,2,3,4]

len(array)

array[1]="blub"

array[2]=["bla", [1,2,3], 'ups']

append(), extend(), count(), index(), insert(), remove(), pop(), reverse(), sort()

range()

range(4)

[0,1,2,3]

range(5,10,2]

[5,7,9]
```

Tuples

same as list but imutable
```python
t1=(1,2,3)
```

indicies and slices
```python
s[4:]

s[4:7]

s[:-7]

s[-4:]

s[:]

max(), min(), len()

a,b,c = [ 1, 2, 3 ]
```
del delete a varaible
```python
a= 1

del a
```

assoziative lists, hash
```python
h = { k:v, k2:v2, k3:v3 }

t={"peter":23450, "anna":39454, "blub":439549}

t["blub"]

items(), keys(), values(), has_key(), update()

t.has_key("anna")

len(), del()

None, type(), in-operator

if 2 in lists:

...

if not "a" in string:

```

Functions:
```python
def p(n):

"bla bla, describe function for help"

for a in range(2,n):

...

p(3)

def fct(a, b="bla"):

...

fct(3, "lala")

fct(3)
```

several arguments with *
```python
def h(g, *args):

for m in args:

...

h("bl", "blub", "abc", "dbc")

def h(**args):

if len(args==0): return

for n in args.keys():

print args[n]+" : "+ n

h(v1="blub", v2="aga")

def complexparameters(firma, delim="-", *address, **inventars):

def doNothing():
  pass
```
functionale coding
```python
add = lambda x,y: x+y

add(2,3)

map(ord, "string")

[115,116,114,...]

[ord(a) for a in "string"]

map(lambda x:x+1,(1,2,3))

map for tuple (1,2,3) x+1

def p(n):
    for a in range(2,n):
        if n%a == 0:
            return 0
        else:
            return 1

filter(p, range(100))

reduce(function, collection)

a=5

exec("var" +str(a)+"="+str(a))

=> var5=5
```

docstrings:
```python
def bla():

""" blal bla"""

...

bla.__doc__
```


bottlepy.org

Bottle is a fast, simple and lightweight WSGI micro web-framework for Python. It is distributed as a single file module and has no dependencies other than the Python Standard Library.

How to use: simple, download and copy the file bottle.py in your directory. (or you can install it, see the README file).

myweb01.py
```pyton
from bottle import route, run

@route('/test/:file')
def hello(file):
    if file=="test":
        return &lt;h1&gt;Testing!&lt/h1&gt'
    else:
        return 'nothing here to see'

run(host='localhost', port=8080)
```

start with: python myweb01.py

go to browser and go to http://localhost:8080/test/test

you will get from console:
```shell
Bottle server starting up (using WSGIRefServer())...
Listening on http://localhost:8080/
Use Ctrl-C to quit.

localhost.localdomain - - [18/Jul/2011 15:27:47] "GET /test/test HTTP/1.1" 200 17
```

and in the browser the message Testing!

for more info go to Bottle documentation.


Here is part 2 about python web framework bottle.

let see code myweb02.py
```python
from bottle import route, run, get, post, request, redirect

@route('/')
@route('/index.html')
def redirect_index():
    redirect("/object/4")

@route('/object/:id#[0-9]+#')
def view_object(id):
    return "Object ID: %d" % int(id)

run(host='localhost', port=8080)
```

with import we set the functions which we need:

* run - start the server
* run(host='localhost', port=8080) - self explained or?
* route - is a decorator, which say how the URI should be resolved.
* decorator - see galileo book (german) or english: short: Decorators dynamically alter the functionality of a function, method, or class without having to directly use subclasses or change the source code of the function being decorated. A Python decorator is a specific change to the Python syntax that allows us to more conveniently alter functions and methods (and possibly classes in a future version).

there are other decorators too:

* get - simulate the GET request
* post - simulate the POST request
* put, delete - simulates the PUT, DELETE requests
* further imports from bottle are
* request - get the formular datas
* redirect - redirect the page

In function redirect_index(), we redirect the / and index.html to /object/4.

Thus we call the function view_object(id), which the id is a number given by dynamic routing /:id (thus we can change the input of URI) and only numbers #[0-9]+#. This is a regular expression [0-9]+ number 0 to 9 1 or many times. If we put /object/asd3, the we get a 404 Error.

The functions itself return a string, which will be displayed.

let see how get and post routing work: myweb03.py
```python
from bottle import run, get, post, request

#@route('/login')
@get('/login')
def login_form():
    return '''<form action="/login" method="POST">
                <input name="name"     type="text" />
                <input name="password" type="password" />
                <input type="submit" value="Send"/>
              </from>'''

#@route('/login', method='POST')
@post('/login')
def login_submit():
    name     = request.forms.get('name')
    password = request.forms.get('password')
    if name==password:
        return "<p>Your login was correct</p>"
    else:
        return "<p>Login failed</p>"


run(host='localhost', port=8080)
```

`@get('/login')` - set the /login routing to function login_form() input for a get request.

the login_form() generate a html formular and call the /login as a post request.

@post('/login') - set the post request routing for login. The login_submit() get the setted fields from formular with request.forms.get('fieldname'). Next it test if the password similar to name and set the output.

If you simple call /login, you get the formular, after send you go to /login via post and get the results.


now we want to call static and templates.

let see myweb04.py:
```python
from bottle import run, route, static_file

@route('/:filename')
def getstaticfile(filename):
    return static_file(filename, root='./files')

run(host='localhost', port=8080)
```

to get the html-files you call static_file(filename, root)

where the root is the path to the files.

If you now call /index.html, the static_file() will be return the file index.html from the path.

If there no such file, then we get 404 Error.

Templates:
```python
from bottle import run, route, view

@route('/hello')
@route('/hello/:name')
@view('template1.tmpl')
def hello(name='World'):
    return dict(name=name)

run(host='localhost', port=8080)
```

With `@view()` you set the template file name. The function return a dictionary for the template.

The template itself has following content:
```html
%if name == 'World':
    <h1>Hello {{name}}!</h1>
    <p>This is a test.</p>
%else:
    <h1>Hello {{name.title()}}!</h1>
    <p>How are you?</p>
%end
```

%if, else, end is similar to python syntax.

```python
f = (x for x in xrange(100)) # выражение - генератор
c = [x for x in xrange(100)] # генератор списков

def prime(lst):
    for i in lst:
        if i % 2 == 0:
            yield i

>>> f = prime([1,2,3,4,5,6,7])
>>> list(f)
[2, 4, 6]
>>> next(f)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
StopIteration
```

Python 3.3 : yield from.  because of "yield and for"
```python
def generator_range(first, last):
    for i in xrange(first, last):
        yield i

def generator_range(first, last):
    yield from range(first, last)

class Hello:
    def __del__(self):
        print "destructor"
    def __enter__(self):
        print "enter a block"
    def __exit__(self, exp_type, exp_value, traceback):
        print "exit a block"
```

```python
if file.endswith('.bz2'):
    os.path.abspath(os.path.dirname(sys.argv[0]))
    execfile(fullpath)
    os.environ['AUTODIR']
if not os.path.isdir(self.resultdir):
    os.mkdir(self.resultdir)
if x not in list1:
    if (src.startswith('http://')) or (src.startswith('ftp://')):
        os.getcwd()
        urllib.urlretrieve(src, dest)
        shutil.copyfile(src, dest)
if os.path.isfile(dest):
    os.remove(dest)

signal.signal(signal.SIGPIPE, signal.SIG_DFL)
signal.signal(signal.SIGPIPE, signal.SIG_IGN)
os.dup2(newfd, self.fd)
filehandle = os.fdopen(self.fd, 'w')
os.fdopen(fd [, mode='r' [, bufsize]]) -> file_object
    Return an open file object connected to a file descriptor.
os.dup2(old_fd, new_fd)
    Duplicate file descriptor.
os.dup(fd) -> fd2
    Return a duplicate of a file descriptor.
os.pipe() -> (read_end, write_end)
    Create a pipe.
lines[i] = re.sub(r'^timeout.*/', 'timeout 60', lines[i])
```

Copy data from src to dst
```python
shutil.copyfile(src, dst)
```

pickle - Create portable serialized representations of Python objects.
```python
>>> l1
[1, 2, 3, 4]
>>> pickle.dumps(l1)
'(lp0\nI1\naI2\naI3\naI4\na.'
```
