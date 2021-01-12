class simpleHash:
    def __init__(self, hash_size = 1000):
        self.hash_size = hash_size
        self.T = [0] * hash_size

    def _hash_function(self, x):
        return x % self.hash_size

    def isnert(self, x):
        self.T[self._hash_function(x)] = 1

    def delete(self, x):
        self.T[self._hash_function(x)] = 0

    def search(self, x):
        return self.T[self._hash_function(x)] == 1


class chainHash:
    def __init__(self, hash_size = 1000):
        self.hash_size = hash_size
        self.T = [[]] * hash_size

    def _hash_function(self, x):
        return x % self.hash_size

    def isnert(self, x):
        self.T[self._hash_function(x)].append(x)

    def delete(self, x):
        self.T[self._hash_function(x)].remove(x)

    def search(self, x):
        return x in self.T[self._hash_function(x)]


class ProbeHash:
    def __init__(self, hash_size = 1000):
        self.hash_size = hash_size
        self.T = [None] * hash_size
    
    def _hash_function(self, x, i):
        return (x+i) % self.hash_size

    def insert(self, x):
        for i in range(self.hash_size):

            j = self._hash_function(x, i)
            if self.T[j] is None:
                self.T[j] = x
                return j

        raise Exception('Hash table overflow')


    def delete(self, x):
        i = self.search(x)
        if i is None:
            raise Exception('key not found')
        else:
            self.T[i] = None


    def search(self, x):
        for i in range(self.hash_size):
            j = self._hash_function(x, i)
            if self.T[j] == x:
                return j

        return None


    def print_table(self):
        print(self.T)





if __name__ == '__main__':

    """h = simpleHash()
    h.isnert(100035)
    h.isnert(100121)

    print(h.search(3560293))
    print(h.search(100121))



    h = chainHash()
    h.isnert(1234035)
    h.isnert(1000121)

    print(h.search(1000121))
    print(h.search(9897035))
    print(h.search(100000000121))

    h.isnert(35)
    h.delete(1234035)
    print(h.search(35))"""


    h = ProbeHash(10)
    for i in range(15, 60, 5):
        h.insert(i)

    h.print_table()

    h.delete(25)
    h.delete(35)
    h.print_table()

    h.insert(65)
    h.print_table()