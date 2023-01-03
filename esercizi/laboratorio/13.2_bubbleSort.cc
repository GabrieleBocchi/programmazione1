#include <iostream>
using namespace std;

int nRandom();
void bubbleSort(int array[], const int dimArray);

int main()
{
    srand(time(NULL));
    const int dimArray = 10;
    int array [dimArray];
    int *p_array;
    p_array = array;
    cout << "Array: " << endl << endl;
    for (int i = 0; i < dimArray; i++)
    {
        array[i] = nRandom();
        cout << "Array[" << i << "] = " << array[i] << endl;
    }
    bubbleSort(p_array, dimArray);
    cout << endl << "Array ordinato con l'algoritmo Bubble Sort: " << endl << endl;
    for (int i = 0; i < dimArray; i++)
        cout << "Array[" << i << "] = " << array[i] << endl;
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