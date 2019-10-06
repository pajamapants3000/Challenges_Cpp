#include "test.h"

Test::Test() : m_in {0}
{ }

Test::Test(int input) : m_in {input}{}

int Test::add(int arg) const
{
    return m_in + arg;
}

int Test::in() const
{
    return m_in;
}

void Test::setIn(int newIn)
{
    m_in = newIn;
}
