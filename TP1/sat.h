#ifndef SAT_H
#define SAT_H

#include <iostream>
#include <vector>
#include <stack>

class SAT {
private:
    int size, componentsNumber;
    std::vector<std::vector<int>> graph, graphT;
    std::vector<bool> usedVertex;
    std::vector<int> components;
    std::stack<int> finishingOrder;

    void dfs(int vertex);
    void dfs_t(int vertex);

public:
    explicit SAT(int n);
    void add(int v, int u, bool neg);
    bool solve_2SAT();
};

#endif //SAT_H
