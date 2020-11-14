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

    def seprate(self, string):
        pass

    def read_poly(self, string):
        lis = self.seprate(string)  # given a string, must get rid of middle pluses

        for i in range(len(lis)):
            if self.has_parenthesis(lis[i]):
                lis[i] = self.make_poly(lis[i])
            else:
                lis[i] = self.make_poly2(lis[i])

        for i in range(1, len(lis)):
            lis[0] = self.add(lis[0], lis[i])

        

    def make_poly(self, string):
        seprated = list()
        hold = str()
        parenthesis_count = 0
        const, ind = self.constan(string)
        
        while ind < len(string):
            if string[ind] == '(' :
                if parenthesis_count == 0:
                    seprated.append(hold)
                    hold = str()
                else:
                    hold += string[ind]

                parenthesis_count += 1
                
            elif string[ind] == ')':
                parenthesis_count -= 1
                if parenthesis_count == 0:
                    seprated.append(hold)
                    hold = str()
                else:
                    hold += string[ind]

            else:
                hold += string[ind]

        for poly in seprated:
            poly = self.make_poly(poly)

        for i in range(1, len(seprated)):
            seprated[0] = self.mult(seprated[0], seprated[i])


        
    def make_poly2 (self, string):
        pass

    def has_parenthesis(self, string):
        pass
    
    def constan(self, string):
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

        return const, ind


    def convert(self):
        pass

    def print(self):
        pass

    def add(self):
        pass

    def mult(self):
        pass

    def biggest_var(self, string):
        pass

    def destroy_parenthesis(self, string):
        pass
                
