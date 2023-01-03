// GDT: il codice non da il risultato corretto per alcuni casi di test.
// Ti sei dimenticato di scrivere l'output nel file di testo. Lo stampi
// solo a video.

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAXDIM = 100 + 1; //+1 per il terminatore di stringa
const int catturabile = 19; //16 per i numeri e 3 per i delimitatori "-"
bool check(char *s);

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    cout << "Errore nell'utilizzo: <a.out> <input.txt> <output.txt>" << endl;
    exit(1);
  }
  fstream input, output;
  input.open(argv[1], ios::in);
  if (input.fail())
  {
    cout << "Errore in apertura del file di input" << endl;
    input.close();
    exit(1);
  }
  output.open(argv[2], ios::out);
  if (output.fail())
  {
    cout << "Errore in apertura del file di output" << endl;
    input.close();
    output.close();
    exit(1);
  }
  char buffer[MAXDIM];
  int counter = 0; //conta quante parole vanno bene
  while (input >> buffer)
  {
    if (strlen(buffer) == catturabile)
    {                                                                //controllo la parola solo se la lunghezza è tale da essere un codice
      if (buffer[4] == '-' && buffer[9] == '-' && buffer[14] == '-') //controllo che ogni 4 char ci sia un delimitatore
      {                                                              //sfruttando la consegna che dice espressamente
                                                                     //che la forma deve essere del tipo NNNN-NNNN-NNNN-NNNN
        if (check(buffer))
        {            //controllo se il contenuto siano solo numeri
          counter++; //incremento il numero di stringhe compatibili con la mia ricerca
        }
      }
    }
  }
  cout << counter << endl; //stampo il numero di stringhe compatibili che ho trovato

  input.close();
  output.close();
  return 0;
}

bool check(char *s)
{
  int i = 0;
  int check = 0;
  bool ok = true;
  int numero_delimitatori = 4;
  // GDT: bastava solo:  && ok
  while ((s[i] != '\0') && (ok == true))
  {
    if (s[i] == '-')
    {
      check++;
    }
    else if ((s[i] >= '0' && s[i] <= '9') && (check < numero_delimitatori))
    {
      ok = true;
    }
    else
    {
      ok = false;
    }
    i++;
  }
  return ok;
}
