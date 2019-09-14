#include "solver.h"

int main(int argc, char *argv[])
{
    try {
        Solver* solver;
        if (argc > 1) {
            solver = new Solver(argv[1]);
        } else {
            solver = new Solver();
        }

        solver->run_tests();

    } catch (const char * errorMessage) {
        std::cout << errorMessage << "\n";
    }

    return 0;
}
