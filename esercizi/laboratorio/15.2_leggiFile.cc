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
    char buffer[256];
    while (!file.eof())
    {
        file >> buffer;
        cout << buffer << " ";
    }
    cout << endl;
    file.close();
    return 0;
}