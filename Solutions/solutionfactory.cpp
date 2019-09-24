#include "solutionfactory.h"

#include <memory>

#include "solution.h"
/* Challenge solutions */
#include "vowelsquare.h"
#include "palindromenumber.h"
#include "addtwonumbers.h"
#include "closestenemy.h"
#include "laststoneweight.h"
#include "stringsort.h"
#include "isunique.h"
#include "arepermutations.h"
#include "urlify.h"
#include "palindromepermutation.h"
#include "oneaway.h"
#include "compressstring.h"
#include "rotatematrix.h"
#include "zeromatrix.h"
#include "stringrotation.h"
#include "removedups.h"
/* ******************* */

SolutionFactory::SolutionFactory() {}

std::shared_ptr<Solution> SolutionFactory::getSolution(const std::string challenge)
{
    return getSolution(Solution::getChallengeFromString(challenge));
}

std::shared_ptr<Solution> SolutionFactory::getSolution(std::string input, const std::string challenge)
{
    return getSolution(input, Solution::getChallengeFromString(challenge));
}

std::shared_ptr<Solution> SolutionFactory::getSolution(const Challenge challenge)
{
    switch (challenge)
    {
    case Challenge::VowelSquare:
        return std::shared_ptr<Solution>(new VowelSquare());
    case Challenge::PalindromeNumber:
        return std::shared_ptr<Solution>(new PalindromeNumber());
    case Challenge::AddTwoNumbers:
        return std::shared_ptr<Solution>(new AddTwoNumbers());
    case Challenge::ClosestEnemy:
        return std::shared_ptr<Solution>(new ClosestEnemy());
    case Challenge::LastStoneWeight:
        return std::shared_ptr<Solution>(new LastStoneWeight());
    case Challenge::StringSort:
        return std::shared_ptr<Solution>(new StringSort());
    case Challenge::IsUnique:
        return std::shared_ptr<Solution>(new IsUnique());
    case Challenge::ArePermutations:
        return std::shared_ptr<Solution>(new ArePermutations());
    case Challenge::Urlify:
        return std::shared_ptr<Solution>(new Urlify());
    case Challenge::PalindromePermutation:
        return std::shared_ptr<Solution>(new PalindromePermutation());
    case Challenge::OneAway:
        return std::shared_ptr<Solution>(new OneAway());
    case Challenge::CompressString:
        return std::shared_ptr<Solution>(new CompressString());
    case Challenge::RotateMatrix:
        return std::shared_ptr<Solution>(new RotateMatrix());
    case Challenge::ZeroMatrix:
        return std::shared_ptr<Solution>(new ZeroMatrix());
    case Challenge::StringRotation:
        return std::shared_ptr<Solution>(new StringRotation());
    case Challenge::RemoveDups:
        return std::shared_ptr<Solution>(new RemoveDups());
    default:
        return nullptr;
    }
}

std::shared_ptr<Solution> SolutionFactory::getSolution(std::string input, const Challenge challenge)
{
    switch (challenge)
    {
    case Challenge::VowelSquare:
        return std::shared_ptr<Solution>(new VowelSquare(input));
    case Challenge::PalindromeNumber:
        return std::shared_ptr<Solution>(new PalindromeNumber(input));
    case Challenge::AddTwoNumbers:
        return std::shared_ptr<Solution>(new AddTwoNumbers(input));
    case Challenge::ClosestEnemy:
        return std::shared_ptr<Solution>(new ClosestEnemy(input));
    case Challenge::LastStoneWeight:
        return std::shared_ptr<Solution>(new LastStoneWeight(input));
    case Challenge::StringSort:
        return std::shared_ptr<Solution>(new StringSort(input));
    case Challenge::IsUnique:
        return std::shared_ptr<Solution>(new IsUnique(input));
    case Challenge::ArePermutations:
        return std::shared_ptr<Solution>(new ArePermutations(input));
    case Challenge::Urlify:
        return std::shared_ptr<Solution>(new Urlify(input));
    case Challenge::PalindromePermutation:
        return std::shared_ptr<Solution>(new PalindromePermutation(input));
    case Challenge::OneAway:
        return std::shared_ptr<Solution>(new OneAway(input));
    case Challenge::CompressString:
        return std::shared_ptr<Solution>(new CompressString(input));
    case Challenge::RotateMatrix:
        return std::shared_ptr<Solution>(new RotateMatrix(input));
    case Challenge::ZeroMatrix:
        return std::shared_ptr<Solution>(new ZeroMatrix(input));
    case Challenge::StringRotation:
        return std::shared_ptr<Solution>(new StringRotation(input));
    case Challenge::RemoveDups:
        return std::shared_ptr<Solution>(new RemoveDups(input));
    default:
        return nullptr;
    }
}
