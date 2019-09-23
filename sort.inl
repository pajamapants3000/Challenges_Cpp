#include "sort.h"

#include <vector>
#include <cmath>

template<typename T>
Sort<T>::Sort() :
    m_a { nullptr },
    m_N { 0 },
    m_kind { SortAlgorithm::Unspecified }
{ }

template<typename T>
Sort<T>::Sort(T* a, const size_t N, const SortAlgorithm kind) :
    m_a { a },
    m_N { N },
    m_head {nullptr},
    m_kind { kind }
{
}

template<typename T>
Sort<T>::Sort(Node* head, const SortAlgorithm kind) :
    m_a { nullptr },
    m_N { 0 },
    m_head {head},
    m_kind { kind }
{
}

template<typename T>
Sort<T>::~Sort()
{
    delete[] m_a;
    m_head->clearMem();
}

template<typename T>
void Sort<T>::sort()
{
    return sort(m_a, m_N, m_kind);
}

template<typename T>
void Sort<T>::sortLL()
{
    Node* pDummy { new Node() };
    pDummy->next = m_head;
    sortLL(pDummy, m_kind);
    m_head = pDummy->next;
    delete pDummy;
}

template<typename T>
T* Sort<T>::getSorted() const
{
    T* a = new T[m_N];
    copy(m_a, a, m_N);

    sort(a, m_N, m_kind);
    return a;
}

template<typename T>
typename Sort<T>::Node* Sort<T>::getLLSorted() const
{
    Node* b {new Node()};
    copyLL(m_head, b);

    Node* pDummy { new Node() };
    pDummy->next = b;
    sortLL(pDummy, m_kind);
    b = pDummy->next;
    delete pDummy;

    return b;
}

template<typename T>
T* Sort<T>::array() const
{
    return m_a;
}

template<typename T>
size_t Sort<T>::size() const
{
    return m_N;
}

template<typename T>
SortAlgorithm Sort<T>::kind() const
{
    return m_kind;
}

template<typename T>
void Sort<T>::setArray(T* a, size_t N)
{
    m_a = a;
    m_N = N;
}

template<typename T>
void Sort<T>::setKind(SortAlgorithm kind)
{
    m_kind = kind;
}

template<typename T>
void Sort<T>::sort(T* a, const size_t N, const SortAlgorithm algorithm)
{
    switch (algorithm) {
    case SortAlgorithm::Shell:
        return shellsort(a, N);
    case SortAlgorithm::Heap:
        return heapsort(a, N);
    case SortAlgorithm::Merge:
        return mergesort(a, N);
    case SortAlgorithm::BUMerge:
        return bumergesort(a, N);
    default:
        throw "Must specify sort algorithm.";
    }
}

template<typename T>
void Sort<T>::sortLL(Node* in, const SortAlgorithm algorithm)
{
    switch (algorithm) {
    case SortAlgorithm::Shell:
        throw "ShellSort not implemented for linked lists.";
    case SortAlgorithm::Heap:
        throw "HeapSort not implemented for linked lists.";
    case SortAlgorithm::Merge:
        throw "Top-down MergeSort not implemented for linked lists.";
    case SortAlgorithm::BUMerge:
        return bumergesort(in);
    default:
        throw "Must specify sort algorithm.";
    }
}

template<typename T>
void Sort<T>::shellsort(T* a, const size_t N)
{
    std::vector<size_t> h { gapSequence(N, GapSequenceKind::Tokuda) };

    for (size_t k {0}; k < h.size(); ++k) {
        for (size_t i {h[k]}; i < N; ++i) {
            for (size_t j {i}; j >= h[k] && less(a[j], a[j-h[k]]); j-=h[k]) {
                swap(a, j, j-h[k]);
            }
        }
    }
}

template<typename T>
void Sort<T>::heapsort(T* a, const size_t N)
{
    T* heap { new T[N+1] };
    copy(a, heap+1, N);
    heaporder(heap, N);
    sortheap(heap, N);
    copy(heap+1, a, N);
}

template<typename T>
void Sort<T>::mergesort(T* a, const size_t N)
{
    T* aux = new T[N];
    copy(a, aux, N);

    mergesort(a, aux, 0, N-1);

    delete[] aux;
}

template<typename T>
void Sort<T>::mergesort(T* a, T* aux, const size_t lo, const size_t hi)
{
    if (hi <= lo) return;
    size_t mid { lo + ((hi-lo)/2) };
    mergesort(a, aux, lo, mid);
    mergesort(a, aux, mid+1, hi);
    merge(a, aux, lo, mid, hi);
}

template<typename T>
void Sort<T>::bumergesort(T* a, const size_t N)
{
    T* aux = new T[N];
    copy(a, aux, N);

    for (size_t sz {1}; sz<N; sz+=sz) {
        for (size_t i {0}; i<(N-sz); i+=sz+sz) {
            merge(a, aux, i, i+sz-1, std::min(i+(sz+sz)-1, N-1));
        }
    }

    delete[] aux;
}

// in->next == lo
template<typename T>
void Sort<T>::bumergesort(Node* in)
{
    size_t sz {1};
    Node *pIn, *pMid, *pHi;

    mergeReset(in, pIn, pMid, pHi, sz);
    while (pMid && pMid->next) {
        while (pMid && pMid->next) {
            merge(pIn, pMid, pHi);
            mergeAdvance(pIn, pMid, pHi, sz);
        }
        sz+=sz;
        mergeReset(in, pIn, pMid, pHi, sz);
    }
}

template<typename T>
bool Sort<T>::less(const T a, const T b)
{
    return a < b;
}

template<typename T>
void Sort<T>::swap(T* a, const size_t i, const size_t j)
{
    T temp { a[i] };
    a[i] = a[j];
    a[j] = temp;
}

template <typename T>
bool Sort<T>::equals(T* in, T* out, size_t N)
{
    for (size_t i {0}; i < N; ++i) {
        if (in[i] != out[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
bool Sort<T>::equals(Node* in, Node* out)
{
    while (in) {
        if (!out || out->val != in->val) {
            return false;
        }
        in = in->next;
        out = out->next;
    }
    return true;
}

template<typename T>
const std::vector<size_t> Sort<T>::gapSequence(const size_t N, const GapSequenceKind kind)
{
    switch (kind) {
    case GapSequenceKind::PrattKnuth:
        return gapSequence_PrattKnuth(N);
    case GapSequenceKind::Tokuda:
        return gapSequence_Tokuda(N);
    case GapSequenceKind::Ciura:
        return gapSequence_Ciura(N);
    default:
        return std::vector<size_t> {1}; // default to insertionsort
    }
}

template<typename T>
const std::vector<size_t> Sort<T>::gapSequence_PrattKnuth(const size_t N)
{
    throw "Pratt-Knuth gap sequence not implemented";
}

template<typename T>
const std::vector<size_t> Sort<T>::gapSequence_Tokuda(const size_t N)
{
    std::vector<size_t> result;
    size_t h {1};

    for (size_t k {0}; (3*h)<N; ++k) {
        double _h {1.0};
        for (size_t i {0}; i<k; ++i) {
            _h = 2.25*_h + 1;
        }
        h = static_cast<size_t>(ceil(_h));
        result.push_back(h);
    }

    reverse_order(result);

    return result;
}
template<typename T>
const std::vector<size_t> Sort<T>::gapSequence_Ciura(const size_t N)
{
    std::vector<size_t> start { 1, 4, 10, 23, 57, 132, 301, 701 };
    std::vector<size_t> result { };
    size_t h {1};

    int i {0};
    while ((3*h)<N) {
        if (i < start.size()) {
            h = start.at(i++);
        }
        else {
            h = static_cast<size_t>(floor(2.25*h));
        }
        result.push_back(h);
    }

    reverse_order(result);

    return result;
}

template<typename T>
void Sort<T>::reverse_order(std::vector<size_t> &v)
{
    // Note: 2*i<v.size() means size=5: swap 0,4; 1,3; 2,2; size=4: swap 0,3; 1,2;
    // i<(v.size()/2) means size=5: swap 0,4; 1,3; size=4: swap 0,3; 1,2
    // the latter avoids an extra useless swap for odd N
    for (size_t i {0}; i < (v.size()/2); ++i) {
        size_t temp { v.at(i) };
        v.at(i) = v.at(v.size()-1-i);
        v.at(v.size()-1-i) = temp;
    }
}

template<typename T>
void Sort<T>::copy(T* a, T* b, size_t N)
{
    for (size_t i {0}; i < N; ++i) {
        b[i] = a[i];
    }
}

template<typename T>
void Sort<T>::copyLL(Node* a, Node* b)
{
    b->val = a->val;
    while ((a = Node::advance(a))) {    // test assignment result
        b->next = new Node();
        b = Node::advance(b);
        b->val = a->val;
    }
}

template<typename T>
void Sort<T>::heaporder(T* a, size_t N)
{
    for (size_t i {N/2}; i != 0; --i) {
        sink(a, i, N);
    }
}

template<typename T>
void Sort<T>::sortheap(T* heap, size_t N)
{
    size_t n {N};
    while (n>1) {
        swap(heap, 1, n--);
        sink(heap, 1, n);
    }
}

template<typename T>
void Sort<T>::sink(T* heap, size_t k, size_t N)
{
    size_t i {k};
    while (2*i <= N) {
        size_t j {2*i};
        if (j<N && less(heap[j], heap[j+1])) ++j;
        if (!less(heap[i], heap[j])) break;
        swap(heap, i, j);
        i = j;
    }
}

template<typename T>
void Sort<T>::merge(T* a, T* aux, size_t lo, size_t mid, size_t hi)
{
    copy(a, aux, hi+1);
    size_t i {lo};
    size_t j {mid+1};
    for (size_t k {0}; k <= hi; ++k) {
        if (i > mid) a[k] = aux[j++];
        else if (j > hi) a[k] = aux[i++];
        else if (less(a[j], a[i])) a[k] = aux[j++];
        else a[k] = aux[i++];
    }
}

template<typename T>
void Sort<T>::merge(Node* in, Node* &mid, Node* &hi)
{
    Node* const pDummy = new Node();
    Node* const pMid = mid->next;
    Node* const pOut = hi ? hi->next : hi;
    Node* pTail {pDummy};
    Node* a {in->next};
    Node* b {pMid};
    size_t n {0};
    while ((a != pMid) || (b != pOut)) {
        if (a == pMid) {
            pTail->next = b;
            pTail = pTail->next;
            b = b->next;
        } else if (b == pOut) {
            pTail->next = a;
            pTail = pTail->next;
            a = a->next;
        } else  if (less(b->val, a->val)) {
            pTail->next = b;
            pTail = pTail->next;
            b = b->next;
        } else {
            pTail->next = a;
            pTail = pTail->next;
            a = a->next;
        }
        ++n;
    }
    in->next = pDummy->next;
    // n/2 == sz, advance lo by sz-1 same as advance in by sz
    mid = Node::advance(in, (n/2));
    hi = pTail;
    hi->next = pOut;
    delete pDummy;
}

template<typename T>
void Sort<T>::mergeAdvance(Node* &in, Node* &mid, Node* &hi, size_t sz)
{
    in = Node::advance(in, sz+sz);
    mid = Node::advance(mid, sz+sz);
    hi = Node::advance(hi, sz+sz);
}

template<typename T>
void Sort<T>::mergeReset(Node* pHead, Node* &in, Node* &mid, Node* &hi, size_t sz)
{
    in = pHead;
    mid = Node::advance(in->next, sz-1);
    hi = Node::advance(mid ? mid->next : mid, sz-1);
}
