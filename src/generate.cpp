#include <iostream>
#include <string>

void generate_matrix(){

}

void generate_list(){

}

void generate_table(){

}

void generate(std::string type){
    int nodes, saturation;
    std::cin >> nodes;
    std::cout << "nodes> " << nodes << "\n";
    std::cin >> saturation;
    std::cout << "saturation> " << saturation << "\n";
    if(type == "matrix") generate_matrix();
    else if(type == "list") generate_list();
    else if(type == "table") generate_table();
    else {
        std::cout << "Wrong type of representation.\n";
        std::exit(0);
    }
}