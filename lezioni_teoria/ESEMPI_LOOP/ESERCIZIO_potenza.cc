using namespace std;
#include <iostream>
#include <cmath>

int main ()
{
  int N;
  //   Somma_i (-1)^i 1/(x^i)
  double prodotto, X;
  cout << "Inserire N?: ";
  cin >> N;
  cout << "Numero reale X?: ";
  cin >> X;
  prodotto=1.0;
  for (int i=0;i<=N;i++)
    prodotto*= X;
  cout << "Il valore di " << X << "^" << N << " e´: " << prodotto << endl;

  return 0;
}
