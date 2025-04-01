#pragma once

struct Node {
    char data;
    Node *next;

    Node(Node *n,char data) {
        this->next = n;
        this->data = data;
    }
};

class LinkedList {
    Node *root;
    Node *head;

    bool isNumber=true;
    bool isNegative=true;
public:
    LinkedList();
    void push(char data);
    void pop(Node *currentNode=nullptr);
    void print();
    Node *getHead();


    int convertListToNumber(Node *currentNode,int &multiplier,int number);
    char getNthElementData(int index,int currentIndex,Node *currentNode) ;
    char getLastElementData();
    void negate();
    void abs();
    void copyLinkedList(LinkedList *destination,Node *currentNode);
private:
    void printRecursive(Node *n);
};

