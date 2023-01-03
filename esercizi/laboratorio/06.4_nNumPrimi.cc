#include <iostream>
using namespace std;

int main()
{
    int n;
    bool isPrime;
    cout << "Inserire un numero maggiore o uguale a 2: ";
    cin >> n;
    if (n >= 2)
    {
        cout << "I numeri primi compresi tra 1 e " << n << " sono: ";
        for (int i = 2; i <= n; i++)
        {
            isPrime = true;
            for (int j = 2; j <= i / 2 && isPrime == true; j++)
                if (i % j == 0)
                    isPrime = false;
            if (isPrime == true)
                cout << "  " << i << "  ";
        }
        cout << endl;
    }
    else
        cout << "Il numero inserito deve essere maggiore o uguale a 2" << endl;
    return 0;
}