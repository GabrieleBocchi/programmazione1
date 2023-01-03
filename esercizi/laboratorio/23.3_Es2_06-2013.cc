#include <iostream>
using namespace std;

void riempiArray(int *array, int dim, int pos);

int main()
{
    int dim;
    cout << "Inserire un numero maggiore o uguale a 1: ";
    cin >> dim;
    if (dim < 1)
    {
        cout << endl << "Il numero inserito deve essere maggiore o uguale a 1" << endl;;
        return 0;
    }
    int *array = new int[dim];
    cout << endl << "I primi " << dim << " numeri esagonali partendo da 0 sono: ";
    riempiArray(array, dim, 0);
    cout << endl;
    delete [] array;
    return 0;
}

void riempiArray(int *array, int dim, int pos)
{
    array[pos] = (pos * (2 * pos - 1));
    cout << array[pos] << "  ";
    if (pos + 1 == dim)
        return;
    else
        riempiArray(array, dim, ++pos);
    return;
}