// GDT: vedi commenti nel codice

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int maxDim = 100+1;
int dimSniffer = 19;

int main(int argc, char * argv [])
{
  if(argc!=3)
  {
    cout << "usage : ./a.out <inputfile> <outputfile>"<< endl;
    return 1;
  }

  fstream input, output;

  input.open(argv[1], ios::in);
  if(input.fail())
  {
    cout << "errore nel caricamento del file di input" << endl;
    return 2;
  }

  output.open(argv[2], ios::out);
  if(output.fail())
  {
    cout << "errore nel caricamento del file di output" << endl;
    return 3;
  }

  char buffer[maxDim];
  int a = 0, ll =0, count = 0;

  while(input >> buffer)
  {
    a = 0;
    ll = strlen(buffer);
    if(ll == dimSniffer)
    {
      for(int i = 0; i<ll; i++)
      {
        if(buffer[i] == '-' )
        {
          // GDT: manca un carattere pipe | per segnalare il secondo OR (stai usando
          // il bitwise OR invece che il logical OR).
          // Sempre compilare con -Wall che permette di catturare questi errori.
          // Fortunatamente, in questo caso non causa troppi problemi.
          if(i== 4 ||i ==9 | i== 14 )
          {
            a++;
          }

        }
        else if(buffer[i] >= 'A' && buffer[i] <='Z')
        {
          a++;
        }
      }
    }
    if(a == ll)
    {
      count ++;
    }

  }

  output << count << endl;
  input.close();
  output.close();
  return 0;
}
