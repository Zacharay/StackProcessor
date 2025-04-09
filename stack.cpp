#include "stack.h"

#include <iostream>

Stack::Stack() {
    top = nullptr;
}

void Stack::push(linkedlist *list) {
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
void Stack::mergeWithTopList(linkedlist *list) {
    if(list->head == nullptr)return;


    int data = list->head->data;

    Node *node = new Node(top->list->root,nullptr,data);
    top->list->root->prev = node;
    top->list->root = node;

    list->pop();

    mergeWithTopList(list);
}
bool Stack::areLinkedListsEqual(linkedlist *list1,linkedlist *list2) {



    if(list1->isListEmpty&&list2->isListEmpty)return true;

    if(list1->isListEmpty||list2->isListEmpty)return false;

    if(list1->head->data != list2->head->data) {

        return false;
    }

    list1->pop();
    list2->pop();
    return areLinkedListsEqual(list1,list2);

}
bool Stack::isAGreaterThanB(linkedlist *a,linkedlist *b) {

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

linkedlist* Stack::getListCopy(int index) {
    StackNode *node = getNodeAtIndex(0,index,top);

    linkedlist *list = new linkedlist();

    list->isNegative = node->list->isNegative;
    node->list->copyLinkedList(list,nullptr);

    return list;
}

StackNode* Stack::getNodeAtIndex(int currentIndex,int finalIndex,StackNode *node) {

    if(finalIndex == currentIndex) {
        return node;
    }

    return getNodeAtIndex(currentIndex+1,finalIndex,node->prev);
}
void Stack::addTwoNumbers(Node *firstNode,Node *secondNode,int carry,linkedlist *destination) {
    if(firstNode==nullptr&&secondNode==nullptr) {

        if(carry != 0 ) {
            destination->pushAtBeginning((char)carry+'0');
        }

        return;
    }


    int number1 = 0;
    if(firstNode!=nullptr) {
        number1 = firstNode->data - '0';
    }

    if(firstNode && firstNode->prev!=nullptr) {
        Node *temp = firstNode;
        firstNode = firstNode->prev;
        firstNode->next = nullptr;
        delete temp;
    }
    else {
        firstNode=nullptr;
    }


    int number2 = 0;
    if(secondNode!=nullptr) {
        number2 = secondNode->data - '0';
    }

    if(secondNode && secondNode->prev!=nullptr) {
        Node *temp = secondNode;
        secondNode = secondNode->prev;
        secondNode->next = nullptr;
        delete temp;
    }
    else {
        secondNode=nullptr;
    }

    int sum = number1 + number2 + carry;

    int result = sum % 10;

    destination->pushAtBeginning((char)result+'0');
    addTwoNumbers(firstNode,secondNode,sum/10,destination);
}
void Stack::substractTwoNumbers(Node *biggerNumberNode,Node *smallerNumberNode,int borrow,linkedlist *destination) {
    if(biggerNumberNode==nullptr&&smallerNumberNode==nullptr) {
        return;
    }

    int number1 = 0;
    if(biggerNumberNode!=nullptr) {
        number1 = biggerNumberNode->data - '0';
    }

    if(biggerNumberNode && biggerNumberNode->prev!=nullptr) {
        Node *temp = biggerNumberNode;
        biggerNumberNode = biggerNumberNode->prev;
        biggerNumberNode->next = nullptr;
        delete temp;
    }
    else {
        biggerNumberNode=nullptr;
    }


    int number2 = 0;
    if(smallerNumberNode!=nullptr) {
        number2 = smallerNumberNode->data - '0';
    }

    if(smallerNumberNode && smallerNumberNode->prev!=nullptr) {
        Node *temp = smallerNumberNode;
        smallerNumberNode = smallerNumberNode->prev;
        smallerNumberNode->next = nullptr;
        delete temp;
    }
    else {
        smallerNumberNode=nullptr;
    }

    number1 -= borrow;


    if( number2 > number1) {
        number1= number1 + 10;
        borrow=1;
    }
    else {
        borrow = 0;
    }

    int result = number1 - number2;
    destination->pushAtBeginning((char)result+'0');
    substractTwoNumbers(biggerNumberNode,smallerNumberNode,borrow,destination);
}
bool Stack::isAGreaterThanBb(linkedlist *a ,linkedlist *b) {


    bool condition = true;//a>b
    if(a->isListEmpty && b->isListEmpty) {
        condition = false;

    }
    else if(a->isNegative && !b->isNegative) {
        condition = false;
    }
    else if(a->isNegative == b->isNegative) {
        if(a->getLength(0,nullptr) < b->getLength(0,nullptr)) {
            condition = false;

            if(a->isNegative && b->isNegative) {
                condition = !condition;
            }
        }
        else if(a->getLength(0,nullptr) == b->getLength(0,nullptr)) {
            a->removeLeadingZeros();
            b->removeLeadingZeros();

            linkedlist*copya = new linkedlist();
            a->copyLinkedList(copya,nullptr);
            linkedlist* copyb = new linkedlist();
            b->copyLinkedList(copyb,nullptr);

            condition = isAGreaterThanB(copya,copyb);
            if(a->isNegative && b->isNegative && !areLinkedListsEqual(a,b)) {
                condition = !condition;
            }
        }

    }
    return condition;
}
