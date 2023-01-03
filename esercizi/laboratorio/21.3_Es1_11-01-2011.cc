#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv [])
{
    if (argc != 2)
    {
        cout << "Numero di argomenti inseriti errato" << endl;
        return 0;
    }
    fstream file;
    file.open(argv[1], ios::in | ios::out);
    if (file.fail())
    {
        cout << "Il file non esiste" << endl;
        return 0;
    }
    char parola[10];
    int risultato = 0, stringheTotali = 0;
    while (file >> parola)
    {
        for (int j = 0; parola[j] != '\0'; j++)
            risultato++;
        stringheTotali++;
    }
    file.clear();
    file.app;
    if (stringheTotali != 0)
    {
        risultato /= stringheTotali;
        file << endl;
        for (int i = 0; i < risultato; i++)
            file << '*';
    }
    cout << "File modificato correttamente" << endl;
    file.close();
    return 0;
}