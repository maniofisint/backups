class Stack:
    class Node:
        def __init__(self, element, next):
            self.element = element
            self.next = next

    def __init__(self):
        self._top = None
        self.size = 0

    def __len__(self):
        return self.size

    def is_empty(self):
        return self.size == 0

    def push(self, e):
        self._top = self.Node(e, self._top)
        self.size += 1

    def top(self):
        if not self.is_empty():
            return self._top.element
        else:
            raise Exception('Stack is Empty')


    def pop(self):
        if self.is_empty():
            raise Exception('Stack is empty')

        temp = self._top.element
        self._top = self._top.next
        return temp

    def __str__(self):
        p = self._top
        l = []
        while p is not None:
            l.append(p.element)
            p = p.next
        return str(l)

class Queue:
    class Node:
        def __init__(self, element, next):
            self.element = element
            self.next = next

    def __init__(self):
        self.front = None
        self.rear = None
        self.size = 0

    def __len__(self):
        return self.size

    def is_empty(self):
        return self.size == 0

    def front_element(self):
        if not self.is_empty():
            return self.front.element
        else:
            raise Exception('Queue is empty')


    def enqueue(self, e):
        newest = self.Node(e, None)
        if self.is_empty():
            self.front = newest
        else:
            self.rear.next = newest
        self.rear = newest
        self.size += 1

    def dequeue(self):
        if self.is_empty():
            raise Exception('Queue is empty')
        temp = self.front.element
        self.front = self.front.next
        self.size -= 1
        return temp

    def __str__(self):
        p = self.front
        l = []
        while p is not None:
            l.append(p.element)
            p = p.next
        return str(l)
        
def sort(Q, S):
    Q.enqueue(None)

    while len(Q) > 1:
        Max = Q.dequeue()
        p = Q.dequeue()
        while p is not None:
            if p > Max:
                Q.enqueue(Max)
                Max = p
                p = Q.dequeue()
            else:
                Q.enqueue(p)
                p = Q.dequeue()

        S.push(Max)
        Q.enqueue(p)


from random import shuffle
x = [ i for i in range(14)]
shuffle(x)

Q = Queue()
S = Stack()

for i in x:
    Q.enqueue(i)
        
print(Q)
sort(Q, S)
print(S)