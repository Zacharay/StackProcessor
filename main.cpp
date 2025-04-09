#include <iostream>
#include "stack.h"

#define MAX_INPUT_SIZE 20000

int main() {

    Stack stack;
    char input[MAX_INPUT_SIZE+1];

    int currentInputIndex = 0;
    std::cin>>input;
    int i=0;
    while(input[currentInputIndex]!='\0') {
        char c = input[currentInputIndex++];
        switch(c) {
            case '\'': {
                linkedlist *list = new linkedlist();
                stack.push(list);
                break;
            }
            case ',': {
                stack.pop();
                break;
            }
            case ':': {
                linkedlist *list = stack.getListCopy(0);

                stack.push(list);
                break;
            }
            case ';': {
                stack.switchTopList();
                break;
            }
            case '@': {
                int multiplier = 1;
                int index = stack.top->list->convertListToNumber(nullptr,multiplier,0);
                stack.pop();

               linkedlist *list = stack.getListCopy(index);

                stack.push(list);
                break;
            }
            case '.': {
                char a;
                std::cin>>a;

                stack.pushToTopList(a);

                break;
            }
            case '>': {
                char c = stack.top->list->getLastElementData();

                std::cout<<c;

                stack.pop();
                break;
            }
            case '^': {
                stack.top->list->abs();
                break;
            }
            case '-': {
                stack.top->list->negate();
                break;
            }
            case '$': {
                char c = stack.top->list->getLastElementData();
                stack.top->list->pop();

                linkedlist *list = new linkedlist();
                stack.push(list);
                stack.pushToTopList(c);

                break;
            }
            case ']': {
                int multiplier = 1;
                int number = stack.top->list->convertListToNumber(nullptr,multiplier,0);
                stack.pop();

                linkedlist *list = new linkedlist();
                stack.push(list);

                char c = (char)number;

                stack.pushToTopList(c);

                break;
            }
            case '[': {
                char c = stack.top->list->getLastElementData();

                int number = (int)c;
                stack.pop();

                linkedlist *list = new linkedlist();
                list->pushNumber(number);

                stack.push(list);

                break;
            }
            case '~': {
                linkedlist *list = new linkedlist();


                if(currentInputIndex <10) {
                    char c = (currentInputIndex-1)+'0';
                    list->push(c);
                }
                else {
                    list->pushNumber(currentInputIndex-1);
                }
                stack.push(list);
                break;
            }
            case '!': {

                if(stack.top->list->head==nullptr ||
                    (stack.top->list->head->data=='0' &&
                    stack.top->list->head->next==nullptr&&
                    stack.top->list->head->prev==nullptr
                    )) {
                    stack.pop();
                    linkedlist *list = new linkedlist();
                    list->push('1');
                    stack.push(list);
                }
                else {
                    stack.pop();
                    linkedlist *list = new linkedlist();
                    list->push('0');
                    stack.push(list);
                }

                break;
            }
            case '#': {
                linkedlist *list = new linkedlist();
                stack.top->list->copyLinkedList(list,nullptr);

                stack.pop();

                stack.mergeWithTopList(list);
                break;
            }
            case '=': {
                bool areEqual = true;

                linkedlist *list1 = stack.top->list;
                list1->removeLeadingZeros();
                stack.pop();
                linkedlist *list2 = stack.top->list;
                list2->removeLeadingZeros();




                stack.pop();

                if(list1->isListEmpty && list2->isListEmpty) {
                    areEqual = true;
                }
                else if(list1->isNegative != list2->isNegative) {
                    areEqual = false;
                }


                if(!stack.areLinkedListsEqual(list1,list2)) {

                    areEqual = false;
                }

                linkedlist *list = new linkedlist();
                if(areEqual) {
                    list->push('1');
                }
                else {
                    list->push('0');
                }
                stack.push(list);
                break;
            }
            case '<': {
                linkedlist *a = stack.top->list;
                stack.pop();
                linkedlist *b = stack.top->list;
                stack.pop();

                a->removeLeadingZeros();
                b->removeLeadingZeros();


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
                        condition = stack.isAGreaterThanB(a,b);

                        if(a->isNegative && b->isNegative && !stack.areLinkedListsEqual(a,b)) {
                            condition = !condition;
                        }
                    }

                }

                linkedlist *list = new linkedlist();
                if(condition) {
                    list->push('1');
                }
                else {
                    list->push('0');
                }
                stack.push(list);
                break;
            }
            case '?': {
                int multiplier = 1;
                int T = stack.top->list->convertListToNumber(nullptr,multiplier,1);
                stack.pop();

                int listLength = stack.top->list->getLength(0,nullptr);

                if(listLength > 0  && stack.top->list->head->data != '0') {

                    currentInputIndex = T;
                }

                stack.pop();
                break;
            }
            case '+': {
                linkedlist *a = stack.top->list;
                stack.pop();
                linkedlist *b = stack.top->list;
                stack.pop();

                linkedlist *sum = new linkedlist();


                if(!a->isNegative && !b->isNegative) {
                    stack.addTwoNumbers(a->head,b->head,0,sum);
                }
                else if(a->isNegative  && b->isNegative) {

                    a->abs();
                    b->abs();
                    stack.addTwoNumbers(a->head,b->head,0,sum);
                    sum->pushAtBeginning('-');
                }
                else {
                    bool isANegative = a->isNegative;
                    bool isBNegative = b->isNegative;
                    b->abs();
                    a->abs();
                    a->removeLeadingZeros();
                    b->removeLeadingZeros();


                    if(stack.isAGreaterThanBb(a,b)) {
                        stack.substractTwoNumbers(a->head,b->head,0,sum);

                        sum->removeLeadingZeros();

                        if(isANegative && sum->head->data != '0') {
                            sum->pushAtBeginning('-');
                            sum->isNegative = true;
                        }
                    }
                    else {

                        stack.substractTwoNumbers(b->head,a->head,0,sum);

                        sum->removeLeadingZeros();

                        if(isBNegative && sum->head->data != '0') {
                            sum->pushAtBeginning('-');
                            sum->isNegative = true;
                        }
                    }

                }
                stack.push(sum);
                break;
            }
            case '&': {
                stack.printStack(nullptr,0);
                break;
            }
            default:
                stack.pushToTopList(c);
                break;
        }
    }

    return 0;
}
