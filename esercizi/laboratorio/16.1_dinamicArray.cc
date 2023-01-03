#include <iostream>
using namespace std;

int *generate_numbers(int N);

int main()
{
    srand(time(NULL));
    int N;
    cout << "Inserire un numero maggiore o uguale a 1: ";
    cin >> N;
    if(N >= 1)
    {
        int *array = generate_numbers(N);
        cout << endl << "Array: " << endl << endl;
        for (int i = 0; i < N; i++)
            cout << "Array[" << i << "] = " << array[i] << endl;
        delete [] array;
    }
    else
        cout << "Il numero inserito deve essere maggiore o uguale a 1" << endl;
    return 0;
}

int *generate_numbers(int N)
{
    int *array = new int[N];
    for (int i = 0; i < N; i++)
        array[i] = rand() % 10;
    return array;
}