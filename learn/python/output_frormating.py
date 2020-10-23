s = 'hello, world'
print(str(s))
print(repr(s))
print(str(1/7))
print(repr(1/7))

x = 10 * 3.25
y = 200 * 200
s = 'The value of x is ' + repr(x) + ', and y is ' + repr(y) + '...'
print(s)
s = 'The value of x is ' + str(x) + ', and y is ' + str(y) + '...'
print(s)

hello = 'hello, world\n'
hellos = repr(hello)
print(hellos)

print(repr((x, y, ('spam', 'eggs'))))

for x in range(1, 11):
    print(repr(x).rjust(45), repr(x*x).rjust(10), end=' ')
    print(repr(x*x*x).rjust(4))


for x in range(1, 11):
    print('{0:40d} {1:30d} {2:4d}'.format(x, x*x, x*x*x))

f = open ( 'workfile.txt' , 'r+')
print(f.read())

f = open ( 'workfile.txt' , 'r+')
for line in f:
    print(line )

f.write("\nI don't know")

value = ('the answer', 42)
s = str(value)  # convert the tuple to string
f.write('\n'+ s)