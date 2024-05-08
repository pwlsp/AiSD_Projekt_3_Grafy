#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <bits/stdc++.h>

#include "../include/struct_graph.h"
#include "../include/struct_edgeList.h"

void topologicalSortDFS(int node, std::vector<std::vector<int>>& graph, std::vector<bool>& visited, std::vector<int>& order) {
    visited[node] = true;
    for (int neighbor = 0; neighbor < graph.size(); ++neighbor) {
        if (graph[node][neighbor] && !visited[neighbor]) {
            topologicalSortDFS(neighbor, graph, visited, order);
        }
    }
    order.push_back(node);
}

// Funkcja do generowania grafu acyklicznego skierowanego
std::vector<std::vector<int>> generateDAG(int nodes, double saturation) {
    std::vector<std::vector<int>> graph(nodes, std::vector<int>(nodes, 0));
    std::vector<int> order; // Kolejność odwiedzenia wierzchołków

    // Tworzenie kolejności topologicznej
    std::vector<bool> visited(nodes, false);
    for (int node = 0; node < nodes; ++node) {
        if (!visited[node]) {
            topologicalSortDFS(node, graph, visited, order);
        }
    }
    std::reverse(order.begin(), order.end()); // Odwrócenie kolejności, aby rozpocząć od wierzchołka o najwyższym indeksie

    // Generowanie grafu
    srand(time(nullptr));
    for (int i = 0; i < nodes; ++i) {
        int numEdges = std::min(i, static_cast<int>(saturation / 100.0 * i));
        for (int j = 0; j < numEdges; ++j) {
            int from = rand() % i; // Losowy wierzchołek źródłowy z wcześniejszych w kolejności topologicznej
            graph[order[from]][order[i]] = 1; // Dodanie krawędzi
        }
    }

    return graph;
}

void generate_matrix(int **matrix, int vertices){
    for(int i = 1; i < vertices; i++){

    }
}

void generate_list(graph *L, int vertices){
   
}

void generate_table(edgeList *eList, int edges, int vertices){

}