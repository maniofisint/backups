class ArrayStack:
    def __init__(self, max = 100):
        self.data = [None] * max
        self.max = max
        self._top = -1

    def __len__(self):
        return self._top + 1

    def isEmpty(self):
        return self._top == -1

    def push(self, e):
        if self._top >= self.max - 1:
            raise Exception('stack is full')
        else:
            self._top += 1
            self.data[self._top] = e

    def top(self):
        if self.isEmpty():
            raise Exception('stack is empty')
        return self.data[self._top]

    def pop(self):
        if self.isEmpty():
            raise Exception('stack is empty')

        else:
            e = self.data[self._top]
            self._top -= 1
            return e

    def prnt(self):
        print('[', end='')
        for i in range(self._top+1):
            print (self.data[i], end=', ')
        print(']')
    

A = [8, 7, 6, 5, 4, 3, 2, 1]
goal = [5, 4, 6, 3, 7, 2, 1, 8] 
#goal = [4, 3, 7, 8, 6, 2, 5, 1]
sA = ArrayStack()

for i in A:
    sA.push(i)

sB = ArrayStack()
valid = True
hold = []

for i in goal:
    print('sA: ', end=' ')
    sA.prnt()
    print('sB: ', end=' ')
    sB.prnt()
    print('hold: ', end=' ')
    print(hold)
    inB = False
    if not sB.isEmpty():
        if sB.top() == i:
            inB = True
            hold.append(sB.top())
            sB.pop()

    inA = False
    if not inB:
        while not sA.isEmpty():
            if sA.top() == i:
                inA = True
                hold.append(sA.top())
                sA.pop()
                break

            else:
                sB.push(sA.top())
                sA.pop()

    if not ( inA or inB ):
        valid = False
        break

print()
print()
print('is this series valid?',valid)
if not valid: print('it is valid until here',hold)





