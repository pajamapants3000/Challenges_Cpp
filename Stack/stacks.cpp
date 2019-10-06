#include "stacks.h"

StacksVoid::StacksVoid() :
    storage {nullptr},
    pimpl {}
{}

StacksVoid::~StacksVoid() { delete[] storage; }

struct StacksVoid::StacksImpl
{
    StacksImpl() :
        counters { new size_t[static_cast<int>( StackId::StackCount )] }
    {
        for ( int i {0}; i < static_cast<int>( StackId::StackCount ); ++i ) {
            counters[ i ] = 0;
        }
    }

    ~StacksImpl()
    {
        delete[] counters;
    }

    void push(void* newVal, StackId id, void** storage)
    {
        storage[ static_cast<int>( id ) ] = newVal;
    }

    void* pop(StackId id, void** storage)
    {
        return storage[ static_cast<int>( id ) ];
    }

    void* peek(StackId id, void** storage) const
    {
        return storage[ static_cast<int>( id ) ];
    }

private:
    size_t* counters;
};

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
    return pimpl->peek( id, this->storage );
}
