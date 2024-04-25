#include <iostream>
#include <string>
#include <list>
#include <sstream>

#include "../include/struct_graph.h"

void user_provided_matrix(int **matrix, int vertices){
    //std::cout << "wczytywanie\n";
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++) std::cin >> matrix[i][j];
    }
}

void user_provided_list(graph *L, int vertices){
    std::string line; 
    int to;
    std::cin.ignore();
    for(int i = 0; i < vertices; i++){
        getline(std::cin, line);
        std::stringstream is(line);
        if(line == ""){
            L[i].next.push_back(-1); // jakoś to rozwiązać, żeby było puste
        }
        else{
            while(is >> to) L[i].next.push_back(to);
        }
        
    }

}

void user_provided_table(int vertices){

}