#include <iostream>

void find_edge_matrix(){

}

void find_edge_list(){

}

void find_edge_table(){

}

void find_edge(std::string type){
    int from, to;
    std::cin >> from;
    std::cout << "from> " << from << "\n";
    std::cin >> to;
    std::cout << "to> " << to << "\n";
    if(type == "matrix") find_edge_matrix();
    else if(type == "list") find_edge_list();
    else if(type == "table") find_edge_table();
}