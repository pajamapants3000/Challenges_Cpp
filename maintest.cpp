#include "solver.h"

int main(int argc, char *argv[])
{
    Solver* solver;
    if (argc > 1) {
        solver = new Solver(argv[1]);
    } else {
        solver = new Solver();
    }

    solver->run_tests();

    return 0;
}
