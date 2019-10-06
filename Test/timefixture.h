#ifndef TIMEFIXTURE_H
#define TIMEFIXTURE_H

#include <chrono>
#include <boost/test/unit_test.hpp>

class TimeFixture
{
    using hires_clock = std::chrono::high_resolution_clock;

public:
    TimeFixture() :
        m_start { hires_clock::now() }
    {
        BOOST_TEST_MESSAGE( "Test run started." );
    }
    ~TimeFixture()
    {
        BOOST_TEST_MESSAGE( "Completed in " + std::to_string(duration().count()) + " nanoseconds." );
    }

    hires_clock::duration duration()
    {
        return hires_clock::now() - m_start;
    }
private:
    hires_clock::time_point m_start;
};

#endif // TIMEFIXTURE_H
