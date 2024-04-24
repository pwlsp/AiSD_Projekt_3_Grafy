#include <iostream>

void print_graph_matrix(int **matrix, int vertices){
    for(int j = 0; j < vertices; j++) std::cout << j << "\t";
    std::cout << "\n";
    for(int i = 0; i < vertices; i++){
        std::cout << i << "\t";
        for(int j = 0; j < vertices; j++){
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void print_graph_list(){

}

void print_graph_table(){

}