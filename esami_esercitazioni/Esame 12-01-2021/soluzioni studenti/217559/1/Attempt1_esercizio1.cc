// GDT: il file di output non è conforme alle specifiche del testo d'esame. Fare
// riferimento alla soluzione ufficiale per lo svolgimento.

#include <iostream>
#include <fstream>

using namespace std;

bool CaricaParole(char *inputFile, char *outputFile);
int LunghezzaStringa(char *stringa);

int main(int argc, char *argv[])
{
    int returnValue = 0;
    if (argc != 3)
    {
        cout << "Errore, è necessario specificare due parametri per eseguire il programma" << endl;
        returnValue = 1;
    }
    else
    {
        CaricaParole(argv[1], argv[2]);
    }
    return returnValue;
}

bool CaricaParole(char *inputFile, char *outputFile)
{
    bool copiaEseguita = false;
    fstream in, out;
    in.open(inputFile, ios::in);
    if (in.fail())
    {
        cout << "Errore, impossibile aprire il file " << inputFile << endl;
    }
    else
    {
        out.open(outputFile, ios::out);
        if (out.fail())
        {
            cout << "Errore, impossibile scrivere sul file " << outputFile << endl;
        }
        else
        {
            char c[100];
            int i = 0;
            int lunghezzaParola;
            while (!in.eof())
            {
                in >> c;
                lunghezzaParola = LunghezzaStringa(c);
                if (lunghezzaParola <= 4 && lunghezzaParola > 0)
                {
                    i++;
                    out << c << " ";
                }
            }

            copiaEseguita = true;
        }
    }
    return copiaEseguita;
}

int LunghezzaStringa(char *stringa)
{
    int i = 0;
    while (stringa[i] != '\0' && i <= 5)
    {
        i++;
    }
    return i;
}
