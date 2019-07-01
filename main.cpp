#include <iostream>

#include "solution.h"       // abstract base class for all challenge solutions
/* Challenge solutions */
#include "vowelsquare.h"
#include "palindromenumber.h"
#include "addtwonumbers.h"
#include "closestenemy.h"
#include "laststoneweight.h"
/* ******************* */

/* Specify which challege solution to test here by default */
static const Challenge todaysChallenge { Challenge::LastStoneWeight };
/* ******************************************** */

/* Additional Constants */
constexpr int inputMaxChar { 65536 };
/* ******************** */

/* Forward Declarations */
Challenge getChallengeFromString(std::string challenge);
Solution* getSolverForChallenge(Challenge challenge, std::string input = nullptr);
std::string getSolution(std::string input, Challenge challenge = todaysChallenge);
/* ******************** */

int main(int argc, char *argv[])
{
    char B[inputMaxChar];
    std::string input { fgets(B, inputMaxChar, stdin) };

    if (argc > 1) {
        std::cout << getSolution(input, getChallengeFromString(argv[1])) << "\n";
    } else {
        std::cout << getSolution(input) << "\n";
    }

    return 0;
}

Challenge getChallengeFromString(std::string challenge)
{
    std::locale loc;
    for (std::string::size_type i=0; i<challenge.length(); ++i) {
        challenge[i] = std::tolower(challenge[i],loc);
    }

    if (challenge == "vowelsquare") {
        return Challenge::VowelSquare;
    } else if (challenge == "palindromenumber") {
        return Challenge::PalindromeNumber;
    } else if (challenge == "addtwonumbers") {
        return Challenge::AddTwoNumbers;
    } else if (challenge == "closestenemy") {
        return Challenge::ClosestEnemy;
    } else if (challenge == "laststoneweight") {
        return Challenge::LastStoneWeight;
    } else {
        return Challenge::Unspecified;
    }
}

Solution* getSolverForChallenge(Challenge challenge, std::string input)
{
    switch (challenge)
    {
    case Challenge::VowelSquare:
        return new VowelSquare(input);
    case Challenge::PalindromeNumber:
        return new PalindromeNumber(input);
    case Challenge::AddTwoNumbers:
        return new AddTwoNumbers(input);
    case Challenge::ClosestEnemy:
        return new ClosestEnemy(input);
    case Challenge::LastStoneWeight:
        return new LastStoneWeight(input);
    default:
        return nullptr;
    }
}

std::string getSolution(std::string input, Challenge challenge)
{
    if (challenge == Challenge::Unspecified) {
        challenge = todaysChallenge;
    }

    Solution *solution { getSolverForChallenge(challenge, input) };
    return solution->getSolution();

}
