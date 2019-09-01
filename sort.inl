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
    m_a { nullptr },
    m_N { N },
    m_kind { kind }
{
    m_a = a;
}

template<typename T>
Sort<T>::~Sort()
{
    delete[] m_a;
}

template<typename T>
void Sort<T>::sort()
{
    return sort(m_a, m_N, m_kind);
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
    case SortAlgorithm::Unspecified:
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
