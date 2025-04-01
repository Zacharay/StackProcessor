#include "LinkedList.h"

#include <iostream>


LinkedList::LinkedList() {
    head = nullptr;
    root = nullptr;
}
void LinkedList::push(char data) {
    if(head == nullptr) {
        head = new Node(nullptr,nullptr,data);
        root = head;
        return;
    }

    Node *newNode = new Node(nullptr,head,data);
    head->next = newNode;
    head = newNode;
}

void LinkedList::pop() {

    if(head==nullptr) {
        return;
    }
    if(head->prev==nullptr) {
        delete head;
        head = nullptr;
        root = nullptr;
        return;
    }
    Node *temp = head;
    head = head->prev;
    head->next = nullptr;
    delete temp;
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
void LinkedList::pushNumber(int number,int div) {
    if (number / div < 10) {
        char c = (number / div) + '0';
        push(c);
        return;
    }

    pushNumber(number, div * 10);

    int temp = (number / div) % 10;
    char c = temp + '0';
    push(c);
}
void LinkedList::negate() {

    if(root==nullptr) {
        Node *newNode = new Node(nullptr,nullptr,'-');
        root = newNode;
        head = root;
        return;
    }

    if(root->data == '-') {
        Node *temp = root;

        if(root->next == nullptr) {
            root = nullptr;
        }
        else {
            root = root->next;
            root->prev = nullptr;
        }

        delete temp;
    }
    else if(root->data != '-') {
        Node *newNode = new Node(root,nullptr,'-');
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
            root->prev = nullptr;
        }

        delete temp;
    }
}
Node *LinkedList::getHead() {

}
