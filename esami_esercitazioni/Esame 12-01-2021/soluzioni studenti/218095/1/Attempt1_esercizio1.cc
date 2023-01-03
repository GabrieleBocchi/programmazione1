#include <iostream>
#include <fstream>

#define MAXC 101
#define MAXW 10000

using namespace std;

int lunghezzaStringa(char s[MAXC]);

int main(int argc, char * argv[])
{
    if(argc == 3)
    {

        ifstream in(argv[1]);
        ofstream out(argv[2]);

        if(in.fail() || out.fail())
        {
            cerr << "Abbiamo riscontrato un errore con la lettura del file di input o di output, riprovare" << endl;
        }
        else
        {
            int nParole = 0;
            char testo[MAXW][MAXC];

            while(in >> testo[nParole])
                nParole++;

            for(int i=nParole; i>=0; i--)
                if(lunghezzaStringa(testo[i]) > 4)
                    out << testo[i] << " ";
        }

        in.close();
        out.close();
    }
    else cerr << "Usage: <inputfile> <outputfile>" << endl;
    return 0;
}

int lunghezzaStringa(char s[MAXC]){
    int lung = 0;
    for(int i = 0; s[i] != '\0'; i++)
        lung++;
    return lung;
}
