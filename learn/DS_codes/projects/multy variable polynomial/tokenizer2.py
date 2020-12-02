string1 = '-12x(y(z-y(z)))'
string2 = '-12.3123'
string3 = '12x(y(z-y(z)))-12.432'
string4 = '0.987'
string5 = '1456.098g'
string6 = '(3+x^2)+xyz(xy+y-z)+x^3(1-3x)'

# string = ()()...()+ .... + ()()()


def token(string):
    def is_variable(ch):
        return ch.isalpha()

    def is_num(ch):
        return ch in '0987654321.'

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
            if index+1 == len(string):
                break
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
                lis.append(')')
            elif is_variable(string[i]):
                lis.append((1, string[i], 1))

        elif string[i] == '(':
            lis.append('(')
            if is_variable(string[i+1]):      
                lis.append((1, mx_vr, 0))

        elif string[i] == ')':
            lis.append(')')
            if is_variable(string[i+1]):      
                lis.append((1, mx_vr, 0))

            
        elif is_variable(string[i]):
            if string[i+1] == '^':        
                ch = string[i]
                num, i = make_num(i+2)
                num = int(num)
                lis.append( (1, ch, num))
                i -= 1
            else:
                lis.append((1, string[i], 1))

        elif is_num(string[i]):
            num, i = make_num(i)
            num = float(num)
            lis.append((num, mx_vr, 0))
            i -= 1

        elif string[i] == '+':
            lis.append('+')
            if is_variable(string[i+1]):      
                lis.append((1, mx_vr, 0))

        elif string[i] == '-':
            lis.append('+')
            if string[i+1] == '(':          
                lis.append((-1, mx_vr, 0))

            elif is_variable(string[i+1]):      
                lis.append((-1, mx_vr, 0))

            elif is_num(string[i+1]):      
                num, i= make_num(i)
                num = float(num)
                lis.append((num, mx_vr, 0))
                i -= 1
        i += 1
    if len(lis) > 0:
        if isinstance(lis[0], str):
            if lis[0] == '+':
                lis = lis[1:]
    return lis

def seprate_by_plus(ls):
    lis = []
    holder = []
    prn_count = 0
    
    for i in ls:
        if isinstance(i, tuple):
            holder.append(i)
        elif i == '(':
            prn_count += 1
            holder.append(i)
        elif i == ')':
            prn_count -= 1
            holder.append(i)
        elif i == '+':
            if prn_count == 0:
                lis.append(holder)
                holder = []
            else:
                holder.append(i)
    lis.append(holder)
    return lis

def seprate_by_parenthesis(ls):
    lis = []
    holder = []
    prn_count = 0

    for i in ls:
        if isinstance(i, tuple):
            holder.append(i)
        elif i == '+':
            holder.append(i)
        elif i == '(':
            if prn_count == 0:
                lis.append(holder)
                holder = []
            else:
                holder.append(i)
            prn_count += 1
        elif i == ')':
            prn_count -= 1
            if prn_count == 0:
                lis.append(holder)
                holder = []
            else:
                holder.append(i)
    if len(holder) > 0:
        lis.append(holder)
    return lis

def clean(ls):
    ls.sort(key= lambda x: x[1], reverse=True)
    out = []
    ind , constant, power = 0, 1, 0
    for i in ls:
        constant *= i[0]
    
    while ind < len(ls):
        if not ls[ind][1] == ls[0][1]:
            break
        power += ls[ind][2]
        ind += 1

    out.append((constant, ls[0][1], power))

    while ind < len(ls):
        power = 0
        ch = ls[ind][1]
        while ls[ind][1] == ch:
            power += ls[ind][2]
            if ind + 1 == len(ls):
                ind += 1
                break
            ind += 1
        out.append((1, ch, power))

    return out

def destroy_parenthesis(lis):

    def mult(first, second):

        def sub_mult(first, second):
            third = first + second
            return clean(third)
            
        first = seprate_by_plus(first)
        second = seprate_by_plus(second)
        third = []
        for i in first:
            for j in second:
                third += sub_mult(i, j)
                third.append('+')
        third.pop()
        return third

    def has_parenthesis():
        for i in lis:
            if isinstance(i, str):
                if i == '(':
                    return True

    if not has_parenthesis():
        return lis

    lis = seprate_by_plus(lis)
    lis = list(map(seprate_by_parenthesis, lis))
    
    for i in range(len(lis)):
        if len(lis[i]) > 1:
            lis[i] = list(map(destroy_parenthesis, lis[i]))

            for j in range(1, len(lis[i])):
                lis[i][0] = mult(lis[i][0], lis[i][j])

            lis[i] = lis[i][0]

    out = []
    for i in lis:
        out += i
        out += '+'
    out.pop()
    return out

def simplify(string):
    lis = token(string)
    lis = destroy_parenthesis(lis)
    lis = seprate_by_plus(lis)
    for i in range(len(lis)):
        lis[i] = clean(lis[i])
    lis.sort(key= lambda x: x[0][2], reverse= True)
    return lis










if __name__ == "__main__":
    string1 = '-12x(y(z-y(z)))'
    string2 = '-12.3123'
    string3 = '12x(y(z-y(z)))-12.432'
    string4 = '0.987'
    string5 = '1456.098g'
    string6 = '(3+x^2)+xyz(xy+y-z)+x^3(1-3x)'
    print(simplify(string6))