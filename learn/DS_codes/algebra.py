
n = 11

print('+ |', end=' ')
for i in range(n):
    print(i, end=' ')

"""print('_'*(2*n+3), end=' ')"""
for i in range(n):
    print()
    print(i,'|', end=' ')
    for j in range(n):
        print((i+j) % n , end=' ')


print()
print()


print('* |', end=' ')
for i in range(n):
    print(i, end=' ')
"""print()
print('_'*(2*n+3), end=' ')"""
for i in range(n):
    print()
    print(i,'|', end=' ')
    for j in range(n):
        print((i*j) % n , end=' ')


