/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraystack.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:16:16 by euiclee           #+#    #+#             */
/*   Updated: 2022/12/15 19:19:42 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYSTACK_H
# define ARRAYSTACK_H

# define TRUE	1
# define FALSE	0

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct StackNodeType {
	char	data;
}StackNode;

typedef struct StackType {
	int	maxElementCount;
	int	currentElementCount;
	StackNode	*pElement;
} Stack;

Stack *createStack(int maxElementCount);

int push(Stack *pStack, StackNode element);

StackNode *pop(Stack *pStack);

StackNode *peek(Stack *pStack);

void deleteStack(Stack *pStack);

int isStackFull(Stack *pStack);

int isStackEmpty(Stack *pStack);


#endif
