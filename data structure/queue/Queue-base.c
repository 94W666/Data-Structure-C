#include <stdio.h>
#include <stdlib.h>

//定义队的节点结构体
typedef struct QNode
{
    char data;
    struct QNode *next;
} QNode;

//定义队的指针结构体-----头指针，尾指针
typedef struct Queue
{
    QNode *head;
    QNode *rear;
} Queue;

//初始化指针
Queue* initQueue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    queue->head = NULL;
    queue->rear = NULL;
    return queue;
}

Queue* inQueue(Queue *queue, char data)
{
    QNode *temp = (QNode*)malloc(sizeof(QNode));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return queue;
    }
    temp->data = data;
    temp->next = NULL;

    if (queue->head == NULL && queue->rear == NULL) {
        queue->head = queue->rear = temp;
        return queue;
    }

    queue->rear->next = temp;
    queue->rear = temp;
    return queue;
}

Queue* outQueue(Queue *queue)
{
    if (queue->head == NULL) {
        printf("Queue is empty\n");
        return queue;
    }

    QNode *temp = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return queue;
}

void Print(Queue *queue)
{
    QNode *current = queue->head;
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeQueue(Queue *queue) {
    QNode *current = queue->head;
    while (current != NULL) {
        QNode *temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
}

int main(void)
{
    Queue *queue = initQueue();
    queue = inQueue(queue, 'a');
    queue = inQueue(queue, 's');
    queue = inQueue(queue, 'd');
    queue = inQueue(queue, 'f');
    queue = inQueue(queue, 'g');
    queue = inQueue(queue, 'h');
    queue = inQueue(queue, 'j');
    queue = inQueue(queue, 'k');
    queue = inQueue(queue, 'l');

    Print(queue);
    
    // Example of dequeue
    queue = outQueue(queue);
    Print(queue);
    
    freeQueue(queue);
    return 0;
}