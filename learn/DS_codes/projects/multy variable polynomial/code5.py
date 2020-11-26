import tokenizer2

string1 = '-12x(y(z-y(z)))'
string2 = '-12.3123'
string3 = '12x(y(z-y(z)))-12.432'
string4 = '0.987'
string5 = '1456.098g'
string6 = '(3+x^2)+xyz(xy+y-z)+x^3(1-3x)'

# string = ()()...()+ .... + ()()()
# var, opr, prn -> v, o, p

print(tokenizer2.simplify(string6))
"""
def convert(string):
    lis = tokenizer2.simplify(string)
    out = sub_convert(lis[0])
    for i in range(1, len(lis)):
        out = add(out, sub_convert(lis[i]))

    return out"""


# god bless us!

print(string2)
string2.format()
print(string2)