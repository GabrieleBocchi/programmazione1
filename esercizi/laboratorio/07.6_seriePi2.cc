#include <iostream>
using namespace std;

int main()
{
    float n, ris = 1, preced = 0;
    cout << "Inserire un valore compreso tra 0 e 1 esclusi: ";
    cin >> n;
    if (n > 0 && n < 1)
    {
        for (float i = 2; (ris - preced) > n; i++)
        {
            preced = ris;
            ris += 1 / (i * i);
        }
        cout << "Il valore della serie 1 / (i ^ 2) con una precisione di " << n << " e' " << preced << endl;
    }
    else
        cout << "Il numero inserito deve essere compreso tra 0 e 1 esclusi" << endl;
    return 0;
}