#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "../include/generate.h"
#include "../include/user_provided.h"
#include "../include/actions_matrix.h"
#include "../include/actions_list.h"
#include "../include/actions_table.h"
#include "../include/generate.h"
#include "../include/user_provided.h"
#include "../include/struct_graph.h"

int main(int argc, char *argv[]){

    if(argc <= 1){
        std::cout << "No arguments given\n";
        return 1;
    }

    std::string create = std::string(argv[1]);

    if(create != "--generate" && create != "--user-provided"){
        std::cout << "Wrong arguments\n";
        return 0;
    }

    std::string type;
    std::cin >> type;
    std::cout << "type> " << type << "\n";

    int vertices;
    std::cin >> vertices;
    std::cout << "vertices> " << vertices << "\n";

    if(type == "matrix"){
        int **matrix; matrix = new int *[vertices];
        for(int i = 0; i < vertices; i++) matrix[i] = new int[vertices];
        if(create == "--generate") generate_matrix(matrix, vertices);
        if(create == "--user-provided") user_provided_matrix(matrix, vertices); 
        actions_matrix(matrix, vertices);         
    }
    else if(type == "list"){
        graph *L; L = new graph[vertices];
        if(create == "--generate") generate_list(L, vertices);
        if(create == "--user-provided") user_provided_list(L, vertices);
        actions_list(L, vertices);
    }
    else if(type == "table"){
        if(create == "--generate") generate_table(vertices);
        if(create == "--user-provided") user_provided_table(vertices);
        actions_table(vertices);
    }
    else{
        std::cout << "Unknown graph representation\n";
        return 0;
    }
    return 0;  
}