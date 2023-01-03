// GDT: l'istruzione parole[i] = parola è errata e causa un double free nella memoria.
// L'istruzione assegna a parole[i] il puntatore parola, non l'effettiva stringa contenuta
// nella variabile. Quindi, alla fine, l'array parole[i] conterrà soltanto l'ultima parola
// letta (e avrai problemi quando dovrai deallocare).

#include <iostream>
#include <fstream>
using namespace std;

int word_length(char word[]);

int main(int argc, char * argv [])
{
  if(argc != 3) {
    cerr << "Usage: " << argv[0] << "<file_input> <file_output>";
    exit(0);
  }

  fstream input, output;

  input.open(argv[1], ios::in);

  if(input.fail()) {
    cerr << "Errore apertura del file " << argv[1];
    exit(0);
  }

  
  char* parola = new char[100+1];
  char** parole = new char* [10000+1];
  int tot_parole = 0;
  
  
  input >> parola;
  for(int i=0; !input.eof(); i++) {
    parole[i] = parola;
    tot_parole++;
    input >> parola;
  }
  input.close();

  output.open(argv[2], ios::out);

  if(output.fail()) {
    cerr << "Errore: file " << argv[2] << " non scrivibile";
    exit(0);
  }
  
  for(int i=tot_parole-1; i >= 0; i--) {
    if(word_length(parole[i]) % 2 == 1)
      output << parole[i] << endl;
  }
  output.close();

  for(int i=0; i<20; i++)
    delete[] parole[i];
  delete[] parole;

  return 0;
}

int word_length(char word[]) {
  int i = 0;

  while(word[i] != '\0')
    i++;

  return i;
}
