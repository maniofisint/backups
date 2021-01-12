
class fibonnacciTree:
    def __init__(self, value):
        self.value = value
        self.child = []
        self.order = 0

    def add_to_end(self, t):
        self.child.append(t)
        self.order += 1


class fibonnacciHeap:
    def __init__(self):
        self.trees = []
        self.least = None
        self.count = 0

    def isnert_node(self, value):
        new_tree = fibonnacciTree(value)
        self.trees.append(new_tree)
        if self.least is None or value < self.least.value:
            self.least = new_tree
        self.count += 1

    def get_min(self):
        if self.least is None: 
            return None
        return self.least.value
    
    def remove_min(self):
        smallest = self.least
        if smallest is not None:
            for child in smallest.child:
                self.trees.append(child)
            self.trees.remove(smallest)
            if self.trees == []:
                self.least = None
            else:
                self.least = self.trees[0]
                self.consolidate()
            self.count -= 1
            return smallest.value

    def consolidate(self):
        aux = (floor_log(self.count) + 1 ) * [None]

        while self.trees != []:
            x = self.trees[0]
            order = x.order
            self.trees.remove(x)
            while aux[order] is not None:
                y = aux[order]
                if x.value > y.value:
                    x, y = y, x

                x.add_at_end(y)
                aux[order] = None
                order += 1
            aux[order] = x
        self.least = None
        for k in aux:
            if k is not None:
                self.trees.append(k)
                if self.least is None or k.value < self.least.value:
                    self.least = k
def floor_log(x):
    import math
    return math.frexp(x)[1] -1




class FibHeap:
    class Node:
        def __init__(self, parent=None, child=None, left=None, right=None, key=None, degree=0, mark=False, c='N'):
            self.parent = parent
            self.child = child
            self.left = left
            self.right = right
            self.key = key
            self.degree = degree
            self.mark = mark
            self.c = c

    
    def __init__(self):
        self.Min = None
        self.size = 0

    def isnert(self, key):
        new_node = self.Node(key=key)
        
        if self.Min is None:
            new_node.left = new_node
            new_node.right = new_node
            self.Min = new_node

        else:
            self.Min.left.right = new_node
            new_node.right = self.Min
            new_node.left = self.Min.left
            self.Min.left = new_node
            self.Min = new_node if new_node.key < self.Min.key else self.Min

        self.size += 1

    def min(self):
        return self.Min.key

    def make_it_child(self, first:Node, second:Node):   
        """first.child = second"""

        second.left.right = second.right
        second.right.left = second.left
    
        if first.child is None:
            first.child = second

        second.right = first.child
        second.left =  first.child.left
        second.parent = first 

        first.child.left = second
        first.child.left.right = second
        
        if second.key < first.child.key:
            first.child = second

        if first.right is first:
            self.Min =  first

        first.degree += 1



class fibCLRS:
    class Node:
        def __init__(self, parent=None, child=None, left=None, right=None, key=None, degree=0, mark=False, c='N'):
            self.parent = parent
            self.child = child
            self.left = left
            self.right = right
            self.key = key
            self.degree = degree
            self.mark = mark
            self.c = c


    def __init__(self):
        self.Min = None
        self.size = 0

    def isnert_key(self, key):
        new_node = self.Node(key=key)
        self.insert_node_to_tree_list(new_node)

    def insert_node_to_tree_list(self, new_node:Node):
        if self.Min is None:
            new_node.left = new_node
            new_node.right = new_node
            self.Min = new_node

        else:
            self.Min.left.right = new_node
            new_node.right = self.Min
            new_node.left = self.Min.left
            self.Min.left = new_node
            self.Min = new_node if new_node.key < self.Min.key else self.Min

        self.size += 1
    
    def delete_a_Node_from_list(self, list_pointer:Node):
        out = list_pointer
        if list_pointer.right is list_pointer:
            if list_pointer.parent is not None:
                list_pointer.parent.child = None
        else:
            right = list_pointer.right
            left = list_pointer.left
            if list_pointer.parent is not None and list_pointer.parent.child is list_pointer:
                right.parent = list_pointer.parent
                right.parent.child = right

            right.left = left
            left.right = right

        return out
        

    def min(self):
        return self.Min.key

    def remove_min(self):
        z = self.Min
        if z is not None:
            while z.child is not None:
                deleted_child = self.delete_a_Node_from_list(z.child)
                deleted_child.parent = None
                self.insert_node_to_tree_list(deleted_child)

            self.delete_a_Node_from_list(z)
            if z.right is z: 
                self.Min = None
            else: 
                self.Min = z.right
                self.consolidate()

            self.size -= 1
            return z.key
        else:
            return z

    def make_it_child(self, first:Node, second:Node):   
        """first.child = second"""

        second.left.right = second.right
        second.right.left = second.left
    
        if first.child is None:
            first.child = second

        second.right = first.child
        second.left =  first.child.left
        second.parent = first 

        first.child.left = second
        first.child.left.right = second
        
        if second.key < first.child.key:
            first.child = second

        if first.right is first:
            self.Min =  first

        first.degree += 1

    def consolidate(self):
        arr = [None] * (self.size // 2)
        w = self.Min
        while True:
            x = w
            d = x.degree
            while arr[d] is not None:
                y = arr[d]
                if x.key > y.key:
                    x, y = y, x
                self.make_it_child(x, y)
                arr[d] = None
                d += 1
            arr[d] = x
        self.Min = None
        for tree in arr:
            if tree is not None:
                if self.Min is None:
                    tree.left = tree
                    tree.right = tree
                    tree.parent = None
                    self.Min = tree
                else:
                    self.insert_node_to_tree_list(tree)
                    if tree.key < self.Min.key:
                        self.Min = tree


                

                
            






def Fib_heap_union(H1:fibCLRS, H2:fibCLRS):
    H = fibCLRS()
    
    if H1.Min is None:
        H.Min = H2.Min
    elif H2.Min is None:
        H.Min = H1.Min
    else:
        hold1 = H1.Min.right
        hold2 = H2.Min.right
        H1.Min.right = H2.Min
        H2.Min.right = H1.Min
        hold1.left = hold2
        hold2.left = hold1
        if H1.Min.key < H2.Min.key:
            H.Min = H1.Min
        else:
            H.Min = H2.Min

    H.size = H1.size + H2.size
    return H



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


def shortest_path_lenght(g:graph,src):      #dijkstra

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



    

    
