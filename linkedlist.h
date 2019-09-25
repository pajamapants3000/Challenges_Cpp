#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <vector>

template <typename T>
struct SllNode
{
    T val;
    SllNode* next;

    SllNode();
    explicit SllNode(T _val, SllNode* _next = nullptr);

    static SllNode* advance(SllNode* x);
    static SllNode* advance(SllNode* x, const std::size_t k);
    static SllNode* fromArray(const T* const a, const std::size_t N);
    static SllNode* fromArray(const std::vector<T> a);
    static T* toArray(const SllNode* const head, std::size_t& outSize);
    static std::vector<T> toArray(const SllNode* const head);
    static SllNode* deleteNode(SllNode* node, SllNode* prev);
    static void clearMem(SllNode* head);
    void clearMem();
};

template <typename T>
struct DllNode
{
    T val;
    DllNode* prev;
    DllNode* next;

    DllNode();
    explicit DllNode(T _val);
    explicit DllNode(T _val, DllNode* _prev, DllNode* _next);

    static DllNode* advance(DllNode* x);
    static DllNode* advance(DllNode* x, const std::size_t k);
    static DllNode* backtrack(DllNode* x);
    static DllNode* backtrack(DllNode* x, const std::size_t k);
    static DllNode* fromArray(const T* const a, const std::size_t N);
    static DllNode* fromArray(const std::vector<T> a);
    static T* toArray(const DllNode* const head, std::size_t& outSize);
    static std::vector<T> toArray(const DllNode* const head);
    static DllNode* deleteNode(DllNode* node);
    static void clearMem(DllNode* head);
    void clearMem();
};

#include "linkedlist.cpp"

#endif // LINKEDLIST_H
