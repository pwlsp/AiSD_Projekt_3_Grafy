#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <ios>
#include <limits>

#include "../include/struct_graph.h"
#include "../include/struct_edgeList.h"

void user_provided_matrix(int **matrix, int vertices){
    //std::cout << "wczytywanie\n";
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++) std::cin >> matrix[i][j];
    }
}

void user_provided_list(graph *L, int vertices){
    std::string line; 
    int to;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for(int i = 0; i < vertices; i++){
        getline(std::cin, line);
        std::stringstream is(line);
        if(line != ""){
            while(is >> to) L[i].next.push_back(to);
        }   
    }
}

void user_provided_table(edgeList *eList, int edges){
    for(int i = 0; i < edges; i++){
        std::cin >> eList[i].out >> eList[i].in;
    }
}