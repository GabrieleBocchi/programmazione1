#include <iostream>
using namespace std;

int nRandom();

int main()
{
    srand(time(NULL));
    const int dimArray = 10;
    int array [dimArray];
    cout << "Array: " << endl << endl;
    for (int i = 0; i < dimArray; i++)
    {
        array[i] = nRandom();
        cout << "Array[" << i << "] = " << array[i] << endl;
    }
    int valore, indice;
    cout << endl << "Inserire un nuovo valore da inserire nell'array: ";
    cin >> valore;
    cout << "Inserire l'indice dell'array in cui si vuole inserire il valore (da 0 a " << dimArray - 1 << "): ";
    cin >> indice;
    if (indice >= 0 && indice < dimArray)
    {
        for (int i = dimArray - 1; i > indice; i--)
            array[i] = array[i - 1];
        array[indice] = valore;
        cout << endl << "Array modificato: " << endl << endl;
        for (int i = 0; i < dimArray; i++)
            cout << "Array[" << i << "] = " << array[i] << endl;
    }
    else
        cout << "L'indice deve essere compreso fra 0 e " << dimArray - 1 << endl;
    return 0;
}

int nRandom()
{
    return rand() % 10;
}