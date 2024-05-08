#include <iostream>
#include <list>
#include <stack>

#include "../include/struct_graph.h"
#include "../include/struct_edgeList.h"

void Tarjan_go_matrix(int **matrix, int vertices, int *color, std::stack<int> &Stack, int Vertex, int *ins)
{
    color[Vertex] = 1;
    for (int i = 0; i < vertices; i++)
    {
        if (matrix[Vertex][i] == 1 && (!color[i]) && color[Vertex] == 1)
        {
            Tarjan_go_matrix(matrix, vertices, color, Stack, i, ins);
        }
    }
    color[Vertex] = 2;
    Stack.push(Vertex);
}

void Tarjan_go_list(int **matrix, int vertices, int *color, std::stack<int> &Stack, int Vertex, int *ins)
{
    color[Vertex] = 1;
    for (int i = 0; i < vertices; i++)
    {
        if (matrix[Vertex][i] == 1 && (!color[i]) && color[Vertex] == 1)
        {
            Tarjan_go_matrix(matrix, vertices, color, Stack, i, ins);
        }
    }
    color[Vertex] = 2;
    Stack.push(Vertex);
}

void Tarjan_go_table(int **matrix, int vertices, int *color, std::stack<int> &Stack, int Vertex, int *ins)
{
    color[Vertex] = 1;
    for (int i = 0; i < vertices; i++)
    {
        if (matrix[Vertex][i] == 1 && (!color[i]) && color[Vertex] == 1)
        {
            Tarjan_go_matrix(matrix, vertices, color, Stack, i, ins);
        }
    }
    color[Vertex] = 2;
    Stack.push(Vertex);
}

void Tarjan_matrix(int **matrix, int vertices)
{
    std::stack<int> Stack;
    int ins[vertices], pierwszy = 0;
    int *color;
    color = new int[vertices];
    for (int i = 0; i < vertices; i++)
    {
        color[i] = 0;
        ins[i] = 0;
    }
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (matrix[i][j] == 1)
            {
                ins[j]++;
            }
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        if (ins[i] == 0 && !color[i])
        {
            std::cout << "Pierwsza petla: " << i << "\n";
            Tarjan_go_matrix(matrix, vertices, color, Stack, i, ins);
        }
    }
    for (int i = 0; i < vertices; i++)
    {
        if (!color[i])
        {
            Tarjan_go_matrix(matrix, vertices, color, Stack, i, ins);
        }
    }

    while (!Stack.empty()) {
        std::cout << Stack.top() <<" ";
        Stack.pop();
    }
    std::cout << "\n";
}

void Tarjan_list(graph *L, int vertices)
{
}

void Tarjan_table(edgeList *eList, int edges, int vertices)
{
}

// ########## WYPISYWANIE MATRYCY ###########
// for(int i = 0; i < vertices; i++){
//     for(int j = 0; j < vertices; j++){
//         std::cout << matrix[i][j] << " ";
//     }
//     std::cout<<"\n";
// }

// ########### WYPISYWANIE LISTY ############
// for (int i = 0; i < vertices; i++)
// {
//     std::cout << color[i] << " ";
// }

// std::cout << "\n";