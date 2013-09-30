
import copy

class A(object):
    def __init__(self, data, name):
        self.data=copy.deepcopy(data)
        self.name=name
    
    def tu1(self):
        raise NotImplementedError( "Should have implemented this" )
        
    def printme(self):
        print "meine name: ",self.name
        print self.data
        print "-"*15
