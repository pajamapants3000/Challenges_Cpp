#include "linkedlist.h"

#include <vector>

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
SllNode<T>* SllNode<T>::advance(const SllNode<T>* x)
{
    return advance(x, 1);
}
template <typename T>
SllNode<T>* SllNode<T>::advance(const SllNode<T>* x, const size_t k)
{
    size_t i {0};
    while (i<k && x) {
        x = x->next;
        ++i;
    }
    return const_cast<SllNode<T>*>(x);
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
SllNode<T>* SllNode<T>::fromArray(const std::vector<T> a)
{
    if (a.size() == 0) return nullptr;

    SllNode* result {new SllNode(a.at(0))};
    SllNode* pNode {result};
    for (std::size_t i {1}; i < a.size(); ++i) {
        pNode->next = new SllNode(a.at(i));
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
std::vector<T> SllNode<T>::toArray(const SllNode* const head)
{
    const SllNode* ptr {head};

    ptr = head;
    std::vector<T> result {};
    while (ptr) {
        result.push_back(ptr->val);
        ptr = ptr->next;
    }
    return result;
}
template <typename T>
size_t SllNode<T>::getLength(const SllNode* const head)
{
    const SllNode* ptr {head};
    size_t result {0};
    while (ptr) {
        ++result;
        ptr = SllNode::advance(ptr);
    }
    return result;
}
template <typename T>
void SllNode<T>::partition(SllNode* lead, T part)
{
    SllNode* dummyLo { new SllNode() };
    SllNode* dummyHi { new SllNode() };
    SllNode* tailLo { dummyLo };
    SllNode* tailHi { dummyHi };
    SllNode* pNode { lead->next };

    while (pNode) {
        if (pNode->val < part) {
            tailLo->next = pNode;
            tailLo = pNode;
            pNode = pNode->next;
        } else {
            tailHi->next = pNode;
            tailHi = pNode;
            pNode = pNode->next;
        }
    }

    lead->next = dummyLo->next;
    tailLo->next = dummyHi->next;
    tailHi->next = nullptr;
    delete dummyLo;
    delete dummyHi;
}
template <typename T>
SllNode<T>* SllNode<T>::deleteNode(SllNode* node, SllNode* prev)
{
    if (!node) return nullptr;
    if (prev) prev->next = node->next;
    delete node;
    return (prev ? prev->next : nullptr);
}
template <typename T>
void SllNode<T>::clearMem(SllNode* head)
{
    SllNode* pCur {head};
    while (pCur) {
        SllNode* pNext = pCur->next;
        delete pCur;
        pCur = pNext;
    }
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
DllNode<T>* DllNode<T>::advance(const DllNode* x)
{
    return advance(x, 1);
}
template <typename T>
DllNode<T>* DllNode<T>::advance(const DllNode* x, const std::size_t k)
{
    size_t i {0};
    while (i<k && x) {
        x = x->next;
        ++i;
    }

    return const_cast<DllNode<T>*>(x);
}
template <typename T>
DllNode<T>* DllNode<T>::backtrack(const DllNode* x)
{
    return backtrack(x, 1);
}
template <typename T>
DllNode<T>* DllNode<T>::backtrack(const DllNode* x, const std::size_t k)
{
    size_t i {0};
    while (i<k && x) {
        x = x->prev;
        ++i;
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
DllNode<T>* DllNode<T>::fromArray(const std::vector<T> a)
{
    if (a.size() == 0) return nullptr;

    DllNode* result {new DllNode(a.at(0), nullptr, nullptr)};
    DllNode* pNode {result};
    DllNode* pPrev {result->prev};
    for (std::size_t i {1}; i < a.size(); ++i) {
        pNode->next = new DllNode(a.at(i));
        pPrev = pNode;
        pNode = pNode->next;
        pNode->prev = pPrev;
    }
    pNode->next = nullptr;
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
std::vector<T> DllNode<T>::toArray(const DllNode* const head)
{
    const DllNode* ptr {head};

    ptr = head;
    std::vector<T> result {};
    while (ptr) {
        result.push_back(ptr->val);
        ptr = ptr->next;
    }
    return result;
}
template <typename T>
size_t DllNode<T>::getLength(const DllNode* const head)
{
    const DllNode* ptr {head};
    size_t result {0};
    while (ptr) {
        ++result;
        ptr = DllNode::advance(ptr);
    }
    return result;
}
template <typename T>
void DllNode<T>::partition(DllNode* lead, T part)
{
    DllNode* dummyLo { new DllNode() };
    DllNode* dummyHi { new DllNode() };
    DllNode* tailLo { dummyLo };
    DllNode* tailHi { dummyHi };
    DllNode* pNode { lead->next };

    while (pNode) {
        if (pNode->val < part) {
            tailLo->next = pNode;
            tailLo = pNode;
            pNode = pNode->next;
        } else {
            tailHi->next = pNode;
            tailHi = pNode;
            pNode = pNode->next;
        }
    }

    lead->next = dummyLo->next;
    tailLo->next = dummyHi->next;
    tailHi->next = nullptr;
    delete dummyLo;
    delete dummyHi;
}
template <typename T>
DllNode<T>* DllNode<T>::deleteNode(DllNode* node)
{
    if (!node) return nullptr;

    DllNode* prev { node->prev };
    if (prev) prev->next = node->next;
    delete node;
    if (prev) node = prev->next;
    if (node) node->prev = prev;
    return node;
}
template <typename T>
void DllNode<T>::clearMem(DllNode* head)
{
    DllNode* pCur {head};
    while (pCur) {
        DllNode* pNext = pCur->next;
        delete pCur;
        pCur = pNext;
    }
}
template <typename T>
void DllNode<T>::clearMem()
{
    DllNode* pCur {this};
    while (pCur) {
        DllNode* pNext = pCur->next;
        delete pCur;
        pCur = pNext;
    }
}
