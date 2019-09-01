#ifndef SORT_H
#define SORT_H

#include <vector>

enum class SortAlgorithm {
    Unspecified,
    Shell,
    Heap,
    MAX_SORTALGORITHM,
};

enum class GapSequenceKind {
    Unspecified,
    PrattKnuth,
    Tokuda,
    Ciura,
    MAX_GAPSEQUENCE,
};

template<class T>
class Sort
{
public:

    Sort();
    explicit Sort(T* a, const size_t N, const SortAlgorithm = SortAlgorithm::Unspecified);
    virtual ~Sort();

    void sort();
    T* getSorted() const;

    T* array() const;
    size_t size() const;
    SortAlgorithm kind() const;
    void setArray(T* a, size_t N);
    void setKind(SortAlgorithm kind);

    static void sort(T* a, const size_t N, const SortAlgorithm algorithm = SortAlgorithm::Unspecified);
    static void shellsort(T* a, const size_t N);
    static void heapsort(T* a, const size_t N);

private:
    T* m_a;
    size_t m_N;
    SortAlgorithm m_kind;

    static bool less(const T a, const T b);
    static void swap(T* a, const size_t i, const size_t j);

    static const std::vector<size_t> gapSequence(const size_t N, const GapSequenceKind kind = GapSequenceKind::Unspecified);
    static const std::vector<size_t> gapSequence_PrattKnuth(const size_t N);
    static const std::vector<size_t> gapSequence_Tokuda(const size_t N);
    static const std::vector<size_t> gapSequence_Ciura(const size_t N);

    static void reverse_order (std::vector<size_t> &v);
    static void copy(T* a, T* b, size_t N);
    static void heaporder(T* a, size_t N);
    static void sortheap(T* heap, size_t N);
    static void sink(T* heap, size_t k, size_t N);

    /* Make sure T supports less-than operation */
    struct LessThanIsDefinedForType {
        static void constraints(T a, T b) { a<b; }
        LessThanIsDefinedForType() { void(*p)(T, T) = constraints; }
    };
    // don't use static because this is a template class! not "real code" and doesn't initialize the same way
    const LessThanIsDefinedForType typeConstraint_lessThan;
    /* *** */
};

#include "sort.inl"

#endif // SORT_H
