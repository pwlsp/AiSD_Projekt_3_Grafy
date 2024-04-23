#include <iostream>
#include <string>
#include <vector>

#include "../include/generate.h"
#include "../include/user_provided.h"
#include "../include/actions.h"

int main(int argc, char *argv[]){

    if(argc <= 1){
        std::cout << "No arguments given\n";
        return 1;
    }

    std::string create = std::string(argv[1]);

    if(create != "--generate" || create != "--user-provided"){
        std::cout << "Wrong arguments\n";
        return 1;
    }

    std::string type;
    std::cin >> type;
   
    if(create == "generate") generate(type);
    if(create == "user-provided") user_provided(type);
    
    actions(type);
    return 0;  
}