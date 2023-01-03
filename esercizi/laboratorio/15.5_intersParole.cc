#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char *argv [])
{
    if (argc != 3)
    {
        cout << "Numero di argomenti inseriti errato" << endl;
        return 0;
    }
    fstream input1, input2, output;
    input1.open(argv[1], ios::in);
    input2.open(argv[2], ios::in);
    output.open("output.txt", ios::in | ios::out | ios::trunc);
    if (input1.fail())
    {
        cout << "Il primo file non esiste" << endl;
        return 0;
    }
    if (input2.fail())
    {
        cout << "Il secondo file non esiste" << endl;
        return 0;
    }
    char parola1[100];
    char parola2[100];
    char parola3[100];
    bool giaTrovato1, giaTrovato2;
    while (!input1.eof())
    {
        giaTrovato1 = false;
        giaTrovato2 = false;
        input1 >> parola1;
        output.clear();
        output.seekg(0, ios::beg);
        while (!output.eof())
        {
            output >> parola3;
            if (strcmp(parola1, parola3) == 0)
                giaTrovato1 = true;
        }
        output.clear();
        input2.clear();
        input2.seekg(0, ios::beg);
        while (!input2.eof() && giaTrovato1 == false && giaTrovato2 == false)
        {
            input2 >> parola2;
            if (strcmp(parola1, parola2) == 0)
            {
                output << parola1 << " ";
                giaTrovato2 = true;
            }
        }
    }
    input1.close();
    input2.close();
    output.close();
    cout << "File generato correttamente" << endl;
    return 0;
}