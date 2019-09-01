#include "solver.h"

int main(int argc, char *argv[])
{
    char B[inputMaxChar];
    std::string input { fgets(B, inputMaxChar, stdin) };

    Solver* solver;
    if (argc > 1) {
        solver = new Solver(argv[1]);
    } else {
        solver = new Solver();
    }

    solver->run(input);

    return 0;
}
