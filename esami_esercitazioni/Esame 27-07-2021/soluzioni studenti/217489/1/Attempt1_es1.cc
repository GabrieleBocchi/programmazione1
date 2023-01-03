#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        cout << "il numero di argomenti non è corretto";
    }
    else
    {
        fstream input, output;
        input.open(argv[1], ios::in);
        output.open(argv[2], ios::out);

        if(input.fail() || output.fail())
        {
            cout << "errore di apertura dei file";
        }
        else
        {
            char *buffer = new char [101];
            int contapartisniffer = 0;
            int conta = 0;
            bool check = true;
            int lunghezzabuffer = 0;
            int contatore = 0;

            while(!input.eof())
            {
                lunghezzabuffer = 0;
                check = true;
                input >> buffer;
                
                for(int i=0;i<101 && buffer[i] != '\0';i++)
                {
                    lunghezzabuffer++;
                }

                if(lunghezzabuffer == 19)
                {
                    if(buffer[4] == '-' && buffer[9] == '-' && buffer[14] == '-')
                    {
                        for(int i=0;i<4;i++)
                        {
                            if(buffer[i] >= '0' && buffer[i] <= '9')
                            {

                            }
                            else
                            {
                                check = false;
                            }
                        }
                        for(int i=5;i<9 && check == true;i++)
                        {
                            if(buffer[i] >= '0' && buffer[i] <= '9')
                            {
                                
                            }
                            else
                            {
                                check = false;
                            }
                        }
                        for(int i=10;i<14 && check == true;i++)
                        {
                            if(buffer[i] >= '0' && buffer[i] <= '9')
                            {
                                
                            }
                            else
                            {
                                check = false;
                            }
                        }
                        for(int i=15;i<19 && check == true;i++)
                        {
                            if(buffer[i] >= '0' && buffer[i] <= '9')
                            {
                                
                            }
                            else
                            {
                                check = false;
                            }
                        }
                    }
                    else
                    {
                        check = false;
                    }
                }
                else
                {
                    check = false;
                }

                if(check == true)
                {
                    contatore++;
                }
            }
            output << contatore;
            delete[] buffer;
        }
        input.close();
        output.close();
    }
}