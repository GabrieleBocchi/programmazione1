#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv [])
{
  // controllo che ci siano 3 argomenti
  if(argc !=3)
  {
    cout << "usage: <a.output> <input><output>"<< endl;
    return 1;
  }
  //inizializzo la lettura e controllo che non ci siano errori con l'apertura del file
  fstream input, output;
  input.open(argv[1], ios::in);
  if(input.fail())
  {
    cout << "errore nell'apertura del file" << argv[1] << endl;
    return 2;
  }
  output.open(argv[2], ios::out);
  char parola[100]; //GDT: dovrebbe essere 101 (100 caratteri + 1 '\0')
  char ** testo = new char*[10000];
  int indice = 0;

  //leggo la prima parola del file
  input >> parola;

  //ciclo fino a che il file non è terminato
  while(!input.eof())
  {
    // calcolo la lunghezza della parola letta
    int lunghezza = 0;
    while(parola[lunghezza] != '\0')
    {
      lunghezza++;
    }
    // se la lunghezza è pari la inserisco nell array testo
    if(lunghezza %2 == 0)
    {
      testo[indice] = new char[lunghezza+1];
      for(int i = 0; i<lunghezza;i++)
      {
        // GDT: qua hai invertito gli indici. Doveva essere testo[indice][i].
        // Questo codice va in segmentation fault. Se inverti gli indici, il codice
        // funziona alla perfezione.
        testo[i][indice] = parola[i];
    }
      // GDT: Manca il parametro EOF per indicare la fine della stringa.
      indice++;
    }
    input >> parola;

  }

  //stampo nell'output l'array al contrario
  for(int i = indice-1; i >=0; i--)
  {
    output << testo[i]<< endl;
  }

  // GDT: manca la deallocazione della variable testo

  //chiudo gli stream
  input.close();
  output.close();
  return 0;
}
