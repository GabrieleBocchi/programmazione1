// GDT: il codice non riporta il risultato corretto in alcuni casi di test.
// Vedi commenti nel codice

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void modificalettera(char buffer[]);

int main(int argc, char * argv[])
{
  if(argc != 3)
  {
    cout << "Usage ./a.out <input.txt> <output.txt> " << endl;
    exit(1);
  }

  fstream input, output;

  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  if(input.fail() || output.fail())
  {
    cout << "Errore nel file di lettura e/o di scrittura" << endl;
    exit(1);
  }

  char carattere; // GDT: questa variabile non viene utilizzata
  if(input.fail() || output.fail())
  {
    cout << "Errore nell'apertura del file di lettura e/o scrittura." << endl;
    exit(2);
  }

  char buffer[256];
  int i=0; // GDT: questa variabile non viene utilizzata

  while(input >> buffer){
    if (buffer[strlen(buffer)-1] == ',' || buffer[strlen(buffer)-1] == ':' || buffer[strlen(buffer)-1] == ';')
    {
      // GDT: in questo modo, alla prima iterazione del ciclo, la prima lettera
      // non viene mai controllata. Quindi, in caso inizi con la lettera minuscola,
      // non verrà mai corretta.
      output << buffer << " ";

      input >> buffer;
      modificalettera(buffer);
      output << buffer << " ";
    }
    else
    {
      output << buffer << " ";
    }

  }


  input.close();
  output.close();


  return 0;
}

void modificalettera(char buffer[])
{
  if (buffer[0] >= 'A' && buffer[0] <= 'Z')
  {
    buffer[0] = 'a' +  buffer[0] - 'A';
  }
}
