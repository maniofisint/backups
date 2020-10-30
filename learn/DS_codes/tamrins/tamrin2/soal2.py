class number:
    class Node:
        def __init__(self, element, next):
            self.element = element
            self.next = next

    def __init__(self):
        self.head = self.Node(None, None)
        self.tail = self.Node(None, None)
        self.size = 0

    def __len__(self):
        return self.size

    def is_empty(self):
        return self.size == 0 
    
    def first(self):
        if self.is_empty():
            raise Exception('last is empty')
        return self.head.element

    def insert_last(self, e):
        if len(self) == 0:
            self.head.element = e
        elif len(self) == 1:
            self.tail.element = e
            self.head.next = self.tail
        else:
            newone = self.Node(e, None)
            self.tail.next = newone
            self.tail = newone
        self.size += 1

    def __str__(self):
        p = self.head.next
        s = str()
        while p is not None:
            s += str(p.element)
            p = p.next

        s = s[::-1]
        index = 0
        while s[index] == '0' and index < len(s)-1 :
            if index + 1 < len(s):
                index += 1
        s = s[index:]
        if self.head.element == -1:
            s = '-' + s
        if s == '-0':
            s = '0'
        return s

def convert_to_list(A):
    a = number()
    if A[0] == '-':
        a.insert_last(-1)
        for i in range(len(A)-1, 0 , -1):
            a.insert_last(int(A[i]))
    else:
        a.insert_last(1)
        for i in range(len(A)-1 , -1 , -1):
            a.insert_last(int(A[i]))
    return a 

def is_first_bigger(a, b):
    is_a_bigger = False

    if len(a) > len(b):
        is_a_bigger = True
    elif a.tail.element > b.tail.element:
        is_a_bigger = True
    else:
        ap = a.head.next
        bp = b.head.next
        while ap is not None:
            if ap.element > bp.element:
                is_a_bigger = True
            elif ap.element < bp.element:
                is_a_bigger = False
            ap = ap.next
            bp = bp.next

    return is_a_bigger

def sum(a, b):
    c = number()
    aSign = a.head.element
    bSign = b.head.element

    if aSign * bSign == 1:
        c.insert_last(aSign)
        aSign = bSign = 1
    else:
        is_a_bigger = is_first_bigger(a, b)
        if is_a_bigger:
            c.insert_last(aSign)
            aSign = 1
            bSign = -1
        else:
            c.insert_last(bSign)
            aSign = -1
            bSign = 1

    carry = 0
    ap = a.head.next
    bp = b.head.next
    
    while not(ap is None and bp is None):

        aDigit = 0 if ap is None else ap.element
        bDigit = 0 if bp is None else bp.element

        x = aDigit * aSign + bDigit * bSign + carry
        c.insert_last( x % 10)
        carry = x // 10

        ap = ap.next if ap is not None else ap
        bp = bp.next if bp is not None else bp
    
    if carry != 0:
        c.insert_last(carry)

    return c

def Sum(a, b):
    a = convert_to_list(a)
    b = convert_to_list(b)
    c = sum(a, b)
    print('(', a, ') + (', b, ') =', c)
    
    



Sum('0', '0')
Sum('-0', '-0')
Sum('1', '2')
Sum('9', '1')
Sum('9', '9')
Sum('-1', '-5')
Sum('-9', '-2')
Sum('-9', '-9')
Sum('9', '-2')
Sum('-9', '2')
Sum('9', '-9')
Sum('9999999999', '1')
Sum('99999999999999999999999999999999999999999999999999999999', '00009999999999999999999999999999999999999999999999999')
Sum('-9999999999999999999999', '2')
Sum('888888888888888888888888', '-1')
Sum('100000000','900000000')
