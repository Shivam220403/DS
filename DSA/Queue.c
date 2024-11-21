#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int data[MAX];
    int front, rear;
};

void initialize(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(struct Queue* queue) {
    return queue->rear == MAX - 1;
}

int isEmpty(struct Queue* queue) {
    return queue->front == -1 || queue->front > queue->rear;
}

void enqueue(struct Queue* queue, int value) {
    if (!isFull(queue)) {
        if (queue->front == -1) queue->front = 0;
        queue->data[++queue->rear] = value;
        printf("Enqueued %d\n", value);
    } else {
        printf("Queue is full! Cannot enqueue %d\n", value);
    }
}

int dequeue(struct Queue* queue) {
    if (!isEmpty(queue)) {
        int dequeuedValue = queue->data[queue->front++];
        printf("Dequeued %d\n", dequeuedValue);
        return dequeuedValue;
    } else {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
}

int peek(struct Queue* queue) {
    if (!isEmpty(queue)) {
        return queue->data[queue->front];
    } else {
        printf("Queue is empty!\n");
        return -1;
    }
}

int main() {
    struct Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element is %d\n", peek(&queue));

    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    return 0;
}
