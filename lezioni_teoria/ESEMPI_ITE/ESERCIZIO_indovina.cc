#include <iostream>
using namespace std;

int main() {
  cout << "Pensa un numero da 0 a 7" << endl;

  cout << "Il numero pensato e' pari? (s/n) ";
  char c;

  cin >> c;
  if (c == 's') {
    // e' 0, 2, 4, 6
    cout << "Il numero pensato e' >= 4? (s/n) ";
    cin >> c;
    if (c == 's') {
      // e' 4 o 6
      cout << "Il numero pensato e' > di 5? (s/n) ";
      cin >> c;
      if (c == 's') {
	cout << "Il numero pensato e' 6" << endl;
      }
      else {
	cout << "Il numero pensato e' 4" << endl;
      }
    }
    else {
      // e' 0 o 2
      cout << "Il numero pensato e' > di 1? (s/n) ";
      cin >> c;
      if (c == 's') {
	cout << "Il numero pensato e' 2" << endl;
      }
      else {
	cout << "Il numero pensato e' 0" << endl;
      }
    }
  }
  else {
    // e' 1, 3, 5, 7
    cout << "Il numero pensato e' >= 4? (s/n) ";
    cin >> c;
    if (c == 's') {
      // e' 5 o 7
      cout << "Il numero pensato e' > di 6? (s/n)";
      cin >> c;
      if (c == 's') {
	cout << "Il numero pensato e' 7" << endl;
      }
      else {
	cout << "Il numero pensato e' 5" << endl;
      }
    }
    else {
      // e' 1 o 3
      cout << "Il numero pensato e' > di 2? (s/n)";
      cin >> c;
      if (c == 's') {
	cout << "Il numero pensato e' 3" << endl;
      }
      else {
	cout << "Il numero pensato e' 1" << endl;
      }
    }
  }
  return 0;
}
