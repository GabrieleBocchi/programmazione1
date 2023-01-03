#include <iostream>
using namespace std;

int calcola_ric_imp(int x, int y, int res=0) {
  if (x < y) {
    return res;
  } else {
    return calcola_ric(x-y, y, res+1);
  }
}

int calcola_ric(int x, int y) {
  return calcola_ric_imp(x, y, 0);
}

int main() {

  calcola_ric(10, 5);

  return 0;
}
