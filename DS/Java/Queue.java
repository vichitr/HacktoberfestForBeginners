import java.util.LinkedList;
import java.util.Queue;

public class Test {

    public static void main(String args[]) {
        Queue<Integer> queue = new LinkedList<>();

        queue_add(queue);
        queue_poll(queue);
        queue_add(queue);
        queue_peek(queue);
        queue_size(queue);
        queue_remove(queue);
        queue_size(queue);
    }

    private static void queue_add(Queue<Integer> queue) {
        for (int i = 0; i < 5; i++) {
            queue.add(i);
        }
    }

    private static void queue_poll(Queue<Integer> queue) {
        System.out.println("Poll :");

        for (int i = 0; i < 5; i++) {
            Integer y = queue.poll();
            System.out.println(y);
        }
    }

    private static void queue_remove(Queue<Integer> queue) {
        System.out.println("Remove :");

        for (int i = 0; i < 5; i++) {
            Integer y = queue.remove();
            System.out.println(y);
        }
    }

    private static void queue_peek(Queue<Integer> queue) {
        Integer element = queue.peek();
        System.out.println("Element on queue top : " + element);
    }

    private static void queue_size(Queue<Integer> queue) {
        Integer size = queue.size();
        System.out.println("The actual size of the queue is: " + size);
    }
}
