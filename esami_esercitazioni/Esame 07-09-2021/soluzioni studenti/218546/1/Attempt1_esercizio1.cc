// GDT: il codice non riporta il risultato corretto in alcuni casi di test.
// Vedi commenti nel codice
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool is_upper(char c);
bool is_lower(char c);
char to_upper(char c);
char to_lower(char c);
bool is_end(char * str);

int main(int argc, char * argv [])
{
  if(argc != 3) {
    cout << "usage: a.out <input.txt> <output.txt>" << endl;
    exit(1);
  }
  else {
    fstream input, output;

    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    if(input.fail()) {
      cout << "errore nell'apertura del file " << argv[1] << endl;
      exit(1);
    }
    else {
      char buffer [200];
      char last_word[200];

      bool first = true;
      while(input >> buffer) {

        if(first) {
          first = false;
          buffer[0] = to_upper(buffer[0]);
          output << buffer << " ";
        }
        else {

          if(is_end(last_word)) {
            // GDT: non era specificato che, se una parola segue uno dei caratteri
            // di punteggiatura specificati, allora dovesse andare con la lettera
            // maiuscola. Bisogna lasciare la parola così com'è.
            buffer[0] = to_upper(buffer[0]);
            output << "\n" << buffer << " ";
          }
          else {
            buffer[0] = to_lower(buffer[0]);
            output << buffer << " ";
          }

          strcpy(last_word,buffer);
        }
      }


      input.close();
      output.close();

    }

  }

  return 0;
}

bool is_upper(char c) {
  return c >= 'A' && c <= 'Z';
}

bool is_lower(char c) {
  return c >= 'a' && c <= 'z';
}

char to_upper(char c) {
  char ret = c;
  if(is_lower(c))
    ret = (c - 'a') + 'A';
  return ret;
}

char to_lower(char c) {
  char ret = c;
  if(is_upper(c))
    ret = (c - 'A') + 'a';
  return ret;
}

bool is_end(char *c) {
  bool ret = false;
  if(c[strlen(c)-1] == '.' || c[strlen(c)-1] == '!' || c[strlen(c)-1] == '?')
    ret = true;
  return ret;
}
