# without tokenizer
Action = [
    ['Push','Push','Push','Push','Push','Push','Push'],
    ['Push','Pop' ,'Pop' ,'Pop' ,'Pop' ,'Pop' ,'Pop' ],
    ['Push','Pop' ,'Pop' ,'Pop' ,'Pop' ,'Pop' ,'Pop' ],
    ['Push','Push','Push','Pop' ,'Pop' ,'Pop' ,'Pop' ],
    ['Push','Push','Push','Pop' ,'Pop' ,'Pop' ,'Pop' ],
    ['Push','Push','Push','Push','Push','Push','Pop' ],
    ['Push','Push','Push','Push','Push','Push','Pop' ],
    ['Pop-more','Pop','Pop','Pop','Pop','Pop' ,'Pop' ],
]
trans = {'(' : 0, '-' : 1, '+' : 2, '*' : 3, '/' : 4, '^' : 5, '~' : 6, ')' : 7}

def action(c, t):
    return Action[trans[c]][trans[t]]

def is_operand(ch):
    return ch.isalpha()

def is_operator(ch):
    return ch in '+*/^~'

def is_seprator(ch):
    return ch in '()'

def is_number(ch):
    return ch in '0987654321.'

infix = 'a+(b-c*d)^e-f^g^(h/~i*k)'

def Postfix(infix):
    postfix = str()
    S = []

    for c in infix:
        if is_operand(c):
            postfix += c
        else:
            done = False
            while not done:
                if len(S) == 0:
                    S.append(c)
                    done = True
                else:
                    t = S[-1]
                    if action(c, t) == 'Push':
                        S.append(c)
                        done = True
                        break
                    elif t != '(':
                        postfix += t
                    elif t == '(':
                        done = True
                    S.pop()


    while not len(S) == 0:
        postfix += S[-1]
        S.pop()

    return postfix

p = Postfix(infix)
print()
print(p)

""""""""""""""""""""""""""""""""""""""""""""""""
# with tokenizer

string = '-12.0098+((-0.0904)-13.312*f)^(-27.012)-b^(-24.43)^(-43/~(-34)*(-764))'     #string = 'num+(num-num*f)^num-b^num^(num/~num*num)'

def tok(string):
    lis = []
    i = 0 
    while i < len(string):
        if is_operator(string[i]):  #*+^/~
            lis.append(('opr', string[i]))

        elif is_seprator(string[i]):  #()
            if string[i] == '(':
                if string[i+1] == '-':
                    j = i+2
                    while is_number(string[j]):
                        j += 1
                    if string[j] == ')':
                        i += 1
                        continue       
            lis.append(('sep', string[i]))

        elif is_operand(string[i]):
            lis.append(('oprnd', string[i]))

        elif is_number(string[i]):
            num = str()
            while is_number(string[i]):
                num += string[i]
                if i + 1 < len(string):
                    i += 1
            num = float(num)
            lis.append(('num', num))
            i -= 1

        elif string[i] == '-':
            for_a_number = False
            if i == 0:
                for_a_number = True 
            elif string[i-1] == '(':
                for_a_number = True
            
            if for_a_number:
                num = str()
                num += string[i]
                i += 1
                while is_number(string[i]):
                    num += string[i]
                    if i + 1 < len(string):
                        i += 1

                num = float(num)
                lis.append(('num', num))
                if string[i] != ')':
                    i -= 1
            else:
                lis.append(('opr', string[i]))
            
        i += 1

    return lis


def Postfix2(infix):
    infix = tok(infix)
    postfix = []
    S = []

    for c in infix:
        if c[0] == 'oprnd' or c[0] == 'num':
            postfix.append(c)
        else:
            done = False
            while not done:
                if len(S) == 0:
                    S.append(c)
                    done = True
                else:
                    t = S[-1]
                    if action(c[1], t[1]) == 'Push':
                        S.append(c)
                        done = True
                        break
                    elif t[1] != '(':
                        postfix.append(t)
                    elif t[1] == '(':
                        done = True
                    S.pop()


    while not len(S) == 0:
        postfix.append(S[-1])
        S.pop()

    return postfix

def prnt(psfix):
    for i in psfix:
        if i[0] == 'num':
            print('({})'.format(i[1]), end='')
        else:
            print(i[1], end='')
    print()

p = Postfix2(string)
print()
prnt(p)

#print(tok(string))
