#include <stdlib.h>
#include <stdio.h>

typedef int Value;

typedef struct Node {
    struct Node* previous;
    struct Node* next;
    Value value;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} Queue;

int is_empty(Queue* queue)
{
    return queue->head == NULL && queue->tail == NULL;
}

void enqueue(Queue* queue, Value value) {
    Node* node = malloc(sizeof(Node));
    Node* head = queue->head;
    node->value = value;
    node->next = head;
    node->previous = NULL;

    if (head != NULL) {
        head->previous = node;
    }
    if (is_empty(queue)) {
        queue->tail = node;
    }
    queue->head = node;
}

Value dequeue(Queue* queue) {
    Value value = queue->tail->value;
    Node* tail = queue->tail;
    if (queue->tail == queue->head) {
        queue->tail = NULL;
        queue->head = NULL;
    } else {
        queue->tail = queue->tail->previous;
    }
    free(tail);
    return value;
}

Queue* init_queue()
{
    Queue* queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}
