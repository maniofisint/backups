def sqrt (x):
    if not isinstance(x,(int,float)):
        raise TypeError(' x is not a number')
    elif x < 0:
        raise ValueError(' x must be positive')
    print(x)


sqrt(input()) # sucks every time