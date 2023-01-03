#include <iostream>
using namespace std;

void conversioneRic(int n, int &ris);

int main()
{
    int n, ris = 0;
    cout << "Inserire un numero: ";
    cin >> n;
    conversioneRic(n, ris);
    cout << "Il numero " << n << " in formato binario corrisponde a: " << ris << endl;
    return 0;
}

void conversioneRic(int n, int &ris)
{
    if (n == 0)
        return;
    else
    {
        conversioneRic(n / 2, ris);
        ris = (ris * 10) + (n % 2);
    }
    return;
}