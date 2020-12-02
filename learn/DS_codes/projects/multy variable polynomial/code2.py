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

    def is_var(self, p):
        if ('a' <= p and p <= 'z' ) or ('A' <= p and p <= 'Z' ):
            return True
        return False

    

    def read_poly(self, string):
        """recursive , step by step until next plus sign"""

        const = 1
        ind = 0
        if self.is_var(string[0]):
            const = 1

        elif string[0] == '-':
            if self.is_var(string[1]) or string[1] == ' ':
                const = -1 
            else:
                ind = 1
                const = str()
                const += '-'
                while '0' <= string[ind] and string[ind] <= '9' or string[ind] =='.':
                    const += string[ind]
                    if ind + 1 < len(string):
                        ind += 1
                const = float(const)

        else:
            ind = 0
            const = str()
            while '0' <= string[ind] and string[ind] <= '9' or string[ind] =='.':
                const += string[ind]
                if ind + 1 < len(string):
                    ind += 1
            const = float(const)



    

    def seprate(self, string):
        pass

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
                

p = polynomial()
print(p.is_var('s'))

