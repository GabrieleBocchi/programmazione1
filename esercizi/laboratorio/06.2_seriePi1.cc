#include <iostream>
using namespace std;

int main()
{
    int n;
    float ris = 0;
    cout << "Inserire un valore maggiore o uguale a 1: ";
    cin >> n;
    if (n >= 1)
    {
        for (float i = 1; i <= n; i++)
            ris += 1 / (i * i);
        cout << "Il valore della serie 1 / (i ^ 2) con i che va da 1 a " << n << " e' " << ris << endl;
    }
    else
        cout << "Il numero inserito deve essere maggiore o uguale a 1" << endl;
    return 0;
}