#include <iostream>
#include <string>

void user_provided_matrix(int **matrix, int vertices){
    //std::cout << "wczytywanie\n";
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++) std::cin >> matrix[i][j];
    }
}

void user_provided_list(int vertices){

}

void user_provided_table(int vertices){

}