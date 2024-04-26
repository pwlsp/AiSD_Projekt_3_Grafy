#include <iostream>
#include <list>

#include "../include/struct_graph.h"

void Kahn_matrix(int **matrix, int vertices){
    int ins[vertices], visited[vertices];
    for(int i = 0; i < vertices; i++){
        ins[i] = 0;
        visited[i] = 0;
    }

    int ins_count = 0;
    int matrix_copy[vertices][vertices];
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            matrix_copy[i][j] = matrix[i][j];
            if(matrix_copy[i][j]){
                ins[j]++; //poczatkowa ilosc wejsc
                ins_count++;
            }
        }
    }

    // for(int i = 0; i < vertices; i++) std::cout << i << " " << ins[i] << "\n";
    // std::cout << ins_count << "\n";

    int a;
    while(ins_count > 0){
        for(int i = 0; i < vertices; i++){
            if(!visited[i] && ins[i] == 0){
                a = i;
                break;
            }
        }
        std::cout << a << " ";
        for(int j = 0; j < vertices; j++){
            if(matrix_copy[a][j]){
                matrix_copy[a][j] = 0;
                ins[j]--;
                ins_count--;
            }
        }
        visited[a] = 1;
    }
     //znalezienie z zerowym wejsciem
    for(int i = 0; i < vertices; i++){
        if(visited[i] == 0) std::cout << i << " ";
    }
    std::cout << "\n";
}

void Kahn_list(graph *L, int vertices){
    int ins[vertices], visited[vertices];
    for(int i = 0; i < vertices; i++){
        ins[i] = 0;
        visited[i] = 0;
    }

    //kopia listy
    int ins_count = 0;
    graph *L_copy; L_copy = new graph[vertices];
    for(int i = 0; i < vertices; i++){
        for(std::list<int>::iterator it = L[i].next.begin(); it != L[i].next.end(); it++){
            L_copy[i].next.push_back(*it);
            ins[*it]++;
            ins_count++;
        }
    }

    for(int i = 0; i < vertices; i++) std::cout << i << " " << ins[i] << "\n";
    std::cout << ins_count << "\n";

    int a, j;
    while(ins_count > 0){
        for(int i = 0; i < vertices; i++){
            if(!visited[i] && ins[i] == 0){
                a = i;
                break;
            }
        }
        std::cout << a << " ";
        while(!L_copy[a].next.empty()){
            j = L_copy[a].next.front();
            L_copy[a].next.pop_front();
            ins[j]--;
            ins_count--;
        }
        
        visited[a] = 1;
    }
    for(int i = 0; i < vertices; i++){
        if(visited[i] == 0) std::cout << i << " ";
    }
    std::cout << "\n";
}

void Kahn_table(int vertices){
    std::cout << "\n";
}