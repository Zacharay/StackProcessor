#pragma once

struct Node {
    char data;
    Node *next;
    Node *prev;

    Node(Node *n,Node *p,char data) {
        this->next = n;
        this->prev = p;
        this->data = data;
    }
};

class LinkedList {



    bool isNumber=true;
    bool isNegative=true;
public:
    Node *root;
    Node *head;
    LinkedList();
    void push(char data);
    void pop();
    void print();
    Node *getHead();


    int convertListToNumber(Node *currentNode,int &multiplier,int number);
    char getNthElementData(int index,int currentIndex,Node *currentNode) ;
    char getLastElementData();
    void pushNumber(int number, int div=1);
    void negate();
    void abs();
    void copyLinkedList(LinkedList *destination,Node *currentNode);
private:
    void printRecursive(Node *n);
};

