#include<stdlib.h>
#include "queue_CA.h"

Queue* createQueue(unsigned int capacity) {
    Queue* qptr = (Queue*)malloc(sizeof(Queue));
    qptr->front = 0;
    qptr->rear = -1;
    qptr->count = 0;
    qptr->size = capacity;
    qptr->data = (itemType*)malloc(sizeof(itemType) * qptr->size);
    return qptr;
}

void destroyQueue(Queue* qptr) {
    free(qptr->data);
    free(qptr);
}

Bool isQueueEmpty(Queue* qptr) {
    return qptr->count == 0;
}

Bool isQueueFull(Queue* qptr) {
    return qptr->count == qptr->size;
}

statusCode insertQ(Queue* qptr, itemType item) {
    statusCode ret_val = SUCCESS;
    if(isQueueFull(qptr))
        ret_val = FAILURE;
    else {
        qptr->data[(qptr->rear + 1) % qptr->size] = item;
        qptr->rear = (qptr->rear + 1) % qptr->size;
        qptr->count++;
    }
    return ret_val;
}

statusCode deleteQ(Queue* qptr, itemType* item_ptr) {
    statusCode ret_val = SUCCESS;
    if(isQueueEmpty(qptr))
        ret_val = FAILURE;
    else {
        *item_ptr = qptr->data[qptr->front];
        qptr->front = (qptr->front + 1) % qptr->size;
        qptr->count--;
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

