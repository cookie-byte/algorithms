class Node(object):
    def __init__(self, value):
        self.value = value
        self.edges = []

class Edge(object):
    def __init__(self, value, node_from, node_to):
        self.value = value
        self.node_from = node_from
        self.node_to = node_to

class Graph(object):
    def __init__(self):
        self.nodes = []
        self.edges = []

    def insert_node(self, value):
        new_node = Node(value)
        self.nodes.append(new_node)

    def insert_edge(self,value,node_from, node_to):
        from_node = to_node = None
        for n in self.nodes:
            if node_from == n.value:
                from_node = n
            if node_to == n.value:
                to_node = n
        if from_node == None:
            from_node = Node(node_from)
            self.nodes.append(from_node)
        if to_node == None:
            to_node = Node(node_to)
            self.nodes.append(to_node)
        edge = Edge(value,from_node,to_node)
        from_node.edges.append(edge)
        ############ comment next line for directional graph ##############
        #to_node.edges.append(edge)
        self.edges.append(edge)

    def adjacency_list(self):
        for n in self.nodes:
            print(n.value,end=' -> ')
            for e in n.edges:
                if e.node_from == n:
                    print(e.node_to.value, end=' ')
                if e.node_to == n:
                    print(e.node_from.value, end=' ')
            print()

# graph = Graph()
# graph.insert_edge(100, 'B', 'A')
# graph.insert_edge(101, 'B', 'D')
# graph.insert_edge(102, 'B', 'E')
# graph.insert_edge(103, 'A', 'C')
# graph.insert_edge(109, 'A', 'F')
# graph.insert_edge(105, 'C', 'F')
# graph.insert_edge(104, 'F', 'E')
# lis = enumerate(graph.nodes, 1)
# # new = sorted(graph.edges, key= lambda x:x.value,reverse=False)
# # for i in new:
# #     print(i.value)
# graph.adjacency_list()




