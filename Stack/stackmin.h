/*
 * CtCI 3.2 - StackMin
 * Additional functionality: Find and return the minimum stored value.
 */

#ifndef STACKMIN_H
#define STACKMIN_H

#include <vector>

#include "stack.h"

template <class T>
class StackMin : Stack<T>
{
public:
    StackMin();
    virtual ~StackMin();

    virtual void push(T newVal) override;
    virtual T pop() override;
    virtual T peek() const override;

    T min() const;
};

#endif // STACKMIN_H
