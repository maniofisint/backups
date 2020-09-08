def fib (n): #fgfdsg
    """printfgsd;kl
    sdfdfsdffs
    sdfdsfdsds
    sdfsdfsdfsdf
    sdfsdfdsfdsfds"""
    a,b = 0,1
    while a < n:
        print( a , end=' ')
        a, b = b, a+b
    print()

def fib2 (n):
    resault = []
    a , b = 0, 1
    while a < n:
        resault.append(a)
        a, b = b, a+b
    return resault
    print()


print( fib2(100) )
print(fib(0))
fib(100)