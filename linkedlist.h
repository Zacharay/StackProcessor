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

class linkedlist {

    bool isNumber=false;
public:
    bool isListEmpty = true;
    bool isNegative=false;
    Node *root;
    Node *head;
    linkedlist();
    void push(char data);
    void pushAtBeginning(char data) ;
    void pop();
    void print();
    Node *getHead();


    int convertListToNumber(Node *currentNode,int &multiplier,int number);
    char getNthElementData(int index,int currentIndex,Node *currentNode) ;
    char getLastElementData()const;
    void pushNumber(int number, int div=1);
    void negate();
    void abs();
    void copyLinkedList(linkedlist *destination,Node *currentNode);
    void removeLeadingZeros();

    int getLength(int currentLength,Node *currentNode);
private:
    void printRecursive(Node *n);
};

