#include <iostream>
#include <fstream>
using namespace std;

const int DIM_PAROLA = 101;

int main(int argc, char * argv [])
{

    if(argc != 3){
        cout <<"Usage: a.out <input.txt> <output.txt>";
        exit(1);
    }

    fstream input, output;
    input.open(argv[1],ios::in);
    output.open(argv[2],ios::out);

    if(input.fail()){
        cout <<"Non sono riuscito ad accedere al file di input";
        input.close();
        output.close();

        exit(1);
    }

    char c, parola[DIM_PAROLA];
    int i=0,contatore;
    bool isI, ok;

    input >> c;
    parola[i]=c;
    i++;
    while(!input.eof()){

        contatore=0;
        ok=true;

        input >> noskipws;
        input >> c;

        while(!input.eof() && ok && c!='\n'){
            parola[i] = c;
            i++;
            input >> c;
        }
        parola[i] = '\0';

        //cout <<"parola:"  <<parola <<"\t i: " <<i <<endl;
        
        for(int j=0; j<i; j++){         //Controllo 2/3

            if(parola[j] == 'I'){
                contatore++;
                if(parola[j+1] == 'M')
                    ok = false;
            }

        }

        if(parola[0] == 'M' && parola[i-1] != 'U')    //Contollo 1
            ok = false;

        if((contatore % 2 == 1 || contatore == 0) && ok){
            for(int j=0; j<i; j++){
                output <<parola[j];
            }
            output <<endl;
        }

        i=0;

    }
    cout <<endl;

    input.close();
    output.close();

  return 0;
}
