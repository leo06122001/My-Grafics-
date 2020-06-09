/*!
    \brief My Graphik
    \author LaB
    \version 1.0
    \date Май 2020 года
*/
#include "TXLib.h"
#include <vector>
#include "functions.hpp"


int main() {
  txCreateWindow(450, 824);
  const int DATA_SIZE = 350;
  std::vector<numbers> data(DATA_SIZE);
  Print1();
  Print2();
  ChoosingSort(data, DATA_SIZE);
}

//--------------------------------------------------------

/**
 * @brief      { Choosing of Sort }
 * вызывает функцию построения графика сортировки, соответствующую нажатой клавише или зачищает график если нажат 0
 *
 * @param      data       The data
 * @param[in]  DATA_SIZE  The data size
 */

void ChoosingSort(std::vector<numbers> & data, int DATA_SIZE) {
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
void StatSh(std::vector<numbers> & data, int Size) {
  printf("Size   Number of compares   Number of exchanges\n");
  for (int size = 10; size < Size; size += 10) {
    Change = 0;
    Comparaison = 0;
    Fill(data, size);
    SortSh(data, size);
    printf("%4d %20d %21d\n", size, Comparaison, Change);
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
void GraphSh(std::vector<numbers> & data, int Size) {
  for (int size = 10; size < Size; size++) {
    Change = 0;
    Comparaison = 0;
    Fill(data, size);
    SortSh(data, size);

    int x = size;
    int y1 = 0.01 * Comparaison;
    int y2 = 0.01 * Change;

    txSetColor(TX_YELLOW);
    txSetFillColor(TX_YELLOW);
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
void GraphPyr(std::vector<numbers> & data, int Size) {
  for (int size = 10; size < Size; size++) {
    Change = 0;
    Comparaison = 0;
    Fill(data, size);
    SortPyr(data, size);

    int x = size;
    int y1 = 0.01 * Comparaison;
    int y2 = 0.01 * Change;

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
void GraphCo(std::vector<numbers> & data, int Size) {
  for (int size = 10; size < Size; size++) {
    Change = 0;
    Comparaison = 0;
    Fill(data, size);
    SortCo(data, size);

    int x = size;
    int y1 = 0.01 * Comparaison;
    int y2 = 0.01 * Change;

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
void GraphQ(std::vector<numbers> & data, int Size) {
  for (int size = 10; size < Size; size++) {
    Change = 0;
    Comparaison = 0;
    Fill(data, size);
    SortQ(data, size, 0);

    int x = size;
    int y1 = 0.01 * Comparaison;
    int y2 = 0.01 * Change;

    txSetColor(TX_RED);
    txSetFillColor(TX_RED);
    txCircle(20 + x, 660 - y1, 3);

    txSetColor(TX_RED);
    txSetFillColor(TX_RED);
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
void GraphGn(std::vector<numbers> & data, int Size) {
  for (int size = 10; size < Size; size++) {
    Change = 0;
    Comparaison = 0;
    Fill(data, size);
    SortGn(data, size);

    int x = size;
    int y1 = 0.01 * Comparaison;
    int y2 = 0.01 * Change;

    txSetColor(TX_ORANGE);
    txSetFillColor(TX_ORANGE);
    txCircle(20 + x, 660 - y1, 3);

    txSetColor(TX_ORANGE);
    txSetFillColor(TX_ORANGE);
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
void GraphM(std::vector<numbers> & data, int Size) {
  for (int size = 10; size < Size; size++) {
    Change = 0;
    Comparaison = 0;
    Fill(data, size);
    SortM(data, size);

    int x = size;
    int y1 = 0.01 * Comparaison;
    int y2 = 0.01 * Change;

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
void GraphS(std::vector<numbers> & data, int Size) {
  for (int size = 10; size < Size; size++) {
    Change = 0;
    Comparaison = 0;
    Fill(data, size);
    SortS(data, size);

    int x = size;
    int y1 = 0.01 * Comparaison;
    int y2 = 0.01 * Change;

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
void GraphB(std::vector<numbers> & data, int Size) {
  for (int size = 10; size < Size; size++) {
    Change = 0;
    Comparaison = 0;
    Fill(data, size);
    SortB(data, size);

    int x = size;
    int y1 = 0.01 * Comparaison;
    int y2 = 0.01 * Change;

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
void GraphSI(std::vector<numbers> & data, int Size) {
  for (int size = 10; size < Size; size++) {
    Change = 0;
    Comparaison = 0;
    Fill(data, size);
    SortSI(data, size);

    int x = size;
    int y1 = 0.01 * Comparaison;
    int y2 = 0.01 * Change;

    txSetColor(TX_GREEN);
    txSetFillColor(TX_GREEN);
    txCircle(20 + x, 660 - y1, 3);

    txSetColor(TX_LIGHTGREEN);
    txSetFillColor(TX_LIGHTGREEN);
    txCircle(20 + x, 660 - y2, 3);
  }
}
