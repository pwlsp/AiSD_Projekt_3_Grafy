#include <iostream>

#include "../include/print_graph.h"
#include "../include/find_edge.h"
#include "../include/dfs.h"
#include "../include/bfs.h"
#include "../include/Tarjan.h"
#include "../include/Kahn.h"

void actions(std::string type){
    std::cout << "Actions\n";
    std::string message = "Help\t\tShow this message\n"; //dokonczyc
    std::string action, sort_method;
    while(std::cin){
        std::cin >> action;
        std::cout << "action> " << action << "\n";
        if(action == "Help") std::cout << message;
        else if(action == "Print") print_graph(type);
        else if(action == "Breath-first search" or action == "BFS") bfs(type);
        else if(action == "Find") find_edge(type);
        else if(action == "Deep-first search" or action == "DFS") dfs(type);
        else if(action == "Sort"){
            std::cin >> sort_method;
            std::cout << sort_method << "\n";
            //z założenia są acykliczne i skierowane
            if(sort_method == "Kahn") Kahn(type);
            else if(sort_method == "Tarjan") Tarjan(type);
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