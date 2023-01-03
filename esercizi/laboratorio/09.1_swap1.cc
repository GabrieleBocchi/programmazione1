#include <iostream>
using namespace std;

void swap(double *n1, double *n2);

int main()
{
    double n1, n2;
    cout << "Inserire il primo numero reale: ";
    cin >> n1;
    cout << "Inserire il secondo numero reale: ";
    cin >> n2;
    swap(&n1, &n2);
    cout << "I valori sono stati scambiati!" << endl << "Ora il primo valore e' " << n1 << " mentre il secondo e' " << n2 << endl;
    return 0;
}

void swap(double *n1, double *n2)
{
    *n1 = *n1 + *n2;
    *n2 = *n1 - *n2;
    *n1 = *n1 - *n2;
    return;
}