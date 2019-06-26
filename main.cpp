#include <iostream>

#include "solution.h"       // abstract base class for all challenge solutions
/* Challenge solutions */
#include "vowelsquare.h"
/* ******************* */

/* Specify which challege solution to test here by default */
static const Challenge todaysChallenge { Challenge::VowelSquare };
/* ******************************************** */

/* Additional Constants */
constexpr int inputMaxChar { 65536 };
/* ******************** */

/* Forward Declarations */
Solution* getSolverForChallenge(Challenge challenge, std::string input = nullptr);
Challenge getChallengeFromString(std::string challenge);
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

Solution* getSolverForChallenge(Challenge challenge, std::string input)
{
    switch (challenge)
    {
    case Challenge::VowelSquare:
        return new VowelSquare(input);
    default:
        return nullptr;
    }
}

Challenge getChallengeFromString(std::string challenge)
{
    std::locale loc;
    for (std::string::size_type i=0; i<challenge.length(); ++i) {
        challenge[i] = std::tolower(challenge[i],loc);
    }

    if (challenge == "vowelsquare") {
        return Challenge::VowelSquare;
    } else {
        return Challenge::Unspecified;
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
