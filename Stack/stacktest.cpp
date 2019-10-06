#define BOOST_TEST_MODULE Stack
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "../Test/timefixture.h"

/*
 * Tests:
 * Setup - for each test, build a stack of many values
 * Test - push, pop, peek
 * Teardown - none needed I think, other than perhaps destruction of stack object
 * ...
 * Apply to every stack implementation
 * Additional tests per stack specialty, e.g. finding minimum value or
 */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdisabled-macro-expansion"
BOOST_FIXTURE_TEST_SUITE( stack_test_suite, TimeFixture )

BOOST_AUTO_TEST_CASE( autopass )
{
    BOOST_TEST( true );
}

BOOST_AUTO_TEST_CASE( autofail )
{
    BOOST_TEST( false );
}

BOOST_AUTO_TEST_SUITE_END()

#pragma GCC diagnostic pop
