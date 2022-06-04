#ifndef _QUEUE_H
#define _QUEUE_H

typedef enum {FALSE, TRUE} Bool;
typedef enum {FAILURE, SUCCESS} statusCode;
typedef int itemType;

//If being implemented w/o using circular arrays, then after deletion, the array needs to be shifted to left causing deQueue() -> O(n) complexity
//To implement deQueue in constant time, i.e O(1), then we should use circular arrays or linked lists.
//Three implememntations are possible when implementing using circular arrays:
//1. By using an unsigned int variable that counts the number of elements in the queue.
//2. By using a boolean flag isFull or isEmpty to track the same.
//3. By resetting the values of rear and front to their initialised value when queue becomes empty.
typedef struct {
    int front, rear;
    unsigned int count, size;
    itemType* data;
}Queue;

//Operations on Queues

//Returns pointer to a created Queue of given capacity
Queue* createQueue(unsigned int);

//Destroys a created Queue and free's the memory allocated for that Queue
void destroyQueue(Queue*);

//Inserts/enQueue() given element to the rear end of the Queue. Returns status code (0 for FAILURE and 1 for SUCCESS)
statusCode insertQ(Queue*, itemType);

//Deletes/deQueue() the element from the front end of the Queue and stores it in the variable which the 2nd parameter is pointing to. Returns status code (0 for FAILURE anfd 1 for SUCCESS)
statusCode deleteQ(Queue*, itemType*);

//Peeks the top most element and stores its value in variable which the 2nd parameter is pointing to. Return status code (0 for FAILURE anfd 1 for SUCCESS)
statusCode peekQ(Queue*, itemType*);

//Checks if Queue is full and returns bool value (0 for FALSE and 1 for TRUE)
Bool isQueueFull(Queue*);
//Checks if Queue is empty and returns bool value (0 for FALSE and 1 for TRUE)
Bool isQueueEmpty(Queue*);


#endif