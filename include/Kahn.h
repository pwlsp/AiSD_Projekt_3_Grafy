#include <list>

#include "../include/struct_graph.h"
#include "../include/struct_edgeList.h"

void Kahn_matrix(int **matrix, int vertices);

void Kahn_list(graph *L, int vertices);

void Kahn_table(edgeList *eList, int edges, int vertices);