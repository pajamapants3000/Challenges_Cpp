#include "stacks.h"

struct StacksVoid::StacksImpl
{
    StacksImpl() :
        stackCount { static_cast<size_t>(StackId::StackCount) },
        counters { new size_t[stackCount] }
    {
        for ( size_t i {0}; i < stackCount; ++i ) {
            counters[ i ] = i;
        }
    }

    ~StacksImpl()
    {
        delete[] counters;
    }

    void push(void* newVal, StackId id, void** storage)
    {
        size_t stackId { static_cast<size_t>(id) };

        if (counters[stackId] >= storageSize*stackCount) {
            throw "Stack is full.";
        }
        storage[counters[stackId]] = newVal;

        // our first check ensures this will produce a result less than storageSize
        counters[stackId] += stackCount;
    }

    void* pop(StackId id, void** storage)
    {
        size_t stackId { static_cast<size_t>(id) };

        if (counters[stackId] / stackCount == 0) {
            throw "Stack is empty.";
        }

        // our first check ensures this will produce a positive result
        counters[stackId] -= stackCount;

        return storage[ counters[stackId] ];
    }

    void* peek(StackId id, void** storage) const
    {
        size_t stackId { static_cast<size_t>(id) };

        if (counters[stackId] / stackCount == 0) {
            throw "Stack is empty.";
        }

        return storage[ counters[stackId] - stackCount];
    }

private:
    size_t stackCount;
    size_t* counters;
};

StacksVoid::StacksVoid() :
    storage {nullptr},
    pimpl { new StacksImpl{} }
{}

StacksVoid::~StacksVoid() { delete[] storage; }

void StacksVoid::pushVoid(void* newVal, StackId id)
{
    return pimpl->push( newVal, id, this->storage );
}

void* StacksVoid::popVoid(StackId id)
{
    return pimpl->pop( id, this->storage );
}

void* StacksVoid::peekVoid(StackId id) const
{
    return pimpl->peek(id, this->storage);
}
