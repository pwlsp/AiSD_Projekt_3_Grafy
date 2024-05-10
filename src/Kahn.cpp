#include <iostream>
#include <list>

#include "../include/struct_graph.h"
#include "../include/struct_edgeList.h"

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
            if(matrix_copy[i][j] == 1){
                ins[j]++; //poczatkowa ilosc wejsc
                ins_count++;
            }
        }
    }

    int a, check = 1;
    while(ins_count > 0){
        for(int b = 0; b < vertices; b++) if(ins[b] == 0) check = 0;
        if(check == 1) {std::cout << "The graph is cyclic, can't be sorted.\n"; return;}
        for(int i = 0; i < vertices; i++){
            if(!visited[i] && ins[i] == 0){
                a = i;
                break;
            }
        }
        std::cout << a << " ";
        for(int j = 0; j < vertices; j++){
            if(matrix_copy[a][j] == 1){
                matrix_copy[a][j] = 0;
                matrix_copy[j][a] = 0;
                ins[j]--;
                ins_count--;
            }
        }
        visited[a] = 1;
    }//znalezienie z zerowym wejściem
    for(int i = 0; i < vertices; i++){
        if(visited[i] == 0) std::cout << i << " ";
    }
    std::cout << "\n";
    std::cout << "The graph has been sorted successfully (Kahn algorithm).\n";
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

    int a, j, check = 1;
    while(ins_count > 0){
        for(int b = 0; b < vertices; b++) if(ins[b] == 0) check = 0;
        if(check == 1) {std::cout << "The graph is cyclic, can't be sorted.\n"; return;}
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
    std::cout << "The graph has been sorted successfully (Kahn algorithm).\n";
}

void Kahn_table(edgeList *eList, int edges, int vertices){
    int ins[vertices], visited[vertices];
    for(int i = 0; i < vertices; i++){
        ins[i] = 0;
        visited[i] = 0;
    }
    edgeList *list_copy; list_copy = new edgeList[edges];
    for(int i = 0; i < edges; i++){
        list_copy[i] = eList[i];
        ins[eList[i].in]++;
    }

    int a, ins_count = edges, check = 1;
    while(ins_count > 0){
        for(int b = 0; b < vertices; b++) if(ins[b] == 0) check = 0;
        if(check == 1) {std::cout << "The graph is cyclic, can't be sorted.\n"; return;}
        for(int i = 0; i < vertices; i++){
            if(!visited[i] && ins[i] == 0){
                a = i;
                break;
            }
        }
        std::cout << a << " ";
        for(int i = 0; i < edges; i ++){
            if(list_copy[i].out == a && list_copy[i].in != -1){
                ins[list_copy[i].in]--;
                list_copy[i].in = -1; //dopytac sie czy wierzcholki maja byc od zera i czy moga byc ujemne
                ins_count--;
            }
        }
        visited[a] = 1;
    }
    for(int i = 0; i < vertices; i++){
        if(visited[i] == 0) std::cout << i << " ";
    }
    std::cout << "\n";
    std::cout << "The graph has been sorted successfully (Kahn algorithm).\n";
}