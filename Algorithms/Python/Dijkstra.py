from Graph import Node, Graph

class Dijkstra(Graph):
    
    def __init__(self, graph):
        self.nodes = graph.nodes
        self.num_nodes = graph.num_nodes
        self.min_costs = None
        self.next_nodes = {}
        self.visited_nodes = []
        
    def add_next_node(self, next_node, current_node):
        if next_node not in self.visited_nodes:
            try:
                self.next_nodes[next_node] = min(self.nodes[current_node].neighbors[next_node] + 
                                            self.min_costs[current_node], self.next_nodes[next_node])
            except:
                self.next_nodes[next_node] = self.nodes[current_node].neighbors[next_node] + \
                                                self.min_costs[current_node]
    
    def remove_next_node(self, remove_idx):
        self.next_nodes.pop(remove_idx)
       
    def visit_node(self, node_idx, cost, step_by_step=False):
        self.min_costs[node_idx] = cost
        if step_by_step:
            print("   Chosen node: ", node_idx, "   |   New minimum costs: ", list(self.min_costs))
            print("-------------------------------------------------------------------------")
        self.visited_nodes.append(node_idx)
        self.remove_next_node(remove_idx=node_idx)
            
    def get_min_in_next_nodes(self, step_by_step=False):
        minimum_value = min(self.next_nodes.values())
        if step_by_step:
            print("Value of nodes to be inserted: ", self.next_nodes)
            print("-------------------------------------------------------------------------")
            print("Lowest value: ", minimum_value, "<<<")
        for node in self.next_nodes.keys():
            if self.next_nodes[node] == minimum_value:
                if step_by_step:
                    print("Lowest value node: ", node, "<<<")
                    print("-------------------------------------------------------------------------")
                return node
            
    def build_instance(self, node_idx, step_by_step=False, next_nodes=True):
        self.min_costs = np.full(self.num_nodes,float('inf'))
        if step_by_step:
            print("Initial node: ", node_idx)
            print("Initial costs: ", list(self.min_costs))
            print("-------------------------------------------------------------------------")
        if next_nodes:
            self.next_nodes[node_idx] = 0
        else:
            self.min_costs[node_idx] = 0
           
    def run(self, node_idx, step_by_step=False):
        self.build_instance(node_idx, step_by_step=step_by_step)
        while(len(self.next_nodes.keys()) > 0):
            chosen_node_idx = self.get_min_in_next_nodes(step_by_step=step_by_step)
            self.visit_node(node_idx=chosen_node_idx, cost=self.next_nodes[chosen_node_idx], 
                            step_by_step=step_by_step)
            for node in self.nodes[chosen_node_idx].neighbors.keys():
                self.add_next_node(next_node=node, current_node=chosen_node_idx)
                if step_by_step:
                    print("Novos nós a serem inseridos: ", self.next_nodes)
    
    def show_results(self):
        print("\n\n\n\n")
        print("Minimum paths:")
        for idx, cost in enumerate(self.min_costs):
            print("-------------------------------------------------------------------------")
            print("Node number:", idx+1,"\nCost:", cost)
