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
    file.open(argv[1], ios::in);
    if (file.fail())
    {
        cout << "Il file non esiste" << endl;
        return 0;
    }
    int dimArray = 26;
    int *array = new int [dimArray];
    for (int i = 0; i < dimArray; i++)
        array[i] = 0;
    char carattere;
    file.get(carattere);
    do
    {
        if (carattere >= 65 && carattere <= 90)
            array[carattere - 65]++;
        else if (carattere >= 97 && carattere <= 122)
            array[carattere - 97]++;
        file.get(carattere);
    } while (!file.eof());
    cout << "Conteggio lettere presenti nel file: " << endl << endl;
    for (int i = 0; i < dimArray; i++)
        cout << char(i + 65) << " = " << array[i] << endl;
    file.close();
    delete [] array;
    return 0;
}