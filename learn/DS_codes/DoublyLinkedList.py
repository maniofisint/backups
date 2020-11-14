class DoublyLinkedList:
    class Node:
        def __init__(self, element, prev, next):
            self.element = element
            self.prev = prev
            self.next = next
            

    def __init__(self):
        self.header = self.Node(None, None, None)
        self.trailer = self.Node(None, None, None)
        self.header.next = self.trailer
        self.trailer.prev = self.header
        self.size = 0
        self.avail = []
        self.avail.append(1)
        self.avail.append(1)
        self.avail.append(1)

    def __len__(self):
        return self.size

    def is_empty(self):
        return self.size == 0

    def first(self):
        if not self.is_empty():
            return self.header.next.element
        else:
            raise Exception('list is empty')

    def _insert_after(self, e, p):
        if p is None:
            raise Exception('element does not exist')
        temp = p.next
        p.next = self.Node(e, p, p.next)
        temp.prev = p.next
        self.size += 1

    def _delete_after(self, p):
        if self.is_empty() or p is None or p.next == self.trailer:
            raise Exception('Element Does Not exist')

        temp = p.next
        if temp.next is not None:
            temp.next.prev = p

        p.next = temp.next
        temp.element = temp.next = temp.prev = None
        self.size -= 1

    def insert_first(self, e):
        self._insert_after(e, self.header)

    def insert_last(self, e):
        self._insert_after(e, self.trailer.prev)

        

ll = DoublyLinkedList()
print(ll.avail)