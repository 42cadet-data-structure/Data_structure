/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:28:55 by euiclee           #+#    #+#             */
/*   Updated: 2022/12/16 09:31:42 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        printf("%c ", peek(pStack)->data);
        printf("%c ", pop(pStack)->data);
        printf("%c ", peek(pStack)->data);
        printf("%c ", pop(pStack)->data);
        printf("%c ", peek(pStack)->data);
        printf("%c ", pop(pStack)->data);
        printf("%c ", peek(pStack)->data);
        printf("%c ", pop(pStack)->data);
        deleteStack(pStack);
    }
    return 0;
}