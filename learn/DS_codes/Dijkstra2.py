class heapPriorityQueue:
    
    class Node:
        __slots__ = 'key', 'value', 'index'

        def __init__(self, key, value, index):
            self.key = key
            self.value = value
            self.index = index

        def __It__(self, other):
            return self.key < other.key 

    

    def is_empty(self):
        return len(self) == 0

    def __init__(self):
        self.data = []

    def __len__(self):
        return len(self.data)

    def parent(self, i):
        return (i-1)//2

    def left(self, i):
        return 2*i+1

    def right(self, i):
        return 2*i+2

    def has_right(self, i):
        return self.right(i) < len(self)

    def has_left(self, i):
        return self.left(i) < len(self)

    def swap(self, i, j):
        self.data[i].index = j
        self.data[j].index = i
        self.data[i], self.data[j] = self.data[j], self.data[i]

    def add(self, key, value):
        new_one = self.Node(key, value, len(self))
        self.data.append(new_one)
        self.upheap(len(self)-1)
        return new_one

    def upheap(self, i):
        prnt = self.parent(i)
        while i > 0 and self.data[i] < self.data[prnt]:
            self.swap(i, prnt)
            i = prnt
            prnt = self.parent(i)

    def downHeap(self, i):
        while self.has_left(i):
            left = self.left(i)
            min_child = left
            if self.has_right(i):
                right = self.right(i)
                if self.data[right] < self.data[min_child]:
                    min_child = right
            
            if self.data[min_child] < self.data[i]:
                self.swap(i, min_child)
                i = min_child
            else:
                return

    def min(self):
        if self.is_empty():
            raise Exception('Priority Queue is empty')
        out = self.data[0]
        return out.key, out.value

    def remove_min(self):
        if self.is_empty():
            raise Exception('Priority Queue is empty')
        self.swap(0, len(self)-1)
        out = self.data.pop()
        self.downHeap(0)
        return out.key, out.value
            

    def update(self, node:Node, key, value):
        index = node.index
        if not( 0<= index < len(self) and self.data[index] is not node):
            raise Exception('Invalid Index')
        node.key = key
        node.value = value
        if index > 0 and self.data[index] < self.data[self.parent(index)]:
            self.upheap(index)
        else:
            self.downHeap(index)


    def remove(self, node:Node):
        index = node.index
        if not( 0<= index < len(self) and self.data[index] is not node):
            raise Exception('Invalid Index')
        if index == len(self)-1:
            self.data.pop()
        else:
            self.swap(index, len(self)-1)
            self.data.pop()
            if index > 0 and self.data[index] < self.data[self.parent(index)]:
                self.upheap(index)
            else:
                self.downHeap(index)
        return node.key, node.value

class graph:
    
    class vertex:
        __slots__ = '_element'

        def __init__(self, x):
            self._element = x

        def element(self):
            return self._element

        def __hash__(self):
            return hash(id(self))

    class edge:
        __slots__ = '_origin', '_destination', '_element'

        def __init__(self, u, v, x):
            self._origin = u
            self._destination = v
            self._element = x

        def endpoints(self):
            return (self._origin, self._destination)

        def opposite(self, v):
            return self._destination if v is self._origin else self._origin

        def element(self):
            return self._element

        def __hash__(self):
            return hash((self._origin, self._destination))

    def __init__(self, directed = False):
        self._outgoing = {}
        self._incoming = {} if directed else self._outgoing

    def is_directed(self):
        return self._incoming is not self._outgoing

    def vertex_count(self):
        return len(self._outgoing)

    def vertices(self):
        return self._outgoing.keys()

    def edge_count(self):
        total = sum(len(self._outgoing[v]) for v in self._outgoing)
        return total if self.is_directed() else total//2

    def edges(self):
        resault = set()
        for secondary_map in self._outgoing.values():
            resault.update(secondary_map.values())
        return resault


    def get_edge(self, u, v):
        return self._outgoing[u].get(v)

    def degree(self, v, outgoing = True):
        adj = self._outgoing if outgoing else self._incoming
        return len(adj[v])

    def incident_edges(self, v, outgoing = True):
        adj = self._outgoing if outgoing else self._incoming
        for edge in adj[v].values():
            yield edge

    def isnert_vertex(self, x=None):
        v = self.vertex(x)
        self._outgoing[v] = {}
        if self.is_directed():
            self._incoming[v] = {}
        return v

    def isnert_edge(self, u, v, x=None):
        e = self.edge(u,v,x)
        self._outgoing[u][v] = e
        self._incoming[v][u] = e



        


def shortest_path_lenght(g:graph, src):      #dijkstra

    d = {}
    cloud = {}
    pq = heapPriorityQueue()
    pqlocator = {}


    for v in g.vertices():
        d[v] = 0 if v is src else float('inf')
        pqlocator[v] = pq.add(d[v], v)

    while not pq.is_empty():
        key, u = pq.remove_min()
        cloud[u] = key
        del pqlocator[u]
        for e in g.incident_edges(u):
            v = e.opposite(u)
            if v not in cloud:
                wgt = e.element()
                if d[u] + wgt < d[v]:
                    d[v] = d[u] + wgt
                    pq.update(pqlocator[v], d[v], v)

    return cloud



    

    
