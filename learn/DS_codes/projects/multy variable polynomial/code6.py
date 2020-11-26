string = "((3) + (1)x^2) + (((-1)x^2)y + ((1)x + (1)x^2)y^2)z +((1) + (-3)x) z^3"
string = string.replace(' ', '')
string = "((3)+(1)x^2)+(((-1)x^2)y+((1)x+(1)x^2)y^2)z+((1)+(-3)x)z^3"
invalid_string = "-1234.341"                            #must contain variable
print(invalid_string.isnumeric())                       #False
print(invalid_string.replace('.', '',1).isnumeric())    #True
print(string[1:-1])
print(float(invalid_string))

class polynomial:

    class Node:
        def __init__(self, exp, v, c, next = None):     #UC = updown or UC
            self.exp = exp
            self.variable = v
            self.UC = c
            self.next = next
            self.is_thread = False

    def __init__(self):
        self.head = None


    def read_poly(self, string):
        pass


    def convert(self, string):
        print(1)
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
            if isinstance(p.UC, float):
                coef = str(p.UC)
            else:
                coef = self.Print(p.UC)
            out += '(' + coef + ')' 
            if p.exp == 1:
                out += str(p.variable)
            elif p.exp > 0:
                out += str(p.variable) + '^' + str(p.exp)

            out += '+'
            p = p.next
        return out[:-1]

        

    def add(self, first:Node, second:Node):
        if isinstance(first, float) and isinstance(second, float):
            return first + second

        if first.variable == second.variable:
            f, s = first, second
            while s is not None:
                while f.next is not None:
                    if f.next.exp > s.exp:break
                    f = f.next

                if f.exp == s.exp:
                    f.UC = self.add(f.UC, s.UC)
                else:
                    hold = f.next
                    f.next = s
                    s.next = hold

            return first

        elif first.variable > second.variable:
            first.UC = self.add(first.UC, second)
            return first
        else:
            second.UC = self.add(first, second.UC)
            return second

    def mult(self):
        pass

    

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

    def biggest_var(self, string):
        Max = min ( 'a' , 'A' )
        for i in range(len(string)):
            if ('a' <= i and i <= 'z') or ( 'A' <= i and i <= 'Z'):
                    Max = max(Max, string[i])
        return Max


    def is_number(self, ch):
        try:
            float(ch)
            return True
        except ValueError:
            return False


    def is_variable(self, ch):
        return ch.isalpha()






x = polynomial()
lis = x.separate_by_plus(string)
print(lis)
x.separate(lis)
print(lis)

y = x.convert(string)
print(x.Print(y))
