#pragma once
#include "linkedlist.h"

struct StackNode{
    StackNode *next;
    StackNode *prev;

    linkedlist *list;

    StackNode(StackNode *next,StackNode *prev,linkedlist *list) {
        this->next = next;
        this->prev = prev;
        this->list = list;
    }
};

class Stack {

public:
    StackNode *top;
    Stack();
    void push(linkedlist *list);
    void pop();
    void printStack(StackNode *currentNode,int depth);
    void switchTopList();
    void mergeWithTopList(linkedlist *list);
    bool areLinkedListsEqual(linkedlist *list1,linkedlist *list2);
    linkedlist* getListCopy(int index);

    bool isAGreaterThanB(linkedlist *a,linkedlist *b);

    void addTwoNumbers(Node *firstNode,Node *secondNode,int carry,linkedlist *destination);
    void substractTwoNumbers(Node *biggerNumberNode,Node *smallerNumberNode,int borrow,linkedlist *destination);

    bool isAGreaterThanBb(linkedlist *a ,linkedlist *b);

    StackNode* getNodeAtIndex(int currentIndex,int finalIndex,StackNode *node);
    void pushToTopList(char c);
private:
};
