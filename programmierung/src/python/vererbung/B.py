from A import *

class B(A):
    def tu1(self):
        for i, x in enumerate(self.data):
            self.data[i]=x+23

