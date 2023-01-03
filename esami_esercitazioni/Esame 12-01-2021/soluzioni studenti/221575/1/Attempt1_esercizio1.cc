// GDT: fare riferimento alla soluzione ufficiale per un esempio di svolgimento.

#include <iostream>
#include <fstream>
using namespace std;

int calcola_lunghezza(char parola[]);

int main(int argc, char * argv [])
{
  int retval = 0;
  
  if (argc != 3) {
    cout << "Usage a.out <input_file> <output_file>" << endl;
    retval = 1;
  } else {
    fstream input;
    fstream output;

    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    if (input.fail()) {
      cout << "Fine di input non esistente" << endl;
      retval = 2;
    } else if (output.fail()) {
      cout << "Fine protetto da scrittura" << endl;
      retval = 3;
    } else {
      const int MAX_DIM_PAROLA = 101;
      const int MAX_PAROLE = 10000;
      int conta_parole = 0;
      int conta_caratteri = 0;
      //int index_array = 0;
      char parola_corrente[MAX_DIM_PAROLA];
      
      // array dove contenere le parole adatte 
      /*
      char ** array = new char* [MAX_PAROLE];
      for (int i=0; i<MAX_PAROLE; i++) {
        array[i] = new char[MAX_DIM_PAROLA];
      }
      */

      input >> parola_corrente;
      while (!input.eof() && conta_parole <= MAX_PAROLE) {
        if (calcola_lunghezza(parola_corrente) <= 4) {
          output << parola_corrente << " ";
        }
        input >> parola_corrente;
      }
    }

    input.close();
    output.close();
  }

  return 0;
}

int calcola_lunghezza(char parola[]) {
  int lunghezza = 0;

  for (int i=0; parola[i] != '\0'; i++) {
    lunghezza ++;
  }

  return lunghezza;
}

