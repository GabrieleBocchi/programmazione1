// GDT: il codice non riporta il risultato corretto in alcuni casi di test.
// Vedi commenti nel codice

#include <iostream>
#include <fstream>



using namespace std;
const int MAX_CARATTERI = 201;


int lunghezza_stringa(char c[MAX_CARATTERI])
{
    int i = 0;
    int lunghezza = 0;
    while(c[i]!='\0')
    {
        ++lunghezza;
        ++i;
    }
    return lunghezza;
}

int main(int argc, char * argv[])
{
    if(argc!=3)
    {
        cerr << "Usage: ./a.out input.txt output.txt\n";
    }
    else
    {
        fstream input,output;
        input.open(argv[1],ios::in);
        output.open(argv[2],ios::out);
        //Assumo che non ci siano problemi con il file di output
        if(input.fail())
        {
            cerr << "Errore nel file di input\n";
        }
        else
        {
            char buffer[MAX_CARATTERI];
            input >> buffer;
            if(buffer[0]>='a' && buffer[0]<='z')
            {
                buffer[0] = buffer[0] -('a'-'A');
            }
            int l = lunghezza_stringa(buffer);
            while(!input.eof())
            {
                output << buffer << " ";
                if(buffer[l-1]== ',' || buffer[l-1] == ':' || buffer[l-1] ==';')
                {
                    input >> buffer;
                    // GDT: dovrebbe essere buffer[0] <= 'Z'
                    // Inoltre, se la parola inizia già con una lettera minuscola,
                    // la variabile l non viene mai resettata. Dovrebbe essere fuori
                    // dall'if la chiamata l = lunghezza_stringa(buffer)
                    if(buffer[0]>='A' && buffer[0]<='z')
                    {
                        buffer[0] = buffer[0] -('A'-'a');
                        //l = lunghezza_stringa(buffer);
                    }
                    //GDT: qua l = lunghezza_stringa(buffer);
                }
                else
                {
                    input >> buffer;
                    l = lunghezza_stringa(buffer);
                }
            }
        }
        input.close();
        output.close();
    }
    return 0;
}
