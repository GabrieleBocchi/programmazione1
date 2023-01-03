#include <iostream>
using namespace std;

int ** generate_matrix(int R, int C);

int main()
{
    srand(time(NULL));
    int R, C;
    cout << "Inserire il numero di righe che avra' la matrice: ";
    cin >> R;
    cout << "Inserire il numero di colonne che avra' la matrice: ";
    cin >> C;
    if (R >= 1 && C >= 1)
    {
        int **matrix = generate_matrix(R, C);
        cout << endl << "Matrice: " << endl << endl;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
                cout << matrix[i] [j] << "   ";
            cout << endl << endl;
        }
        for (int i = 0; i < R; i++)
            delete [] matrix[i];
        delete [] matrix;
    }
    else
        cout << "Il numero di righe e di colonne deve essere maggiore o uguale a 1" << endl;
    return 0;
}

int ** generate_matrix(int R, int C)
{
    int **matrix = new int *[R];
    for (int i = 0; i < R; i++)
        matrix[i] = new int [C];
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            matrix[i] [j] = rand() % 10;
    return matrix;
}