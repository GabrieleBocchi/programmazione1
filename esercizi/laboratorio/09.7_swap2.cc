#include <iostream>
using namespace std;

void scambiaBit(short &n1, short &n2);

int main()
{
    short n1, n2;
    cout << "Inserire il primo numero: ";
    cin >> n1;
    cout << "Inserire il secondo numero: ";
    cin >> n2;
    short temp = n1;
    scambiaBit(n1, n2);
    scambiaBit(n2, temp);
    cout << "Scambiando gli 8 bit meno significativi dei due numeri inseriti, i numeri risultanti sono " << n1 << " e " << n2 << endl;
    return 0;
}

void scambiaBit(short &n1, short &n2)
{
    short temp_n2 = n2, add;
    for (int i = 1; i <= 8; i++)
        n1 /= 2;
    for (int i = 1; i <= 8; i++)
        n1 *= 2;
    for (int i = 1; i <= 8; i++)
    {
        add = 1;
        for (int j = 1; j <= i - 1; j++)
            add *= 2;
        add *= temp_n2 % 2;
        n1 += add;
        temp_n2 /= 2;
    }
    return;
}