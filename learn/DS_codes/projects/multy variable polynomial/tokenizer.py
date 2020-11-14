string = '3+x^2+xyz(xy+y-z)+x^3(1-3x)'
#goal = [('num', 3), ('opr', '+'), ('var', ('x', 2)), ('opr', '+') ....]

def is_variable(ch):
    return ch.isalpha()

def is_num(ch):
    return ch in '0987654321.'

# var, opr, prn -> v, o, p
def token(string):
    def max_var():
        mx = min('a', 'A')
        for i in string:
            if is_variable(i):
                mx = max(mx, i)
        return mx

    def make_num(index):
        num = str()
        num += string[index]
        index += 1
        while is_num(string[index]):
            num += string[index]
            if index+1 < len(string):
                index += 1

        """if string[i] == '^':
                pwr = str()
                while is_num(string[i]):
                    num += string[i]
                    if i+1 < len(string):
                        i += 1
                pwr = float(pwr)
                num = num ** pwr"""

        return num, index
    lis = []
    i = 0
    mx_vr = max_var()
    while i < len(string):
        if i == len(string)-1:
            if string[i] == ')':
                lis.append(('prn', ')'))
            elif is_variable(string[i]):
                lis.append(('var', (string[i], 1)))

        elif string[i] == '(':
            lis.append(('prn', '('))
            if is_variable(string[i+1]):      
                lis.append(('var', (1, mx_vr, 0)))

        elif string[i] == ')':
            lis.append(('prn', ')'))
            if is_variable(string[i+1]):      
                lis.append(('var', (1, mx_vr, 0)))

            
        elif is_variable(string[i]):
            if string[i+1] == '^':        
                ch = string[i]
                num, i = make_num(i+2)
                num = int(num)
                lis.append(('var', (1, ch, num)))
                i -= 1
            else:
                lis.append(('var', (1, string[i], 1)))

        elif is_num(string[i]):
            num, i = make_num(i)
            num = float(num)
            lis.append(('var', (num, mx_vr, 0)))
            i -= 1

        elif string[i] == '+':
            lis.append(('opr', '+'))
            if is_variable(string[i+1]):      
                lis.append(('var', (1, mx_vr, 0)))

        elif string[i] == '-':
            lis.append(('opr', '+'))
            if string[i+1] == '(':          
                lis.append(('var', (-1, mx_vr, 0)))

            elif is_variable(string[i+1]):      
                lis.append(('var', (-1, mx_vr, 0)))

            elif is_num(string[i+1]):      
                num, i= make_num(i)
                num = float(num)
                lis.append(('var', (num, mx_vr, 0)))
                i -= 1
        i += 1

    print(lis)

token(string)


# check list
# num -> var , ('num', num) -> ('var', (num, max_var, 0))
        