using namespace std;
#include <iostream>
#include <cmath>

int main() {
  int n,precedente,precedente2,elemento;

  cout << "Quanti elementi della serie vuoi stampare? ";
  cin >> n;

  if (n==1) {
      cout << "1" <<endl;
  }
  if (n==2) {
      cout << "1 1" <<endl;
  }
  if (n>2) {
      cout << "1 1 ";
      precedente=1;
      precedente2=1;
      for (int i=2; i<n; i++) {
	elemento=precedente+precedente2;
	cout << elemento << " ";
	precedente2=precedente;
	precedente=elemento;
      }
      cout << endl;
  }
  return 0;
}
