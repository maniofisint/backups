# god bless us!
#from Stack import *

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
        def link_them(lis:list):
            """make a circular linked list from them"""
            for i in range(len(lis)-1):
                lis[i].right = lis[i+1]
                lis[i+1].left = lis[i]

            lis[-1].right = lis[0]
            lis[0].left = lis[-1]

            return lis[0]

        def is_number(ch):
            try:
                float(ch)
                return True
            except ValueError:
                return False

        lis = self.separate(string)

        head = self.Node(CV= lis[0][1], exp=expo, up=UP)
        head.right = head
        head.left = head

        for i in range(len(lis)):
            if is_number(lis[i][0]):
                lis[i] = self.Node(up=head, CV=float(lis[i][0]), exp=lis[i][2] )
            else:
                lis[i] = self.convert(string=lis[i][0], expo=lis[i][2], UP=head)

        if lis[0].exp != 0:
            newNode = self.Node(up=head, CV=0.0, exp= 0)
            lis = [newNode] + lis

        left_most_child = link_them(lis)
        head.down = left_most_child
        return head

    def separate(self, string):
        """
        given = ((3)+(1)x^2)z^2+(((-1)x^2)y+((1)x+(1)x^2)y^2)z^4+((1)+(-3)x)z^10
        return = [['(3)+(1)x^2', 'z', 2], ['((-1)x^2)y+((1)x+(1)x^2)y^2', 'z', 4], ['(1)+(-3)x', 'z', 10]] "a list"
        """
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
            """print(out)
            if len(out) > 300: break"""
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
        def replace(p:polynomial.Node, q:polynomial.Node):
            q.up = p.up
            q.right = p.right
            q.left = p.left
            q.right.left = q
            q.left.right = q
            if p.up.down is p and p.up is not None:q.up.down = q

        def insert_after(p:polynomial.Node, q:polynomial.Node):
            q.up = p.up
            q.right = p.right
            q.left = p
            p.right = q
            q.right.left = q

        if isinstance(first.CV, float) and isinstance(second.CV, float):
            return self.Node(exp= 0, CV= first.CV + second.CV)

        if isinstance(first.CV, float):
            replace(second.down, self.add(second.down, first))
            return second
        if isinstance(second.CV, float):
            replace(first.down, self.add(first.down, second))
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
                    replace(f, self.add(f, newNode))
                else:
                    insert_after(f, newNode)
                s = s.right

            return first

        elif first.CV > second.CV:
            replace(first.down, self.add(first.down, second))
            return first
        elif second.CV > first.CV:
            replace(second.down, self.add(second.down, first))
            return second

    def NR_add(self, first:Node, second:Node):
        def insert_before(f, s):
            s.right = f
            s.left = f.left
            s.up = f.up
            s.left.right = s
            f.left = s
            if f.up.down is f:
                s.up.down = s

        def insert_after(f, s):
            s.right = f.right
            s.left = f
            s.up = f.up
            s.right.left = s
            f.right = s

        def swap(f, s):
            hold = f
            if f.up.down is f:
                f.up.down = s
            if s.up.down is s:
                s.up.down = f  

            f.right = s.right
            f.left = s.left
            f.up = s.up
            f.right.left = f
            f.left.right = f
            
            s.right = hold.right
            s.left = hold.left
            s.up = hold.up
            s.right.left = s
            s.left.right = s

        st = set()
        count = 0
        f, s= first, second

        while count == 0 or not s.up is None:
            if s.up is None: count = 1
            elif s.up.down is s:
                if s in st:
                    s = s.up.right
                    while f.up.CV < s.up.CV and not f.up is None:
                        f = f.up
                    if not f.up.down is f: f = f.right
                    st.remove(s)
                    continue
                else:
                    st.add(s)
                

            if f.exp == s.exp:
                if f.down is None and s.down is None:
                    f.CV += s.CV
                    s = s.right
                    while f.up.CV < s.up.CV and not f.up is None:
                        f = f.up
                    if not f.up.down is f: f = f.right
                    
                elif f.down is None:
                    swap(f, s)

                elif s.down is None:
                    f = f.down
                    s.exp = 0
                elif f.CV == s.CV:
                    f, s = f.down, s.down

                elif f.CV > s.CV:
                    f = f.down
                    s.exp = 0
                elif f.CV < s.CV:
                    swap(f,s)      

            elif f.exp > s.exp:
                insert_before(f,s)
                s = s.right
                if not f.right.up.down is f: f = f.right
            elif f.exp < s.exp:
                insert_after(f,s)
                f, s = f.right, s.right

    def mult(self):
        pass



if __name__ =="__main__":

    string = "((3)+(1)x^2)z^2+(((-1)x^2)y+((1)x+(1)x^2)y^2)z^4+((1)+(-3)x)z^10"
    string2 = '(((-1.2)x+(423)x^7)y^6)+(15)z^2+((32)y^7)z^4'
    #string = "((3)+(1)x^2)+(((-1)x^2)y+((1)x+(1)x^2)y^2)z+((1)+(-3)x)z^3"
    string2 = '(((-1.2)x+(423)x^7)y^6)+(15)z^1+((32)y^7)z^5'
    string3 = '(12)x^9'
    string4 = '(42)w^10'
    string5 = '((-1.2)x+(423)x^7)y^6'
    string6 = '(3)+(1)x^2'
    string7 = '(-1.2)x+(423)x^7'

    x = polynomial()  
    print(x.separate(string))
    a = x.convert(string)
    b = x.convert(string2)
    print(x.NR_print(a))
    print(x.NR_print(b))




    """c = x.add(a,b)
    print(x.NR_print(c))"""

    """y = x.convert(string)
    print(x.print(y))
    z = x.add(y,y)
    print(x.print(z))
    x.insert_after(y.down,y.down.right)
    print(x.print(y))"""



    """def insert_before(f, s):
        s.right = f
        s.left = f.left
        s.up = f.up
        s.left.right = s
        f.left = s
        if f.up.down is f:s.up.down = s

    insert_before(a.down.right.right, b.down)
    print(x.NR_print(a))"""


    def insert_after(f, s):
        """isnert s after f"""
        s.right = f.right
        s.left = f
        s.up = f.up
        s.right.left = s
        f.right = s

    insert_after(a.down, b.down)
    print(x.NR_print(a))
    insert_after(a.down, b.down)
    print(x.print(a))


