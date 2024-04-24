#include <iostream>

#include "../include/print_graph.h"
#include "../include/find_edge.h"
#include "../include/dfs.h"
#include "../include/bfs.h"
#include "../include/Tarjan.h"
#include "../include/Kahn.h"

void actions_matrix(int **matrix, int vertices){
    std::cout << "Actions\n";
    std::string message = "Help\t\tShow this message\n"; //dokonczyc
    std::string action, sort_method;
    while(std::cin){
        std::cin >> action;
        std::cout << "action> " << action << "\n";
        if(action == "Help") std::cout << message;
        else if(action == "Print") print_graph_matrix();
        else if(action == "Breath-first search" or action == "BFS") bfs_matrix();
        else if(action == "Find") {
            int from, to;
            std::cin >> from;
            std::cout << "from> " << from << "\n";
            std::cin >> to;
            std::cout << "to> " << to << "\n";
            find_edge_matrix(from, to);
        }
        else if(action == "Deep-first search" or action == "DFS") dfs_matrix();
        else if(action == "Sort"){
            std::cin >> sort_method;
            std::cout << sort_method << "\n";
            //z założenia są acykliczne i skierowane
            if(sort_method == "Kahn") Kahn_matrix();
            else if(sort_method == "Tarjan") Tarjan_matrix();
            else{
                std::cout << "Unknown topological sorting method\n"; 
                continue;
            }
        }
        else if(action == "Exit") break;
        else std::cout << "\nWrong command\n";
        /*w*/


    }

}