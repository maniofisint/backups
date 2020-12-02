class ArrayStack:
    def __init__ (self, max = 100):
        self.data = [None] * max
        self.max = max
        self._top = -1

    def __len__(self):
        return self._top +1

    def is_empty(self):
        return self._top == -1
    
    def push(self, e):
        if self._top >= self.max -1:
            raise Exception('Stack is Full')
        self._top += 1
        self.data[self._top] = e

    def top(self):
        if self.is_empty():
            raise Exception('Stack is empty')
        return self.data[self._top]

    def pop(self):
        if self.is_empty():
            raise Exception('stack is empty')
        e = self.data[self._top]
        self._top -= 1
        return e


class ArrayStack2:
    def __init__(self):
        self.data = []

    def __len__(self):
        return len(self.data)

    def is_empty(self):
        return len(self.data) == 0

    def push(self, e):
        self.data.append(e)
    
    def top(self):
        if self.is_empty():
            raise Exception('stack is empty')
        return self.data[-1]

    def pop(self):
        if self.is_empty():
            raise Exception ('stack is empty')
        return self.data.pop()

class LinkedStack:
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