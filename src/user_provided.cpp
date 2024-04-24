#include <iostream>
#include <string>

void user_provided_matrix(){

}

void user_provided_list(){

}

void user_provided_table(){

}

void user_provided(std::string type){

    if(type == "matrix") user_provided_matrix();
    else if(type == "list") user_provided_list();
    else if(type == "table") user_provided_table();
    else {
        std::cout << "Wrong type of representation.\n";
        std::exit(0);
    }
    
}