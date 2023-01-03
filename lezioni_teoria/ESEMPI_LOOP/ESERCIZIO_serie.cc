using namespace std;
#include <iostream>
#include <cmath>

int main ()
{
  int N;
  //   Somma_i (-1)^i 1/(x^i)
  double somma, X;
  cout << "Numero massimo di iterazioni?: ";
  cin >> N;
  cout << "Numero reale X?: ";
  cin >> X;
  somma=0.0;
  for (int i=0;i<=N;i++)
    somma+= pow(-1,i)/(pow(X,i));
  cout << "La somma e' = " << somma << endl;

  return 0;
}
