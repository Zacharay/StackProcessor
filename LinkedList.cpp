#include "LinkedList.h"

#include <iostream>


LinkedList::LinkedList() {
    head = nullptr;
    root = nullptr;
}
void LinkedList::push(char data) {
    if(head == nullptr) {
        head = new Node(nullptr,data);
        root = head;
        return;
    }

    Node *newNode = new Node(nullptr,data);
    head->next = newNode;
    head = newNode;
}

void LinkedList::pop() {

}
void LinkedList::copyLinkedList(LinkedList *destination,Node *currentNode){
    if(currentNode==nullptr) {
        copyLinkedList(destination,root);
        return;
    }

    if(currentNode->next==nullptr) {
        destination->push(currentNode->data);
        return;
    }

    destination->push(currentNode->data);
    copyLinkedList(destination,currentNode->next);
}
void LinkedList:: printRecursive(Node *n) {
    if(n->next == nullptr) {
        std::cout<<n->data;
        return;
    }

    printRecursive(n->next);
    std::cout<<n->data;

}

void LinkedList::print() {
    if(root!=nullptr) {
        printRecursive(root);
    }

}
int LinkedList::convertListToNumber(Node *currentNode,int &multiplier,int number)
{
    if(currentNode==nullptr) {
        return convertListToNumber(root,multiplier,number);
    }

    if(currentNode->next==nullptr) {

        int temp = (currentNode->data-'0')*multiplier;
        multiplier*=10;
        return temp;

    }
    if(currentNode->data == '-') {
        return convertListToNumber(currentNode->next,multiplier,number);
    }

    int result = convertListToNumber(currentNode->next,multiplier,number);
    result += (currentNode->data-'0')*multiplier;
    multiplier *= 10;

    return result;
}
Node *LinkedList::getHead() {

}
