/*
 * CtCI 3.3 - Stack of Plates
 * Implement stack as a set of stacks of maximum height
 * Additional functionality: popAt(int index) pops off a specific stack
 */

#ifndef MULTISTACK_H
#define MULTISTACK_H

#include "stack.h"

template <class T>
class MultiStack : Stack<T>
{
public:
    explicit MultiStack(size_t limit);
    virtual ~MultiStack() override;

    virtual void push(T newVal) override;
    virtual T pop() override;
    virtual T peek() const override;

private:
    size_t m_limit;
    std::vector<std::vector<T>> m_stack;
};

#endif // MULTISTACK_H
