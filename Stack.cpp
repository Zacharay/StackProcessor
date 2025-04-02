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
    if (top == nullptr) {
        std::cout << "Stack is empty" << std::endl;
        return;
    }

    StackNode* temp = top;

    if (top->prev == nullptr) {
        top = nullptr;
    }
    else {
        top = top->prev;
        top->next = nullptr;
    }

    delete temp;
}
void Stack::printStack(StackNode *currentNode,int depth) {
    if(top==nullptr)return;
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
void Stack::mergeWithTopList(LinkedList *list) {
    if(list->head == nullptr)return;


    int data = list->head->data;

    Node *node = new Node(top->list->root,nullptr,data);
    top->list->root->prev = node;
    top->list->root = node;

    list->pop();

    mergeWithTopList(list);
}
bool Stack::areLinkedListsEqual(LinkedList *list1,LinkedList *list2) {



    if(list1->isListEmpty&&list2->isListEmpty)return true;

    if(list1->isListEmpty||list2->isListEmpty)return false;

    if(list1->head->data != list2->head->data) {

        return false;
    }

    list1->pop();
    list2->pop();
    return areLinkedListsEqual(list1,list2);

}
bool Stack::isAGreaterThanB(LinkedList *a,LinkedList *b) {

    if((int)b->root->data < (int)a->root->data) {
        return true;
    }
    else if((int)b->root->data > (int)a->root->data) {
        return false;
    }

    if(b->root->next==nullptr && a->root->next==nullptr) {
        return false;
    }

    Node *temp = b->root;
    b->root = b->root->next;
    delete temp;
    Node *temp1 = a->root;
    a->root = a->root->next;
    delete temp1;
    return isAGreaterThanB(a,b);

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

