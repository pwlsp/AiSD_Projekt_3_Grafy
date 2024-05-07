#include <iostream>
#include <list>
#include <stack>

#include "../include/struct_graph.h"
#include "../include/struct_edgeList.h"

void Tarjan_go_matrix(int **matrix_copy, int vertices, int *color, std::stack<int> S)
{
    for (int i = 0; i < vertices; i++)
    {
        std::cout << color[i] << " ";
    }

    std::cout << "\n";
}

void Tarjan_matrix(int **matrix, int vertices)
{
    int *color;
    color = new int[vertices];
    for (int i = 0; i < vertices; i++)
        color[i] = 0;

    int **matrix_copy; matrix_copy = new int *[vertices];
    for(int i = 0; i < vertices; i++) matrix_copy[i] = new int[vertices];
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            matrix_copy[i][j] = matrix[i][j];
        }
    }
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            std::cout << matrix_copy[i][j] << " ";
        }
        std::cout<<"\n";
    }

    // Tarjan_go_matrix(matrix_copy, vertices)
}

void Tarjan_list(graph *L, int vertices)
{
}

void Tarjan_table(edgeList *eList, int edges, int vertices)
{
}