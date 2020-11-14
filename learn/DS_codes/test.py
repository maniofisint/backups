lis = []
from random import random

for i in range(9, 0, -1):
    lis.append((i, random()))

for i in lis:
    print(i[0])
print(lis)
lis.sort()
print(lis)

ls = [None] * 10
print(ls)

print(len(lis))
