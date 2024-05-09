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

void generate_matrix(int **matrix, int vertices, int maximum, int edges_sat)
{
    std::cout << "\n-----------GRAPH GENERATION----------\n\n";
    std::cout << "100\% of edges: " << maximum << "\n";
    std::cout << "Number of edges that can be added with given saturation: " << edges_sat << "\n";
    std::vector<std::vector<int>> edge_list;

    // TWORZENIE VECTORA order
    std::vector<int> order(vertices);
    for (int i = 0; i < vertices; ++i)
    {
        order[i] = i;
    }
    // TASOWANIE order'A I TYM SAMYM TWORZENIE KOLEJNOŚCI TOPOLOGICZNEJ NASZEGO GRAFU DAG
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(order.begin(), order.end(), g);

    // NA POCZĄTEK WYPEŁNIAMY ZERAMI MACIERZ I DODAJEMY WSZYSTKIE MOŻLIWE KRAWĘDZIE NIETWORZĄCE CYKLI DO edge_list
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
    std::cout << "Topological order of graph's nodes: ";
    for (int i = 0; i < vertices; i++)
    {
        std::cout << order[i] << " ";
    }

    std::cout << "\n\nThe list of edges that can be added to the DAG:\n";
    for (int i = 0; i < edge_list.size(); i++)
    {
        std::cout << edge_list[i][0] << " " << edge_list[i][1] << "\n";
    }

    std::cout << "\nAdding the minimum number of edges so that the graph is connected:\n";
    int next;

    for (int i = 0; i < vertices - 1; i++)
    {
        next = generate_random_number(i + 1, vertices - 1);
        std::cout << order[i] << " -> " << order[next] << "\n";

        matrix[order[i]][order[next]] = 1;
        matrix[order[next]][order[i]] = -1;

        std::vector edge_i({order[i], order[next]});
        edge_list.erase(std::remove(edge_list.begin(), edge_list.end(), edge_i), edge_list.end());
    }

    std::cout << "\nList of the remaining edges that will be randomly selected:\n";
    for (int i = 0; i < edge_list.size(); i++)
    {
        std::cout << edge_list[i][0] << " " << edge_list[i][1] << "\n";
    }

    // print_graph_matrix(matrix, vertices);

    // UZUPEŁNIANIE MACIERZY AŻ BĘDZIE WYSTARCZAJĄCO DUŻO KRAWĘDZI
    int edges = vertices - 1;
    if (edges > edges_sat)
    {
        std::cout<<"\nWARNING: Given saturation is not enough to make a DAG - generating DAG with minimum amount of edges.\n";
    }
    while (edges < edges_sat)
    {
        // std::cout<<"\nedges: "<<edges<<"\n";
        int i = generate_random_number(0, edge_list.size() - 1);
        int start = edge_list[i][0];
        int end = edge_list[i][1];
        std::vector edge_i({start, end});
        // std::cout << "Dodajemy krawędź: " << start << " > " << end << "\n";

        matrix[start][end] = 1;
        matrix[end][start] = -1;
        edges++;

        // USUWAMY DODANĄ KRAWĘDŹ Z LISTY DOSTĘPNYCH
        edge_list.erase(edge_list.begin() + i);

        // ######## TU MOGĘ WYPISAĆ ZMIANY MACIERZY ###########
        // print_graph_matrix(matrix, vertices);
        // std::cout<<std::endl;
    }

    std::cout << "\n-----------GRAPH GENERATION COMPLETE----------\n\n";
}

void generate_list(graph *L, int vertices, int maximum, int edges_sat)
{
    int **matrix;
    matrix = new int *[vertices];
    for (int i = 0; i < vertices; i++)
        matrix[i] = new int[vertices];

    generate_matrix(matrix, vertices, maximum, edges_sat);
    // print_graph_matrix(matrix, vertices);

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (matrix[i][j] == 1)
            {
                L[i].next.push_back(j);
            }
        }
    }
}

void generate_table(edgeList *eList, int vertices, int maximum, int edges_sat)
{
    int **matrix;
    matrix = new int *[vertices];
    for (int i = 0; i < vertices; i++)
        matrix[i] = new int[vertices];

    generate_matrix(matrix, vertices, maximum, edges_sat);
    // print_graph_matrix(matrix, vertices);

    int iter = 0;

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (matrix[i][j] == 1)
            {
                eList[iter].out = i;
                eList[iter].in = j;

                iter++;
            }
        }
    }
}