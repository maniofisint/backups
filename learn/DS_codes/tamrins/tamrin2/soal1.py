class ArrayStack:

    def __init__(self, max = 10):
        self.data = [None] *max
        self.max = max
        self.first_top = -1
        self.second_top = self.max

    def size_first(self):
        return self.first_top + 1

    def size_second(self):
        return self.max - self.second_top 

    def is_full(self):
        return self.size_first() + self.size_second() == self.max

    def push_first(self, e):
        if self.is_full():
            raise Exception('Stack is full')
        self.first_top += 1
        self.data[self.first_top] = e
    
    def push_second(self, e):
        if self.is_full():
            raise Exception('Stack is full')
        self.second_top -= 1
        self.data[self.second_top] = e

    def top_first(self):
        if self.size_first() == 0:
            raise Exception('first stack is empty')
        return self.data[self.first_top]

    def top_second(self):
        if self.size_second() == 0:
            raise Exception('second stack is empty')
        return self.data[self.second_top]

    def pop_first(self):
        if self.size_first() == 0:
            raise Exception('first stack is empty')
        e = self.data[self.first_top]
        self.data[self.first_top] = None
        self.first_top -= 1
        return e

    def pop_second(self):
        if self.size_second() == 0:
            raise Exception('second stack is empty')
        e = self.data[self.second_top]
        self.data[self.second_top] = None
        self.second_top += 1
        return e


if __name__ == '__main__':
    s = ArrayStack()
    print('initiated state:')

    check = """
print(s.data)
print('size of first stack:',s.size_first())
print('size of second stack:',s.size_second())"""

    exec(check)
    print('is it full ?',s.is_full())
    try:
        print(s.pop_first())
    except:
        print('!!!Exception raised while poping first stack')
    
    try:
        print(s.pop_second())
    except:
        print('!!!Exception raised while poping second stack')

    print('\nadding one number to each stack:')
    s.push_first(12)
    print(s.data)
    s.push_second(38)
    exec(check)

    print('\nclearing stacks:')
    try:
        print(s.pop_first())
    except:
        print('!!!Exception raised while poping first stack')

    print(s.data)
    try:
        print(s.pop_second())
    except:
        print('!!!Exception raised while poping second stack')

    exec(check)

    print('\nfull situation:')
    for i in range(5):
        s.push_first(i)
        s.push_second(i)
    exec(check)
    try:
        s.push_first(5)
    except:
        print('stacks are full and we are good')
    
    try:
        s.push_second(5)
    except:
        print('stacks are full and we are good')




    print('\nand more testing...')
    s.pop_second()
    s.push_first(5)
    exec(check)

