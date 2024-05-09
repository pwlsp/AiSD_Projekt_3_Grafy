#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "../include/generate.h"
#include "../include/user_provided.h"
#include "../include/actions_matrix.h"
#include "../include/actions_list.h"
#include "../include/actions_table.h"
#include "../include/generate.h"
#include "../include/user_provided.h"
#include "../include/struct_graph.h"
#include "../include/struct_edgeList.h"

int main(int argc, char *argv[])
{

    if (argc <= 1)
    {
        std::cout << "No arguments given\n";
        return 1;
    }

    std::string create = std::string(argv[1]);

    if (create != "--generate" && create != "--user-provided")
    {
        std::cout << "Wrong arguments\n";
        return 0;
    }

    std::string type;
    std::cin >> type;
    std::cout << "type> " << type << "\n";

    int vertices, edges;

    if (type == "matrix")
    {
        std::cin >> vertices;
        std::cout << "vertices> " << vertices << "\n";
        int **matrix;
        matrix = new int *[vertices];
        for (int i = 0; i < vertices; i++)
            matrix[i] = new int[vertices];
        if (create == "--generate"){
            double saturation;
            std::cin >> saturation;
            std::cout << "saturation> " << saturation << "\n";

            int maximum = ((vertices * vertices) - vertices) / 2;
            int edges_sat = maximum * saturation / 100;

            generate_matrix(matrix, vertices, maximum, edges_sat);
        }
        if (create == "--user-provided")
            user_provided_matrix(matrix, vertices);
        actions_matrix(matrix, vertices);
    }
    else if (type == "list")
    {
        std::cin >> vertices;
        std::cout << "vertices> " << vertices << "\n";
        graph *L;
        L = new graph[vertices];
        if (create == "--generate")
        {
            double saturation;
            std::cin >> saturation;
            std::cout << "saturation> " << saturation << "\n";

            int maximum = ((vertices * vertices) - vertices) / 2;
            int edges_sat = maximum * saturation / 100;

            generate_list(L, vertices, maximum, edges_sat);
        }
            
        if (create == "--user-provided")
            user_provided_list(L, vertices);
        actions_list(L, vertices);
    }
    else if (type == "table")
    {
        edgeList *eList;
        eList = new edgeList[edges];
        
        if (create == "--generate")
        {
            std::cin >> vertices;
            std::cout << "vertices> " << vertices << "\n";

            double saturation;
            std::cin >> saturation;
            std::cout << "saturation> " << saturation << "\n";

            int maximum = ((vertices * vertices) - vertices) / 2;
            int edges_sat = maximum * saturation / 100;

            edges = edges_sat;

            generate_table(eList, vertices, maximum, edges_sat);
        }
        if (create == "--user-provided")
        {
            std::cin >> vertices;
            std::cout << "vertices> " << vertices << "\n";
            std::cin >> edges;
            std::cout << "edges> " << edges << "\n";
            user_provided_table(eList, edges);
        }
        actions_table(eList, edges, vertices);
    }
    else
    {
        std::cout << "Unknown graph representation\n";
        return 0;
    }
    return 0;
}
// ebe
// ebe
// ebe
// ebe
// ebe
// ebe
// ebe
// ebe
// ebe
// ebe
// ebe
// ebe
// ebe
// ebe
// ebe