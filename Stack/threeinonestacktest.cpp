// Since the intent is to try a few implementations, the tests should involve a lot of repetition to get useful execution times.

#include <boost/test/unit_test.hpp>

#include "stacks.h"

namespace utf = boost::unit_test;

template <typename T>
struct fullStacksFixture
{
    fullStacksFixture()
    {
        stack = new Stacks<T>{};
        for (size_t i {0}; i < storageSize; ++i)
            for (int j {0}; j < static_cast<int>(StackId::StackCount); ++j)
                stack->push(i*static_cast<size_t>(StackId::StackCount)+static_cast<size_t>(j),
                    static_cast<StackId>(j));
    }
    ~fullStacksFixture()
    {
        delete stack;
    }

    Stacks<T>* stack {nullptr};
};

template <typename T>
struct emptyStacksFixture
{
    emptyStacksFixture()
    {
        stack = new Stacks<T>{};
    }
    ~emptyStacksFixture()
    {
        delete stack;
    }

    Stacks<T>* stack {nullptr};
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdisabled-macro-expansion"

BOOST_AUTO_TEST_SUITE( three_in_one_stack_size_t )

BOOST_FIXTURE_TEST_CASE( pop_and_peek_empty_1, emptyStacksFixture<size_t> )
{
    BOOST_CHECK_THROW(stack->pop(StackId::First), const char*);
    BOOST_CHECK_THROW(stack->peek(StackId::First), const char*);
}

BOOST_FIXTURE_TEST_CASE( push_full_1, fullStacksFixture<size_t> )
{
    BOOST_CHECK_THROW(stack->push(1, StackId::First), const char*);
}

BOOST_FIXTURE_TEST_CASE( push_and_peek_1, emptyStacksFixture<size_t> )
{
    stack->push(1, StackId::First);
    size_t result {stack->peek(StackId::First)};
    BOOST_TEST(result == 1);
}

BOOST_FIXTURE_TEST_CASE( pop_and_peek_1, fullStacksFixture<size_t> )
{
    size_t popped {stack->pop(StackId::First)};
    size_t peeked {stack->peek(StackId::First)};
    BOOST_TEST(stack->peek(StackId::First) < popped);
}

BOOST_FIXTURE_TEST_CASE( pop_full_1, fullStacksFixture<size_t> )
{
    BOOST_TEST(stack->pop(StackId::First) < storageSize * static_cast<size_t>(StackId::StackCount));
}

BOOST_FIXTURE_TEST_CASE( pop_and_peek_empty_2, emptyStacksFixture<size_t> )
{
    BOOST_CHECK_THROW(stack->pop(StackId::Second), const char*);
    BOOST_CHECK_THROW(stack->peek(StackId::Second), const char*);
}

BOOST_FIXTURE_TEST_CASE( push_full_2, fullStacksFixture<size_t> )
{
    BOOST_CHECK_THROW(stack->push(1, StackId::Second), const char*);
}

BOOST_FIXTURE_TEST_CASE( push_and_peek_2, emptyStacksFixture<size_t> )
{
    stack->push(1, StackId::Second);
    size_t result {stack->peek(StackId::Second)};
    BOOST_TEST(result == 1);
}

BOOST_FIXTURE_TEST_CASE( pop_and_peek_2, fullStacksFixture<size_t> )
{
    size_t popped {stack->pop(StackId::Second)};
    BOOST_TEST(stack->peek(StackId::Second) < popped);
}

BOOST_FIXTURE_TEST_CASE( pop_full_2, fullStacksFixture<size_t> )
{
    BOOST_TEST(stack->pop(StackId::Second) < storageSize * static_cast<size_t>(StackId::StackCount));
}

BOOST_FIXTURE_TEST_CASE( pop_and_peek_empty_3, emptyStacksFixture<size_t> )
{
    BOOST_CHECK_THROW(stack->pop(StackId::Third), const char*);
    BOOST_CHECK_THROW(stack->peek(StackId::Third), const char*);
}

BOOST_FIXTURE_TEST_CASE( push_full_3, fullStacksFixture<size_t> )
{
    BOOST_CHECK_THROW(stack->push(1, StackId::Third), const char*);
}

BOOST_FIXTURE_TEST_CASE( push_and_peek_3, emptyStacksFixture<size_t> )
{
    stack->push(1, StackId::Third);
    size_t result {stack->peek(StackId::Third)};
    BOOST_TEST(result == 1);
}

BOOST_FIXTURE_TEST_CASE( pop_and_peek_3, fullStacksFixture<size_t> )
{
    size_t popped {stack->pop(StackId::Third)};
    BOOST_TEST(stack->peek(StackId::Third) < popped);
}

BOOST_FIXTURE_TEST_CASE( pop_full_3, fullStacksFixture<size_t> )
{
    BOOST_TEST(stack->pop(StackId::Third) < storageSize * static_cast<size_t>(StackId::StackCount));
}

BOOST_FIXTURE_TEST_CASE( fill_er_up, emptyStacksFixture<size_t> )
{
    for (size_t i {0}; i < storageSize; ++i)
        for (int j {0}; j < static_cast<int>(StackId::StackCount); ++j)
            stack->push(i*static_cast<size_t>(StackId::StackCount)+static_cast<size_t>(j),
                static_cast<StackId>(j));

    BOOST_CHECK_THROW(stack->push(1, StackId::First), const char*);
    BOOST_CHECK_THROW(stack->push(1, StackId::Second), const char*);
    BOOST_CHECK_THROW(stack->push(1, StackId::Third), const char*);
}

BOOST_FIXTURE_TEST_CASE( empty_er_out, fullStacksFixture<size_t> )
{
    for (size_t i {0}; i < storageSize; ++i)
        for (int j {0}; j < static_cast<int>(StackId::StackCount); ++j)
            stack->pop(static_cast<StackId>(j));

    BOOST_CHECK_THROW(stack->pop(StackId::First), const char*);
    BOOST_CHECK_THROW(stack->pop(StackId::Second), const char*);
    BOOST_CHECK_THROW(stack->pop(StackId::Third), const char*);
}

BOOST_AUTO_TEST_SUITE_END()

#pragma GCC diagnostic pop
