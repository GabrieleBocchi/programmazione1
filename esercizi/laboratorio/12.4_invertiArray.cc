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
    for (int i = 0; i < dimArray / 2; i++)
    {
        array[i] = array[i] + array[dimArray - i - 1];
        array[dimArray - i - 1] = array[i] - array[dimArray - i - 1];
        array[i] = array[i] - array[dimArray - i - 1];
    }
    cout << endl << "Array invertito: " << endl << endl;
    for (int i = 0; i < dimArray; i++)
        cout << "Array[" << i << "] = " << array[i] << endl;
    return 0;
}

int nRandom()
{
    return rand() % 10;
}