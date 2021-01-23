import pydot

graph = pydot.Dot(graph_type='digraph', strict=False)

graph.add_edge(pydot.Edge('1', '2'))
graph.add_edge(pydot.Edge('1', '3'))
graph.add_edge(pydot.Edge('1', '3'))
graph.write_png('out.png')

u = pydot.Node(name='4', label='four', style='filled', color='gold')
graph.add_node(u)
v = pydot.Node(name='5', label='four', style='filled', color='yellow')
graph.add_node(v)
new_edge = pydot.Edge(u, v)
graph.add_edge(new_edge)
graph.write_png('out.png')

print(hex(16))


