#include <stdio.h>
#include "linkedstack.h"

int main() {
    Stack *pStack = createStack();
    StackNode node;
    if (pStack != NULL){
        node.data = 'a';
        push(pStack, node);
        node.data = 'b';
        push(pStack, node);
        node.data = 'c';
        push(pStack, node);
        node.data = 'd';
		push(pStack, node);
		for (int i = 0; i < 4; i++)
		{
			printf("%c ", peek(pStack)->data);
			pop(pStack);
		}
        deleteStack(pStack);
    }
    return 0;
}