#include <iostream>
#include <string>
#include <list>
#define n 10
#include "../include/struct_graph.h"

void user_provided_matrix(int **matrix, int vertices){
    //std::cout << "wczytywanie\n";
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++) std::cin >> matrix[i][j];
    }
}

void user_provided_list(graph *L, int vertices){
    for(int i=0;i<vertices;i++){
        int to=0;
        while(std::cin >> to) L[i].next.push_back(to);
    }

}

void user_provided_table(int vertices){

}