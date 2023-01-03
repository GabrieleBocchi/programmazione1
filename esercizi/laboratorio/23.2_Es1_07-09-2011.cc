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
    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out | ios::trunc);
    if (input.fail())
    {
        cout << "Il file non esiste" << endl;
        return 0;
    }
    char carattere;
    bool correggi = true;
    input >> noskipws;
    while (input >> carattere)
    {
        if (correggi)
        {
            if (carattere >= 97 && carattere <= 122)
                carattere -= 32;
            if (carattere >= 65 && carattere <= 90)
                correggi = false;
        }
        if (!correggi && (carattere == '.' || carattere == '?' || carattere == '!'))
            correggi = true;
        output << carattere;
    }
    cout << "Il testo e' stato corretto" << endl;
    input.close();
    output.close();
    return 0;
}