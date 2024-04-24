#include <iostream>
#include <queue>

void bfs_go_matrix(int N, int visited){
    std::queue <int> next;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) visited[i][j] = 0;
    }
    while()
    while(!next.empty()){
        //dodawaj od tego obecnego i idz dalej w kolejce
    }
    next.push();
    next.pop();
}

void bfs_list(){

}

void bfs_table(){
    
}

void bfs_matrix(int nodes){
    bool *visited; visited = new bool[nodes];
    for(int i = 0; i < nodes; i++) visited[i] = new bool[nodes];
    for(int i = 0; i < nodes; i++){
        for(int j = 0; j < nodes; j++) bfs_go_matrix(matrix[i][j], nodes, visited);
    }
}