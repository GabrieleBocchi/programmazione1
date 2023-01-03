// GDT: la variabile MAX_DIM dovrebbe essere 101. Infatti, 100 sono i caratteri della parola
// da leggere, più un carattere di EOF.

#include <iostream>
#include <fstream>
using namespace std;

int MAX_DIM = 100;
int MAX_PAROLE = 10000;

int main(int argc, char * argv []) {
   
   if (argc != 3) {
      cerr << "Errore formato: ./a.out <file_in> <file_out>" << endl;
      exit (0);
   }
   
   fstream input, output;
   input.open (argv[1], ios::in);
   if (input.fail()) {
      cerr << "File non disponibile: " << argv[1] << endl;
      exit (0);
   }
   
   char buffer [MAX_DIM];
   char ** libreria = new char * [MAX_PAROLE];
   int cont = 0;
   while (input >> buffer) {
      libreria[cont] = new char [MAX_DIM];
      int i;
      for (i = 0; buffer[i] != '\0'; i++) {
         libreria[cont][i] = buffer[i];
      }
      if (i%2 == 0) {
         libreria[cont][i] = '\0';
      }
      else {
         libreria[cont][0] = '\0';
      }
      cont++;
   }
   input.close();
   
   output.open (argv[2], ios::out);
   if (output.fail()) {
      cerr << "File non scrivibile: " << argv[2] << endl;
      exit (0);
   }
   
   for (int i = cont - 1; i >= 0; i--) {
      if (libreria[i][0] != '\0') {
         output << libreria[i] << " ";
      }
      delete [] libreria[i];
   }
   output.close();
   
   delete[] libreria;
  
   return 0;
}
