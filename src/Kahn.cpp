#include <iostream>
#include <list>

#include "../include/struct_graph.h"

void Kahn_matrix(int **matrix, int vertices){
    int matrix_copy[vertices][vertices];
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++) matrix_copy[i][j] = matrix[i][j];
    }

}

void Kahn_list(graph *L, int vertices){

}

void Kahn_table(int vertices){
    
}