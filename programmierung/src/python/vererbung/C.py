from A import *

class C(A):
    def tu1(self):
        for i, x in enumerate(self.data):
            self.data[i]=x-13

