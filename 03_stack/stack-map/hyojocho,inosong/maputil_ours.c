/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputil_ours.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:56:27 by hyojocho          #+#    #+#             */
/*   Updated: 2022/12/17 14:44:00 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maputil.h"
#include "mapdef.h"
#include "mapstack.h"

void printMaze(int mazeArray[HEIGHT][WIDTH])
{
	int rows;
	int	cols;

	rows = 0;
	cols = 0;
	while (rows < HEIGHT)
	{
		while (cols < WIDTH)
		{
			if (mazeArray[rows][cols] == 0)
				printf(" ");
			else if (mazeArray[rows][cols] == 1)
				printf("*");
			else if (mazeArray[rows][cols] == 2)
				printf(".");
			cols++;
		}
		printf("\n");
		rows++;
	}
}

void findPath(int mazeArray[HEIGHT][WIDTH],
              MapPosition startPos,
              MapPosition endPos,
              Stack *pStack)
{
	
	
}