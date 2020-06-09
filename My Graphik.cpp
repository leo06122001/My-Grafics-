/*!
    \brief My Graphik
    \author LaB
    \version 1.0
    \date Май 2020 года
*/
#include "TXLib.h"
#include <vector>
#include "functions.hpp"

int Comparaison = 0;
int Change = 0;

int main() {
  txCreateWindow(450, 824);
  const int DATA_SIZE = 350;
  std::vector<numbers> data(DATA_SIZE);
  Print1();
  Print2();
  ChoosingSort(data, DATA_SIZE);
}
