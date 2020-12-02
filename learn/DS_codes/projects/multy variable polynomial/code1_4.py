# god bless us!

from Stack import *
string = "((3)+(1)x^2)+(((-1)x^2)y+((1)x+(1)x^2)y^2)z+((1)+(-3)x)z^3"
class polynomial:

    class Node:
        def __init__(self, up = None, down = None, right = None, left = None, exp = None, CV = None):
            self.up = up
            self.down = down
            self.right = right
            self.left = left
            self.exp = exp
            self.CV = CV

    def __init__(self):
        self.head = None

    def convert(self, string:str, expo:int = 0, UP:Node = None):
        lis = self.separate(string)

        head = self.Node(CV= lis[0][1], exp=expo, up=UP)
        head.right = head
        head.left = head

        for i in range(len(lis)):
            if self.is_number(lis[i][0]):
                lis[i] = self.Node(up=head, CV=float(lis[i][0]), exp=lis[i][2] )
            else:
                lis[i] = self.convert(string=lis[i][0], expo=lis[i][2], UP=head)

        if lis[0].exp != 0:
            newNode = self.Node(up=head, CV=0.0, exp= 0)
            lis = [newNode] + lis

        left_most_kid = self.link_them(lis)
        head.down = left_most_kid
        return head

    def link_them(self, lis):
        for i in range(len(lis)-1):
            lis[i].right = lis[i+1]
            lis[i+1].left = lis[i]

        lis[-1].right = lis[0]
        lis[0].left = lis[-1]

        return lis[0]


    def print(self, n):
        if isinstance(n.CV , float):
            return str(n.CV)

        out = str()
        variable = n.CV
        p = n.down
        p_count = 0

        while p_count == 0 or  not p.up.down is p:
            if p.up.down is p: p_count = 1
            out += '(' + self.print(p) + ')' + str(variable) + '^' + str(p.exp) + '+'
            p = p.right
        return out[:-1]

    def NR_print(self, head:Node):
        stack = ArrayStack2()
        p = head.down
        out = str()
        while p is not head:
            if p.up.down is p:
                try:
                    if p is stack.top():
                        if p.up is head: break
                        p = p.up 
                        out += ')' + p.up.CV + '^' + str(p.exp)
                        p = p.right
                        stack.pop()
                        continue
                    else:
                        stack.push(p)
                except:
                    stack.push(p)
            else:
                out += '+'

            if p.down is None:
                out += '(' + str(p.CV) + ')' + p.up.CV + '^' + str(p.exp)
                p = p.right
            else:
                out += '('
                p = p.down
        return out  

    def add(self, first:Node, second:Node):
        if isinstance(first.CV, float) and isinstance(second.CV, float):
            return self.Node(exp= 0, CV= first.CV + second.CV)

        if isinstance(first.CV, float):
            self.replace(second.down, self.add(second.down, first))
            return second
        if isinstance(second.CV, float):
            self.replace(first.down, self.add(first.down, second))
            return first

        if first.CV == second.CV:
            f, s= first.down, second.down
            f_count, s_count = 0, 0
            while s_count == 0 or not s.up.down is s:
                if s.up.down is s: s_count = 1

                newNode = self.Node(down=s.down, exp=s.exp, CV=s.CV)

                while f_count == 0 or not f.right.up.down is f.right:
                    if f.right.up.down is f.right: f_count = 1
                    if f.right.exp > s.exp:break
                    f = f.right

                if f.exp == s.exp:
                    self.replace(f, self.add(f, newNode))
                else:
                    self.insert_after(f, newNode)
                s = s.right

            return first

        elif first.CV > second.CV:
            self.replace(first.down, self.add(first.down, second))
            return first
        else:
            self.replace(second.down, self.add(second.down, first))
            return second
        
    def replace(self, p:Node, q:Node):
        p.exp = q.exp
        p.CV = q.CV
        p.down = q.down

    def insert_after(self, p:Node, q:Node):
        q.up = p.up
        q.right = p.right
        q.left = p
        p.right = q
        q.right.left = q

    
    def separate(self, string):
        def separate_by_plus(string: str):
            lis = []
            hold = str()
            paren_counter = 0

            for i in string:
                if i == '(': paren_counter += 1
                elif i == ')': paren_counter -= 1
                elif i == '+':
                    if paren_counter == 0:
                        lis.append(hold)
                        hold = str()
                        continue

                hold += i
            lis.append(hold)
            return lis

        lis = separate_by_plus(string)

        hold = str()
        for i in range(len(lis)):
            ind = len(lis[i]) - 1 
            while ind >= 0 and lis[i][ind] != ')':
                hold = lis[i][ind] + hold
                ind -= 1
            lis[i] = [lis[i][:ind+1], hold]
            hold = str()

        var = lis[-1][1][0]

        for i in range(len(lis)):
            if len(lis[i][1]) == 0:
                lis[i] = [lis[i][0][1:-1], var, 0]
            elif len(lis[i][1]) == 1:
                lis[i] = [lis[i][0][1:-1], var, 1]
            else:
                lis[i] = [lis[i][0][1:-1], var, int(lis[i][1][2:])]

        return lis

    def is_number(self, ch):
        try:
            float(ch)
            return True
        except ValueError:
            return False

    def mult(self):
        pass

    def read_poly(self, string):
        pass





string = "((3)+(1)x^2)z^2+(((-1)x^2)y+((1)x+(1)x^2)y^2)z^4+((1)+(-3)x)z^10"
string2 = '(((-1.2)x+(423)x^7)y^6)+(15)z^2+((32)y^7)z^4'
string = "((3)+(1)x^2)+(((-1)x^2)y+((1)x+(1)x^2)y^2)z+((1)+(-3)x)z^3"
string2 = '(((-1.2)x+(423)x^7)y^6)+(15)z^1+((32)y^7)z^5'
string3 = '(12)x^9'
string4 = '(42)w^10'
string5 = '((-1.2)x+(423)x^7)y^6'
string6 = '(3)+(1)x^2'
string7 = '(-1.2)x+(423)x^7'

x = polynomial()  
a = x.convert(string)
b = x.convert(string5)
print(x.print(a))
print(x.print(b))

c = x.add(a,b)
print(100)
print(x.print(c))

"""y = x.convert(string)
print(x.print(y))
z = x.add(y,y)
print(x.print(z))
x.insert_after(y.down,y.down.right)
print(x.print(y))"""

