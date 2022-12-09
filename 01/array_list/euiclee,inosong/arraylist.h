/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:08:16 by euiclee           #+#    #+#             */
/*   Updated: 2022/12/07 19:19:09by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_node_type {
    int data;
} list_node;

typedef struct list_type {
    int max_element_count;
    int current_element_count;
    list_node *p_element;
} list;

list *create_list(int max_element_count);

void delete_list(list *plist);

int is_full(list *plist);

int add_element(list *plist, int position, list_node element);

int remove_element(list *plist, int position);

list_node* get_element(list *plist, int position);

void display_list(list *plist);

void clear_list(list *plist);

int get_list_length(list *plist);

#endif