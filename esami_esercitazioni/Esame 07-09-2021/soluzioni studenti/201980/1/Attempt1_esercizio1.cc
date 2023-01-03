// GDT: va bene ma leggi i commenti 
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool controlla(char parola[],int lunghezza);
int main(int argc, char * argv [])
{

  if(argc!=3){
    cout << "Sintassi: .\a.out input.txt output.txt\n";
    exit(1);
  }

  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);
  if(input.fail() || output.fail()){
    cout << "Non riesco ad aprire un file tra: " << argv[1] << " e " << argv[2] << endl;
    input.close();
    output.close();
    exit(1);
  }


  char parola[201];
  int lunghezza;
    bool alert;

    input >> parola;
    if(!(parola[0] >= 'A' && parola[0] <= 'Z')){
        parola[0] = parola[0] - 32;
    }

    while(!input.eof()){
        lunghezza = strlen(parola);
        alert= controlla(parola,lunghezza);
        if(alert==false){
            input >> parola;
        }else{
            output << parola << " ";
            if(parola[lunghezza-1] == '.' || parola[lunghezza-1] == '?' || parola[lunghezza-1] == '!') {
                input >> parola;
                if(!(parola[0] >= 'A' && parola[0] <= 'Z'))
                    // GDT: NO! Mai usare valori numerici (non è portabile su altre piattaforme),
                    // usare sempre l'aritmetica ASCII.
                    parola[0] = parola[0] - 32;  //-32 equivale ad ('A'-'a')
                }else{
                    input>> parola;
                }
        }
    }
    input.close();
    output.close();
    return(0);

}

bool controlla(char parola [],int lunghezza){
    if(lunghezza<=201){
        return true;
    }else{
        return false;
    }
}
