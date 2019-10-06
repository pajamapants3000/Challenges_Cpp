// Interface for stack implementations

#ifndef STACK_H
#define STACK_H

#include <vector>
#include <memory>

enum class StackKind {
    Unspecified,
    Standard,
    Multi,
    MAX_StackKind
};

template <class T>
class Stack
{
public:
    virtual ~Stack() {}

    virtual void push(T newVal) = 0;
    virtual T pop() = 0;
    virtual T peek() const = 0;
};

#endif // STACK_H
