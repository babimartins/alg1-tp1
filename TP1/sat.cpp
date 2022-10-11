#include "sat.h"

SAT::SAT(int n) {
    size = n;
    componentsNumber = 0;

    graph.resize(2*n + 1);
    graphT.resize(2*n + 1);
    components.resize(2*n + 1);
    for (int i = 0; i < (2*n + 1); ++i) {
        usedVertex.push_back(false);
    }
}
