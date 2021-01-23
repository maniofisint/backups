def cube(x):
    return x**3


def fact(x):
    if not isinstance(x, int):
        raise Exception('must be integer')
    if x < 0:
        raise Exception('factorial: input must not be negative')

    out = 1
    for i in range(1, x+1):
        out *= i
    return out




def count_pattern(pattern:list, lis:list):
    count = 0 
    for i in range(len(lis)-len(pattern)+1):
        flag = 1
        for j in range(len(pattern)):
            if pattern[j] != lis[i+j]:
                flag = 0
                break
        if flag == 1:
            count += 1

    return count

pat = ['a', 'b']
lis = ['a', 'b', 'c', 'e', 'b', 'a', 'b', 'f', 'a', 'b']
print(count_pattern(pat, lis))
