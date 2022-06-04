#include<stdio.h>
#include "queue_CA.c"


int main()  { 
    statusCode sc; itemType x;
    // Create a queue of capacity 4 
    Queue* myQ = createQueue(4); 
 
    // inserting elements in the queue 
    sc = insertQ(myQ, 10);
    if(sc == FAILURE)
        printf("Queue Full!\n");
    else
        printf("10 inserted to the Queue\n");

    sc = deleteQ(myQ, &x);
    if (sc == FAILURE)
        printf("Queue Empty!\n");
    else
        printf("%d deleted from the Queue\n", x);
    sc = insertQ(myQ, 20);
    if(sc == FAILURE)
        printf("Queue Full!\n");
    else
        printf("20 inserted to the Queue\n");
    sc = insertQ(myQ, 30);
    if(sc == FAILURE)
        printf("Queue Full!\n");
    else
        printf("30 inserted to the Queue\n");
    sc = insertQ(myQ, 40);
    if(sc == FAILURE)
        printf("Queue Full!\n");
    else
        printf("40 inserted to the Queue\n");
    sc = insertQ(myQ, 50);
    if(sc == FAILURE)
        printf("Queue Full!\n"); 
    else
        printf("50 inserted to the Queue\n");
  
    
    sc = deleteQ(myQ, &x);
    if (sc == FAILURE)
        printf("Queue Empty!\n");
    else
        printf("%d deleted from the Queue\n", x);
    sc = deleteQ(myQ, &x);
    if (sc == FAILURE)
        printf("Queue Empty!\n");
    else
        printf("%d deleted from the Queue\n", x);
    
    sc = peekQ(myQ, &x);
    if (sc == FAILURE)
        printf("Queue Empty!\n");
    else
        printf("%d peeked from the Queue\n", x);
    sc = deleteQ(myQ, &x);
    if (sc == FAILURE)
        printf("Queue Empty!\n");
    else
        printf("%d deleted from the Queue\n", x);
    
    sc = deleteQ(myQ, &x);
    if (sc == FAILURE)
        printf("Queue Empty!\n");
    else
        printf("%d deleted from the Queue\n", x);
    
    sc = insertQ(myQ, 40);
    if(sc == FAILURE)
        printf("Queue Full!\n");
    else
        printf("40 inserted to the Queue\n");
    sc = deleteQ(myQ, &x);
    if (sc == FAILURE)
        printf("Queue Empty!\n");
    else
        printf("%d deleted from the Queue\n", x);
    printf("%d\n", isQueueEmpty(myQ));
    printf("%d\n", isQueueFull(myQ));
    destroyQueue(myQ);
    return 0; 
} 