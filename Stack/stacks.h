/*
 * CtCI 3.1 - Three-In-One-Stack
 * Implement a class that uses a single array to simultaneously manage three separate stacks.
 *
 * NOTE: Implementation is encapsulated in StacksImpl structure.
 * Try implementing a few ways and compare test times.
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
    ~StacksVoid();

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
        storage = reinterpret_cast<void**> (new T*[storageSize]);
    }
    virtual ~Stacks(){}

    virtual void push(T newVal, StackId id)
    {
        pushVoid( reinterpret_cast<void*>( &newVal ), id );
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

