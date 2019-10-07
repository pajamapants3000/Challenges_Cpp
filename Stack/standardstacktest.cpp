#include <boost/test/unit_test.hpp>

#include "standardstack.h"

namespace utf = boost::unit_test;

template <typename T>
struct nonEmptyStandardStackFixture
{
    nonEmptyStandardStackFixture()
    {
        stack = new StandardStack<T>{};
        for (int i {0}; i < 100; ++i) {
            stack->push(i);
        }
    }
    ~nonEmptyStandardStackFixture()
    {
        delete stack;
    }

    StandardStack<T>* stack {nullptr};
};

template <typename T>
struct emptyStandardStackFixture
{
    emptyStandardStackFixture()
    {
        stack = new StandardStack<T>{};
    }
    ~emptyStandardStackFixture()
    {
        delete stack;
    }

    StandardStack<T>* stack {nullptr};
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdisabled-macro-expansion"

BOOST_AUTO_TEST_SUITE( standard_stack_int )

BOOST_FIXTURE_TEST_CASE( pop_or_peek_empty, emptyStandardStackFixture<int> )
{
    BOOST_CHECK_THROW(stack->pop(), const char*);
    BOOST_CHECK_THROW(stack->peek(), const char*);
}

BOOST_FIXTURE_TEST_CASE( push_and_peek, emptyStandardStackFixture<int> )
{
    stack->push(1);
    BOOST_TEST(stack->peek() == 1);
}

BOOST_FIXTURE_TEST_CASE( pop, nonEmptyStandardStackFixture<int> )
{
    BOOST_TEST(stack->pop() == 99);
}

BOOST_AUTO_TEST_SUITE_END()

#pragma GCC diagnostic pop
