#include <boost/test/unit_test.hpp>

#include "../Test/timefixture.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdisabled-macro-expansion"

BOOST_FIXTURE_TEST_SUITE( multistack_test_suite, TimeFixture )

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
