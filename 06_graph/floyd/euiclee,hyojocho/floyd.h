#ifndef FLOYD_H
#define FLOYD_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "arraygraph.h"

#define INF 1000000

void floyd(int **graph, int max_size);

#endif