#include <iostream>
#include <list>

#include "../include/struct_graph.h"

void find_edge_matrix(int **matrix, int vertices, int from, int to){
    if(matrix[from][to]) std::cout << "The edge (" << from << "," << to << ") exists.\n";
    else std::cout << "The edge (" << from << "," << to << ") doesn't exist.\n";
}

void find_edge_list(graph *L, int vertices, int from, int to){

}

void find_edge_table(int vertices, int from, int to){

}