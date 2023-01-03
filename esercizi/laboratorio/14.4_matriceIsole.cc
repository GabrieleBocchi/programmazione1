#include <iostream>
using namespace std;

const int righe = 10, colonne = 10;

int nRandom();
int nIsole(int matrix[] [colonne]);

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
    int isole = nIsole(matrix);
    cout << "Nella matrice sono presenti " << isole << " isole" << endl;
    return 0;
}

int nRandom()
{
    return rand() % 2;
}

int nIsole(int matrix[] [colonne])
{
    int isole = 0;
    for (int i = 0; i < righe; i++)
        for (int j = 0; j < colonne; j++)
            if (matrix[i] [j] == 1 &&
            (((i - 1 >= 0 && i - 1 <= righe - 1 && j >= 0 && j <= colonne - 1) && matrix[i - 1] [j] == 0) || (i - 1 < 0 || i - 1 > righe - 1 || j < 0 || j > colonne - 1)) &&
            (((i - 1 >= 0 && i - 1 <= righe - 1 && j + 1 >= 0 && j + 1 <= colonne - 1) && matrix[i - 1] [j + 1] == 0) || (i - 1 < 0 || i - 1 > righe - 1 || j + 1 < 0 || j + 1 > colonne - 1)) &&
            (((i >= 0 && i <= righe - 1 && j + 1 >= 0 && j + 1 <= colonne - 1) && matrix[i] [j + 1] == 0) || (i < 0 || i > righe - 1 || j + 1 < 0 || j + 1 > colonne - 1)) &&
            (((i + 1 >= 0 && i + 1 <= righe - 1 && j + 1 >= 0 && j + 1 <= colonne - 1) && matrix[i + 1] [j + 1] == 0) || (i + 1 < 0 || i + 1 > righe - 1 || j + 1 < 0 || j + 1 > colonne - 1)) &&
            (((i + 1 >= 0 && i + 1 <= righe - 1 && j >= 0 && j <= colonne - 1) && matrix[i + 1] [j] == 0) || (i + 1 < 0 || i + 1 > righe - 1 || j < 0 || j > colonne - 1)) &&
            (((i + 1 >= 0 && i + 1 <= righe - 1 && j - 1 >= 0 && j - 1 <= colonne - 1) && matrix[i + 1] [j - 1] == 0) || (i + 1 < 0 || i + 1 > righe - 1 || j - 1 < 0 || j + 1 > colonne - 1)) &&
            (((i >= 0 && i <= righe - 1 && j - 1 >= 0 && j - 1 <= colonne - 1) && matrix[i] [j - 1] == 0) || (i < 0 || i > righe - 1 || j - 1 < 0 || j - 1 > colonne - 1)) &&
            (((i - 1 >= 0 && i - 1 <= righe - 1 && j - 1 >= 0 && j - 1 <= colonne - 1) && matrix[i - 1] [j - 1] == 0) || (i - 1 < 0 || i - 1 > righe - 1 || j - 1 < 0 || j - 1 > colonne - 1)))
                isole++;
    return isole;
}