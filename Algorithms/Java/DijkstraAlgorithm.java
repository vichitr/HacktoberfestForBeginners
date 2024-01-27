import java.util.*;

public class DijkstraAlgorithm {

    public static void main(String[] args) {
        Map<String, Map<String, Integer>> graph = new HashMap<>();
        graph.put("A", Map.of("B", 5, "D", 9, "E", 2));
        graph.put("B", Map.of("A", 5, "C", 2));
        graph.put("C", Map.of("B", 2, "D", 3));
        graph.put("D", Map.of("A", 9, "C", 3, "E", 2));
        graph.put("E", Map.of("A", 2, "D", 2));

        String startNode = "A";
        Map<String, Integer> shortestDistances = dijkstra(graph, startNode);
        System.out.println("Shortest: " + startNode + ": " + shortestDistances);
    }

    public static Map<String, Integer> dijkstra(Map<String, Map<String, Integer>> graph, String startNode) {
        Map<String, Integer> shortestDistances = new HashMap<>();
        PriorityQueue<Node> priorityQueue = new PriorityQueue<>(Comparator.comparingInt(node -> node.distance));

        for (String node : graph.keySet()) {
            shortestDistances.put(node, Integer.MAX_VALUE);
        }
        shortestDistances.put(startNode, 0);
        priorityQueue.add(new Node(startNode, 0));

        while (!priorityQueue.isEmpty()) {
            Node currentNode = priorityQueue.poll();

            for (Map.Entry<String, Integer> neighbor : graph.get(currentNode.name).entrySet()) {
                int newDistance = currentNode.distance + neighbor.getValue();

                if (newDistance < shortestDistances.get(neighbor.getKey())) {
                    
                    shortestDistances.put(neighbor.getKey(), newDistance);
                    priorityQueue.add(new Node(neighbor.getKey(), newDistance));
                }
            }
        }

        return shortestDistances;
    }

    static class Node {
        String name;
        int distance;

        public Node(String name, int distance) {
            this.name = name;
            this.distance = distance;
        }
    }
}
