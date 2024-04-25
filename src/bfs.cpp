#include <iostream>
#include <queue>
#include <list>

#include "../include/struct_graph.h"

void bfs_go_matrix(int **matrix, int V, int N, bool *visited){
    std::queue <int> next;
    next.push(V);
    visited[V] = 1;
    int U, j;
    while(!next.empty()){
        U = next.front();
        next.pop();
        std::cout << U << " ";
        j = 0;
        //dodawaj od tego obecnego i idz dalej w kolejce
        while(j < N){
            if(matrix[U][j] and !visited[j]){
                next.push(j);
                visited[j] = 1;
            }
            j++;
        }
    }
}

void bfs_list_go(){

}

void bfs_table_go(){
    
}

void bfs_matrix(int **matrix, int vertices){
    bool *visited; visited = new bool[vertices];
    for(int i = 0; i < vertices; i++) visited[i] = 0;
    for(int i = 0; i < vertices; i++){
        if(!visited[i]) bfs_go_matrix(matrix, i, vertices, visited);
    }
    std::cout << "\n";
}

void bfs_list(graph *L, int vertices){
    bool *visited; visited = new bool[vertices];
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++) visited[i] = 0;
    }
}

void bfs_table(int vertices){
    bool *visited; visited = new bool[vertices];
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++) visited[i] = 0;
    }
}