#include <stdio.h>
#include "arraystack.h"

int main() {
	
    Stack *pStack = createStack(4);
    StackNode node;

    node.data = 'a';

    push(pStack, node);
    printf("%c ", peek(pStack)->data);

    printf("%c\n", pop(pStack)->data);


    node.data = 'b';

    push(pStack, node);
	deleteStack(pStack);
	
    node.data = 'c';
    push(pStack, node);
	printf("%c\n", peek(pStack)->data);
    node.data = 'u';
    push(pStack, node);

    printf("%c\n", pop(pStack)->data);
    printf("%c\n", pop(pStack)->data);
    printf("%c\n", pop(pStack)->data);


    push(pStack, node);
	printf("%c\n", peek(pStack)->data);

    return 0;
}