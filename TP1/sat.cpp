#include "sat.h"

SAT::SAT(int n) {
    size = n;
    componentsNumber = 0;

    graph.resize(2*n);
    graphT.resize(2*n);
    components.resize(2*n);

    for (int i = 0; i < 2*n; ++i) {
        usedVertex.push_back(false);
    }
}

void SAT::add(int v, int u, bool neg) {
    int vertexV, vertexNegV, vertexU, vertexNegU;

    if (!neg) {
        vertexV = v - 1;
        vertexU = u - 1;
        vertexNegV = v + size - 1;
        vertexNegU = u + size - 1;
    } else {
        vertexV = v + size - 1;
        vertexU = u + size - 1;
        vertexNegV = v - 1;
        vertexNegU = u - 1;
    }

    if (v == 0 && u > 0) {
        graph[vertexNegU].push_back(vertexU);
        graphT[vertexU].push_back(vertexNegU);
    } else if (u == 0 && v > 0) {
        graph[vertexNegV].push_back(vertexV);
        graphT[vertexV].push_back(vertexNegV);
    } else  if (v > 0 && u > 0) {
        graph[vertexNegU].push_back(vertexV);
        graph[vertexNegV].push_back(vertexU);
        graphT[vertexV].push_back(vertexNegU);
        graphT[vertexU].push_back(vertexNegV);
    }
}
