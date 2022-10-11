#ifndef SAT_H
#define SAT_H

#include <iostream>
#include <vector>
#include <stack>

class SAT {
private:
    int size, componentsNumber;
    std::vector<std::vector<int>> graph;
    std::vector<std::vector<int>> graphT;
    std::vector<bool> visited;
    std::stack<int> finished;

    void dfs(int vertex);
    void dfs_t(int vertex);

public:
    SAT();
    SAT(int n);
    void add(int posV, bool negV, int posU, bool negU);
    bool sat_2();
};

#endif //SAT_H
