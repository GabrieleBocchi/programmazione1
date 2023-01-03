#include <iostream>
using namespace std;

int main()
{
    int P, Q;
    cout << "Inserire il valore di P(0 = Falso, 1 = Vero): ";
    cin >> P;
    cout << "Inserire il valore di Q(0 = Falso, 1 = Vero): ";
    cin >> Q;
    cout << P << " --> " << Q << " = " << (!P || Q) << endl;
    return 0;
}