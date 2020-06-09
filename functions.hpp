#pragma once

extern void swap(T& a, T& b);

extern void Fill(std::vector<numbers> & data, int size);

extern void Print1();
extern void Print2();
extern void ChoosingSort(std::vector<numbers> & data, int DATA_SIZE);

extern void GraphSh(std::vector<numbers> & data, int Size);
extern void GraphS(std::vector<numbers> & data, int Size);
extern void GraphB(std::vector<numbers> & data, int Size);
extern void GraphSI(std::vector<numbers> & data, int Size);
extern void GraphGn(std::vector<numbers> & data, int Size);
extern void GraphQ(std::vector<numbers> & data, int Size);
extern void GraphCo(std::vector<numbers> & data, int Size);
extern void GraphM(std::vector<numbers> & data, int Size);
extern void GraphPyr(std::vector<numbers> & data, int Size);

extern void SortSh(std::vector<numbers> & data, int size);
extern void StatSh(std::vector<numbers> & data, int Size);

extern void SortS(std::vector<numbers> & data, int size);
extern int FindMinS(std::vector<numbers> & data, const int size, int i);

extern void SortB(std::vector<numbers> & data, int size); // Bubble

extern void SortSI(std::vector<numbers> & data, int size);
extern int FindPosSI(std::vector<numbers> & data, int size, int i); // Simple Insertion
extern void RorSI(std::vector<numbers> & data, int start, int end);

extern void SortGn(std::vector<numbers> & data, int size); // Gnom

extern void SortQ(std::vector<numbers> & data, int r, int l); // Quick Sort

extern void SortCo(std::vector<numbers> & data, int size); // Comb Sort

extern void SortM(std::vector<numbers> & data, int size); // Merge Sort

extern void SortPyr(std::vector<numbers> & data, int size); // Pyramid Sort

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

bool operator== (numbers a, numbers b) {
    ++Comparaison;
    return (a.num == b.num);
}

bool operator!= (numbers a, numbers b) {
    ++Comparaison;
    return (a.num != b.num);
}

bool operator< (numbers a, numbers b) {
    ++Comparaison;
    return (a.num < b.num);
}

bool operator> (numbers a, numbers b) {
    ++Comparaison;
    return (a.num > b.num);
}

bool operator<= (numbers a, numbers b) {
    ++Comparaison;
    return (a.num <= b.num);
}

bool operator>= (numbers a, numbers b) {
    ++Comparaison;
    return (a.num >= b.num);
}