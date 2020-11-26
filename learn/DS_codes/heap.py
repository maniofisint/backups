import math

class heap:

    def __init__(self):
        self.data = []

    def parent(self, i):
        return (i-1)//2

    def left_child(self, i):
        return i*2+1

    def right_child(self, i):
        return i*2+2

    def has_left(self, i):
        return self.left_child(i) < len(self.data)

    def has_right(self, i):
        return self.right_child(i) < len(self.data)

    def swap(self, i, j):
        self.data[i], self.data[j] = self.data[j], self.data[j]

    def is_empty(self):
        return len(self.data) == 0

    def max_heap_increase_key(self, i, key):
        self.data[i] = key 
        while i > 0 and self.data[i] > self.data[self.parent(i)]:
            self.swap(i, self.parent(i))
            i = self.parent(i)

    def insert(self, key):
        self.data.append(-math.inf)
        self.max_heap_increase_key(len(self.data)-1, key)

    def max_heapify(self, i):
        l = self.left_child(i)
        r = self.right_child(i)

        if self.has_left(i) and self.data[l] > self.data[i]:
            bigchild = l
        else:
            bigchild = i

        if self.has_right(i) and self.data[r] > self.data[bigchild]:
            bigchild = r

        if not bigchild == i:
            self.swap(i, bigchild)
            self.max_heapify(bigchild)

    def build_heap(self, A):
        self.data = [a for a in A]
        for i in range(len(self.data//2, -1, -1)):
            self.max_heapify(i)



            