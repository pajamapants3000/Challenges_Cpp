#include "multistack.h"


template <class T>
MultiStack<T>::MultiStack(size_t limit) : m_limit {limit} {}
template <class T>
MultiStack<T>::~MultiStack(){}

template <class T>
void MultiStack<T>::push(T newVal){}
template <class T>
T MultiStack<T>::pop(){}
template <class T>
T MultiStack<T>::peek() const {}
