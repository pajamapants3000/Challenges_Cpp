#include <boost/test/unit_test.hpp>

namespace utf = boost::unit_test;

#include "standardstack.h"

#include "../Test/timefixture.h"

template <typename T>
static StandardStack<T>* stack {nullptr};

struct stackFixture
{
    stackFixture(StandardStack<int>* &stack_in)
    {
        stack_in = new StandardStack<int>{};
    }
    ~stackFixture()
    {
        delete stack<int>;
    }
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdisabled-macro-expansion"

BOOST_FIXTURE_TEST_SUITE( standard_stack_int_outer, TimeFixture )
BOOST_AUTO_TEST_SUITE( standard_stack_int, * utf::fixture<stackFixture>(stack<int>) )

BOOST_AUTO_TEST_CASE( initialize )
{
    stack<int> = new StandardStack<int>{};
    BOOST_CHECK_THROW(stack<int>->pop(), const char*);
    BOOST_CHECK_THROW(stack<int>->peek(), const char*);
}

BOOST_AUTO_TEST_CASE( push_and_peek, * utf::depends_on( "standard_stack_int_outer/standard_stack_int/initialize" ) )
{
    stack<int>->push(1);
    BOOST_TEST(stack<int>->peek() == 1);
}

BOOST_AUTO_TEST_CASE( pop, * utf::depends_on( "standard_stack_int_outer/standard_stack_int/push_and_peek" ) )
{
    BOOST_TEST(stack<int>->pop() == 1);
}

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()

#pragma GCC diagnostic pop
