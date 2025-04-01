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
            case '#': {
                LinkedList *list = new LinkedList();
                stack.top->list->copyLinkedList(list,nullptr);

                stack.pop();

                stack.mergeWithTopList(list);
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
