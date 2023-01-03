#include <iostream>
#include <cstdlib>
using namespace std;

int generaNumero();
bool controllaPattern(int pattern[], int dimPattern, int testo[], int dimTesto);

int main()
{
    srand(time(NULL));
    int dimPattern = 1, dimTesto = 10;
    int pattern[dimPattern];
    int testo[dimTesto];
    cout << "Array Pattern: " << endl << endl;
    cout << "[";
    for (int i = 0; i < dimPattern; i++)
    {
        pattern[i] = generaNumero();
        cout << "  " << pattern[i] << "  ";
    }
    cout << "]";
    cout << endl << endl << "Array Testo: " << endl << endl;
    cout << "[";
    for (int i = 0; i < dimTesto; i++)
    {
        testo[i] = generaNumero();
        cout << "  " << testo[i] << "  ";
    }
    cout << "]";
    if (controllaPattern(pattern, dimPattern, testo, dimTesto))
        cout << endl << endl << "L'array Pattern e' contenuto nell'array Testo" << endl;
    else
        cout << endl << endl << "L'array Pattern non e' contenuto nell'array Testo" << endl;
    return 0;
}

int generaNumero()
{
    return rand() % 10;
}

bool controllaPattern(int pattern[], int dimPattern, int testo[], int dimTesto)
{
    bool result = false;
    for (int i = 0; i < dimTesto - dimPattern + 1 && !result; i++)
    {
        if (testo[i] == pattern[0])
        {
            result = true;
            for (int j = 1; j < dimPattern && result; j++)
                if (pattern[j] != testo[i + j])
                    result = false;
        }
    }
    return result;
}