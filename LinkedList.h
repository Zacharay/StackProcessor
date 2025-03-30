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
    void pop();
    void print();
    Node *getHead();


    int convertListToNumber(Node *currentNode,int &multiplier,int number);
    void copyLinkedList(LinkedList *destination,Node *currentNode);
private:
    void printRecursive(Node *n);
};

