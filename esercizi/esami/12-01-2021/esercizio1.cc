#include <iostream>
#include <fstream>
using namespace std;

int lettere(char parola[]);

const int maxParole = 10000;
const int maxLettere = 100;

int main(int argc, char *argv [])
{
    if (argc != 3)
    {
        cout << "Numero di argomenti inseriti errato" << endl;
        return 0;
    }
    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out | ios::trunc);
    if (input.fail())
    {
        cout << "Il file non esiste" << endl;
        return 0;
    }
    int contParolePari = 0, lunghezza;
    char parola[maxLettere];
    char array[maxParole] [maxLettere];
    while (input >> parola)
    {
        lunghezza = lettere(parola);
        if(lunghezza % 2 == 0)
        {
            for (int i = 0; i < lunghezza; i++)
                array[contParolePari] [i] = parola[i];
            contParolePari++;
        }
    }
    for (int i = contParolePari - 1; i >= 0; i--)
        output << array[i] << " ";
    input.close();
    output.close();
    return 0;
}

int lettere(char parola[])
{
    int cont = 0;
    for (int i = 0; parola[i] != '\0'; i++)
        cont++;
    return cont;
}