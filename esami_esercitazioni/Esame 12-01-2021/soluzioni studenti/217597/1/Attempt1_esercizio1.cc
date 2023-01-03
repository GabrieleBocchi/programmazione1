// GDT: nel tuo codice stai utilizzando il tipo string. Di norma, per utilizzarlo
// bisognerebbe aggiungere la libreria <string>, però capita che certi compilatori lo
// includano automaticamente dentro ad <iostream>. Quindi, in questo caso funziona, ma
// non sempre. 
//
// Nel testo d'esame non era specificato di poter utilizzare tipi composti come il tipo
// string. Questo perchè utilizzare strutture dati avanzati non ci permette di verificare
// se avete acquisito certe competenze di base. Perciò viene data una penalizzazione. 

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv [])
{
  // controllo parametri
  if(argc != 3) {
    cout << "Il numero di parametri è errato!" << endl;
    return 1;
  }

  fstream in, out;

  // apertura in
  in.open(argv[1], ios::in);
  if(in.fail()) {
    cout << "File input non presente!" << endl;
    return 2;
  }

  // apertura out
  out.open(argv[2], ios::out);
  if(out.fail()) {
    cout << "Impossibile aprire/creare file di output!" << endl;
    return 3;
  }

  // lettura di tutte le parole
  string *phrase = new string[1000];

  // lettura prima parola
  string fword;
  in >> fword;
  phrase[0] = fword;

  // lettura altre parole
  int pos = 1;
  while(!in.eof()) {
    string word;
    in >> word;
    phrase[pos++] = word;
  }

  // scrittura con controllo
  for (int i = pos - 2; i >= 0; i--) {
    // lunghezza parola
    int len = 0;
    while(phrase[i][len++] != '\0');

    // controllo e output
    if((len - 1) % 2 != 0)
      out << phrase[i] << " ";
  }

  // chiusura risorse
  in.close();
  out.close();

  return 0;
}
