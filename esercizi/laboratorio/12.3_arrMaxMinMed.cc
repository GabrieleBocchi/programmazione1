#include <iostream>
using namespace std;

int nRandom();

int main()
{
    srand(time(NULL));
    const int dimArray = 10;
    int max = 0, min = 9;
    float media = 0;
    int array [dimArray];
    cout << "Array: " << endl << endl;
    for (int i = 0; i < dimArray; i++)
    {
        array[i] = nRandom();
        cout << "Array[" << i << "] = " << array[i] << endl;
        if (max < array[i])
            max = array[i];
        if (min > array[i])
            min = array[i];
        media += array[i];
    }
    media /= dimArray;
    cout << endl << "Il valore piu' grande contenuto nell'array e': " << max << endl;
    cout << "Il valore piu' piccolo contenuto nell'array e': " << min << endl;
    cout << "La media dei valori contenuti nell'array e': " << media << endl;
    return 0;
}

int nRandom()
{
    return rand() % 10;
}