#!/usr/bin/python

from A import *
from B import *
from C import *

data=[1,2,3,4,5]

b=B(data, "B")
c=C(data, "C")

b.printme()
b.tu1()
b.printme()
c.printme()
c.tu1()
b.printme()
c.printme()
