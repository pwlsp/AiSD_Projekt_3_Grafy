#include <iostream>
#include <string>
#include <vector>

#include "../include/generate.h"
#include "../include/user_provided.h"
#include "../include/actions_matrix.h"
#include "../include/actions_list.h"
#include "../include/actions_table.h"
#include "../include/generate.h"
#include "../include/user_provided.h"

int main(int argc, char *argv[]){

    if(argc <= 1){
        std::cout << "No arguments given\n";
        return 1;
    }

    std::string create = std::string(argv[1]);

    if(create != "--generate" && create != "--user-provided"){
        std::cout << "Wrong arguments\n";
        return 1;
    }

    std::string type;
    std::cin >> type;
    std::cout << "type>" << type << "\n";

    if(type == "matrix"){
        if(create == "generate") generate_matrix();
        if(create == "user-provided") user_provided_matrix(); 
        actions_matrix();         
    }
    else if(type == "list"){
        if(create == "generate") generate_list();
        if(create == "user-provided") user_provided_list();
        actions_list();
    }
    else if(type == "table"){
        if(create == "generate") generate_table();
        if(create == "user-provided") user_provided_table();
        actions_table();
    }
    else{
        std::cout << "Unknown graph representation\n";
        return 0;
    }
    return 0;  
}