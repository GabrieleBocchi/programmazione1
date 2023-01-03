#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        cerr << "errore, numero di file scorretto!";
    }
    else
    {
        fstream input, output;
        input.open(argv[1], ios::in);
        output.open(argv[2], ios::out);

        if(input.fail() || output.fail())
        {
            cerr << "errore di apertura di un file";
        }
        else
        {
            char carattere;
            input.get(carattere);
            int diff = 'A'-'a';

            if(carattere >= 'a' && carattere <= 'z')
            {
                carattere = carattere + diff;
            }
            output << carattere;
            bool check = false;

            while(!input.eof())
            {
                input.get(carattere);
                if(carattere == '.' || carattere == '?' || carattere == '!')
                {
                    output << carattere;
                    check = true;
                }
                else if(check == true)
                {
                    if(carattere == ' ' || carattere == '\n')
                    {
                        output << carattere;
                    }
                    else if(carattere >= 'a' && carattere <= 'z')
                    {
                        carattere = carattere + diff;
                        output << carattere;
                        check = false;
                    }
                    else if(carattere >= 'A' && carattere <= 'Z')
                    {
                        check = false;
                        output << carattere;
                    }
                }
                else
                {
                    output << carattere;
                }
            }
        }

        input.close();
        output.close();
    }
}