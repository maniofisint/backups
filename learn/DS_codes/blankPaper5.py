
class Memory:
    __instance = None
    @staticmethod 
    def getInstance():
        """ Static access method. """
        if Memory.__instance == None:
            Memory()
        return Memory.__instance

    def __init__(self, Max = 999):
        """ Virtually private constructor. """
        if Memory.__instance != None:
            raise Exception("This class is a Singleton!")
        else:
            Memory.__instance = self
    
        self.memory = [None] * Max                  #actual memory
        self.__avail = []
        self.__avail.append((0, Max-1))             #storing free blocks of memory
        self.max = Max
        self.MaxMemoryUsed = 0                      #keeps addres of last allocated Node, used in self.pMemory
        self.outPutFormating = 4                    #used in self.pMemory, which is lenght of the biggest number or 'None'
        count = 0
        m = Max
        while m != 0:
            count += 1
            m //= 10
        self.outPutFormating = max ( count , self.outPutFormating )

    def allocate(self):
        if len(self.__avail) == 0:
            raise Exception ("memory is full")
        temp = self.__avail.pop()
        if temp[0]+5 <= temp[1]:
            self.__avail.append((temp[0]+3, temp[1]))
        self.MaxMemoryUsed = max(self.MaxMemoryUsed, temp[0])
        return temp[0]

    def free(self, p):
        self.__avail.append((p, p+2))
        self.__avail.sort(reverse=True)             #having no better idea :)
        self.memory[p] = self.memory[p+1] = self.memory[p+2] = None

    def pMemory(self):
        """print memory"""
        print('Each group representing each possible Node and for each pair, first number is its addres in memory:' , end='')

        for i in range(0, self.MaxMemoryUsed+1, 3):
            if i % 12 == 0:
                print()

            print('({0}:{1} , {2}:{3} , {4}:{5}) __ '.format(str(i).rjust(4, ' '), str(self.memory[i]).rjust(self.outPutFormating, ' '), \
                str(i+1).rjust(4, ' '), str(self.memory[i+1]).rjust(self.outPutFormating, ' '), \
                    str(i+2).rjust(4, ' '), str(self.memory[i+2]).rjust(self.outPutFormating, ' ')), end='')
        
        print('\nthat is all..., there is possibly more, but definitely empty')



s = Memory.getInstance()
ss = Memory.getInstance()
sss = Memory.getInstance()

print(s)
print(sss)
print(ss)

print(s.allocate())
print(ss.allocate())
print(sss.allocate())

print(s.allocate())
print(ss.allocate())
print(sss.allocate())

s.pMemory()