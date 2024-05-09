#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>

#include "../include/struct_graph.h"
#include "../include/struct_edgeList.h"
#include "../include/print_graph.h"

int generate_random_number(int x, int y)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(x, y);
    return distribution(gen);
}

void topologicalSortDFS(int node, std::vector<std::vector<int>> &graph, std::vector<bool> &visited, std::vector<int> &order)
{
    visited[node] = true;
    for (int neighbor = 0; neighbor < graph.size(); ++neighbor)
    {
        if (graph[node][neighbor] && !visited[neighbor])
        {
            topologicalSortDFS(neighbor, graph, visited, order);
        }
    }
    order.push_back(node);
}

// Funkcja do generowania grafu acyklicznego skierowanego
std::vector<std::vector<int>> generateDAG(int nodes, double saturation)
{
    std::vector<std::vector<int>> graph(nodes, std::vector<int>(nodes, 0));
    std::vector<int> order; // Kolejność odwiedzenia wierzchołków

    // Tworzenie kolejności topologicznej
    std::vector<bool> visited(nodes, false);
    for (int node = 0; node < nodes; ++node)
    {
        if (!visited[node])
        {
            topologicalSortDFS(node, graph, visited, order);
        }
    }
    std::reverse(order.begin(), order.end()); // Odwrócenie kolejności, aby rozpocząć od wierzchołka o najwyższym indeksie

    // Generowanie grafu
    srand(time(nullptr));
    for (int i = 0; i < nodes; ++i)
    {
        int numEdges = std::min(i, static_cast<int>(saturation / 100.0 * i));
        for (int j = 0; j < numEdges; ++j)
        {
            int from = rand() % i;            // Losowy wierzchołek źródłowy z wcześniejszych w kolejności topologicznej
            graph[order[from]][order[i]] = 1; // Dodanie krawędzi
        }
    }

    std::cout << "WiD: \n";
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            std::cout << graph[i][j] << " ";
        }
        std::cout << "\n";
    }

    return graph;
}

void topological_sort_DFS_bad(int Vertex, int **matrix, bool *visited, std::vector<int> &order, int vertices)
{
    visited[Vertex] = true;
    for (int neighbor = 0; neighbor < vertices; ++neighbor)
    {
        if (matrix[Vertex][neighbor] && !visited[neighbor])
        {
            topological_sort_DFS_bad(neighbor, matrix, visited, order, vertices);
        }
    }
    order.push_back(Vertex);
}

void generate_matrix_bad(int **matrix, int vertices)
{
    double saturation;
    std::cin >> saturation;
    std::cout << "saturation> " << saturation << "\n";
    saturation = 100;
    std::cout << "saturation> " << saturation << "\n";

    std::vector<int> order;
    bool *visited;
    visited = new bool[vertices];
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    // NA POCZĄTEK WYPEŁNIAMY ZERAMI MACIERZ
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; i < vertices; i++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < vertices; ++i)
    {
        if (!visited[i])
        {
            topological_sort_DFS_bad(i, matrix, visited, order, vertices);
        }
    }
    std::reverse(order.begin(), order.end()); // Odwrócenie kolejności, aby rozpocząć od wierzchołka o najwyższym indeksie

    // GENEROWANIE GRAFU
    srand(time(nullptr));
    for (int i = 0; i < vertices; ++i)
    {
        int numEdges = std::min(i, static_cast<int>(saturation / 100.0 * i));
        for (int j = 0; j < numEdges; ++j)
        {
            int from = rand() % i;             // Losowy wierzchołek źródłowy z wcześniejszych w kolejności topologicznej
            matrix[order[from]][order[i]] = 1; // Dodanie krawędzi
        }
    }

    generateDAG(vertices, saturation);
}

void generate_matrix(int **matrix, int vertices)
{
    double saturation;
    std::cin >> saturation;
    std::cout << "saturation> " << saturation << "\n";

    int maximum = ((vertices * vertices) - vertices) / 2;
    int edges_sat = maximum * saturation / 100;
    std::cout << "maximum: " << maximum << "\n";
    std::cout << "edges_sat: " << edges_sat << "\n";
    std::vector<std::vector<int>> edge_list;

    std::vector<int> order(vertices);
    // Fill vector with numbers from 0 to vertices-1
    for (int i = 0; i < vertices; ++i)
    {
        order[i] = i;
    }
    // Randomly shuffle the elements
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(order.begin(), order.end(), g);

    bool *visited;
    visited = new bool[vertices];
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    // NA POCZĄTEK WYPEŁNIAMY ZERAMI MACIERZ I DODAJEMY WSZYSTKIE MOŻLIWE KRAWĘDZIE DO edge_list
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            matrix[i][j] = 0;

            auto it = std::find(order.begin(), order.end(), i);
            auto jt = std::find(order.begin(), order.end(), j); 
            int index_i = it - order.begin(); 
            int index_j = jt - order.begin();

            if (i != j && (index_i < index_j))
            {
                std::vector edge({i, j});
                edge_list.push_back(edge);
            }
        }
    }

    // WYPISANIE ORDERA
    std::cout << "Order: ";
    for (int i = 0; i < vertices; i++)
    {
        std::cout << order[i] << " ";
    }
    std::cout << "\nPoczątkowy edge_list przed usuwaniem dodanych:\n";
    for (int i = 0; i < edge_list.size(); i++)
    {
        std::cout << edge_list[i][0] << " " << edge_list[i][1] << "\n";
    }

    int next;
    
    for (int i = 0; i < vertices - 1; i++)
    {
        next = generate_random_number(i + 1, vertices - 1);
        std::cout << order[i] << " > " << order[next] << "\n";

        matrix[order[i]][order[next]] = 1;
        matrix[order[next]][order[i]] = -1;

        std::vector edge_i({order[i], order[next]});
        edge_list.erase(std::remove(edge_list.begin(), edge_list.end(), edge_i), edge_list.end());
    }

    std::cout << "\nPoczątkowy edge_list po usuwanku:\n";
    for (int i = 0; i < edge_list.size(); i++)
    {
        std::cout << edge_list[i][0] << " " << edge_list[i][1] << "\n";
    }

    print_graph_matrix(matrix, vertices);

    // UZUPEŁNIANIE MACIERZY AŻ BĘDZIE
    int edges = vertices - 1;
    std::cout<<"edges: "<<edges<<"\nedges_sat: "<<edges_sat<<"\n";
    while (edges < edges_sat)
    {
        std::cout<<"edges: "<<edges<<"\n";
        int i = generate_random_number(0, edge_list.size() - 1);
        int start = edge_list[i][0];
        int end = edge_list[i][1];
        std::vector edge_i({start, end});
        std::cout << "DODAJEMY KRAWĘDŹ: " << start << " > " << end << "\n";

        matrix[start][end] = 1;
        matrix[end][start] = -1;
        edges++;

        // USUWAMY DODANĄ KRAWĘDŹ Z LISTY DOSTĘPNYCH DO DODANIA KRAWĘDZI
        edge_list.erase(edge_list.begin() + i);

        for (int i = 0; i < edge_list.size(); i++)
        {
            std::cout << edge_list[i][0] << " " << edge_list[i][1] << "\n";
        }
        print_graph_matrix(matrix, vertices);
    }
}

void generate_list(graph *L, int vertices)
{
}

void generate_table(edgeList *eList, int edges, int vertices)
{
}