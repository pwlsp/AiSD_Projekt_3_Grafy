#include <iostream>

void print_matrix(){

}

void print_list(){

}

void print_table(){

}

void print_graph(std::string type){
    if(type == "matrix") print_matrix();
    else if(type == "list") print_list();
    else print_table();
}