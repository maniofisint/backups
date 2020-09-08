def f ( ham : str , eggs : str = 'eggs' ) -> str:
    return f.__annotations__

print (f.__annotations__)

def f(ham: str, eggs: str = 'eggs') -> str:
    print("Annotations:", f.__annotations__)
    print("Arguments:", ham, eggs)
    return ham + ' and ' + eggs

print(f('spam'))