#include <iostream>
#include <climits>
using namespace std;

int max(int n1, int n2 = INT_MIN, int n3 = INT_MIN, int n4 = INT_MIN, int n5 = INT_MIN);

int main()
{
    int n1, n2, n3, n4, n5, scelta, massimo;
    cout << "Quanti numeri si vogliono inserire da 1 a 5? ";
    cin >> scelta;
    switch (scelta)
    {
        case 1:
        cout << "Inserire il primo numero: ";
        cin >> n1;
        massimo = max(n1);
        break;
        case 2:
        cout << "Inserire il primo numero: ";
        cin >> n1;
        cout << "Inserire il secondo numero: ";
        cin >> n2;
        massimo = max(n1, n2);
        break;
        case 3:
        cout << "Inserire il primo numero: ";
        cin >> n1;
        cout << "Inserire il secondo numero: ";
        cin >> n2;
        cout << "Inserire il terzo numero: ";
        cin >> n3;
        massimo = max(n1, n2, n3);
        break;
        case 4:
        cout << "Inserire il primo numero: ";
        cin >> n1;
        cout << "Inserire il secondo numero: ";
        cin >> n2;
        cout << "Inserire il terzo numero: ";
        cin >> n3;
        cout << "Inserire il quarto numero: ";
        cin >> n4;
        massimo = max(n1, n2, n3, n4);
        break;
        case 5:
        cout << "Inserire il primo numero: ";
        cin >> n1;
        cout << "Inserire il secondo numero: ";
        cin >> n2;
        cout << "Inserire il terzo numero: ";
        cin >> n3;
        cout << "Inserire il quarto numero: ";
        cin >> n4;
        cout << "Inserire il quinto numero: ";
        cin >> n5;
        massimo = max(n1, n2, n3, n4, n5);
        break;
        default:
        cout << "Il numero inserito deve essere compreso tra 1 e 5" << endl;
        return 0;
    }
    cout << "Il numero piu' grande che e' stato inserito e': " << massimo << endl;
    return 0;
}

int max(int n1, int n2, int n3, int n4, int n5)
{
    int massimo = n1;
    if (n2 > massimo)
        massimo = n2;
    if (n3 > massimo)
        massimo = n3;
    if (n4 > massimo)
        massimo = n4;
    if (n5 > massimo)
        massimo = n5;
    return massimo;
}