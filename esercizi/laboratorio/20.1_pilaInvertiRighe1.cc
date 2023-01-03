#include <iostream>
#include <fstream>
#include "20.1_pilaInvertiRighe.h"
using namespace std;

int main(int argc, char *argv [])
{
    if (argc != 2)
    {
        cout << "Numero di argomenti inseriti errato" << endl;
        return 0;
    }
    fstream input, output;
    input.open(argv[1], ios::in);
    output.open("output.txt", ios::out | ios::trunc);
    if (input.fail())
    {
        cout << "Il file non esiste" << endl;
        return 0;
    }
    int n;
    init();
    while (input >> n)
        push(n);
    while (top(n))
    {
        output << n << endl;
        pop();
    }
    cout << "File copiato correttamente con le righe inverse" << endl;
    deinit();
    input.close();
    output.close();
    return 0;
}