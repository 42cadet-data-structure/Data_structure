/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:17:02 by euiclee           #+#    #+#             */
/*   Updated: 2022/12/16 08:48:54y euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "arraystack.h"

int	main(void)
{
	Stack *pStack = createStack(4);
	StackNode node;

	node.data = 'a';

	push(pStack, node);

	printf("%c ", peek(pStack)->data);

	printf("%c ", pop(pStack)->data);

	node.data = 'b';

	push(pStack, node);
	node.data = 'c';

	push(pStack, node);
	node.data = 'd';

	push(pStack, node);

	printf("%c ", pop(pStack)->data);
	printf("%c ", pop(pStack)->data);
	printf("%c ", pop(pStack)->data);

	deleteStack(pStack);


	return (0);
}
