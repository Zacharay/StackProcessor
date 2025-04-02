#pragma once
#include "LinkedList.h"

struct StackNode{
    StackNode *next;
    StackNode *prev;

    LinkedList *list;

    StackNode(StackNode *next,StackNode *prev,LinkedList *list) {
        this->next = next;
        this->prev = prev;
        this->list = list;
    }
};

class Stack {

public:
    StackNode *top;
    Stack();
    void push(LinkedList *list);
    void pop();
    void printStack(StackNode *currentNode,int depth);
    void switchTopList();
    void mergeWithTopList(LinkedList *list);
    bool areLinkedListsEqual(LinkedList *list1,LinkedList *list2);
    LinkedList* getListCopy(int index);

    bool isAGreaterThanB(LinkedList *a,LinkedList *b);

    StackNode* getNodeAtIndex(int currentIndex,int finalIndex,StackNode *node);
    void pushToTopList(char c);
private:
};
