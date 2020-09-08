#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef int element;
typedef struct{
    element queue[MAX_QUEUE_SIZE];
    int rear, front;
} QueueType;

void error(char *msg){
    fprintf(stderr,"%s \n",msg);
    exit(1);
}

void init(QueueType *q){
    q->rear = q->front = 0;
}

int is_empty(QueueType *q){
    return (q->rear == q->front);
}

int is_full(QueueType *q){
    return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, element item){
    if(is_full(q)) error("error: queue is full! \n");
    q->rear = (q->rear+1)%MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

element dequeue(QueueType *q){
    if(is_empty(q)) error("error: queue is empty! \n");
    q->front = (q->front+1)%MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

element peek(QueueType *q){
    if(is_empty(q)) error("error: queue is empty! \n");
    return q->queue[(q->front+1)%MAX_QUEUE_SIZE];
}

int main(void){
    QueueType q;
    init(&q);

    printf("front: %d, rear: %d \n",q.front, q.rear);
    for(int i=0; i<10; i++){
        printf("enqueue: %d \n",i+1);
        enqueue(&q,i+1);
    }
    printf("front: %d, rear: %d \n",q.front, q.rear);

    for(int i=0; i<5; i++)
        printf("dequeue: %d \n", dequeue(&q));
    printf("front: %d, rear: %d \n",q.front, q.rear);

    return 0;
}