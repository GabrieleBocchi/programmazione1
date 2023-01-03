#include <iostream>
using namespace std;

int nRandom();
void bubbleSort(int array[], const int dimArray);
int binarySearchRic(int array[], int inizio, int fine, int n);

int main()
{
    srand(time(NULL));
    const int dimArray = 10;
    int array [dimArray];
    int *p_array;
    p_array = array;
    for (int i = 0; i < dimArray; i++)
        array[i] = nRandom();
    bubbleSort(p_array, dimArray);
    cout << "Array ordinato con l'algoritmo Bubble Sort: " << endl << endl;
    for (int i = 0; i < dimArray; i++)
        cout << "Array[" << i << "] = " << array[i] << endl;
    int n, indice, inizio = 0, fine = dimArray - 1;
    cout << endl << "Inserire un numero da 0 a 9 che si vuole ricercare nell'array: ";
    cin >> n;
    if (n >= 0 && n <= 9)
    {
        indice = binarySearchRic(array, inizio, fine, n);
        if (indice != -1)
            cout << endl << "La prima occorrenza in cui e' presente il numero " << n << " nell'array e' alla posizione " << indice << endl;
        else
            cout << endl << "Il numero " << n << " non e' presente nell'array " << endl;
    }
    else
        cout << endl << "Il numero " << n << " non e' presente nell'array " << endl;
    return 0;
}

int nRandom()
{
    return rand() % 10;
}

void bubbleSort(int array[], const int dimArray)
{
    bool order = false;
    while (order == false)
    {
        order = true;
        for (int i = 1; i < dimArray; i++)
            if (array[i] < array[i - 1])
            {
                array[i] = array[i] + array[i - 1];
                array[i - 1] = array[i] - array[i - 1];
                array[i] = array[i] - array[i - 1];
                order = false;
            }
    }
    return;
}

int binarySearchRic(int array[], int inizio, int fine, int n)
{
    int medio = (inizio + fine) / 2;
    if (fine - inizio <= 1)
    {
        if (array[inizio] == n)
            return inizio;
        else if (array[fine] == n)
            return fine;
        else
            return -1;
    }
    else if (array[medio] >= n)
        return binarySearchRic(array, inizio, medio, n);
    else
        return binarySearchRic(array, medio, fine, n);
}