#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv [])
{
    if (argc != 3)
    {
        cout << "Numero di argomenti inseriti errato" << endl;
        return 0;
    }
    fstream input;
    input.open(argv[1], ios::in);
    if (input.fail())
    {
        cout << "Il file non esiste" << endl;
        return 0;
    }
    char lettera = *argv[2];
    char carattere;
    while (!input.eof())
    {
        input.get(carattere);
        if (carattere == lettera)
            cout << '?';
        else
            cout << carattere;
    }
    cout << endl;
    input.close();
    return 0;
}