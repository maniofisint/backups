class Memory:
    """singleton pattern used"""
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
            

    
class doublyLinkedList:

    def __init__(self):
        self.memory = Memory.getInstance() 
        self.__header = self.__Node(None, None, None)
        self.__trailer = self.__Node(None, None, None)
        self.__set_next(self.__header, self.__trailer)
        self.__set_prev(self.__trailer, self.__header)
        self.__size = 0
        self.__deleted = False
        
    
    def __Node(self, prev, element, next):
        index = self.memory.allocate()
        self.memory.memory[index] = prev
        self.memory.memory[index + 1] = element
        self.memory.memory[index + 2] = next
        return index

    
    def __prev(self, p):
        return p

    def __element(self, p):
        return p+1

    def __next(self, p):
        return p+2

    def __set_prev(self, p, prev):
        self.memory.memory[self.__prev(p)] = prev

    def __set_element(self, p, element):
        self.memory.memory[self.__element(p)] = element

    def __set_next(self, p, next):
        self.memory.memory[self.__next(p)] = next

    def __get_prev(self, p):
        return self.memory.memory[self.__prev(p)]  

    def __get_element(self, p):
        return self.memory.memory[self.__element(p)]

    def __get_next(self, p):
        return self.memory.memory[self.__next(p)]

    def __len__(self):
        return self.__size

    def __insert_after(self, e, p):
        temp = self.__get_next(p)
        self.__set_next(p, self.__Node(p, e, self.__get_next(p)))
        self.__set_prev(temp, self.__get_next(p))
        self.__size += 1

    def __delete_after(self, p):
        temp = self.__get_next(p)
        if self.__get_next(temp) is not None:
            self.__set_prev(self.__get_next(temp), p)
        self.__set_next(p, self.__get_next(temp))
        self.memory.free(temp)
        self.__size -= 1

    def is_empty(self):
        return self.__size == 0 

    def insert_first(self, e):
        self.__insert_after(e, self.__header)

    def insert_last(self, e):
        self.__insert_after(e, self.__get_prev(self.__trailer))

    def first(self):
        if not self.is_empty():
            return self.__get_element(self.__get_next(self.__header))
        else:
            raise Exception('list is empty')

    def at(self, index):
        """indexing from 0
        returnds the element at given index of list"""
        p = self.__get_next(self.__header)
        for _ in range(index):
            p = self.__get_next(p)
        return self.__get_element(p)

    def delete_first(self):
        if self.is_empty():
            raise Exception('NO more elements')
        self.__delete_after(self.__header)

    def delete_last(self):
        self.__delete_after(self.__get_prev(self.__get_prev(self.__trailer)))

    def delete(self):
        """would erace all Nodes including header and trailer"""
        self.erace()
        self.memory.free(self.__header)
        self.memory.free(self.__trailer)

    def delete_at(self, index):
        p = self.__header
        for _ in range(index):
            p = self.__get_next(p)
        self.__delete_after(p)

    def erace(self):
        """erasing all elements but keeping the list"""
        for _ in range(self.__size):
            self.delete_first()

    def __str__(self):
        lis = []
        p = self.__header
        for _ in range(self.__size):
            p = self.__get_next(p)
            lis.append(self.__get_element(p))
        return str(lis)
        



if __name__ == "__main__":

    l1 = doublyLinkedList()
    l2 = doublyLinkedList()
    l3 = doublyLinkedList()
    
    print()
    print(l1)
    print(l2)
    print(l3)

    for i in range(20):
        l1.insert_last(2*i)
        l2.insert_last(3*i)
        l3.insert_first(l2.at(i) - l1.at(i))
    
    print()
    print(l1)
    print(l2)
    print(l3)

    for i in range(5):
        l1.delete_first()
        l2.delete_last()
        l3.delete_at(i)             # deleting 0, 2, 4, 6, 8

    print()
    print(l1)
    print(l2)
    print(l3)

    for i in range(20):             #checking if delete functions worked correctly
        l1.insert_last(i)
        l2.insert_first(i)
        l3.insert_last(i)

    print()
    print(l1)
    print(l2)
    print(l3)

    print()
    m = Memory.getInstance()
    m.pMemory()                     #showing how memory looks like
