#include <iostream>
#include <queue>
#include <list>

#include "../include/struct_graph.h"
#include "../include/struct_edgeList.h"

void bfs_go_matrix(int **matrix, int V, int N, bool *visited){
    std::queue <int> Q;
    Q.push(V);
    visited[V] = 1;
    int U, j;
    while(!Q.empty()){
        U = Q.front();
        Q.pop();
        std::cout << U << " ";
        j = 0;
        //dodawaj od tego obecnego i idz dalej w kolejce
        while(j < N){
            if(matrix[U][j] == 1 and !visited[j]){
                Q.push(j);
                visited[j] = 1;
            }
            j++;
        }
    }
}

void bfs_go_list(graph *L, int V, int N, bool *visited){
    std::queue <int> Q;
    Q.push(V);
    visited[V] = 1;
    int U, j;
    while(!Q.empty()){
        U = Q.front();
        Q.pop();
        std::cout << U << " ";
        for (std::list<int>::iterator it = L[U].next.begin(); it != L[U].next.end(); it++){
            if(!visited[*it]){
                Q.push(*it);
                visited[*it] = 1;
            }
        }
    }

}

void bfs_go_table(edgeList *eList, int V, int E, bool *visited){
    std::queue <int> Q;
    Q.push(V);
    visited[V] = 1;
    int U, j;
    while(!Q.empty()){
        U = Q.front();
        Q.pop();
        std::cout << U << " ";
        j = 0;
        //dodawaj od tego obecnego i idz dalej w kolejce
        for(int i = 0; i < E; i++){
            if(eList[i].out == U && !visited[eList[i].in])
            {
                Q.push(eList[i].in);
                visited[eList[i].in] = 1;
            }
        }
    }
}

void bfs_matrix(int **matrix, int vertices){
    bool *visited; visited = new bool[vertices];
    for(int i = 0; i < vertices; i++) visited[i] = 0;
    for(int i = 0; i < vertices; i++){
        if(!visited[i]) bfs_go_matrix(matrix, i, vertices, visited);
    }
    std::cout << "\n";
}

void bfs_list(graph *L, int vertices){ //pomyslec jak jest puste, jak to zaznaczac, ze pusta lista dla jakiegos elementu
    bool *visited; visited = new bool[vertices];
    for(int i = 0; i < vertices; i++) visited[i] = 0;
    for(int i = 0; i < vertices; i++){
        if(!visited[i]) bfs_go_list(L, i, vertices, visited);
    }
    std::cout << "\n";
}

void bfs_table(edgeList *eList, int edges, int vertices){
    bool *visited; visited = new bool[vertices];
    for(int i = 0; i < vertices; i++) visited[i] = 0;
    for(int i = 0; i < vertices; i++){
        if(!visited[i]) bfs_go_table(eList, i, edges, visited);
    }
    std::cout << "\n";
}