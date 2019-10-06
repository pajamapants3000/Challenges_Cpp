#ifndef STANDARDSTACK_H
#define STANDARDSTACK_H

#include <vector>

#include "stack.h"

template <class T>
class StandardStack : Stack<T>
{
public:
    StandardStack();
    virtual ~StandardStack() override;

    virtual void push(T newVal) override;
    virtual T pop() override;
    virtual T peek() const override;

private:
    std::vector<T> m_storage;
};

template <class T>
StandardStack<T>::StandardStack() : m_storage {}
{}
template <class T>
StandardStack<T>::~StandardStack(){}

template <class T>
void StandardStack<T>::push(T newVal){m_storage.push_back(newVal);}
template <class T>
T StandardStack<T>::pop()
{
    if (m_storage.empty()) throw "Stack is empty.";
    T result {m_storage.back()};
    m_storage.pop_back();
    return result;
}

template <class T>
T StandardStack<T>::peek() const
{
    if (m_storage.empty()) throw "Stack is empty.";
    return m_storage.back();
}

#endif // STANDARDSTACK_H
