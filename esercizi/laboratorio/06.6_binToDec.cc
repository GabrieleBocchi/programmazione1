#include <iostream>
using namespace std;

int main()
{
    int n, t, ris = 0;
    cout << "Inserire un numero in formato binario: ";
    cin >> n;
    cout << n;
    for (int i = 0; n != 0; i++)
    {
        if (n % 10 == 1  || n % 10 == -1)
        {
            t = (n >= 0) - (n < 0);
            for (int j = 1; j <= i; j++)
                t *= 2;
            ris += t;
        }
        n /= 10;
    }
    cout << " in formato decimale equivale a " << ris << endl;
    return 0;
}