class ArrayQueue:
    def __init__(self, max = 100):
        self.data = [None] * max
        self.front = 0
        self.rear = 0
        self.max = max

    def __len__(self):
        return (self.max - self.front + self.rear ) % self.max

    def is_empty(self):
        return self.front == self.rear

    def is_full(self):
        return self.__len__ == self.max -1

    def front_element(self):
        if not self.is_empty():
            return self.data[self.front]
        else:
            raise Exception('Queue is empty')

    def enqueue(self, e):
        if self.is_full:
            raise Exception('Queue is Full')
        self.data[self.rear] = e
        self.rear = (self.rear + 1) % self.max

    def dequeue(self):
        if self.is_empty():
            raise Exception('Queue is empty')

        temp = self.data[self.front]
        self.front = (self.front + 1) % self.max
        return temp


class LinkedQueue:
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


        