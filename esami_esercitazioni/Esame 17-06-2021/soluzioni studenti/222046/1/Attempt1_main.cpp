// Giovanni: il programma non ritorna risultati corretti in alcuni casi di test.
// Le condizioni di controllo non sono corrette. Vedi commenti nel codice.

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int controllalunghezza(char buffer[256])
{
    int i=0;
    while(buffer[i]!='\0')
    {
        i++;
    }
    return i;
}

int ControllaM(char buffer[256],int i)
{
    if(buffer[i+1]=='M')
        return true;
    else
        return false;
}

int contaI(char buffer[256])
{
    int i=0,contatoreI=0;
   while(buffer[i]!='\0')
    {
        if(buffer[i]=='I')
        {
            if(ControllaM(buffer,i))
                return 2;

            contatoreI++;
        }
        i++;
    }
    return contatoreI;
}


int main(int argc, char * argv[])
{
    if(argc!=3)
    {
        cout<<"Errore inserimento dati: ";
    }


    fstream lettura,scrittura;
    lettura.open(argv[1],ios::in);
    scrittura.open(argv[2],ios::out);

    if(lettura.fail())
    {
        cout<<"Il file dato in input non esiste ";
        lettura.close();
    }

    char buffer[256];
    while(!lettura.eof())
    {
        bool primacond=false,secondacond=false;

        lettura>>buffer;

        // Giovanni: in questo modo, solo le parole che iniziano per M saranno
        // valide. Questo però non è corretto, visto che anche parole come UUUU
        // sono valide nel linguaggio MIU.
        int lenght=controllalunghezza(buffer);
        if(buffer[0]=='M')
        {
            if(buffer[lenght-1]=='U')
                primacond=true;
        }

        int I=contaI(buffer);
        cout<<I;
        if(I%2!=0 || I==0)
        {
            secondacond=true;
        }
        if(primacond && secondacond)
            scrittura<<buffer;
    }

    lettura.close();
    scrittura.close();
    return 0;
}
