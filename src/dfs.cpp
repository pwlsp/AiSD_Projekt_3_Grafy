#include <iostream>
#include <queue>
#include <stack>
#include <list>

#include "../include/struct_graph.h"
#include "../include/struct_edgeList.h"

void dfs_go_matrix(int **matrix, int V, int N, bool *visited)
{
    std::cout << V << " ";

    visited[V] = true;

    for (int i = 0; i < N; i++)
    {
        if (matrix[V][i] == 1 && (!visited[i]))
        {
            dfs_go_matrix(matrix, i, N, visited);
        }
    }
}

void dfs_go_list(graph *L, int V, int N, bool *visited)
{
    std::cout << V << " ";

    visited[V] = true;

    for (std::list<int>::iterator it = L[V].next.begin(); it != L[V].next.end(); it++)
    {
        if (!visited[*it])
        {
            dfs_go_list(L, *it, N, visited);
        }
    }
}

void dfs_go_table(edgeList *eList, int V, int E, bool *visited)
{
    std::cout << V << " ";

    visited[V] = true;

    for (int i = 0; i < E; i++)
    {
        if (eList[i].out == V && !visited[eList[i].in])
        {
            visited[eList[i].in] = 1;
            dfs_go_table(eList, eList[i].in, E, visited);
        }
    }
}

void dfs_matrix(int **matrix, int vertices)
{
    bool *visited;
    visited = new bool[vertices];
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;
    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
            dfs_go_matrix(matrix, i, vertices, visited);
    }
    std::cout << "\n";
}

void dfs_list(graph *L, int vertices)
{
    bool *visited;
    visited = new bool[vertices];
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;
    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
            dfs_go_list(L, i, vertices, visited);
    }
    std::cout << "\n";
}

void dfs_table(edgeList *eList, int edges, int vertices)
{
    bool *visited;
    visited = new bool[vertices];
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;
    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
            dfs_go_table(eList, i, edges, visited);
    }
    std::cout << "\n";
}