#include <iostream>
#include <queue>

void bfs_go_matrix(int **matrix, int V, int N, bool *visited){
    std::queue <int> next;
    next.push(V);
    int U, j;
    while(!next.empty()){
        U = next.front();
        next.pop();
        std::cout << U << " ";
        visited[U] = 1;
        j = 0;
        //dodawaj od tego obecnego i idz dalej w kolejce
        while(j < N){
            if(matrix[U][j] and !visited[j]) next.push(matrix[V][j]); 
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
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++) visited[i] = 0;
    }

    for(int i = 0; i < vertices; i++) visited[i] = new bool[vertices];
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++) {
            bfs_go_matrix(matrix, matrix[i][j], vertices, visited);
            //visited[i] = 1;
        }
    }
}

void bfs_list(int vertices){
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