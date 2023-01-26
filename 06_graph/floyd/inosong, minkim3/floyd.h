
#ifndef FLOYD_H
#define FLOYD_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include "arraygraph.h"

int **floyd(ArrayGraph *graph, int	count);
void display_floyd(int **floyd, int count);

#endif