#include "closestenemy.h"

#include <ctype.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "solution.h"
#include "solutionio.h"

ClosestEnemy::ClosestEnemy() :
    Solution(),
    matrix{},
    selfPos{}
{
}

ClosestEnemy::ClosestEnemy(std::string input) :
    Solution(),
    matrix{},
    selfPos{}
{
    setInput(input);
}

ClosestEnemy::~ClosestEnemy(){}

std::vector<std::tuple<std::string, std::string>> ClosestEnemy::testCases() const
{
    return {{ "0 0 0, 1 0 0, 2 0 0", "1"}, { "0 0 0 0, 2 0 1 0, 0 0 0 0, 2 0 0 2", "2"},
            { "0 0 0 0 1 0 0, 0 0 0 0 0 0 0, 0 0 0 0 0 0 0, 0 2 0 0 0 0 0, 0 0 0 0 0 0 0, 0 0 0 0 0 0 0, 0 0 0 0 0 2 0", "2"}};
}

void ClosestEnemy::setInput(const std::string input)
{
    matrix = extractMatrix<int>(input, "ClosestEnemy");
    findSelf();
}

std::string ClosestEnemy::getSolution() const
{
    size_t maxIndex { static_cast<size_t>(
                (matrix.size() > matrix.at(0).size() ? matrix.size() : matrix.at(0).size()) / 2
    )};

    for (size_t i {1}; i <= maxIndex; ++i) {
        for (Corner c : { Corner::LL, Corner::LR, Corner::UL, Corner::UR }) {
            if (isEnemyOnDiagonal(i, c)) {
                return std::to_string(i);
            }
        }
    }

    return "0";
}

void ClosestEnemy::findSelf()
{
    for (size_t i {0}; i < matrix.size(); ++i) {
        for (size_t j {0}; j < matrix.at(0).size(); ++j) {
            if (matrix.at(i).at(j) == 1) {
                selfPos.clear();
                selfPos.push_back(i);
                selfPos.push_back(j);
            }
        }
    }
}

size_t ClosestEnemy::translate(size_t x, long trans, size_t max) const
{
    bool isTransNegative { trans < 0 };
    size_t absModTrans = static_cast<size_t>(trans * (isTransNegative ? -1 : 1)) % max;
    if (isTransNegative) {
        return (x + (max - absModTrans)) % max;
    } else {
        return (x + absModTrans) % max;
    }
}

bool ClosestEnemy::isEnemyOnDiagonal(size_t distance, Corner corner) const
{
    size_t height { matrix.size() };
    size_t width { matrix.at(0).size() };
    size_t maxIndex = static_cast<size_t>((height > width ? height : width) / 2);

    size_t self_y = selfPos.at(0);
    size_t self_x = selfPos.at(1);

    if (distance > maxIndex) {
        std::cerr << "Invalid argument to `isEnemyOnDiagonal`: distance exceeded range.\n";
        exit(1);
    }

    size_t x {0};
    size_t y {0};
    for (size_t i = 0; i <= distance; ++i) {
        if ((distance - i > static_cast<size_t>(width/2))) continue;
        if (i > static_cast<size_t>(height/2)) continue;

        switch (corner) {

        case Corner::LR:
            x = translate(self_x, static_cast<long>(distance - i), width);
            y = translate(self_y, static_cast<long>(i), height);
            break;
        case Corner::UR:
            x = translate(self_x, static_cast<long>(distance - i), width);
            y = translate(self_y, static_cast<long>(-i), height);
            break;
        case Corner::LL:
            x = translate(self_x, static_cast<long>(i - distance), width);
            y = translate(self_y, static_cast<long>(i), height);
            break;
        case Corner::UL:
            x = translate(self_x, static_cast<long>(i - distance), width);
            y = translate(self_y, static_cast<long>(-i), height);
            break;
        }

        if (matrix.at(y).at(x) == 2) {
            return true;
        }
    }

    return false;
}

