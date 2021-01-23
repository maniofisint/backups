class tree:
    import pydot

    class Node:
        def __init__(self, parent=None, is_leaf=False, element=None, node=None):
            self.parent = parent
            self.children = []
            self.is_leaf = is_leaf
            self.element = element
            self.associated_node = node
            

    def __init__(self):
        self.root = None
        self.graph = pydot.Dot(graph_type='digraph', strict=True)
        self.node_counter = 0
        


    def _make_tree(self, input, prnt=None:Node):
        if not isinstance(input, tuple):
            u = pydot.Node(name='input')
            graph.add_node(u)
            graph.add_edge(position[:-2], u)
            return self.Node(parent=prnt, is_leaf=True, element=input, position=position)

        parent = self.Node(parent=prnt,position=position)
        u = pydot.Node(name=position, label=' ')
        for i in input:
            v1, v2 = self.make_tree(i, parent, position+','+str(i))
            parent.children.append(v1)
            graph.add_edge(u, v2)
            
        
        return parent, u

    def make_tree(self, input):
        self.root = self._make_tree(input=input, position=' ')
        

    def print(self, p:Node):
        if p.is_leaf:
            return str(p.element)

        out = str()
        for i in p.children:
            out += self.print(i)

        return out


    def iteration(self, address:tuple):
        p = self.root
        for i in address:
            p = p.children[i]
        return p

    
    def tree_ref(self, address:tuple):
        p = self.iteration(p)
        return print(p)

        











tup = (((1, 2), 3), (4, (5, 6)), 7, (8, 9, 10))
for i in tup:
    print(i)