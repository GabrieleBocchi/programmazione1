// GDT: fare riferimento alla soluzione ufficiale per un possibile
// svolgimento

/*Esercizio 1 Papuga Tomas*/

#include <iostream>
#include <fstream>


using namespace std;

const int DIM_PAROLA = 4;

int main(int argc, char * argv[]) {
   fstream file_input, file_output;

   // Controllo argomenti passati in ingresso
  if (argc != 3) {
    cerr << "Sintassi: <file eseguibile> <file_di_input> <file_di_output>" << endl;
    exit(0);
  }
  
  // Tentativo di apertura file di input
  file_input.open(argv[1], ios::in);
  
  if (file_input.fail()) {
    cerr << "Non riesco ad accedere al file di input (" << argv[1] << ")\n";
    exit(0);
  }
  
  // Buffer per una parola
  char parola[DIM_PAROLA];

  // Leggo la prima parola del file
  file_input >> parola;
  while(!file_input.eof()){
    file_output << parola;
    file_input >> parola;
  }

  file_input.close();
  
  file_output.close();
  
return 0;
}
