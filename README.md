# Challenges_Cpp
Collection of coding challenge solutions, along with framework for testing them.

Currently includes a way to execute challenge solutions from the command line, as well as a way to run
built-in test cases. At some point I will probably add timing to the solution test process.

To run from the command line, just execute `Challenges_Cpp <algorithm>`.
To perform built-in tests, execute `Challenges_Cpp_TEST <algorithm>`.
<algorithm> is the name of the challenge as one word (e.g. "oneaway", "StringSort") - case insensitive. 

e.g.
$ Challenges_Cpp isunique
> Enter input:
> aaa
> Result: false
$ Challenges_Cpp_TEST VowelSquare
> PASS: aaaa, aaaa, aaaa -> 0-0
> PASS: aqrst, ukaei, ffooo -> 1-2
> PASS: gg, ff -> not found
> Summary: 3 test cases; 0 tests failed.

To add a new solution to a challenge, add a class that derives from Solution in the Solutions subdirectory. Add
to CMakeLists.txt in both the project directory and the Solutions subdirectory. Use the existing solutions as
examples - it's pretty straightforward. Add the solution to the Challenges enumeration in Solutions/solution.h and
add the cases to solver.cpp in `getChallengeFromString` and both overloads of `getSolverForChallenge`, making sure the
correct constructor is used (default in one case, input argument in the other). It's not as clean as it could be,
but I haven't gotten around to simplifying it yet. At some point I hope the solutions will be easier to add.

I also intend, hopefully sometime soon, to add a "list" feature that lists all available algorithms, and a "testall"
feature that runs all tests for all algorithms.
