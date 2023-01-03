#include <iostream>
using namespace std;

bool isPalindromo(int array[], int dim, int inizio, int fine);

int main()
{
    int dim;
    cout << "Inserire quanti numeri si vuole aggiungere all'array: ";
    cin >> dim;
    if (dim < 0 || dim > 100)
    {
        cout << endl << "La dimensione dell'array deve essere compresa fra 0 e 100" << endl;
        return 0;
    }
    int array[dim];
    for (int i = 0; i < dim; i++)
    {
        cout << endl << "Inserire numero: ";
        cin >> array[i];
    }
    if (isPalindromo(array, dim, 0, dim - 1))
        cout << endl << "La sequenza di numeri contenuta nell'array e' palindroma" << endl;
    else
        cout << endl << "La sequenza di numeri contenuta nell'array non e' palindroma" << endl;
    return 0;
}

bool isPalindromo(int array[], int dim, int inizio, int fine)
{
    if (inizio >= fine)
        return true;
    else if (array[inizio] == array[fine])
        return isPalindromo(array, dim, ++inizio, --fine);
    else
        return false;
}