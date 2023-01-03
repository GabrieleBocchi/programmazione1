#include <iostream>
using namespace std;

int nRandom();
int sequentialSearch(int array[], const int dimArray, int n);

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
    int n;
    cout << endl << "Inserire un numero che si vuole ricercare nell'array: ";
    cin >> n;
    int indice = sequentialSearch(array, dimArray, n);
    if (indice != -1)
        cout << endl << "La prima occorrenza in cui e' presente il numero " << n << " nell'array e' alla posizione " << indice << endl;
    else
        cout << endl << "Il numero " << n << " non e' presente nell'array " << endl;
    return 0;
}

int nRandom()
{
    return rand() % 10;
}

int sequentialSearch(int array[], const int dimArray, int n)
{
    for (int i = 0; i < dimArray; i++)
        if (array[i] == n)
            return i;
    return -1;
}