#include <iostream>
#include <list>

#include "../include/struct_graph.h"

void Kahn_matrix(int **matrix, int vertices){
    int ins[vertices], visited[vertices];
    for(int i = 0; i < vertices; i++){
        ins[i] = 0;
        visited[i] = 0;
    }

    int matrix_copy[vertices][vertices];
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++) matrix_copy[i][j] = matrix[i][j];
    }

    int ins_count = 0;
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            if(matrix_copy[i][j]){
                ins[j]++; //poczatkowa ilosc wejsc
                ins_count++;
            }
        }
    }
    for(int i = 0; i < vertices; i++) std::cout << i << " " << ins[i] << "\n";
    std::cout << ins_count << "\n";

    int a;
    while(ins_count != 0){
        a = 0;
        while(ins[a] != 0 && a < vertices && !visited[a]) a++;
        std::cout << a << " ";
        for(int j = 0; j < vertices; j++){
            if(matrix_copy[a][j]){
                matrix_copy[a][j] = 0;
                ins[j]--;
                ins_count--;
            }
        }
        visited[a] = 1;
    }
     //znalezienie z zerowym wejsciem

}

void Kahn_list(graph *L, int vertices){
std::cout << "\n";
}

void Kahn_table(int vertices){
    std::cout << "\n";
}