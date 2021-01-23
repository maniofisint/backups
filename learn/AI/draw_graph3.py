import pydot

graph = pydot.Dot(graph_type='digraph', strict=True)
def fib3(n):
    if n <= 2:
        u = pydot.Node(name=str(fib3.counter), label='1')
        fib3.counter += 1
        graph.add_node(u)
        return 1, u

    u1, u2 = fib3(n-1)
    v1, v2 = fib3(n-2)
    u = pydot.Node(name=str(fib3.counter), label=str(u1+v1))
    graph.add_node(u)
    graph.add_edge(pydot.Edge(u, u2))
    graph.add_edge(pydot.Edge(u, v2))
    fib3.counter += 1
    return u1+v1, u

fib3.counter = 0
fib3(4)
graph.write_png('12.png')



