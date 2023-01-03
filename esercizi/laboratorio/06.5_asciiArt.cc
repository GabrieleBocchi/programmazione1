#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Inserire un numero maggiore o uguale a 1: ";
    cin >> n;
    if (n >= 1)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n - i; j++)
                cout << " ";
            for (int j = 1; j <= 2 * i - 1; j++)
                cout << "*";
            cout << endl;
        }
    }
    else
        cout << "Il numero inserito deve essere maggiore o uguale a 1" << endl;
    return 0;
}