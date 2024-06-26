#include <iostream>

#include "../include/print_graph.h"
#include "../include/find_edge.h"
#include "../include/dfs.h"
#include "../include/bfs.h"
#include "../include/Tarjan.h"
#include "../include/Kahn.h"

void actions_matrix(int **matrix, int vertices){
    std::cout << "Actions\n";
   std::string message = "Help\t\tShow this message\nPrint\t\tPrint the graph in given representation\nBreadth-first search or BFS\t\tPRzeszukanie grafu metodą Breadth-first search\nDepth-first search or DFS\t\tPRzeszukanie grafu metodą Depth-first search\nFind\t\tReturn true if the egde between vertices exists, otherwise return false\nKahn\t\tSort topologically using Kahn algorithm\nTarjan\t\tSort topologically using Tarjan algorithm";
    std::string action, sort_method;
    while(std::cin){
        std::cin >> action;
        if(action != "") std::cout << "action> " << action << "\n";
        if(action == "Help") std::cout << message;
        else if(action == "Print"){
            print_graph_matrix(matrix, vertices);
            std::cout << "The graph has been printed successfully.\n";
        }
        else if(action == "Find"){
            int from, to;
            std::cin >> from;
            std::cout << "from> " << from << "\n";
            std::cin >> to;
            std::cout << "to> " << to << "\n";
            if(matrix[from][to]) std::cout << "The edge (" << from << "," << to << ") exists.\n";
            else std::cout << "The edge (" << from << "," << to << ") doesn't exist.\n";
        }
        else if(action == "Breadth-first search" or action == "BFS"){
            bfs_matrix(matrix, vertices);
            std::cout << "Breadth-first search algorithm executed successfully.\n";
        }
        else if(action == "Depth-first search" or action == "DFS"){
            dfs_matrix(matrix, vertices);
            std::cout << "Depth-first search algorithm executed successfully.\n";
        }
        else if(action == "Sort"){
            std::cin >> sort_method;
            std::cout << sort_method << "\n";
            //z założenia są acykliczne i skierowane
            if(sort_method == "Kahn"){
                Kahn_matrix(matrix, vertices);
            }
            else if(sort_method == "Tarjan"){
                Tarjan_matrix(matrix, vertices);
            }
            else{
                std::cout << "Unknown topological sorting method\n"; 
                continue;
            }
        }
        else if(action == "Exit"){
            std::cout << "Exiting the program...\n";
            break;
        }
        else if(action == ""){
            std::cout << "End of file.\nExiting the program...\n";
            break;
        }
        else std::cout << "\nWrong command\n";
        /*w*/


    }

}