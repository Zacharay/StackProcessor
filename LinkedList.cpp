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

void LinkedList::pop(Node *currentNode) {
    if (currentNode == nullptr) {
        pop(root);
        return;  // Prevent double execution
    }

    if (head == nullptr) return;

    if (currentNode->next == head) {
        delete head;
        head = currentNode;
        head->next = nullptr;
        return;
    }
    pop(currentNode->next);

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
char LinkedList::getNthElementData(int index,int currentIndex,Node *currentNode) {
    if(currentNode==nullptr) {
        return getNthElementData(index,currentIndex,root);
    }

    if(currentIndex == index) {
        return currentNode->data;
    }

    return getNthElementData(index,currentIndex+1,currentNode->next);
}
char LinkedList::getLastElementData() {
    return head->data;
}
void LinkedList::negate() {

    if(root==nullptr) {
        Node *newNode = new Node(nullptr,'-');
        root = newNode;
        head = root;
        return;
    }

    if(root->data == '-') {
        Node *temp = root;

        root = root->next;
        delete temp;
    }
    else if(root->data != '-') {
        Node *newNode = new Node(root,'-');
        root = newNode;
    }
}
void LinkedList::abs() {
    if(root==nullptr || root->data !='-')return;

    if(root->data == '-') {
        Node *temp = root;

        if(root->next == nullptr) {
            root = nullptr;
        }
        else {
            root = root->next;
        }

        delete temp;
    }
}
Node *LinkedList::getHead() {

}
