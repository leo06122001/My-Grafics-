/*!
    \brief My Graphik
    \author LaB
    \version 1.0
    \date Май 2020 года
*/
#include "TXLib.h"

void Fill(int data[], int size);

void Print1();
void Print2();
void ChoosingSort(int data[], int DATA_SIZE);

void GraphSh(int data[], int Size);
void GraphS(int data[], int Size);
void GraphB(int data[], int Size);
void GraphSI(int data[], int Size);
void GraphGn(int data[], int Size);
void GraphQ(int data[], int Size);
void GraphCo(int data[], int Size);
void GraphM(int data[], int Size);
void GraphPyr(int data[], int Size);

void SwapSh(int data[], int a, int b); // Shaker
void SortSh(int data[], int size);
void StatSh(int data[], int Size);

void SwapS(int data[], int a, int b); // Selection
void SortS(int data[], int size);
int FindMinS(int data[], const int size, int i);

void SortB(int data[], int size); // Bubble
void SwapB(int data[], int min, int pos);

void SortSI(int data[], int size);
int FindPosSI(int data[], int size, int i); // Simple Insertion
void RorSI(int data[], int start, int end);

void SortGn(int data[], int size); // Gnom

void SortQ(int data[], int r, int l); // Quick Sort

void SortCo(int data[], int size); // Comb Sort

void SortM(int data[], int size); // Merge Sort

void SortPyr(int data[], int size); // Pyramid Sort

int ComparaisonSh = 0;
int ChangeSh = 0;

int ComparaisonS = 0;
int ChangeS = 0;

int ComparaisonB = 0;
int ChangeB = 0;

int ComparaisonSI = 0;
int ChangeSI = 0;

int ComparaisonGn = 0;
int ChangeGn = 0;

int ComparaisonQ = 0;
int ChangeQ = 0;

int ComparaisonCo = 0;
int ChangeCo = 0;

int ComparaisonM = 0;
int ChangeM = 0;

int ChangePyr = 0;
int ComparaisonPyr = 0;

int main() {
  txCreateWindow(450, 824);
  const int DATA_SIZE = 900;
  int data[DATA_SIZE] = {};
  Print1();
  Print2();
  ChoosingSort(data, DATA_SIZE);
}

///--------------------------------------------------------

/**
 * @brief      { Choosing of Sort }
 * вызывает функцию построения графика сортировки, соответствующую нажатой клавише или зачищает график если нажат 0
 *
 * @param      data       The data
 * @param[in]  DATA_SIZE  The data size
 */
void ChoosingSort(int data[], int DATA_SIZE) {
  while (1 > 0) {
    if (GetAsyncKeyState(VK_NUMPAD5)) {
      GraphGn(data, DATA_SIZE);
    }
    if (GetAsyncKeyState(VK_NUMPAD9)) {
      GraphPyr(data, DATA_SIZE);
    }
    if (GetAsyncKeyState(VK_NUMPAD8)) {
      GraphM(data, DATA_SIZE);
    }
    if (GetAsyncKeyState(VK_NUMPAD7)) {
      GraphCo(data, DATA_SIZE);
    }
    if (GetAsyncKeyState(VK_NUMPAD6)) {
      GraphQ(data, DATA_SIZE);
    }
    if (GetAsyncKeyState(VK_NUMPAD4)) {
      GraphSI(data, DATA_SIZE);
    }
    if (GetAsyncKeyState(VK_NUMPAD3)) {
      GraphSh(data, DATA_SIZE);
    }
    if (GetAsyncKeyState(VK_NUMPAD2)) {
      GraphB(data, DATA_SIZE);
    }
    if (GetAsyncKeyState(VK_NUMPAD1)) {
      GraphS(data, DATA_SIZE);
    }
    if (GetAsyncKeyState(VK_NUMPAD0)) {
      txSetFillColor(TX_BLACK);
      txClear();
      Print1();
      Print2();
    }
    if (GetAsyncKeyState(VK_ESCAPE)) {
      break;
    }
  }
}

///--------------------------------------------------------

/**
 * @brief      Prints a 1.
 * функция выводит на экран меню и подсказки
 */
void Print1() {
  txSetColor(TX_WHITE);
  txSetFillColor(TX_WHITE);
  txLine(20, 0, 20, 680);
  txLine(10, 670, 410, 670);
  txSelectFont("Lucida Console", 14, 9);
  txTextOut(80, 690, "Press on numpad:");
  txTextOut(100, 704, "1 - Selection Sort        - blue");
  txTextOut(100, 718, "2 - Bubble Sort           - pink");
  txTextOut(100, 732, "3 - Shaker Sort           - yellow");
  txTextOut(100, 746, "4 - Simple Insertion Sort - green");
  txTextOut(100, 760, "5 - Gnom Sort - lightgreen");
  txTextOut(100, 774, "6 - Quick Sort - red");
  txTextOut(100, 788, "7 - Comb Sort - white");
  txTextOut(100, 802, "8 - Merge Sort - red");
  txTextOut(100, 816, "9 - Pyramid Sort - grey");
  txTextOut(220, 50, "Press 0 to clear all");
  txTextOut(220, 64, "Press Esc to finish");

  HDC cat = txLoadImage("kotik\\kotik.bmp");
  txBitBlt(txDC(), 40, 10, 219, 167, cat, 0, 0);
}

///--------------------------------------------------------

/**
 * @brief      Prints a 2.
 * функция выводит на экран оси графика с подписями
 */
void Print2() {
  txSetColor(TX_WHITE);
  txSetFillColor(TX_WHITE);

  txSelectFont("Lucida Console", 15, 9);
  txTextOut(180, 673, "Size");

  txSelectFont("Lucida Console", 15, 9, false, false, false, false, 90);
  txTextOut(3, 500, "Number of compares and changes");
}

///--------------------------------------------------------

/**
 * @brief      { Shaker }
 *
 * @param      data  The data
 * @param[in]  Size  The size
 */
void StatSh(int data[], int Size) {
  printf("Size   Number of compares   Number of exchanges\n");
  for (int size = 10; size < Size; size += 10) {
    ChangeSh = 0;
    ComparaisonSh = 0;
    Fill(data, size);
    SortSh(data, size);
    printf("%4d %20d %21d\n", size, ComparaisonSh, ChangeSh);
  }
}

///--------------------------------------------------------

/**
 * @brief      { Shows Shaker }
 * многократно запукает Shaker Sort на ростущем количестве данных, строит и выводит график сортировки и информацию о нём
 * в ходе работы изменяет глобальные переменные ChangeSh, ComparaisonSh, отвечающие за подсчёт операций перестанови и сравнения элементов массива
 *
 * @param      data  The data
 * @param[in]  Size  The size
 */
void GraphSh(int data[], int Size) {
  for (int size = 10; size < Size; size++) {
    ChangeSh = 0;
    ComparaisonSh = 0;
    Fill(data, size);
    SortSh(data, size);

    int x = size;
    int y1 = 0.01 * ComparaisonSh;
    int y2 = 0.01 * ChangeSh;

    txSetColor(TX_ORANGE);
    txSetFillColor(TX_ORANGE);
    txCircle(20 + x, 660 - y1, 3);

    txSetColor(TX_YELLOW);
    txSetFillColor(TX_YELLOW);
    txCircle(20 + x, 660 - y2, 3);
  }
}

///--------------------------------------------------------

/**
 * @brief      { Shows Pyramid }
 * многократно запукает Pyramid Sort на ростущем количестве данных, строит и выводит график сортировки и информацию о нём
 * в ходе работы изменяет глобальные переменные ChangePyr, ComparaisonPyr, отвечающие за подсчёт операций перестанови и сравнения элементов массива
 *
 * @param      data  The data
 * @param[in]  Size  The size
 */
void GraphPyr(int data[], int Size) {
  for (int size = 10; size < Size; size++) {
    ChangePyr = 0;
    ComparaisonPyr = 0;
    Fill(data, size);
    SortPyr(data, size);

    int x = size;
    int y1 = 0.01 * ComparaisonPyr;
    int y2 = 0.01 * ChangePyr;

    txSetColor(TX_GREY);
    txSetFillColor(TX_GREY);
    txCircle(20 + x, 660 - y1, 3);

    txSetColor(TX_GREY);
    txSetFillColor(TX_GREY);
    txCircle(20 + x, 660 - y2, 3);
  }
}

///--------------------------------------------------------

/**
 * @brief      { Shows Comb }
 * многократно запукает Comb Sort на ростущем количестве данных, строит и выводит график сортировки и информацию о нём
 * в ходе работы изменяет глобальные переменные ChangeCo, ComparaisonCo, отвечающие за подсчёт операций перестанови и сравнения элементов массива
 *
 * @param      data  The data
 * @param[in]  Size  The size
 */
void GraphCo(int data[], int Size) {
  for (int size = 10; size < Size; size++) {
    ChangeCo = 0;
    ComparaisonCo = 0;
    Fill(data, size);
    SortCo(data, size);

    int x = size;
    int y1 = 0.01 * ComparaisonCo;
    int y2 = 0.01 * ChangeCo;

    txSetColor(TX_WHITE);
    txSetFillColor(TX_WHITE);
    txCircle(20 + x, 660 - y1, 3);

    txSetColor(TX_WHITE);
    txSetFillColor(TX_WHITE);
    txCircle(20 + x, 660 - y2, 3);
  }
}

///--------------------------------------------------------

/**
 * @brief      { Shows Quick }
 * многократно запукает Quick Sort на ростущем количестве данных, строит и выводит график сортировки и информацию о нём
 * в ходе работы изменяет глобальные переменные ChangeQ, ComparaisonQ, отвечающие за подсчёт операций перестанови и сравнения элементов массива
 *
 * @param      data  The data
 * @param[in]  Size  The size
 */
void GraphQ(int data[], int Size) {
  for (int size = 10; size < Size; size++) {
    ChangeQ = 0;
    ComparaisonQ = 0;
    Fill(data, size);
    SortQ(data, size, 0);

    int x = size;
    int y1 = 0.01 * ComparaisonQ;
    int y2 = 0.01 * ChangeQ;

    txSetColor(TX_RED);
    txSetFillColor(TX_RED);
    txCircle(20 + x, 660 - y1, 3);

    txSetColor(TX_ORANGE);
    txSetFillColor(TX_ORANGE);
    txCircle(20 + x, 660 - y2, 3);
  }
}

///--------------------------------------------------------

/**
 * @brief      { Shows Shaker }
 * многократно запукает Gnome Sort на ростущем количестве данных, строит и выводит график сортировки и информацию о нём
 * в ходе работы изменяет глобальные переменные ChangeGn, ComparaisonGn, отвечающие за подсчёт операций перестанови и сравнения элементов массива
 *
 * @param      data  The data
 * @param[in]  Size  The size
 */
void GraphGn(int data[], int Size) {
  for (int size = 10; size < Size; size++) {
    ChangeGn = 0;
    ComparaisonGn = 0;
    Fill(data, size);
    SortGn(data, size);

    int x = size;
    int y1 = 0.01 * ComparaisonGn;
    int y2 = 0.01 * ChangeGn;

    txSetColor(TX_LIGHTGREEN);
    txSetFillColor(TX_LIGHTGREEN);
    txCircle(20 + x, 660 - y1, 3);

    txSetColor(TX_GREEN);
    txSetFillColor(TX_GREEN);
    txCircle(20 + x, 660 - y2, 3);
  }
}

///--------------------------------------------------------

/**
 * @brief      { Shows Shaker }
 * многократно запукает Merge Sort на ростущем количестве данных, строит и выводит график сортировки и информацию о нём
 * в ходе работы изменяет глобальные переменные ChangeM, ComparaisonM, отвечающие за подсчёт операций перестанови и сравнения элементов массива
 *
 * @param      data  The data
 * @param[in]  Size  The size
 */
void GraphM(int data[], int Size) {
  for (int size = 10; size < Size; size++) {
    ChangeM = 0;
    ComparaisonM = 0;
    Fill(data, size);
    SortM(data, size);

    int x = size;
    int y1 = 0.01 * ComparaisonM;
    int y2 = 0.01 * ChangeM;

    txSetColor(TX_BLUE);
    txSetFillColor(TX_BLUE);
    txCircle(20 + x, 660 - y1, 3);

    txSetColor(TX_BLUE);
    txSetFillColor(TX_BLUE);
    txCircle(20 + x, 660 - y2, 3);
  }
}

///--------------------------------------------------------

/**
 * @brief      { Shows Selections Sort }
 * многократно запукает Selections Sort на ростущем количестве данных, строит и выводит график сортировки и информацию о нём
 * в ходе работы изменяет глобальные переменные ChangeS, ComparaisonS, отвечающие за подсчёт операций перестанови и сравнения элементов массива
 *
 * @param      data  The data
 * @param[in]  Size  The size
 */
void GraphS(int data[], int Size) {
  for (int size = 10; size < Size; size++) {
    ChangeS = 0;
    ComparaisonS = 0;
    Fill(data, size);
    SortS(data, size);

    int x = size;
    int y1 = 0.01 * ComparaisonS;
    int y2 = 0.01 * ChangeS;

    txSetColor(TX_LIGHTCYAN);
    txSetFillColor(TX_LIGHTCYAN);
    txCircle(20 + x, 660 - y1, 3);

    txSetColor(TX_CYAN);
    txSetFillColor(TX_CYAN);
    txCircle(20 + x, 660 - y2, 3);
  }
}

///--------------------------------------------------------

/**
 * @brief      { Shows Bubble Sort }
 * многократно запукает Bubble Sort на ростущем количестве данных, строит и выводит график сортировки и информацию о нём
 * в ходе работы изменяет глобальные переменные ChangeB, ComparaisonB, отвечающие за подсчёт операций перестанови и сравнения элементов массива
 *
 * @param      data  The data
 * @param[in]  Size  The size
 */
void GraphB(int data[], int Size) {
  for (int size = 10; size < Size; size++) {
    ChangeB = 0;
    ComparaisonB = 0;
    Fill(data, size);
    SortB(data, size);

    int x = size;
    int y1 = 0.01 * ComparaisonB;
    int y2 = 0.01 * ChangeB;

    txSetColor(TX_MAGENTA);
    txSetFillColor(TX_MAGENTA);
    txCircle(20 + x, 660 - y1, 3);

    txSetColor(TX_PINK);
    txSetFillColor(TX_PINK);
    txCircle(20 + x, 660 - y2, 3);
  }
}

///--------------------------------------------------------

/**
 * @brief      { Shows Simple Insertion}
 * многократно запукает Simple Insertion Sort на ростущем количестве данных, строит и выводит график сортировки и информацию о нём
 * в ходе работы изменяет глобальные переменные ChangeSI, ComparaisonSI, отвечающие за подсчёт операций перестанови и сравнения элементов массива
 *
 * @param      data  The data
 * @param[in]  Size  The size
 */
void GraphSI(int data[], int Size) {
  for (int size = 10; size < Size; size++) {
    ChangeSI = 0;
    ComparaisonSI = 0;
    Fill(data, size);
    SortSI(data, size);

    int x = size;
    int y1 = 0.01 * ComparaisonSI;
    int y2 = 0.01 * ChangeSI;

    txSetColor(TX_GREEN);
    txSetFillColor(TX_GREEN);
    txCircle(20 + x, 660 - y1, 3);

    txSetColor(TX_LIGHTGREEN);
    txSetFillColor(TX_LIGHTGREEN);
    txCircle(20 + x, 660 - y2, 3);
  }
}

///--------------------------------------------------------

/**
 * @brief      { Fills DATA }
 * заполняет массив DATA указанным количеством случайных чисел
 *
 * @param      data  The data
 * @param[in]  size  The size
 */
void Fill(int data[], int size) {
  for (int i = 0; i < size; i++) {
    data[i] = rand();
  }
}

///--------------------------------------------------------

/**
 * @brief      { Swap Shaker }
 *
 * @param      data  The data
 * @param[in]  a     { parameter_description }
 * @param[in]  b     { parameter_description }
 */
void SwapSh(int data[], int a, int b) {
  int x = data[a];
  data[a] = data[b];
  data[b] = x;
  ChangeSh++;
}

///--------------------------------------------------------

/**
 * @brief      { Shaker Sort }
 * сортирует массив DATA указанного размера с помощью Shaker Sort
 * изменяет глобальные переменные ChangeSh, ComparaisonSh, отвечающие за подсчёт операций перестанови и сравнения элементов массива
 *
 * @param      data  The data
 * @param[in]  size  The size
 */
void SortSh(int data[], int size) {
  for (int pos = 1; pos < size - 1; pos++) {
    for (int i = 0; i < size - pos; i++) {
      if (data[i + 1] < data[i]) {
        SwapSh(data, i, i + 1);
      }
      ComparaisonSh++;
    }
    for (int i = size - pos; i > pos + 1; i--) {
      if (data[i] > data[i + 1]) {
        SwapSh(data, i, i + 1);
      }
      ComparaisonSh++;
    }
  }
}

///--------------------------------------------------------

/**
 * @brief      Finds a minimum s.
 * функция поиска минимума для Selections Sort 
 *
 * @param      data  The data
 * @param[in]  size  The size
 * @param[in]  pos   The position
 *
 * @return     { description_of_the_return_value }
 */
int FindMinS(int data[], const int size, int pos) {
  int minpos = pos;
  int minnum = data[pos];
  for (int i = minpos; i < size; i++) {
    if (data[i] < minnum) {
      minpos = i;
      minnum = data[i];
    }
    ComparaisonS++;
  }
  return minpos;
}

///--------------------------------------------------------

/**
 * @brief      {Swap Selections}
 *
 * @param      data  The data
 * @param[in]  i     { Counter }
 * @param[in]  min   The minimum
 */
void SwapS(int data[], int i, int min) {
  int x = data[i];
  data[i] = data[min];
  data[min] = x;
  ChangeS++;
}

///--------------------------------------------------------

/**
 * @brief      { Selections Sort }
 * сортирует массив DATA указанного размера с помощью Selections Sort
 * изменяет глобальные переменные ChangeS, ComparaisonS, отвечающие за подсчёт операций перестанови и сравнения элементов массива
 *
 * @param      data  The data
 * @param[in]  size  The size
 */
void SortS(int data[], const int size) {
  for (int i = 0; i < size; i++) {
    int min = FindMinS(data, size, i);
    SwapS(data, i, min);
  }
}

///--------------------------------------------------------

/**
 * @brief      { Swaps Bubble Sort }
 *
 * @param      data  The data
 * @param[in]  min   The minimum
 * @param[in]  pos   The position
 */
void SwapB(int data[], int min, int pos) {
  int x = data[min];
  data[min] = data[pos];
  data[pos] = x;
  ChangeB++;
}

/**
 * @brief      { Gnom bro }
 * сортирует массив DATA указанного размера с помощью Gnom Sort
 * изменяет глобальные переменные ChangeG, ComparaisonG, отвечающие за подсчёт операций перестанови и сравнения элементов массива
 *
 * @param      data  The data
 * @param[in]  size  The size
 */
void SortGn(int data[], int size) {
  int i = 0;
  while (i < size) {
    if (i == 0) {
      ++ComparaisonGn;
      ++i;
    } else {
      if (data[i - 1] <= data[i]) {
        ++ComparaisonGn;
        ++i;
      } else {
        std::swap(data[i - 1], data[i]);
              ++ChangeGn;
              --i;
      }
    }
  }
}

///--------------------------------------------------------

/**
 * @brief      { Sort Bubble }
 * сортирует массив DATA указанного размера с помощью Bubble Sort
 * изменяет глобальные переменные ChangeB, ComparaisonB, отвечающие за подсчёт операций перестанови и сравнения элементов массива
 *
 * @param      data  The data
 * @param[in]  size  The size
 */
void SortB(int data[], int size) {
  for (int pos = 1; pos < size - 1; pos++) {
    for (int i = 0; i < size - pos; i++) {
      if (data[i + 1] < data[i]) {
        SwapB(data, i, i + 1);
      }
      ComparaisonB++;
    }
  }
}

///----------------------------------------------------------

/**
 * @brief      { function_description }
 * сортирует массив DATA указанного размера с помощью Quick Sort
 * изменяет глобальные переменные ChangeQ, ComparaisonQ, отвечающие за подсчёт операций перестанови и сравнения элементов массива
 *
 * @param      data  The data
 * @param[in]  r     The right pointer
 * @param[in]  l     The left pointer
 */
void SortQ(int data[], int r, int l) {
    if (r - l <= 1) {
        return;
    }
    int z = data[l + (r - l) / 2];
    int ll = l, rr = r - 1;
    while (ll <= rr) {
        while (data[ll] < z) {
            ++ComparaisonQ;
            ++ll;
        }
        while (data[rr] > z) {
            ++ComparaisonQ;
            --rr;
        }
        if (ll <= rr) {
            std::swap(data[ll], data[rr]);
            ++ChangeQ;
            ++ll;
            --rr;
        }
    }
    if (l < rr) {
        SortQ(data, rr + 1, l);
    }
    if (ll < r) {
        SortQ(data, r, ll);
    }
}

/**
 * @brief      { Comb Sort }
 * сортирует массив DATA указанного размера с помощью Comb Sort
 * изменяет глобальные переменные ChangeCo, ComparaisonCo, отвечающие за подсчёт операций перестанови и сравнения элементов массива
 *
 * @param      data  The data
 * @param[in]  size  The size
 */
void SortCo(int data[], int size) {
  if (size <= 1) {
        return;
    }
  double k = 1.2473309;
  int step = size - 1;
  while (step > 1) {
    for (int i = 0; i + step < size; i++) {
            ++ComparaisonCo;
      if (data[i] > data[i + step]) {
                std::swap(data[i], data[i + step]);
                ++ChangeCo;
            }
    }
    step /= k;
  }
  bool b = true;
  while (b) {
    b = false;
    for (int i = 0; i + 1 < size; i++) {
            ++ComparaisonCo;
      if (data[i] > data[i + 1]) {
        std::swap(data[i], data[i + 1]);
                ++ChangeCo;
        b = true;
      }
    }
  }
}


/**
 * @brief      This class describes a heap.
 * реализация структуры Heap на векторе
 * операция вставки Insert(x) где x - число типа int
 * операция извлечения Extract() возвращает число типа int и удаляет его из Heap
 * изменяет глобальные переменные ChangePyr, ComparaisonPyr, отвечающие за подсчёт операций перестанови и сравнения элементов массива
 */
class Heap {
private:
    std::vector<int> heap;

public:
    void Insert(int x) {
        heap.push_back(x);
        int child = heap.size() - 1;
        int parent = (child - 1) / 2;
        while (child > 0 && parent >= 0) {
            ++ComparaisonPyr;
            if (heap[child] > heap[parent]) {
                std::swap(heap[child], heap[parent]);
                ++ChangePyr;
            }
            child = parent;
            parent = (child - 1) / 2;
        }
    }

    void heapify(int parent) {
        int left = parent * 2 + 1;
        int right = parent * 2 + 2;
        int max = parent;
        if (left < heap.size()) {
            ++ComparaisonPyr;
            if (heap[parent] < heap[left]) {
                max = left;
            }
        }
        if (right < heap.size()) {
            ++ComparaisonPyr;
            if (heap[parent] < heap[right]) {
                ++ComparaisonPyr;
                if (heap[right] > heap[left]) {
                    max = right;
                }
            }
        }
        if (max != parent) {
            std::swap(heap[max], heap[parent]);
            ++ChangePyr;
            heapify(max);
        }
    }

    int Extract() {
        int x = heap[0];
        std::swap(heap[0], heap[heap.size() - 1]);
        ++ChangePyr;
        heap.pop_back();
        heapify(0);
        return x;
    }
};

/**
 * @brief      { Pyramid Sort }
 * сортирует массив DATA указанного размера с помощью Pyramid Sort
 *
 * @param      data  The data
 * @param[in]  size  The size
 */
void SortPyr(int data[], int size) {
    Heap heap;
    for (int i = 0; i < size; ++i) {
        heap.Insert(data[i]);
    }
    int i = 0;
    for (int i = size - 1; i >= 0; --i) {
        data[i] = heap.Extract();
    }
}


/**
 * @brief      { Merge Sort }
 * сортирует массив DATA указанного размера с помощью Merge Sort
 * изменяет глобальные переменные ChangeM, ComparaisonM, отвечающие за подсчёт операций перестанови и сравнения элементов массива
 *
 * @param      data  The data
 * @param[in]  size  The size
 */
void SortM(int data[], int size) {
    int mid = size / 2;
    if (size % 2 == 1) {
        mid++;
    }
    int h = 1;
    //int *c = (int*)malloc(size * sizeof(int));
    int c[900] = {};
    //std::vector<int> c (size);
    int step;
    while (h < size) {
        step = h;
        int i = 0;
        int j = mid;
        int k = 0;
        while (step <= mid) {
            while ((i < step) && (j < size) && (j < (mid + step))) {
                ++ComparaisonM;
                if (data[i] < data[j]) {
                    c[k] = data[i];
                    ++ChangeM;
                    ++i;
                    ++k;
                } else {
                    c[k] = data[j];
                    ++ChangeM;
                    ++j;
                    ++k;
                }
            }
            while (i < step) {
                c[k] = data[i];
                ++ChangeM;
                ++i;
                ++k;
            }
            while ((j < (mid + step)) && (j<size)) {
                c[k] = data[j];
                ++ChangeM;
                ++j;
                ++k;
            }
            step = step + h;
        }
        h = h * 2;
        for (i = 0; i < size; i++) {
            data[i] = c[i];
        }
    }
}

///--------------------------------------------------------

/**
 * @brief      { Simple Insertion Sort }
 * сортирует массив DATA указанного размера с помощью Simple Insertion Sort
 * изменяет глобальные переменные ChangeSI, ComparaisonSI, отвечающие за подсчёт операций перестанови и сравнения элементов массива
 *
 * @param      data  The data
 * @param[in]  size  The size
 */
void SortSI(int data[], int size) {
  Fill(data, size);
  for (int i = 0; i < size - 1; i++) {
    int pos = FindPosSI(data, i, data[i + 1]);
    RorSI(data, pos, i + 1);
  }
  int pos = FindPosSI(data, size, data[size - 1]);
  RorSI(data, pos, size - 1);
}

///--------------------------------------------------------

/**
 * @brief      { Changes SI }
 * функция подсчитывает операции перестановки элементов в массиве в Simple Insertion Sort и изменяет глобальную переменную ChangeSI
 *
 * @param      data   The data
 * @param[in]  start  The start
 * @param[in]  end    The end
 */
void RorSI(int data[], int start, int end) {
  int x = data[end];
  for (int i = 0; i <= end - start; i++) {
    data[end - i] = data[end - i - 1];
    ChangeSI++;
  }
  data[start] = x;
  ChangeSI++;
}

///--------------------------------------------------------

/**
 * @brief      From which position we hould start Ror.
 * функция подсчитывает операции сравнения элементов в массиве в Simple Insertion Sort и изменяет глобальную переменную ComparaisonSI
 *
 * @param      data  The data
 * @param[in]  size  The size
 * @param[in]  k     The element from the data
 *
 * @return     { description_of_the_return_value }
 */
int FindPosSI(int data[], int size, int k) {
  int pos = 0;
  for (int i = 0; i < size; i++) {
    if (k >= data[i]) {
      pos++;
    }
    ComparaisonSI++;
  }
  return pos;
}

///--------------------------------------------------------
