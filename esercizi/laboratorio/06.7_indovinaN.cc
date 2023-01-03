#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    srand (time (NULL));
    int n = rand() % 10 + 1;
    int scelta;
    cout << "Indovina il numero da 1 a 10 che ho generato: ";
    do
    {
        cin >> scelta;
        if (scelta == n)
            cout << "Congratulazioni, hai indovinato il numero" << endl;
        else
            cout << "Mi dispiace, non hai indovinato, riprova: ";
    } while (scelta != n);
    return 0;
}