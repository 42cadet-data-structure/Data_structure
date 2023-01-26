#ifndef GRAPHHSP_H
#define GRAPHHSP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "arraygraph.h"

#define INF 1e9

void floydWarshall(int **graph, int max_size);

#endif
