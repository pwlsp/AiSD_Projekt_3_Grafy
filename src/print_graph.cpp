#include <iostream>
#include <list>

#include "../include/struct_graph.h"
#include "../include/struct_edgeList.h"

void print_graph_matrix(int **matrix, int vertices){
    for(int j = 0; j < vertices; j++) std::cout << "\t" << j;
    std::cout << "\n";
    for(int i = 0; i < vertices; i++){
        std::cout << i << "\t";
        for(int j = 0; j < vertices; j++){
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void print_graph_list(graph *L, int vertices){
    for(int i = 0; i < vertices; i++){
        std::cout << i << ": ";
        for(std::list<int>::iterator it = L[i].next.begin(); it != L[i].next.end(); it++) std::cout << *it << " ";
        std::cout << "\n";
    }
}

void print_graph_table(edgeList *eList, int edges){
    std::cout << "out\tin\n";
    for(int i = 0; i < edges; i++){
        std::cout << eList[i].out << "\t" << eList[i].in << "\n";
    }
}