// GDT: il codice non da il risultato corretto per alcuni casi di test.(segmentation fault)
// Fare riferimeno alla soluzione ufficiale per un possibile svolgimento.
// vedere commenti nel codice.

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool testa_parola(char *parola, int len)
{
  //Pattern CCCC-CCCC-CCCC-CCCC
  //var. da ritornare
  bool res = false;

  //vedere se la lungezza del codice a barre conbacia
  if (len == 5+5+5+4)
  {
    res = true;
    //loop per vedere se i carattere nella stringa sono correti
    for (int i = 0; i < len+1; i++)
    {
      if((parola[i] == '-') || (parola[i] == '\0'))
      {
        for (int j = i-4; j < i; j++)
        {
          if (!(parola[j] >= 'A' && parola[j] <= 'Z'))
          {
            res = false;
          }
        }
      }
    }
  }

  return res;
}

int main(int argc, char *argv[])
{
  const int MAXCHAR = 101;

  //inizializzazione del software e relativi test
  if (argc != 3)
  {
    cout << "errore nel input " << argc << endl;
    exit(1);
  }

  fstream in;
  fstream out;
  in.open(argv[1], ios::in);
  out.open(argv[2], ios::out);

  if (in.fail() || out.fail())
  {
    cout << "errore nelle lettura file" << endl;
    exit(1);
  }

  // GDT: Manca l'inizializzaione dell'area di memoria necessaria per salvare
  // la stringa. Questo viene considerato come un puntatore a null.
  // Soluzione: char * buffer = new char[101]
  //alocazione di un buffer e di un risultato
  char *buffer;
  int nCode = 0;

  //utilizzo delle funzione deffinita sopra andando a leggere ogni parola
  while (in >> buffer)
  {
    if (strlen(buffer) < MAXCHAR)
    {
      if (testa_parola(buffer, strlen(buffer)))
      {
        nCode++;
      }
    }
  }

  //scritura del numero di parola
  out << nCode;

  //chiusura dei file
  in.close();
  out.close();

  // GDT: manca la deallocazione di buffer con delete

  return 0;
}
