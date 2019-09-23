#ifndef SORT_H
#define SORT_H

#include <vector>

enum class SortAlgorithm {
    Unspecified,
    Shell,
    Heap,
    Merge,
    BUMerge,
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
    struct Node {
        T val;
        Node* next;

        Node() : val {}, next {nullptr} {}
        Node(T _val) : val { _val }, next {nullptr} {}

        static Node* advance(Node* x)
        {
            return advance(x, 1);
        }
        static Node* advance(Node* x, const size_t k)
        {
            size_t i {0};
            while (i<k && x) {
                x = x->next;
                ++i;
            }
            return x;
        }
        static Node* fromArray(const T* const a, const std::size_t N)
        {
            Node* result {new Node(a[0])};
            Node* pNode {result};
            for (std::size_t i {1}; i < N && pNode; ++i) {
                pNode->next = new Node(a[i]);
                pNode = pNode->next;
            }
            pNode->next = nullptr;
            return result;
        }
        static T* toArray(const Node* const head, std::size_t& outSize)
        {
            const Node* ptr {head};
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
        void clearMem()
        {
            Node* pCur {this};
            while (!!pCur) {
                Node* pNext = pCur->next;
                delete pCur;
                pCur = pNext;
            }
        }
    };

    Sort();
    explicit Sort(T* a, const size_t N, const SortAlgorithm = SortAlgorithm::Unspecified);
    explicit Sort(Node* head, const SortAlgorithm = SortAlgorithm::Unspecified);
    virtual ~Sort();

    void sort();
    void sortLL();
    T* getSorted() const;
    Node* getLLSorted() const;

    T* array() const;
    size_t size() const;
    SortAlgorithm kind() const;
    void setArray(T* a, size_t N);
    void setKind(SortAlgorithm kind);

    static void sort(T* a, const size_t N, const SortAlgorithm algorithm = SortAlgorithm::Unspecified);
    static void sortLL(Node* in, const SortAlgorithm algorithm = SortAlgorithm::Unspecified);
    static void shellsort(T* a, const size_t N);
    static void heapsort(T* a, const size_t N);
    static void mergesort(T* a, const size_t N);
    static void mergesort(T* a, T* aux, const size_t lo, const size_t hi);
    static void bumergesort(T* a, const size_t N);
    static void bumergesort(Node* in);

    static bool equals(T* in, T* out, size_t N);
    static bool equals(Node* in, Node* out);

private:
    T* m_a;
    size_t m_N;
    Node* m_head;
    SortAlgorithm m_kind;

    static bool less(const T a, const T b);
    static void swap(T* a, const size_t i, const size_t j);

    static const std::vector<size_t> gapSequence(const size_t N, const GapSequenceKind kind = GapSequenceKind::Unspecified);
    static const std::vector<size_t> gapSequence_PrattKnuth(const size_t N);
    static const std::vector<size_t> gapSequence_Tokuda(const size_t N);
    static const std::vector<size_t> gapSequence_Ciura(const size_t N);

    static void reverse_order (std::vector<size_t> &v);
    static void copy(T* a, T* b, size_t N);
    static void copyLL(Node* a, Node* b);
    static void heaporder(T* a, size_t N);
    static void sortheap(T* heap, size_t N);
    static void sink(T* heap, size_t k, size_t N);
    static void merge(T* a, T* aux, size_t lo, size_t mid, size_t hi);
    static void merge(Node* in, Node* &mid, Node* &hi);
    static void mergeAdvance(Node* &in, Node* &mid, Node* &hi, size_t sz);
    static void mergeReset(Node* pHead, Node* &in, Node* &mid, Node* &hi, size_t sz);

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
