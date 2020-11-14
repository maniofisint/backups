class foo:

    def __init__(self, max = 99):
        self.max = max 
        self.memory = [None] * self.max
        self.header = self.Node(None, None, None)
        self.trailer = self.Node(None, None, None)
        self.set_next(self.header, self.trailer)
        self.set_prev(self.trailer, self.header)
        self.avail = list()
        self.avail.append((0, max-1))
        self.size = 0

    def allocate(self):
        """if len(self.avail.) == 0:
            raise Exception("mempry is full, can't allocate more")"""
        temp = self.avail.pop()
        if temp[0] +5  <= temp[1]:
            self.avail.append((temp[0]+3 , temp[1]))
        return temp[0]

    def free(self, p):
        self.avail.append((p, p+2))
        self.avail.sort()
        self.memory[p] = self.memory[p+1] = self.memory[p+2] = None

    def Node(self, element, prev, next):
        index = self.allocate()
        self.memory[index] = prev
        self.memory[index + 1] = element
        self.memory[index + 2] = next
        return index

    def prev(self, p):
        return p

    def element(self, p):
        return p+1

    def next(self, p):
        return p+2


    def set_next(self, p, next):
        self.memory[self.next(p)] = next

    def set_prev(self, p, prev):
        self.memory[self.prev(p)] = prev

    def set_element(self, p, element):
        self.memory[self.element(p)] = element

    def get_element(self, p):
        return self.memory[p+1]

    def get_next(self, p):
        return self.memory[p+2]

    def get_prev(self, p):
        return self.memory[p]


    def __len__(self):
        return self.size

    def is_empty(self):
        return self.size == 0

    def first(self):
        if not self.is_empty():
            return self.get_element(self.get_next(self.header))
        else:
            raise Exception('list is empty')

    def _insert_after(self, e, p):
        if p is None:
            raise Exception('element does not exist')

        temp = self.get_next(p)
        self.set_next(p, self.Node(e, p, self.get_next(p)))
        self.set_prev(temp, self.get_next(p))
        self.size += 1

    def _delete_after(self, p):
        """if self.is_empty() or p is None or p.next == self.trailer:
            raise Exception('Element Does Not exist')"""

        temp = self.get_next(p)
        if self.get_next(temp) is not None:
            self.set_prev(self.get_next(temp), p)

        self.set_next(p, self.get_next(temp))
        self.free(temp)
        self.size -= 1

    def insert_first(self, e):
        self._insert_after(e, self.header)

    def insert_last(self, e):
        self._insert_after(e, self.get_prev(self.trailer))


if __name__ == "__main__":
    ll = foo()
    print(ll.memory)