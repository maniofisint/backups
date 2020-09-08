fruits = ['orange', 'apple', 'pear', 'banana', 'kiwi', 'apple', 'banana']

print(fruits.count('apple'))

print(fruits.count('tangerine'))

print(fruits.index('banana'))

print(fruits.index('banana', 4))  # Find next banana starting a position 4

fruits.reverse()
print(fruits)

fruits.append('grape')
print(fruits)

fruits.sort()
print(fruits)

fruits.pop()
print(fruits)

# Usin Lists As Stacks
stack = [3, 4, 5]
print(stack)

stack.append(6)
stack.append(7)
print(stack)

stack.pop()
print(stack)


stack.pop()

stack.pop()
print(stack)

# all the same
squars = []
for x in range(10):
    squars.append(x**2)
#or
squars = list(map(lambda x : x**2, range(10)))
#or
squars = [ x**2 for x in range(10)] # !!!!!!!!
######

lis = [(x,y) for x in [1,2,3] for y in [3,1,4] if x != y]
print(lis)
#or
lis = []
for x in [1,2,3]:
    for y in [3,1,4]:
        if x != y:
            lis.append((x,y))


vec = [[1,2,3], [4,5,6], [7,8,9]]
print([num for elem in vec for num in elem ])

vec = [-4, -2, 0, 2, 4]
print([x*2 for x in vec])
print([x for x in vec if x >= 0])
print([abs(x) for x in vec])

freshfruit = ['  banana', '  loganberry ', 'passion fruit  ']
freshfruit = [weapon.strip() for weapon in freshfruit]
print(freshfruit)
print([weapon.strip() for weapon in freshfruit])

print([(x, x**2) for x in range(1,6)])

from math import pi
print( [str(round(pi,i)) for i in range(1,6)] )

matrix = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12],
]
print( [[row[i] for row in matrix] for i in range(4)])
#or
transposed = []
for i in range(4):
    transposed.append([row[i] for row in matrix])
#or
transposed = []
for i in range(4):
    transposed_row = []
    for row in matrix:
        transposed_row.append(row[i])
    transposed.append(transposed_row)
#or
print(list(zip(*matrix)))
