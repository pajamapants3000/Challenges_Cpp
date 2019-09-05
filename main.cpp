#include "solver.h"

#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Enter input:\n";

    char B[inputMaxChar];
    std::string input { fgets(B, inputMaxChar, stdin) };

    Solver* solver;
    if (argc > 1) {
        solver = new Solver(argv[1]);
    } else {
        solver = new Solver();
    }

    std::cout << "Result: ";
    solver->run(input);
    std::cout << "\n";

    return 0;
}
