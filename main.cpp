#include <iostream>
#include "Stack.h"

#define MAX_INPUT_SIZE 20000



int main() {
    Stack stack;
    char input[MAX_INPUT_SIZE+1];

    int currentInputIndex = 0;
    std::cin>>input;

    while(input[currentInputIndex]!='\0') {
        char c = input[currentInputIndex++];
        switch(c) {
            case '\'': {
                LinkedList *list = new LinkedList();
                stack.push(list);
                break;
            }
            case ',': {
                stack.pop();
                break;
            }
            case ':': {
                LinkedList *list = stack.getListCopy(0);

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

               LinkedList *list = stack.getListCopy(index);

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

                LinkedList *list = new LinkedList();
                stack.push(list);
                stack.pushToTopList(c);

                break;
            }
            case ']': {
                int multiplier = 1;
                int number = stack.top->list->convertListToNumber(nullptr,multiplier,0);
                stack.pop();

                LinkedList *list = new LinkedList();
                stack.push(list);

                char c = (char)number;

                stack.pushToTopList(c);

                break;
            }
            case '[': {
                char c = stack.top->list->getLastElementData();

                int number = (int)c;
                stack.pop();

                LinkedList *list = new LinkedList();
                list->pushNumber(number);

                stack.push(list);

                break;
            }
            case '~': {
                LinkedList *list = new LinkedList();


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
                    LinkedList *list = new LinkedList();
                    list->push('1');
                    stack.push(list);
                }
                else {
                    stack.pop();
                    LinkedList *list = new LinkedList();
                    list->push('0');
                    stack.push(list);
                }

                break;
            }
            case '#': {
                LinkedList *list = new LinkedList();
                stack.top->list->copyLinkedList(list,nullptr);

                stack.pop();

                stack.mergeWithTopList(list);
                break;
            }
            case '=': {
                bool areEqual = true;

                LinkedList *list1 = stack.top->list;
                list1->removeLeadingZeros();
                stack.pop();
                LinkedList *list2 = stack.top->list;
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

                LinkedList *list = new LinkedList();
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
                LinkedList *a = stack.top->list;
                stack.pop();
                LinkedList *b = stack.top->list;
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

                LinkedList *list = new LinkedList();
                if(condition) {
                    list->push('1');
                }
                else {
                    list->push('0');
                }
                stack.push(list);
                break;
            }
            case '+': {
                stack.top->list->pop();

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
