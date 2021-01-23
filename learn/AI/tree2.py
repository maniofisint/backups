import pydot
class tree:

    class Node:
        def __init__(self, parent=None, is_leaf=False, element=None):
            self.parent = parent
            self.children = []
            self.is_leaf = is_leaf
            self.element = element



    def __init__(self):
        self.root = None
        self.graph = pydot.Dot(graph_type='digraph', strict=True)
        self.size = 0

    def _make_tree(self, input, prnt=None):
        if not isinstance(input, tuple):
            u = pydot.Node(name=str(self.size), label=str(input), style='filled', fillcolor='green')
            self.size += 1
            self.graph.add_node(u)
            new_node = self.Node(parent=prnt, is_leaf=True, element=input)
            return new_node, u

        parent = self.Node(parent=prnt)
        string = 'Node'
        u = pydot.Node(name=str(self.size), label=string, style="filled", fillcolor="green")
        self.size += 1
        for i in input:
            node, v = self._make_tree(i, parent)
            parent.children.append(node)
            self.graph.add_edge(pydot.Edge(u, v))

        return parent, u


    def make_tree(self, input):
        self.root, _ = self._make_tree(input)

    def write_graph(self, name='tree2_output'):
        self.graph.write_png(name+'.png')





t = tree()
tup = (7, (5, 4), 6)
t.make_tree(tup)
t.write_graph()
