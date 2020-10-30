# methods to find min(max) of a stack or a queue in O(1)
class stack:
    """
    to find minimum of stack in O(1), I used another stack (min_stack) which top of it is minimum of main stack
    to update min_stack, while pushing a new element ,it should be pushed to min_stack in case it is smaller or equal to top of min_stack
    and if top of both stacks are equal, min_stak most be poped when poping main stack
    finding maximum is the same
    """

    class Node:
        def __init__(self, element, next):
            self.element = element
            self.next = next


    def __init__(self):
        self.top = None
        self.min = None
        self.max = None
        self.size = 0

    def __len__(self):
        return self.size

    def is_empty(self):
        return self.size == 0


    def update_min(self, e = None):                                     # used in both pushing and poping
        if e is None:                                                   # called in pop
            if self.top.element == self.min.element:          
                self.min = self.min.next

        elif self.min is None or e <= self.min.element:                 # called in push
            self.min = self.Node(e, self.min)                           

    def update_max(self, e = None):                                     # similar to self.update_min()
        if e is None:
            if self.top.element == self.max.element:
                self.max = self.max.next

        elif self.max is None or e >= self.max.element:
            self.max = self.Node(e, self.max)

    def push(self, e):
        self.top = self.Node(e, self.top)
        self.update_min(e)
        self.update_max(e)
        self.size += 1

    def pop(self):
        if self.is_empty():
            raise Exception('Stack is empty')

        temp = self.top.element
        self.update_min()
        self.update_max()
        self.size -= 1
        self.top = self.top.next
        return temp

    def minimum(self):
        if self.is_empty():
            raise Exception('stack is empty')

        return self.min.element

    def maximum(self):
        if self.is_empty():
            raise Exception('stack is empty')
        return self.max.element

    def __str__(self):
        p = self.top
        l = []
        while p is not None:
            l.append(p.element)
            p = p.next
        return str(l)

    # just for debuging
    def foo(self):
        print()
        p = self.top
        l = []
        while p is not None:
            l.append(p.element)
            p = p.next
        print(l)

        p = self.min
        l = []
        while p is not None:
            l.append(p.element)
            p = p.next
        print(l)

        p = self.max
        l = []
        while p is not None:
            l.append(p.element)
            p = p.next
        print(l)

    


class queue:
    """ 
    to find minimum , used a list which the front element is minimum of queue
    """
    class Node:
        def __init__(self, element, next):
            self.element = element 
            self.next = next

    def __init__(self):
        self.front = None
        self.rear = None
        self.min_head = self.Node(None, None)
        self.max_head = self.Node(None, None)
        self.size = 0

    def __len__(self):
        return self.size

    def is_empty(self):
        return self.size == 0

    def update_min(self, e = None):
        if e is None:
            if self.min_head.next.element == self.front.element:
                self.min_head.next = self.min_head.next.next
        else:
            newest = self.Node(e, None)
            p = self.min_head
            while p.next is not None:
                if e < p.next.element:
                    break
                p = p.next
            p.next = newest

    def update_max(self, e = None):
        if e is None:
            if self.max_head.next.element == self.front.element:
                self.max_head.next = self.max_head.next.next
        else:
            newest = self.Node(e, None)
            p = self.max_head
            while p.next is not None:
                if e > p.next.element:
                    break
                p = p.next
            p.next = newest
    
    def enqueue(self, e):
        newest = self.Node(e, None)
        if self.is_empty():
            self.front = newest
        else:
            self.rear.next = newest
        self.rear = newest
        self.update_min(e)
        self.update_max(e)
        self.size += 1

    def dequeue(self):
        if self.is_empty():
            raise Exception('Queue is empty')
        temp = self.front.element
        self.update_min()
        self.update_max()
        self.front = self.front.next    
        self.size -= 1
        return temp

    def minimum(self):
        return self.min_head.next.element

    def maximum(self):
        return self.max_head.next.element

#debuging
    def foo(self):
        print()
        p = self.front
        l = []
        while p is not None:
            l.append(p.element)
            p = p.next
        print(l)

        p = self.min_head.next
        l = []
        while p is not None:
            l.append(p.element)
            p = p.next
        print(l)

        p = self.max_head.next
        l = []
        while p is not None:
            l.append(p.element)
            p = p.next
        print(l)


if __name__ == "__main__":

    STACK = """

s = stack()
for i in range(12):
    s.push(i)

s.foo()
s.pop()
s.foo()

for i in range(4, -5, -1):
    s.push(i)

s.foo()

print(s.minimum())
print(s.maximum())
"""

    QUEUE = """
q = queue()
for i in range(12):
    q.enqueue(i)

q.foo()

q.enqueue(11)
q.foo()

q.enqueue(11)
q.foo()

q.dequeue()
q.foo()

q.enqueue(-1)
q.foo()

q.enqueue(20)
q.foo()

q.dequeue()
q.foo()

print(q.minimum())
print(q.maximum())
"""
exec(STACK)
exec(QUEUE)