#include <iostream>
using namespace std;

int main() {
  cout << "Inserisci un carattare tra: [i,e,f]: ";
  char c;
  cin >> c;
  switch(c) {
  case 'i':
    cout << "Buongiorno!" << endl;
    break;
  case 'e':
    cout << "Good morning!" << endl;
    break;
  case 'f':
    cout << "Bonjour!" << endl;
    break;
  default:
    cout << "Lingua sconosciuta!" << endl;
    break;
  }
  return 0;
}
