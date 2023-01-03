// GDT: il codice non riporta il risultato corretto in alcuni casi di test.
// Vedi commenti nel codice
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_WORD_LEN = 201;

void firstToupper (char & c){
  if(c >= 'a' && c <= 'z'){
    c += 'A' - 'a';
  }
}

void firstTolower (char & c){
  if(c >= 'A' && c <= 'Z'){
    c += 'a' - 'A';
  }
}

int main(int argc, char * argv [])
{
  if(argc != 3){
    cout << "Error! wrong parameters" << endl;
    exit(EXIT_FAILURE);
  }

  fstream in, out;
  in.open(argv[1], ios::in);
  out.open(argv[2], ios::out);

  if(in.fail() || out.fail()){
    cout << "Error! file not found" << endl;
    exit(EXIT_FAILURE);
  }

  char word [MAX_WORD_LEN];
  bool first = true;
  bool past_was_point = false;

  while(in >> word){

    if(past_was_point){
      // GDT: non era specificato che, se una parola segue uno dei caratteri
      // di punteggiatura specificati, allora dovesse andare con la lettera
      // maiuscola. Bisogna lasciare la parola così com'è.
      firstToupper(word[0]);
      past_was_point = false;
    }
    else{
      firstTolower(word[0]);
    }

    if(first){
      firstToupper(word[0]);
      first = false;
    }

    if(word[strlen(word)-1] == '.' || word[strlen(word)-1] == '!' || word[strlen(word)-1] == '?'){
      past_was_point = true;
    }

    out << word << " ";
  }

  in.close();
  out.close();

  return 0;
}
