#include <iostream>
using namespace std;

const int righe = 3, colonne = 3;

int nRandom();
int determinanteSarrus(int matrix[] [colonne]);
int calcolaDiagonale(int matrix[] [colonne], int colonnaPartenza, bool diagonaleNormale);

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
    int determinante = determinanteSarrus(matrix);
    cout << "Il determinante di questa matrice e' " << determinante << endl;
    return 0;
}

int nRandom()
{
    return rand() % 10;
}

int determinanteSarrus(int matrix[] [colonne])
{
    return calcolaDiagonale(matrix, 0, true) +
    calcolaDiagonale(matrix, 1, true) +
    calcolaDiagonale(matrix, 2, true) -
    calcolaDiagonale(matrix, 0, false) -
    calcolaDiagonale(matrix, 1, false) -
    calcolaDiagonale(matrix, 2, false);
}

int calcolaDiagonale(int matrix[] [colonne], int colonnaPartenza, bool diagonaleNormale)
{
    int ris = 1;
    if (diagonaleNormale == true)
        for (int i = 0; i < righe; i++)
            ris *= matrix[i] [(colonnaPartenza + i) % 3];
    else
        for (int i = righe - 1; i >= 0; i--)
            ris *= matrix[i] [(colonnaPartenza + righe - 1 - i) % 3];
    return ris;
}