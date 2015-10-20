//
//  main.cpp
//  GraphsSandbox
//
//  Created by Jonathan Ginsburg on 10/15/15.
//  Copyright © 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "../../Graph.h"
#include "../../Helper.h"

void PM(int * * matrix, int rows, int columns){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (matrix[i][j] == INT_MAX) std::cout << "∞" << "\t";
            else std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void addE(int v1, int v2, Graph<int, int> & g, int e){
    g.addEdge(e, v1, v2);
    g.addEdge(e, v2, v1);
}

void FW(Graph<int, int> & g){
    
    int V = (int)g.getVertices()->size();
    
    int ** dist = Helper::buildMatrix<int>(V, V);
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INT_MAX;
        }
    }
    
    for (int i = 0; i < (int)g.getEdges()->size(); ++i) {
        Edge<int, int> * e = g.getEdgeAt(i);
        int origin = *(e->getOrigin()->getInfo());
        int destination = *(e->getDestination()->getInfo());
        dist[origin - 1][destination - 1] = *e->getInfo();
    }
    for (int k = 1; k <= V; ++k) {
        PM(dist, V, V);
        for (int i = 1; i <= V; ++i) {
            for (int j = 1; j <= V; ++j) {
                if (dist[i - 1][k - 1] == INT_MAX || dist[k - 1][j - 1] == INT_MAX) {
                }
                else if (dist[i - 1][k - 1] + dist[k - 1][j - 1] < dist[i - 1][j - 1]) {
                    dist[i - 1][j - 1] = dist[i - 1][k - 1] + dist[k - 1][j - 1];
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    Graph<int, int> g;
    for (int i = 1; i < 10 ; i++) {
        g.addVertex(i);
    }
    addE(6, 8, g, 5);
    addE(2, 3, g, 5);
    addE(5, 9, g, 2);
    addE(1, 4, g, 10);
    addE(4, 7, g, 5);
    addE(2, 1, g, 6);
    addE(2, 5, g, 10);
    addE(5, 4, g, 9);
    addE(6, 9, g, 1);
    addE(8, 7, g, 4);
    FW(g);
    
    
    return 0;
}
