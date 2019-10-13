class Bheap:
    def __init__(self,a):
        self.heap = a
        self.l = len(a)
        for i in range(self.l // 2 - 1, -1, -1):
            self.heapify(i)
    def left(self,i):
        return (2*i)
    def right(self,i):
        return (2*i+1)
    def parent(self,i):
        return i//2
    def heapify(self,i):
        lt = 2 * i + 1
        rt = 2 * (i + 1)
        if lt < self.l and rt < self.l:
            if self.heap[lt] < self.heap[rt]:
                x = lt
            else:
                x = rt
        elif lt < self.l and rt >= self.l:
            #x = lt
            x=lt
        elif rt < self.l and lt >= self.l:
            #x = rt
            x=rt
        else:
            return
        #print(self.heap[i], self.heap[x])
        if self.heap[i] > self.heap[x]:
            t = self.heap[i]
            self.heap[i] = self.heap[x]
            self.heap[x] = t
            self.heapify(x)
    def maximum(self):
        return self.heap[0]
    def extractmax(self):
        tmp=self.heap[0]
        t=self.heap[0]
        self.heap[0]=self.heap[-1]
        self.heap[-1]=t
        self.l=self.l-1
        #print(self.l)
        #print(self.heap)
        self.heap.pop()
        self.heapify(0)
        return tmp
    def printh(self):
        if len(self.t)>0:
            print(self.t)
    def insert(self,val):
        self.l=self.l+1
        self.heap.append(val)
        for i in range(self.l//2-1,-1,-1):
            self.heapify(i)
    def heapsort(self):
        for i in range(self.l-1):
            l=self.extractmax()
            self.heap.append(l)
def main():
    a = [21,11,5,9,22,1,18,14,19]
    t = Bheap(a)
    print(t.heap)
    t.heapsort()
    print(t.heap)
if __name__ == '__main__':
     main()
