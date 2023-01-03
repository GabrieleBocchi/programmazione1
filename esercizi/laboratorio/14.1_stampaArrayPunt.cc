#include <iostream>
using namespace std;

int nRandom();
void inizializza(int *p_array, const int dimArray);
void stampaArray(int *p_array, const int dimArray);

int main()
{
    srand(time(NULL));
    const int dimArray = 10;
    int array [dimArray];
    int *p_array = array;
    inizializza(p_array, dimArray);
    stampaArray(p_array, dimArray);
    return 0;
}

int nRandom()
{
    return rand() % 10;
}

void inizializza(int *p_array, const int dimArray)
{
    for (int i = 0; i < dimArray; i++)
        *(p_array + i) = nRandom();
    return;
}

void stampaArray(int *p_array, const int dimArray)
{
    cout << "Array: " << endl << endl;
    for (int i = 0; i < dimArray; i++)
        cout << "Array[" << i << "] = " << *(p_array + i) << endl;
    return;
}