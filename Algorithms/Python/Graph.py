class Node(object):
    '''
      Class for representing a node in a graph
      Attributes:
        index_in_graph(int): An index for registering the order of the elements in the graph
        neighbors(dict(Node)): A dictionary of nodes for registering which elements are 1 edge away from the actual 
        node as keys and the weight of the edge between them as values.
    '''
    def __init__(self):
        self.index_in_graph = 0
        self.neighbors = {}

    def add_neighbors(self, node_idx, cost):
        self.neighbors[node_idx] = cost

    def remove_neighbor(self, node_idx):
        self.neighbors.pop(node_idx, None)

class Graph(object):
    '''
      Class for representing a graph
      Attributes:
        nodes(list(Node)): A list of the nodes in the graph
        num_nodes(int): The number of nodes in the graph
    '''
    def __init__(self):
        self.nodes = []
        self.num_nodes = 0

    def new_completely_connected_v(self):
        self.add_node(Node())
        idx = self.num_nodes-1
        for old_node in range(idx):
            self.add_edge_from_to(idx_from=idx, idx_to=old_node, cost=0)

    def add_node(self, node):
        self.nodes.append(node)
        node.index_in_graph = len(self.nodes) - 1
        self.num_nodes += 1

    def create_graph_by_num_of_nodes(self, num_of_nodes):
        for i in range(num_of_nodes):
            self.add_node(node=Node())

    def add_edge_from_to(self, idx_from, idx_to, cost):
        self.nodes[idx_from].add_neighbors(node_idx=idx_to, cost=cost)

    def remove_node(self, node):
        for other_node in self.nodes:
            other_node.remove_neighbor(node_idx=node.index_in_graph)
        self.nodes.remove(node)
        self.num_nodes -= 1
