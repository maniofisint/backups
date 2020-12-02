# working code

string = "((3) + (1)x^2) + (((-1)x^2)y + ((1)x + (1)x^2)y^2)z +((1) + (-3)x) z^3"
string = string.replace(' ', '')

invalid_string = "-1234.341"                            #must contain variable

class polynomial:

    class Node:
        def __init__(self, exp, v, c, next = None):     
            self.exp = exp
            self.variable = v
            self.coefficient = c
            self.next = next
            self.is_thread = False

    def __init__(self):
        self.head = None


    def convert(self, string):
        lis = self.separate_by_plus(string)
        self.separate(lis)

        for i in range(len(lis)):
            if self.is_number(lis[i][0][1:-1]):
                lis[i] = self.Node(lis[i][2], lis[i][1], float(lis[i][0][1:-1]))
            else:
                lis[i] = self.Node(lis[i][2], lis[i][1], self.convert(lis[i][0][1:-1]))

        lis.append(None)

        for i in range(1, len(lis)):
            lis[i-1].next = lis[i]

        return lis[0]


    def Print(self, p:Node):
        out = str()
        while p is not None:
            coef = str()
            if isinstance(p.coefficient, float):
                coef = str(p.coefficient)
                out += coef
            else:
                coef = self.Print(p.coefficient)
                if p.exp == 0 or not '+' in coef:
                    out += coef
                else:
                    out += '(' + coef + ')' 
            if p.exp == 1:
                out += str(p.variable)
            elif p.exp > 0:
                out += str(p.variable) + '^' + str(p.exp)

            out += '+'
            p = p.next
        return out[:-1]

    def print2(self, p:Node):
        out = str()
        while p is not None:
            coef = str()
            if isinstance(p.coefficient, float):
                coef = str(p.coefficient)
            else:
                coef = self.print2(p.coefficient)
            out += '(' + coef + ')' + str(p.variable) + '^' + str(p.exp) + '+'
            p = p.next
        return out[:-1]

    def add(self, first:Node, second:Node):
        if isinstance(first, float) and isinstance(second, float):
            return first + second


        if isinstance(first, float):
            if second.exp == 0:
                second.coefficient = self.add(first, second.coefficient)
                return second
            else:
                return self.Node(exp=0, v= second.variable, c= first, next=second)

        elif isinstance(second, float):
            if first.exp == 0:
                first.coefficient = self.add(first.coefficient, second)
                return first
            else:
                return self.Node(exp=0, v= first.variable, c= second, next=first)


        if first.exp != 0:
            first = self.Node(exp=0, v=first.variable, c=0.0, next=first)
        if second.exp != 0:
            second = self.Node(exp=0, v=second.variable, c=0.0, next=second)

        if first.variable == second.variable:
            
            f, s = first, second
            while s is not None:
                newNode = self.Node(exp= s.exp, v=s.variable, c=s.coefficient, next=None)

                while f.next is not None:
                    if f.next.exp > newNode.exp:break
                    f = f.next

                if  f.exp == newNode.exp:
                    f.coefficient = self.add(f.coefficient, newNode.coefficient)
                else:
                    newNode.next = f.next
                    f.next = newNode
                s = s.next

            return first

        elif first.variable > second.variable:
            first.coefficient = self.add(first.coefficient, second)
            return first
        else:
            second.coefficient = self.add(first, second.coefficient)
            return second


    def add2(self, first:Node, second:Node):
        if isinstance(first, float) and isinstance(second, float):
            return first + second

        if isinstance(first, float):
            if second.exp == 0:
                second.coefficient = self.add(first, second.coefficient)
                return second
            else:
                return self.Node(exp=0, v= second.variable, c= first, next=second)

        elif isinstance(second, float):
            if first.exp == 0:
                first.coefficient = self.add(first.coefficient, second)
                return first
            else:
                return self.Node(exp=0, v= first.variable, c= second, next=first)


        if first.variable == second.variable:
            if second.exp < first.exp: first, second = second, first
            f, s = first, second
            while s is not None:
                newNode = self.Node(exp= s.exp, v=s.variable, c=s.coefficient, next=None)

                while f.next is not None:
                    if f.next.exp > newNode.exp:break
                    f = f.next

                if  f.exp == newNode.exp:
                    f.coefficient = self.add(f.coefficient, newNode.coefficient)
                else:
                    newNode.next = f.next
                    f.next = newNode
                s = s.next

            return first

        elif first.variable > second.variable:
            if first.exp == 0:
                first.coefficient = self.add(first.coefficient, second)
                return first
            else:
                return self.Node(exp=0, v= first.variable, c= second, next=first)
        else:
            if second.exp == 0:
                second.coefficient = self.add(first, second.coefficient)
                return second
            else:
                return self.Node(exp=0, v= second.variable, c= first, next=second)

    def separate_by_plus(self, string: str):
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
        
    def separate(self, lis):
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
                lis[i] = [lis[i][0], var, 0]
            elif len(lis[i][1]) == 1:
                lis[i] = [lis[i][0], var, 1]
            else:
                lis[i] = [lis[i][0], var, int(lis[i][1][2:])]



    def is_number(self, ch):
        try:
            float(ch)
            return True
        except ValueError:
            return False


    def is_variable(self, ch):
        return ch.isalpha()

    def read_poly(self, string):
        pass
    def mult(self):
        pass


string = "((3)+(1)x^2)+(((-1)x^2)y+((1)x+(1)x^2)y^2)z+((1)+(-3)x)z^3"
string2 = '(((-1.2)x+(423)x^7)y^6)+(15)z^1+((32)y^7)z^5'
string3 = '(12)x^9'
string4 = '(42)w^10'
string5 = '((-1.2)x+(423)x^7)y^6'
string6 = '(3)+(1)x^2'
string7 = '(-1.2)x+(423)x^7'
print(12)
x = polynomial()

y = x.convert(string)
z = x.convert(string2)
print(x.print2(y).replace('+-', '-'))
print(x.print2(z).replace('+-', '-'))

f = x.add2(y,z)
print(x.print2(f).replace('+-', '-'))
"""
print(y.coefficient)
print(z.coefficient)"""


