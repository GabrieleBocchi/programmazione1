// GDT: quando controlli argc, sarebbe bene anche emettere un messaggio per l'utente (va bene essere stringati, però bisogna rendere anche tutto un po' user friendly). 
// Inoltre, l'array char parola dovrebbe avere una lunghezza di 101.
// 100 caratteri + 1 EOF. Ti sei dimenticato di aggiungerlo anche quando copi la stringa nell'array finale.

#include <iostream>
#include <fstream>

using namespace std;

const int maxdim=10000;

int main(int argc, char * argv [])
{
  fstream in, out;
  if(argc==3){
    in.open(argv[1],ios::in);
    out.open(argv[2],ios::out);
    char parola[100];
    char **matrice;
    matrice = new char * [maxdim];
    int i=0;
    if(!in.fail() and !out.fail()){
     while(in>>parola){
        int p=0;
        for(; parola[p]!='\0';p++);
        if(p>4){
          matrice[i] = new char [100];
          for(int g=0; g<p;g++){
              matrice[i][g]=parola[g];
          }
          i++; 
        }
      }

      for(int g=i-1;g>=0;g--){
        out<<matrice[g]<<"  ";
      }
      in.close();
      out.close();

      for(int r=0;r<i;r++){
        delete [] matrice[r];
      }
      delete [] matrice;
    }

  }
  
  cout<<endl;

  return 0;
}
