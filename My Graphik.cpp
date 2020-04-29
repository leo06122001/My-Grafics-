#include <txlib.h>

void Fill           (int data[], int size);

void Print1         ();
void Print2         ();
void ChoosingSort   (int data[], int DATA_SIZE);

void GraphSh        (int data[], int Size);
void GraphS         (int data[], int Size);
void GraphB         (int data[], int Size);
void GraphSI         (int data[], int Size);

void SwapSh         (int data[], int a, int b);                     //Shaker
void SortSh         (int data[], int size);
void StatSh         (int data[], int Size);

void SwapS          (int data[], int a, int b);                     //Selection
void SortS          (int data[], int size);
int  FindMinS       (int data[], const int size, int i);

void SortB          (int data[], int size);                         //Bubble
void SwapB          (int data[], int min, int pos);

void SortSI          (int data[], int size);
int  FindPosSI       (int data[], int size, int i);                  //Simple Insertion
void RorSI           (int data[], int start, int end);

int ComparaisonSh = 0;
int ChangeSh = 0;

int ComparaisonS = 0;
int ChangeS = 0;

int ComparaisonB = 0;
int ChangeB = 0;

int ComparaisonSI = 0;
int ChangeSI = 0;


int main ()
    {
    txCreateWindow (450, 800);
    const int DATA_SIZE = 900;
    int data[DATA_SIZE] = {};
    Print1 ();
    Print2 ();
    ChoosingSort (data, DATA_SIZE);
    }

///--------------------------------------------------------

void ChoosingSort (int data[], int DATA_SIZE)
    {
    while (1>0)
        {
        if (GetAsyncKeyState (VK_NUMPAD4))
            {
            GraphSI (data, DATA_SIZE);
            }
        if (GetAsyncKeyState (VK_NUMPAD3))
            {
            GraphSh (data, DATA_SIZE);
            }
        if (GetAsyncKeyState (VK_NUMPAD2))
            {
            GraphB (data, DATA_SIZE);
            }
        if (GetAsyncKeyState (VK_NUMPAD1))
            {
            GraphS (data, DATA_SIZE);
            }
        if (GetAsyncKeyState (VK_NUMPAD0))
            {
            txSetFillColor (TX_BLACK);
            txClear ();
            Print1 ();
            Print2 ();
            }
        if (GetAsyncKeyState (VK_ESCAPE))
            {
            break ;
            }

        }
    }

///--------------------------------------------------------

void Print1 ()
    {
    txSetColor (TX_WHITE);
    txSetFillColor (TX_WHITE);
    txLine (20, 0, 20, 680);
    txLine (10, 670, 410, 670);
    txSelectFont ("Lucida Console", 14, 9);
    txTextOut (80, 690, "Press on numpad:");
    txTextOut (100, 704, "1 - Selection Sort        - blue");
    txTextOut (100, 718, "2 - Bubble Sort           - pink");
    txTextOut (100, 732, "3 - Shaker Sort           - yellow");
    txTextOut (100, 746, "4 - Simple Insertion Sort - green");
    txTextOut (220, 760, "Press 0 to clear all");
    txTextOut (220, 774, "Press Esc to finish");

    HDC cat = txLoadImage ("kotik\\kotik.bmp");
    txBitBlt (txDC(), 40, 10, 219, 167, cat, 0, 0);
    }

///--------------------------------------------------------

void Print2 ()
    {
    txSetColor (TX_WHITE);
    txSetFillColor (TX_WHITE);

    txSelectFont ("Lucida Console", 15, 9);
    txTextOut (180, 673, "Size");

    txSelectFont ("Lucida Console", 15, 9, false, false, false, false, 90);
    txTextOut (3, 500, "Number of compares and changes");

    }

///--------------------------------------------------------

void StatSh (int data[], int Size)
    {
    printf ("Size   Number of compares   Number of exchanges\n");
    for (int size = 10; size < Size; size += 10)
         {
         ChangeSh = 0; ComparaisonSh = 0;
         Fill (data, size);
         SortSh (data, size);
         printf ("%4d %20d %21d\n", size,  ComparaisonSh, ChangeSh);
         }
    }

///--------------------------------------------------------

void GraphSh (int data[], int Size)
    {
    for (int size = 10; size < Size; size ++)
         {
         ChangeSh = 0; ComparaisonSh = 0;
         Fill (data, size);
         SortSh (data, size);

         int x  = size;
         int y1 = 0.01*ComparaisonSh;
         int y2 = 0.01*ChangeSh;

         txSetColor (TX_ORANGE);
         txSetFillColor (TX_ORANGE);
         txCircle (20+x, 660-y1, 3);

         txSetColor (TX_YELLOW);
         txSetFillColor (TX_YELLOW);
         txCircle (20+x, 660-y2, 3);
         }
    }

///--------------------------------------------------------

void GraphS (int data[], int Size)
    {
    for (int size = 10; size < Size; size ++)
         {
         ChangeS = 0; ComparaisonS = 0;
         Fill (data, size);
         SortS (data, size);

         int x  = size;
         int y1 = 0.01*ComparaisonS;
         int y2 = 0.01*ChangeS;

         txSetColor (TX_LIGHTCYAN);
         txSetFillColor (TX_LIGHTCYAN);
         txCircle (20+x, 660-y1, 3);

         txSetColor (TX_CYAN);
         txSetFillColor (TX_CYAN);
         txCircle (20+x, 660-y2, 3);
         }
    }

///--------------------------------------------------------

void GraphB (int data[], int Size)
    {
    for (int size = 10; size < Size; size ++)
         {
         ChangeB = 0; ComparaisonB = 0;
         Fill (data, size);
         SortB (data, size);

         int x  = size;
         int y1 = 0.01*ComparaisonB;
         int y2 = 0.01*ChangeB;

         txSetColor (TX_MAGENTA);
         txSetFillColor (TX_MAGENTA);
         txCircle (20+x, 660-y1, 3);

         txSetColor (TX_PINK);
         txSetFillColor (TX_PINK);
         txCircle (20+x, 660-y2, 3);
         }

    }

///--------------------------------------------------------

void GraphSI (int data[], int Size)
    {
    for (int size = 10; size < Size; size ++)
         {
         ChangeSI = 0; ComparaisonSI = 0;
         Fill (data, size);
         SortSI (data, size);

         int x  = size;
         int y1 = 0.01*ComparaisonSI;
         int y2 = 0.01*ChangeSI;

         txSetColor (TX_GREEN);
         txSetFillColor (TX_GREEN);
         txCircle (20+x, 660-y1, 3);

         txSetColor (TX_LIGHTGREEN);
         txSetFillColor (TX_LIGHTGREEN);
         txCircle (20+x, 660-y2, 3);
         }

    }

///--------------------------------------------------------

void Fill (int data[], int size)
    {
    for (int i = 0; i < size; i++)
        {
        data[i] = rand ();
        }
    }

///--------------------------------------------------------

void SwapSh (int data[], int a, int b)
    {
    int x = data[a];
    data[a] = data[b];
    data[b] = x;
    ChangeSh++;
    }

///--------------------------------------------------------

void SortSh (int data[], int size)
    {
    for (int pos = 1; pos < size - 1; pos++)
        {
        for (int i = 0; i < size - pos; i++)
            {
            if (data[i+1] < data[i])
                {
                SwapSh (data, i, i+1);
                }
            ComparaisonSh++;
            }
        for (int i = size - pos; i > pos + 1 ; i--)
            {
            if (data[i] > data[i+1])
                {
                SwapSh (data, i, i+1);
                }
            ComparaisonSh++;
            }
        }
    }

///--------------------------------------------------------

int FindMinS (int data[], const int size, int pos)
    {
    int minpos = pos;
    int minnum = data[pos];
    for (int i = minpos; i < size; i++)
        {
        if (data[i] < minnum)
            {
            minpos = i;
            minnum = data[i];
            }
        ComparaisonS++;
        }
    return minpos;
    }

///--------------------------------------------------------

void SwapS   (int data[], int i, int min)
    {
    int x = data[i];
    data[i] = data[min];
    data[min] = x;
    ChangeS++;
    }

///--------------------------------------------------------

void SortS   (int data[], const int size)
    {
    for (int i = 0; i < size; i++)
         {
         int min = FindMinS (data, size, i);
         SwapS (data, i, min);
         }

}

///--------------------------------------------------------

void SwapB  (int data[], int min, int pos)
    {
    int x = data[min];
    data[min] = data[pos];
    data[pos] = x;
    ChangeB++;
    }

///--------------------------------------------------------

void SortB  (int data[], int size)
    {
    for (int pos = 1; pos < size - 1; pos++)
        {
        for (int i = 0; i < size - pos; i++)
            {
            if (data[i+1] < data[i])
                {
                SwapB (data, i, i+1);
                }
            ComparaisonB++;
            }
        }
    }

///--------------------------------------------------------

void SortSI (int data[], int size)
    {
    Fill  (data, size);
    for (int i = 0; i < size-1; i++)
        {
        int pos = FindPosSI (data, i, data[i+1]);
        RorSI (data, pos, i+1);
        }
    int pos = FindPosSI (data , size, data[size-1]);
    RorSI (data, pos, size-1);
    }

///--------------------------------------------------------

void RorSI (int data[], int start, int end)
    {
    int x = data[end];
    for (int i = 0; i <= end-start; i++)
        {
        data[end-i] = data[end-i-1];
        ChangeSI++;
        }
    data[start] = x;
    ChangeSI++;
    }

///--------------------------------------------------------

int FindPosSI (int data[], int size, int k)
    {
    int pos = 0;
    for (int i = 0; i < size; i++)
        {
        if (k >= data[i])
            {
            pos++;
            }
        ComparaisonSI++;
        }
    return pos;
    }

///--------------------------------------------------------

