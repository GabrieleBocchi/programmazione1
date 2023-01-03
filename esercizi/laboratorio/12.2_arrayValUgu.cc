#include <iostream>
using namespace std;

int nRandom();

int main()
{
    srand(time(NULL));
    const int dimArray = 10;
    int cont = 0;
    int array1 [dimArray];
    int array2 [dimArray];
    cout << "Array1 e Array2: " << endl << endl;
    for (int i = 0; i < dimArray; i++)
    {
        array1[i] = nRandom();
        array2[i] = nRandom();
        if (array1[i] == array2[i])
            cont++;
        cout << "Array1[" << i << "] = " << array1[i] << endl;
        cout << "Array2[" << i << "] = " << array2[i] << endl << endl;
    }
    cout << "Nei due array ci sono " << cont << " valori uguali nello stesso indice" << endl;
    return 0;
}

int nRandom()
{
    return rand() % 10;
}