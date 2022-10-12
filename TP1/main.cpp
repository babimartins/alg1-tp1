#include <iostream>
#include "sat.h"

int main() {
    int followers, propositions;
    std::cin >> followers >> propositions;

    while (followers > 0 && propositions > 0) {
        SAT sat = SAT(propositions);

        for (int i = 0; i < followers; ++i) {
            int keepP1, keepP2, removeP1, removeP2;
            std::cin >> keepP1 >> keepP2 >> removeP1 >> removeP2;

            sat.add(keepP1, keepP2, false);
            sat.add(removeP1, removeP2, true);
        }

        bool isPossible = sat.solve_2SAT();
        if (isPossible) {
            std::cout << "sim" << std::endl;
        } else {
            std::cout << "nao" << std::endl;
        }

        std::cin >> followers >> propositions;
    }

    return(0);
}
