#include<stdlib.h>
#include "queue_A.h"

Queue* createQueue(unsigned int capacity) {
    Queue* qptr = (Queue*)malloc(sizeof(Queue));
    qptr->front = 0;
    qptr->rear = -1;
    qptr->size = capacity;
    qptr->data = (itemType*)malloc(sizeof(itemType) * qptr->size);
    return qptr;
}

void destroyQueue(Queue* qptr) {
    free(qptr->data);
    free(qptr);
}

Bool isQueueEmpty(Queue* qptr) {
    return qptr->rear == -1;
}

Bool isQueueFull(Queue* qptr) {
    return qptr->rear == qptr->size - 1;
}

statusCode insertQ(Queue* qptr, itemType item) {
    statusCode ret_val = SUCCESS;
    if(isQueueFull(qptr))
        ret_val = FAILURE;
    else
        qptr->data[++(qptr->rear)] = item;
    return ret_val;
}

statusCode deleteQ(Queue* qptr, itemType* item_ptr) {
    statusCode ret_val = SUCCESS;
    if(isQueueEmpty(qptr))
        ret_val = FAILURE;
    else {
        *item_ptr = qptr->data[qptr->front];
        for (int i = qptr->front; i < qptr->rear; i++) {
            qptr->data[i] = qptr->data[i+1];
        }
        (qptr->rear)--;
    }
    return ret_val;
}

statusCode peekQ(Queue* qptr, itemType* item_ptr) {
    statusCode ret_val = SUCCESS;
    if(isQueueEmpty(qptr))
        ret_val = FAILURE;
    else
        *item_ptr =  qptr->data[qptr->front];
    return ret_val;
}