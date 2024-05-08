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

void Tarjan_go_list(graph *L, int vertices, int *color, std::stack<int> &Stack, int Vertex, int *ins)
{
    color[Vertex] = 1;

    for (std::list<int>::iterator it = L[Vertex].next.begin(); it != L[Vertex].next.end(); it++)
    {
        if ((!color[*it]) && color[Vertex] == 1)
        {
            Tarjan_go_list(L, vertices, color, Stack, *it, ins);
        }
    }
    color[Vertex] = 2;
    Stack.push(Vertex);
}

void Tarjan_go_table(edgeList *eList, int edges, int vertices, int *color, std::stack<int> &Stack, int Vertex, int *ins)
{
    color[Vertex] = 1;
    for (int i = 0; i < edges; i++)
    {
        if(eList[i].out == Vertex && (!color[eList[i].in]) && color[Vertex] == 1){
            Tarjan_go_table(eList, edges, vertices, color, Stack, eList[i].in, ins);
        }
    }
    color[Vertex] = 2;
    Stack.push(Vertex);
}

void Tarjan_matrix(int **matrix, int vertices)
{
    // DEKLARACJE:
    std::stack<int> Stack;
    int ins[vertices], pierwszy = 0;
    int *color;
    color = new int[vertices];

    // NAPEŁNIAMY ZERAMI TABLICĘ "COLOR" I "INS" (JAKI STOPIEŃ WEJŚCIOWY)
    for (int i = 0; i < vertices; i++)
    {
        color[i] = 0;
        ins[i] = 0;
    }

    // SPRAWDZAMY JAKI JEST STOPIEŃ WEJŚCIOWY WIERZCHOŁKÓW I ZAPISUJEMY W "INS"
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

    // ###### WŁAŚCIWY ALGORYTM #######

    // ROBIMY DFS'A ZACZYNAJĄC OD WIERZCHOŁKÓW NIEZALEŻNYCH
    for (int i = 0; i < vertices; i++)
    {
        if (ins[i] == 0 && !color[i])
        {
            Tarjan_go_matrix(matrix, vertices, color, Stack, i, ins);
        }
    }

    int blacks = 0;
    for (int j = 0; j < vertices; j++)
    {
        if (color[j] == 2)
        {
            blacks++;
        }
    }

    if (blacks == vertices)
    {
        while (!Stack.empty())
        {
            std::cout << Stack.top() << " ";
            Stack.pop();
        }
        std::cout << "\n";
    }
}

void Tarjan_list(graph *L, int vertices)
{
    // DEKLARACJE:
    std::stack<int> Stack;
    int ins[vertices], pierwszy = 0;
    int *color;
    color = new int[vertices];

    // NAPEŁNIAMY ZERAMI TABLICĘ "COLOR" I "INS" (JAKI STOPIEŃ WEJŚCIOWY)
    for (int i = 0; i < vertices; i++)
    {
        color[i] = 0;
        ins[i] = 0;
    }

    // SPRAWDZAMY JAKI JEST STOPIEŃ WEJŚCIOWY WIERZCHOŁKÓW I ZAPISUJEMY W "INS"
    for (int i = 0; i < vertices; i++)
    {
        for (std::list<int>::iterator it = L[i].next.begin(); it != L[i].next.end(); it++)
        {
            ins[*it]++;
        }
    }

    // ###### WŁAŚCIWY ALGORYTM #######

    // ROBIMY DFS'A ZACZYNAJĄC OD WIERZCHOŁKÓW NIEZALEŻNYCH
    for (int i = 0; i < vertices; i++)
    {
        if (ins[i] == 0 && !color[i])
        {
            Tarjan_go_list(L, vertices, color, Stack, i, ins);
        }
    }

    int blacks = 0;
    for (int j = 0; j < vertices; j++)
    {
        if (color[j] == 2)
        {
            blacks++;
        }
    }

    if (blacks == vertices)
    {
        while (!Stack.empty())
        {
            std::cout << Stack.top() << " ";
            Stack.pop();
        }
        std::cout << "\n";
    }
}

void Tarjan_table(edgeList *eList, int edges, int vertices)
{
    // DEKLARACJE:
    std::stack<int> Stack;
    int ins[vertices], pierwszy = 0;
    int *color;
    color = new int[vertices];

    // NAPEŁNIAMY ZERAMI TABLICĘ "COLOR" I "INS" (JAKI STOPIEŃ WEJŚCIOWY)
    for (int i = 0; i < vertices; i++)
    {
        color[i] = 0;
        ins[i] = 0;
    }

    // SPRAWDZAMY JAKI JEST STOPIEŃ WEJŚCIOWY WIERZCHOŁKÓW I ZAPISUJEMY W "INS"
    for (int i = 0; i < edges; i++)
    {
        ins[eList[i].in]++;
    }

    // ###### WŁAŚCIWY ALGORYTM #######

    // ROBIMY DFS'A ZACZYNAJĄC OD WIERZCHOŁKÓW NIEZALEŻNYCH
    for (int i = 0; i < vertices; i++)
    {
        if (ins[i] == 0 && !color[i])
        {
            Tarjan_go_table(eList, edges, vertices, color, Stack, i, ins);
        }
    }
    
    int blacks = 0;
    for (int j = 0; j < vertices; j++)
    {
        if (color[j] == 2)
        {
            blacks++;
        }
    }

    if (blacks == vertices)
    {
        while (!Stack.empty())
        {
            std::cout << Stack.top() << " ";
            Stack.pop();
        }
        std::cout << "\n";
    }
}
