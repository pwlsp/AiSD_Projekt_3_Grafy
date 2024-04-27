#include <list>

#include "../include/struct_graph.h"
#include "../include/struct_edgeList.h"

void Tarjan_matrix(int **matrix, int vertices);

void Tarjan_list(graph *L, int vertices);

void Tarjan_table(edgeList *eList, int edges, int vertices);