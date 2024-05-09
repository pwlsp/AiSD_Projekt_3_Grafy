#include <list>

#include "../include/struct_graph.h"
#include "../include/struct_edgeList.h"

void generate_matrix(int **matrix, int vertices, int maximum, int edges_sat);

void generate_list(graph *L, int vertices, int maximum, int edges_sat);

void generate_table(edgeList *eList, int vertices, int maximum, int edges_sat);