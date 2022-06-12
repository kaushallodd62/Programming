#include<bits/stdc++.h>
#include "linkedlist.h"
using namespace std;

// recursive method
Node* reverseList(Node* head) {
    if(head == __null || head->next == __null)
        return head;
    
    Node* rest = reverseList(head->next);
    head->next->next = head;
    head->next = __null;
    return rest;
}

// iterative method
Node* reverseListIter(Node* head) {
    if(head == __null || head->next == __null)
        return head;

    
    
}