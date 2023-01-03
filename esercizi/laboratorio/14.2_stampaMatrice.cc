#include <iostream>
using namespace std;

const int righe = 5, colonne = 5;

int nRandom();

int main()
{
    srand(time(NULL));
    int matrix [righe] [colonne];
    cout << "Matrice: " << endl << endl;
    for (int i = 0; i < righe; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            matrix[i] [j] = nRandom();
            cout << matrix[i] [j] << "   ";
        }
        cout << endl << endl;
    }
    return 0;
}

int nRandom()
{
    return rand() % 10;
}