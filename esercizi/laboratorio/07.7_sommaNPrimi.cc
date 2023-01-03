#include <iostream>
using namespace std;

int main()
{
    int n;
    bool isPrime;
    cout << "Inserire un numero: ";
    cin >> n;
    if (n >= 4)
    {
        for (int i = 2; i <= n / 2; i++)
        {
            isPrime = true;
            for (int j = 2; j <= i / 2 && isPrime == true; j++)
                if (i % j == 0)
                    isPrime = false;
            if (isPrime == true)
            {
                for (int k = i; k <= n - i; k++)
                {
                    isPrime = true;
                    for (int s = 2; s <= k / 2 && isPrime == true; s++)
                        if (k % s == 0)
                            isPrime = false;
                    if (isPrime == true)
                        if (i + k == n)
                        {
                            cout << "Il numero " << n << " puo' essere scritto come somma di due numeri primi, ovvero " << i << " e " << k << endl;
                            return 0;
                        }
                }
            }
        }
        cout << "Il numero inserito non puo' essere scritto come somma di due numeri primi" << endl;
    }
    else
        cout << "Il numero inserito non puo' essere scritto come somma di due numeri primi" << endl;
    return 0;
}