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