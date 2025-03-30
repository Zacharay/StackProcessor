#include <iostream>
#include "Stack.h"


int main() {

    char c;
    Stack stack;
    while(std::cin >> c) {
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
