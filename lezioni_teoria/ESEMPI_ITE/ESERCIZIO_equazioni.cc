#include <iostream>
#include <cmath>

using namespace std;

int main() {
  // a * x * x + b * x + c = 0
  float a, b, c;
  cout << "Inserisci tre float: ";
  cin >> a >> b >> c;
  float x1, x2, delta;

  if (a != 0) {
    // d * d = d ==> d = sqrt(d * d);
    delta = b * b - 4.0 * a * c;
    // Controllo con if se delta e' negativo
    if (delta < 0) {
      cout << "(x1, x2) = (" << -b/(2.0*a) << " + " << sqrt(-delta) / (2.0 * a) << "i, ";
      cout                             << -b/(2.0*a) << " - " << sqrt(-delta) / (2.0 * a) << "i)" << endl;
    } else {
      x1 = (-b - sqrt(delta)) / (2 * a);
      x2 = (-b + sqrt(delta)) / (2 * a);
      cout << "(x1, x2) = (" << x1 << ", " << x2 << ")" << endl;
    }
  }
  else {
    if ((b==0)&&(c==0))
      cout<<"Infinite soluzioni\n";
    if ((b==0)&&(c!=0))
      cout<<"Non esiste soluzione\n";
    if (b!=0)
      cout<<"Unica soluzione: "<<-c/b<<endl;
  }
  return 0;
}
