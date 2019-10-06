// Since the intent is to try a few implementations, the tests should involve a lot of repetition to get useful execution times.

#include <boost/test/unit_test.hpp>
#include <chrono>

namespace utf = boost::unit_test;

#include "stacks.h"

#include "../Test/timefixture.h"

template <typename T>
static Stacks<T>* stack {nullptr};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdisabled-macro-expansion"

BOOST_FIXTURE_TEST_SUITE( three_in_one_stack_int, TimeFixture )

BOOST_AUTO_TEST_CASE( initialize )
{
    stack<int> = new Stacks<int>{};
    BOOST_CHECK_THROW(stack<int>->pop(StackId::First), const char*);
    BOOST_CHECK_THROW(stack<int>->peek(StackId::First), const char*);
}

BOOST_AUTO_TEST_CASE( push_and_peek, * utf::depends_on( "three_in_one_stack_int/initialize" ) )
{
    stack<int>->push(1, StackId::First);
    BOOST_TEST(stack<int>->peek(StackId::First) == 1);
}

BOOST_AUTO_TEST_CASE( pop, * utf::depends_on( "three_in_one_stack_int/push_and_peek" ) )
{
    BOOST_TEST(stack<int>->pop(StackId::First) == 1);
}

BOOST_AUTO_TEST_CASE( kill, * utf::depends_on( "three_in_one_stack_int/pop" ) )
{
    delete stack<int>;
    BOOST_TEST(stack<int> == nullptr);
}

BOOST_AUTO_TEST_SUITE_END()

#pragma GCC diagnostic pop
