#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <ios>
#include <limits>
#include <vector>

#include "../include/struct_graph.h"
#include "../include/struct_edgeList.h"

void user_provided_matrix(int **matrix, int vertices)
{
    std::string line;
    int j, to;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 0; i < vertices; i++)
    {
        j = 0;
        getline(std::cin, line);
        std::stringstream is(line);
        for (int j = 0; j < line.size(); j++)
        {
            if (line[j] != ' ')
            {
                if (!((line[j] == '0' || line[j] == '1') || line[j] == '-'))
                {
                    std::cout << "Wrong type of data.\nExiting the program...\n";
                    exit(0);
                }
            }
        }
        while (is >> to)
        {
            matrix[i][j] = to;
            j++;
        }
        std::cout << "\n";
    }
}

void user_provided_list(graph *L, int vertices)
{
    std::string line;
    int to;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 0; i < vertices; i++)
    {
        getline(std::cin, line);
        std::stringstream is(line);
        if (line != "")
        {
            for (int j = 0; j < line.size(); j++)
            {
                if (!(line[j] >= '0' && line[j] <= '9' || line[j]))
                {
                    std::cout << "Wrong type of data.\nExiting the program...\n";
                    exit(0);
                }
            }
            while (is >> to)
                L[i].next.push_back(to);
        }
    }
}

void user_provided_table(edgeList *eList, int edges, int vertices)
{ // int &vertices){
    int prevL, prevR;
    for (int i = 0; i < edges; i++)
    {
        std::cin >> eList[i].out >> eList[i].in;
        if (i != 0)
        {
            if (prevL > eList[i].out || (prevL == eList[i].out && prevR > eList[i].in))
            {
                std::cout << "The list of edges must be sorted.\nExiting the program...\n";
                exit(0);
            }
            if(eList[i].out > vertices-1 || eList[i].in > vertices-1){
                std::cout << "Vertex out of range.\nExiting the program...\n";
                exit(0);
            }
        }
        prevL = eList[i].out;
        prevR = eList[i].in;
    }
}