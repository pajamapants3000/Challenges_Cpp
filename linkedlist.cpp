#include "linkedlist.h"

template <typename T>
SllNode<T>::SllNode() :
    val {},
    next {nullptr}
{}

template <typename T>
SllNode<T>::SllNode(T _val, SllNode* _next) :
    val { _val },
    next {_next}
{}

template <typename T>
SllNode<T>* SllNode<T>::advance(SllNode<T>* x)
{
    return advance(x, 1);
}
template <typename T>
SllNode<T>* SllNode<T>::advance(SllNode<T>* x, const size_t k)
{
    if (k<=0) return x;

    size_t i {0};
    while (i<k && x) {
        x = x->next;
        ++i;
    }
    return x;
}
template <typename T>
SllNode<T>* SllNode<T>::fromArray(const T* const a, const std::size_t N)
{
    SllNode* result {new SllNode(a[0])};
    SllNode* pNode {result};
    for (std::size_t i {1}; i < N && pNode; ++i) {
        pNode->next = new SllNode(a[i]);
        pNode = pNode->next;
    }
    pNode->next = nullptr;
    return result;
}
template <typename T>
T* SllNode<T>::toArray(const SllNode<T>* const head, std::size_t& outSize)
{
    const SllNode* ptr {head};
    std::size_t size {0};
    while (ptr) {++size; ptr = ptr->next;}

    ptr = head;
    T* result = new T[size];
    for (std::size_t i {0}; i < size && ptr; ++i) {
        result[i] = ptr->val;
        ptr = ptr->next;
    }
    outSize = size;
    return result;
}
template <typename T>
void SllNode<T>::clearMem()
{
    SllNode* pCur {this};
    while (pCur) {
        SllNode* pNext = pCur->next;
        delete pCur;
        pCur = pNext;
    }
}

template <typename T>
DllNode<T>::DllNode() :
    val {},
    prev {nullptr},
    next {nullptr}
{}

template <typename T>
DllNode<T>::DllNode(T _val) :
    val { _val },
    prev {nullptr},
    next {nullptr}
{}

template <typename T>
DllNode<T>::DllNode(T _val, DllNode* _prev, DllNode* _next) :
    val { _val },
    prev {_prev},
    next {_next}
{}

template <typename T>
DllNode<T>* DllNode<T>::advance(DllNode* x)
{
    return advance(x, 1);
}
template <typename T>
DllNode<T>* DllNode<T>::advance(DllNode* x, const std::size_t k)
{
    size_t i {0};
    if (k>=0) {
        while (i<k && x) {
            x = x->next;
            ++i;
        }
    } else {
        while (i<(0-k) && x) {
            x = x->prev;
            ++i;
        }
    }

    return x;
}
template <typename T>
DllNode<T>* DllNode<T>::fromArray(const T* const a, const std::size_t N)
{
    DllNode* result {new DllNode(a[0])};
    DllNode* pDllNode {result};
    for (std::size_t i {1}; i < N && pDllNode; ++i) {
        pDllNode->next = new DllNode(a[i]);
        pDllNode = pDllNode->next;
    }
    pDllNode->next = nullptr;
    return result;
}
template <typename T>
T* DllNode<T>::toArray(const DllNode* const head, std::size_t& outSize)
{
    const DllNode* ptr {head};
    std::size_t size {0};
    while (ptr) {++size; ptr = ptr->next;}

    ptr = head;
    T* result = new T[size];
    for (std::size_t i {0}; i < size && ptr; ++i) {
        result[i] = ptr->val;
        ptr = ptr->next;
    }
    outSize = size;
    return result;
}
template <typename T>
void DllNode<T>::clearMem()
{
    DllNode* pCur {this};
    while (!!pCur) {
        DllNode* pNext = pCur->next;
        delete pCur;
        pCur = pNext;
    }
}
