#include <iostream>
#include <list>

#include "../include/struct_graph.h"
#include "../include/struct_edgeList.h"

bool find_edge_list(graph *L, int vertices, int from, int to){
    for (std::list<int>::iterator it = L[from].next.begin(); it != L[from].next.end(); it++) if(*it == to) return true;
    return false;

}

bool find_edge_table(edgeList *eList, int edges,  int from, int to){
    return true;
}