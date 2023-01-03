#include <iostream>
using namespace std;

int nRandom();
void bubbleSort(int array[], const int dimArray);
void merge(int array1[], const int dimArray1, int array2[], const int dimArray2, int array3[]);

int main()
{
    srand(time(NULL));
    const int dimArray1 = 10;
    const int dimArray2 = 10;
    int array1 [dimArray1];
    int array2 [dimArray2];
    int array3 [dimArray1 + dimArray2];
    int *p_array1;
    p_array1 = array1;
    int *p_array2;
    p_array2 = array2;
    int *p_array3;
    p_array3 = array3;
    for (int i = 0; i < dimArray1; i++)
        array1[i] = nRandom();
    bubbleSort(p_array1, dimArray1);
    for (int i = 0; i < dimArray2; i++)
        array2[i] = nRandom();
    bubbleSort(p_array2, dimArray2);
    cout << "Array1 ordinato con l'algoritmo Bubble Sort: " << endl << endl;
    for (int i = 0; i < dimArray1; i++)
        cout << "Array1[" << i << "] = " << array1[i] << endl;
    cout << endl << "Array2 ordinato con l'algoritmo Bubble Sort: " << endl << endl;
    for (int i = 0; i < dimArray2; i++)
        cout << "Array2[" << i << "] = " << array2[i] << endl;
    merge(array1, dimArray1, array2, dimArray2, p_array3);
    cout << endl << "Merge di Array1 e Array2: " << endl << endl;
    for (int i = 0; i < dimArray1 + dimArray2; i++)
        cout << "Array3[" << i << "] = " << array3[i] << endl;
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

void merge(int array1[], const int dimArray1, int array2[], const int dimArray2, int array3[])
{
    int indice1 = 0, indice2 = 0;
    for (int i = 0; i < dimArray1 + dimArray2; i++)
    {
        if (indice1 >= dimArray1)
        {
            array3[i] = array2[indice2];
            indice2++;
        }
        else if (indice2 >= dimArray2)
        {
            array3[i] = array1[indice1];
            indice1++;
        }
        else if (array1[indice1] <= array2[indice2])
        {
            array3[i] = array1[indice1];
            indice1++;
        }
        else
        {
            array3[i] = array2[indice2];
            indice2++;
        }
    }
    return;
}