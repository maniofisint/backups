# god bless us!

class polynomial:

    class Node:
        def __init__(self):
            self.up = None
            self.down = None
            self.right = None
            self.left = None
            self.exp = None
            self.CV = None

    def __init__(self):
        self.head = None


    def read_poly(self, string):
        var = biggest_var(string)


    def convert(self):
        pass

    def print(self):
        pass

    def add(self):
        pass

    def mult(self):
        pass

    def biggest_var(self, string):
        Max = min ( 'a' , 'A' )
        for i in range(len(string)):
            if ('a' <= i and i <= 'z') or ( 'A' <= i and i <= 'Z'):
                    Max = max(Max, string[i])
        return Max


    def destroy_parenthesis(self, string):
        ind = 0
        out = str()
        while ind < len(string):
            hold = str()
            parenthesis_count = 0
            
            if string[ind] == '+' or string[ind] == '-' :
                if parenthesis_count == 0:
                    out += hold
                    hold = str()
                else:
                    hold += string[ind]

            elif string[ind] == '(' :
                parenthesis_count += 1
                hold += string[ind]

            elif string[ind] == ')':
                parenthesis_count -= 1
                hold += string[ind]

            else:
                hold += string[ind]
                
