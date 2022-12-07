/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:22:21 by euiclee           #+#    #+#             */
/*   Updated: 2022/12/07 20:49:52 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"

list *create_list(int max_element_count)
{
	list	*array;
	int		i;

	array = NULL;
	i = 0;
	if (max_element_count > 0)
	{
		array = (list *)malloc(sizeof(list));
		if (!array)
		{
			printf("Error : create memory\n");
			return (NULL);
		}
		array->max_element_count = max_element_count;
		array->current_element_count = 0;
		array->p_element = NULL;
	}
	
	array->p_element = (list_node *)malloc(sizeof(list_node) * max_element_count);
	if (!array->p_element)
	{
		printf("Error : second memory\n");
		free(array);
		return (NULL);
	}
	memset(array->p_element, 0, sizeof(list_node) * max_element_count);
	return (array);
}

void delete_list(list *plist)
{
	int	i;

	i = 0;
	if (plist)
	{
		free(plist->p_element);
		free(plist);
	}
	printf("delete complete\n");
}

int is_full(list *plist)
{
	int	ret;

	ret = FALSE;
	if (plist)
		if (plist->current_element_count == plist->max_element_count)
			ret = TRUE;
	return (ret);
}

int add_element(list *plist, int position, list_node element)
{
	int	ret;
	int	i;

	ret = FALSE;
	i = 0;
	if (plist)
	{
		if (is_full(plist) == FALSE)
		{
			if (position >= 0 && position <= plist->current_element_count)
			{
				i = plist->current_element_count - 1;
				while (i >= position)
				{
					plist->p_element[i + 1] = plist->p_element[i];
					i--;
				}
				plist->p_element[position] = element;
				plist->current_element_count++;
				ret = TRUE;
			}
			else
				printf("Error : max idx\n");
		}
		else
			printf("Error : list max\n");
	}
	return (ret);
}

int remove_element(list *plist, int position)
{
	int	ret;
	int	i;

	ret = FALSE;
	i = 0;
	if (plist)
	{
		if (position >= 0 && position < plist->current_element_count)
		{
			i = position;
			while (i < plist->current_element_count - 1)
			{
				plist->p_element[i] = plist->p_element[i + 1];
				i++;
			}
			plist->current_element_count--;
			ret = TRUE;
		}
		else
			printf("Error : wrong idx\n");
	}
	return (ret);
}

list_node* get_element(list *plist, int position)
{
	list_node	*pelement;

	pelement = NULL;
	if (plist)
	{
		if (position >= 0 && position < get_list_length(plist))
			pelement = &(plist->p_element[position]);
		else
			printf("Error : wrong idx\n");
	}
	return (pelement);
}

void	display_list(list *plist)
{
	int	i;

	i = 0;
	if (plist)
	{
		printf("max element count : %d\n", plist->max_element_count);
		printf("current element count : %d\n", plist->current_element_count);
		while (i < plist->current_element_count)
		{
			printf("array[%d] : %d\n", i, get_element(plist, i)->data);
			i++;
		}
		i = plist->current_element_count;
		while (i < plist->max_element_count)
		{
			printf("array[%d] : Empty\n", i);
			i++;
		}
	}
	else
		printf("list is NULL\n");
}

void clear_list(list *plist)
{
	plist->current_element_count = 0;
}

int get_list_length(list *plist)
{
	int	ret;

	ret = 0;
	if (plist)
		ret = plist->current_element_count;
	return (ret);
}