def factorrs(n):
    for k in range (1,1+n):
        if n % k == 0:
            yield k


for i in factorrs(100):
    print(i)


def factors (n):
    k = 1
    while k*k < n:
        if n % k == 0:
            yield k , n//k
            # yield n//k

        k += 1

    if  k * k == n:
        yield k

for i , j in factors(130):
    print(i, j)
