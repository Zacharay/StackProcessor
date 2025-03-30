#include "Stack.h"

#include <iostream>

Stack::Stack() {
    top = nullptr;
}

void Stack::push(LinkedList *list) {
    if(top == nullptr) {
        top = new StackNode(nullptr,nullptr,list);
    }

    else {
        StackNode *newNode = new StackNode(nullptr,top,list);
        top->next = newNode;
        top = newNode;
    }
}
void Stack::pushToTopList(char c) {
    if(top == nullptr) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }

    top->list->push(c);
}
void Stack::pop() {
    if(top==nullptr) {
        std::cout<<"Stack is empty"<<std::endl;
        return;
    }

    StackNode *temp = top;

    if(top->prev == nullptr) {
        top = nullptr;
    }
    else {
        top = top->prev;
        top->next =nullptr;
    }


    delete temp;
    
}
void Stack::printStack(StackNode *currentNode,int depth) {

    if(currentNode==nullptr) {
        printStack(top,depth);
        return;
    }

    if(currentNode->prev == nullptr) {
        std::cout<<depth<<": ";
        currentNode->list->print();
        std::cout<<"\n";
        return;
    }

    printStack(currentNode->prev,depth+1);
    std::cout<<depth<<": ";
    currentNode->list->print();
    std::cout<<"\n";

}
void Stack::switchTopList() {
    StackNode *secondNode = top->prev;

    top->prev = secondNode->prev;
    top->next = secondNode;

    secondNode->prev = top;
    secondNode->next =nullptr;

    top = secondNode;
}

LinkedList* Stack::getListCopy(int index) {
    StackNode *node = getNodeAtIndex(0,index,top);

    LinkedList *list = new LinkedList();

    node->list->copyLinkedList(list,nullptr);

    return list;
}

StackNode* Stack::getNodeAtIndex(int currentIndex,int finalIndex,StackNode *node) {

    if(finalIndex == currentIndex) {
        return node;
    }

    return getNodeAtIndex(currentIndex+1,finalIndex,node->prev);
}

