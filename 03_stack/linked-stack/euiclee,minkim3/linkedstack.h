/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedstack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:28:43 by euiclee           #+#    #+#             */
/*   Updated: 2022/12/16 09:36:07 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDSTACK_H
# define LINKEDSTACK_H

# define TRUE 1
# define FALSE 0

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct StackNodeType {
    char data;
    struct StackNodeType *next;
} StackNode;

typedef struct StackType {
    int currentElementCount;
    StackNode *pTopElement;
} Stack;

Stack *createStack();

int push(Stack *pStack, StackNode node);

StackNode *pop(Stack *pStack);

StackNode *peek(Stack *pStack);

int isEmptyStack(Stack *pStack);

void deleteStack(Stack *pStack);

#endif 
