// Giovanni: il programma ritorna risultato errato su alcuni casi di test.
// Fare riferimento alla soluzione ufficiale per un possibile svolgimento.
// Vedere commenti nel codice.

#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        cout << "errore! Il numero di argomenti non è corretto!";
        exit(0);
    }
    else
    {
        fstream input, output;
        input.open(argv[1], ios::in);
        output.open(argv[2], ios::out);
        if(input.fail() || output.fail())
        {
            cout << "errore di apertura del file di input/output";
            exit(0);
        }
        else
        {
            char *buffer = new char [100];
            bool check = true;
            int contaI = 0;
            bool proxI = false;
            int contacaratteri = 0;

            while(!input.eof())
            {
                input >> buffer;

                for(int i=0;i<100 && buffer[i] != '\0';i++)
                {
                    if(buffer[i] == 'M' || buffer[i] == 'I' || buffer[i] == 'U')
                    {
                        // Giovanni: proxI una volta settato a true non viene più
                        // cambiato. Dovrebbe essere settato a false ogni volta che
                        // si passa ad un nuovo carattere (sempre che il nuovo carattere
                        // non sia a sua volta una I)
                        if(proxI == true && buffer[i] == 'M')
                        {
                            check = false;
                        }
                        if(buffer[i] == 'I')
                        {
                            contaI++;
                            proxI = true;
                        }
                    }
                    else
                    {
                        check = false;
                    }
                    contacaratteri++;
                }

                if(contaI != 0)
                {
                    if(contaI % 2 == 0) //se è dispari o = 0 VA BENE
                    {
                        cout << "prova";
                        check = false;
                    }
                }


                if(buffer[0] == 'M')
                {
                    if(buffer[contacaratteri-1] != 'U')
                    {
                        check = false;
                    }
                }

                if(check == false)
                {
                    output << buffer << endl;
                    cout << buffer << endl;
                }
                contaI = 0;
                contacaratteri = 0;
                check = true;
                proxI = false;
            }

            delete[] buffer;
        }
    }
}
