#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Inserire un numero maggiore o uguale a 0: ";
    cin >> n;
    if (n == 0 || n == 1)
    {
        cout << "Il numero inserito non e' primo" << endl;
        return 0;
    }
    else if (n > 1)
    {
        for (int i = 2; i <= n / 2; i++)
            if (n % i == 0)
            {
                cout << "Il numero inserito non e' primo" << endl;
                return 0;
            }
        cout << "Il numero inserito e' primo" << endl;
    }
    else
        cout << "Il numero inserito deve essere maggiore o uguale a 0" << endl;
    return 0;
}