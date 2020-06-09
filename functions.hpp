#pragma once
#include <vector>




extern int Comparaison;
extern int Change;
class numbers{
    public:
    int num;
    public:numbers(int num = 0): num(num) {
    }
    friend bool operator== (numbers a, numbers b);
    friend bool operator!= (numbers a, numbers b);
    friend bool operator< (numbers a, numbers b);
    friend bool operator> (numbers a, numbers b);
    friend bool operator<= (numbers a, numbers b);
    friend bool operator>= (numbers a, numbers b);
    numbers operator=(const numbers &b) {
        num = b.num;
        return *this;
    }
};

inline bool operator== (numbers a, numbers b) {
    ++Comparaison;
    return (a.num == b.num);
}

inline bool operator!= (numbers a, numbers b) {
    ++Comparaison;
    return (a.num != b.num);
}

inline bool operator< (numbers a, numbers b) {
    ++Comparaison;
    return (a.num < b.num);
}

inline bool operator> (numbers a, numbers b) {
    ++Comparaison;
    return (a.num > b.num);
}

inline bool operator<= (numbers a, numbers b) {
    ++Comparaison;
    return (a.num <= b.num);
}

inline bool operator>= (numbers a, numbers b) {
    ++Comparaison;
    return (a.num >= b.num);
}

template <class T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
    ++Change;
}

void Fill(std::vector<numbers> & data, int size);

extern void Print1();
extern void Print2();
extern void ChoosingSort(std::vector<numbers> & data, int DATA_SIZE);

void GraphSh(std::vector<numbers> & data, int Size);
void GraphS(std::vector<numbers> & data, int Size);
void GraphB(std::vector<numbers> & data, int Size);
void GraphSI(std::vector<numbers> & data, int Size);
void GraphGn(std::vector<numbers> & data, int Size);
void GraphQ(std::vector<numbers> & data, int Size);
void GraphCo(std::vector<numbers> & data, int Size);
void GraphM(std::vector<numbers> & data, int Size);
void GraphPyr(std::vector<numbers> & data, int Size);

void SortSh(std::vector<numbers> & data, int size);
void StatSh(std::vector<numbers> & data, int Size);

void SortS(std::vector<numbers> & data, int size);
extern int FindMinS(std::vector<numbers> & data, const int size, int i);

void SortB(std::vector<numbers> & data, int size); // Bubble

void SortSI(std::vector<numbers> & data, int size);
extern int FindPosSI(std::vector<numbers> & data, int size, int i); // Simple Insertion
void RorSI(std::vector<numbers> & data, int start, int end);

void SortGn(std::vector<numbers> & data, int size); // Gnom

void SortQ(std::vector<numbers> & data, int r, int l); // Quick Sort

void SortCo(std::vector<numbers> & data, int size); // Comb Sort

void SortM(std::vector<numbers> & data, int size); // Merge Sort

void SortPyr(std::vector<numbers> & data, int size); // Pyramid Sort

