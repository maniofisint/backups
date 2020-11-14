class LinkedList:
    class Node:
        def __init__(self, element, next):
            self.element = element
            self.next = next

    def __init__ (self):
        self.head = None
        self.size = 0

    def __len__(self):
        return self.size

    def is_empty(self):
        return self.size == 0

    def first(self):
        if not self.is_empty():
            return self.head.element
        else:
            raise Exception('list is empty')

    def insert_first(self, e):
        newest = self.Node(e, self.head)
        self.head = newest
        self.size += 1

    def insert_last(self, e):
        if self.is_empty():
            self.insert_first(e)
        else:
            p = self.head
            while p.next is not None:
                p = p.next
            self._insert_after(e, p)

    def delete_first(self):
        if self.is_empty():
            raise Exception('list is empty')
        temp = self.head
        self.head = self.head.next
        self.size -= 1
        temp.element = temp.next = None

    def _insert_after(self, e, p):
        if p is None:
            raise Exception('Elemnt is empty')
        else:
            p.next = self.Node(e, p.next)
            self.size += 1

    def _delete_after(self, p):
        if self.is_empty() or p is None or p.next is None:
            raise Exception('Element does not exist')
        temp = p.next
        p.next = temp.next
        self.size -= 1
        temp.element = temp.next = None

    def pure_list(self):
        p = self.head
        while p is not None:
            q = p
            while q.next is not None:
                if p.element == q.next.element:
                    self._delete_after(q)
                else:
                    q = q.next
            p = p.next

    def traverse(self, l):
        p = l
        while p is not None:
            print(p.element, end=' ')
            p = p.next
        print()

    def delete_all(self):
        if self.is_empty():
            return
        while self.head.next is not None:
            self._delete_after(self.head)
        self.head.element = None
        self.head = None
        self.size -= 1

    def delete_key(self, key):
        if self.is_empty():
            raise Exception('list is empty')

        elif self.head.element == key:
            self.delete_first()
        else:
            p = self.head
            while p.next is not None and p.next.element != key:
                p = p.next
            if p.next.element == key:
                self._delete_after(p)
            else:
                raise Exception('key not found')
    
    def delete_at(self, pos):
        if self.is_empty():
            raise Exception('list is empty')

        elif 0 <= pos < self.size():
            p = self.head
            for _ in range(pos-1):
                p = p.next
            self._delete_after(p)
        else:
            raise Exception('out of range')

    def __str__(self):
        s = []
        p = self.head
        while p is not None:
            s.append(p.element)
            p = p.next
        return str(s)

    def nr_reverse(self):
        p = self.head
        q = p.next
        r = q.next
        p.next = None
        while r != None:
            q.next = p
            p = q
            q = r
            r = q.next
        q.next = p
        self.head = q

    def _re_reverse(self,p):
        if p is None or p.next is None:
            return p

        q = p.next
        r = self._re_reverse(q)
        q.next = p
        p.next = None
        return r

    def r_reverse(self):
        self.head = self._re_reverse(self.head)

    def Merge_sort(self):
        self.head = self._merge_sort(self.head)

    def _merge_sort(self, l):
        if l.next is None :
            return
        l1, l2 = self._split(l)
        l1 = self._merge_sort(l1)
        l2 = self._merge_sort(l2)
        l = self._merge_list(l1, l2)
        return l

    def _split(self, l):
        if l is None:
            return None, None
        elif l.next is None:
            return None, l
        l1 = l
        l2 = l.next
        l1.next , l2.next = self._split(l2.next)
        return l1 , l2
    
    def _merge_list(self, l1, l2):
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        if l1.element <= l2.element:
            l1.next = self._merge_list(l1.next, l2)
            return l1
        else:
            l2.next = self._merge_list(l1, l2.next)
            return l2

    def foo(self):
        l1 , l2 = self._split(self.head)
        print(l1)
        print(l2)
        l3 = self._merge_list(l1,l2)
        print(l3)


if __name__ == '__main__':
    from random import random,randint
    ll = LinkedList()
    
    
    put_numbers_1 = """
for i in range(12):
    ll.insert_first(i)
    """
    put_numbers_2 ="""
for i in range(13):
    ll.insert_last(i)"""

    exec(put_numbers_2)
    print(ll)
    #ll.delete_all()
    ll.delete_key(11)
    print(ll)
    ll.nr_reverse()
    print(ll)
    """ll.r_reverse()
    print(ll)
    ll.foo()
    print(ll)
    ll.foo2()"""

    ll.Merge_sort()
    print(ll)
    