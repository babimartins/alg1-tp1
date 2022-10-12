#include "sat.h"

SAT::SAT(int n) {
    size = n;

    graph.resize(2 * size);
    graphT.resize(2 * size);
    components.resize(2 * size);
    usedVertex.resize(2 * size, false);
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

bool SAT::solve_2SAT() {
    int componentNumber = 0;
    for (int i = 0; i < 2*size; i++) {
        if (!usedVertex[i]) {
            dfs(i);
        }
    }

    for (int i = 0; i < 2*size; ++i) {
        usedVertex[i] = false;
    }

    while(!finishingOrder.empty()){
        int top = finishingOrder.top();
        finishingOrder.pop();

        if(!usedVertex[top]){
            componentNumber++;
            dfs_t(top, componentNumber);
        }
    }

    bool isPossible = true;
    for (int i = 0; i < size; i++) {
        if (components[i] == components[i + size]) {
            isPossible = false;
        }
    }
    return isPossible;
}

void SAT::dfs(int vertex) {
    usedVertex[vertex] = true;
    for(auto i: graph[vertex]){
        if(!usedVertex[i]){
            dfs(i);
        }
    }
    finishingOrder.push(vertex);
}

void SAT::dfs_t(int vertex, int componentNumber) {
    usedVertex[vertex] = true;
    for(auto v: graphT[vertex]){
        if(!usedVertex[v]){
            dfs_t(v, componentNumber);
        }
    }
    components[vertex] = componentNumber;
}
