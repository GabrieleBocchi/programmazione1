#include <iostream>
#include <fstream>
#include "18.1_cifrCesare.h"
using namespace std;

int main(int argc, char *argv [])
{
    if (argc != 4)
    {
        cout << "Numero di argomenti inseriti errato" << endl;
        return 0;
    }
    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out | ios::trunc);
    if (input.fail())
        {
            cout << endl << "Il file non esiste" << endl;
            return 0;
        }
    int key = atoi(argv[3]) % 26;
    int scelta;
    cout << "Vuoi cifrare o decifrare il messaggio?" << endl;
    cout << "Per cifrarlo inserisci 1, per decifrarlo inserisci 2: ";
    cin >> scelta;
    char parola[64];
    if (scelta == 1)
    {
        while (!input.eof())
        {
            input >> parola;
            crypt(parola, key);
            output << parola << " ";
        }
        cout << endl << "Messaggio cifrato correttamente" << endl;
    }
    else if (scelta == 2)
    {
        while (!input.eof())
        {
            input >> parola;
            decrypt(parola, key);
            output << parola << " ";
        }
        cout << endl << "Messaggio decifrato correttamente" << endl;
    }
    else
    {
        cout << endl << "Numero inserito errato" << endl;
        return 0;
    }
    input.close();
    output.close();
    return 0;
}