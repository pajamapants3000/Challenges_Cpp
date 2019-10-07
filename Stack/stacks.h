/*
 * CtCI 3.1 - Three-In-One-Stack
 * Implement a class that uses a single array to simultaneously manage three separate stacks.
 *
 * NOTE: Implementation is encapsulated in StacksImpl structure.
 * Try implementing a few ways and compare test times.
 *
 * This is actually a really cool example of a successful pattern that produces a template from a
 * fully encapsulated underlying implementation.
 */

#ifndef STACKS_H
#define STACKS_H

#include <memory>

constexpr size_t storageSize {100};

enum class StackId {
    First,
    Second,
    Third,
    StackCount
};

class StacksVoid
{
public:
    StacksVoid();
    virtual ~StacksVoid();

    virtual void* allocate() = 0;

    void pushVoid(void* newVal, StackId id);
    void* popVoid(StackId id);
    void* peekVoid(StackId id) const;

protected:
    void** storage;

private:
    struct StacksImpl;
    std::unique_ptr<StacksImpl> pimpl;
};

template <class T>
class Stacks : private StacksVoid
{
public:
    Stacks()
    {
        storage = reinterpret_cast<void**> (new T*[storageSize * static_cast<size_t>(StackId::StackCount)]);
    }
    virtual ~Stacks(){}

    T* allocate(T newVal)
    {
        T* newAlloc {reinterpret_cast<T*>(allocate())};
        *newAlloc = newVal;
    }

    virtual void* allocate() override
    {
        return new T{};
    }

    virtual void push(T newVal, StackId id)
    {
        return pushVoid( allocate(newVal), id );
    }
    virtual T pop(StackId id)
    {
        return *reinterpret_cast<T*>( popVoid( id ) );
    }
    virtual T peek(StackId id) const
    {
        return *reinterpret_cast<T*>( peekVoid( id ) );
    }
};

#endif  // STACKS_H

