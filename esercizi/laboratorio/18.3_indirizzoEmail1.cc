#include <iostream>
#include <fstream>
#include "18.3_indirizzoEmail.h"
using namespace std;

int main(int argc, char *argv [])
{
    if (argc != 2)
    {
        cout << "Numero di argomenti inseriti errato" << endl;
        return 0;
    }
    fstream file;
    file.open(argv[1], ios::in);
    if (file.fail())
    {
        cout << "Il file non esiste" << endl;
        return 0;
    }
    char parola[256];
    int cont = 0;
    file >> parola;
    while (!file.eof())
    {
        if (check(parola))
        {
            cout << "Indirizzo email trovato: " << parola << endl;
            cont++;
        }
        file >> parola;
    }
    if (cont == 0)
        cout << "Nessun indirizzo email trovato" << endl;
    file.close();
    return 0;
}