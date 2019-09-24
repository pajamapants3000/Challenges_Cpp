#ifndef SOLUTIONFACTORY_H
#define SOLUTIONFACTORY_H

#include <memory>

#include "solution.h"

class SolutionFactory
{
    SolutionFactory();

public:
    static std::shared_ptr<Solution> getSolution(const Challenge challenge);
    static std::shared_ptr<Solution> getSolution(std::string input, const Challenge challenge);
    static std::shared_ptr<Solution> getSolution(const std::string challenge);
    static std::shared_ptr<Solution> getSolution(std::string input, const std::string challenge);
};

#endif // SOLUTIONFACTORY_H
