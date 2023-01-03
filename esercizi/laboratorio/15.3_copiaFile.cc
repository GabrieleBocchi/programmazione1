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
    if (input.fail())
    {
        cout << "Il file non esiste" << endl;
        return 0;
    }
    output.open(argv[2], ios::out);
    char buffer[256];
    while (!input.eof())
    {
        input >> buffer;
        output << buffer << " ";
    }
    output << endl;
    input.close();
    output.close();
    cout << "File copiato correttamente" << endl;
    return 0;
}