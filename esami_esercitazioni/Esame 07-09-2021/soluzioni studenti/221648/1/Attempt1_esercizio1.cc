// GDT: il codice non riporta il risultato corretto in alcuni casi di test.
// Vedi commenti nel codice

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//funzioni ausiliarie
char toUpper(char);
bool isLowercase(char);
bool isLetter(char);
bool isPeriod(char);

int main(int argc, char * argv [])
{
  //verifico di aver ricevuto i nomi dei file negli argomenti
  if(argc != 3){
    cerr << "Utilizzo: a.out <input file> <output file>" << endl;
    exit(0);
  }

  //apertura stream
  fstream input, output;

  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  //verifico che gli stream si siano aperti correttamente
  if(input.fail() || output.fail()){
    cerr << "Impossibile aprire il file " << argv[1] << " o " << argv[2] << endl;
    output.close();
    input.close();
    exit(0);
  }

  bool nextUpper = true;
  char c;

  while(input.get(c)){
    if(nextUpper && isLetter(c)){
      //passo a lettera maiuscola
      c = toUpper(c);

      nextUpper = false;
    }else if(isPeriod(c)){
      //ho letto un punto e la prossima lettera sarà maiuscola

      // GDT: la logica è errata. Il testo dell'esercizio indica che solo
      // le parole che non seguono la punteggiatura indicata devono iniziare
      // con la lettera maiuscola.
      // Si veda la soluzione ufficiale per uno possibile svolgimento

      nextUpper = true;
    }

    output << c;
  }

  //chiusura stream
  input.close();
  output.close();

}

//funzioni ausiliarie

bool isLowercase(char c){
  return (c >= 'a' && c <= 'z');
}

bool isLetter(char c){
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

char toUpper(char c){
  //se non è una lettera minuscola lascio così com'è
  if(isLowercase(c))
    c += ('A' - 'a');

  return c;
}

bool isPeriod(char c){
  return (c==',' || c==':' || c==';');
}
