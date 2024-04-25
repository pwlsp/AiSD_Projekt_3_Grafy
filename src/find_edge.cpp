#include <iostream>
#include <list>

#include "../include/struct_graph.h"

bool find_edge_list(graph *L, int vertices, int from, int to){
    for (std::list<int>::iterator it = L[from].next.begin(); it != L[from].next.end(); it++) if(*it == to) return true;
    return false;

}

void find_edge_table(int vertices, int from, int to){

}