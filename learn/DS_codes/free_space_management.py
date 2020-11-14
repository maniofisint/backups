class courseList:
    def __init__(self, max = 100):
        self.max = max
        self.next = [None] * max
        self.element = [None] * max
        self.prev = [None] * max
        self.avail = 0
        self.head = None
        self.size = 0
        for i in range (self.max -1):
            self.next[i] = i + 1

    def allocate (self):
        if self.avail is None:
            raise Exception ('out of space')
        x = self.avail
        self.avail = self.next[self.avail]
        return x

    def free (self, x):
        self.next[x] = self.avail
        self.avail = x

    def is_empty ( self):
        return self.size == 0

    def insert_fist (self, e):
        index = self.allocate()

        self.next[index] = self.head
        self.element[index] = e
        self.prev[index] = None

        if not self.is_empty():
            self.prev[self.head] = index
        self.head = index
        self.size += 1

    def delete_first(self):
        if self.is_empty():
            raise Exception ('last is empty')
        index = self.head
        e = self.element[index]
        self.head = self.next[self.head]
        self.size -= 1

        self.free (index)
        return e

        