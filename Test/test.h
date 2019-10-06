#ifndef TEST_H
#define TEST_H

class Test
{
public:
    Test();
    explicit Test(int input);

    int add(int arg) const;
    int in() const;
    void setIn(int newIn);

private:
    int m_in;
};

#endif // TEST_H
