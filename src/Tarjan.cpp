#include <iostream>
#include <list>
#include <stack>

#include "../include/struct_graph.h"
#include "../include/struct_edgeList.h"

void Tarjan_go_matrix(int **matrix_copy, int vertices, int *color, std::stack<int> Stack, int Vertex, int *ins)
{
    // if (color[Vertex] == 0)
    // {
    //     color[Vertex] = 1;
    //     for (int i = 0; i < vertices; i++)
    //     {
    //         if (matrix_copy[Vertex][i] == 1 && (!color[i]) && color[Vertex] == 1)
    //         {
    //             Tarjan_go_matrix(matrix_copy, vertices, color, Stack, i, ins);
    //         }
    //     }
    //     color[Vertex] = 2;
    //     Stack.push(Vertex);
    // }

    color[Vertex] = 1;
    for (int i = 0; i < vertices; i++)
    {
        if (matrix_copy[Vertex][i] == 1 && (!color[i]) && color[Vertex] == 1)
        {
            Tarjan_go_matrix(matrix_copy, vertices, color, Stack, i, ins);
        }
    }
    color[Vertex] = 2;
    Stack.push(Vertex);
}

// bool DFStsort (int **matrix_copy, int vertices, int *color, std::stack<int> Stack, int V)
// {
//   slistEl *p;

//   if(visited [v] == 1)     // Sprawdzamy, czy nie ma cyklu
//   {
//     cout << "\nNOT A DAG\n\n";    // Jest cykl - sortowanie topologiczne
//     return false;                 // nie może zostać wykonane
//   }
//   if(visited [v] == 0)    // Jeśli wierzchołek jest biały,
//   {
//     visited [v] = 1;         // to kolorujemy go na szaro
//     for(p = graf [v];p;p = p->next) // i przeglądamy wszystkich sąsiadów
//       if(!DFStsort (p->v)) return false; // Wywołanie rekurencyjne
//     visited [v] = 2;        // Wierzchołek kolorujemy na zielono
//     S [sptr++] = v;             // i umieszczamy go na stosie
//   }
//   return true;                    // Kończymy z wynikiem true
// }

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
    int **matrix_copy;
    matrix_copy = new int *[vertices];
    for (int i = 0; i < vertices; i++)
        matrix_copy[i] = new int[vertices];
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            matrix_copy[i][j] = matrix[i][j];
            if (matrix_copy[i][j] == 1)
            {
                ins[j]++;
            }
        }
    }

    for (int i = 0; i < vertices; i++)
    {
        if (ins[i] == 0)
        {
            pierwszy = i;
            break;
        }
    }

    // Tarjan_go_matrix(matrix_copy, vertices, color, Stack, 0, ins);
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
//         std::cout << matrix_copy[i][j] << " ";
//     }
//     std::cout<<"\n";
// }

// ########### WYPISYWANIE LISTY ############
// for (int i = 0; i < vertices; i++)
// {
//     std::cout << color[i] << " ";
// }

// std::cout << "\n";