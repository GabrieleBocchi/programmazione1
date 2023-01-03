// GDT: il codice non rispetta la consegna d'esame. Fare riferimento alla soluzione ufficiale
// per un possibile svolgimento.

#include <iostream>
#include <fstream>
using namespace std;

int conta(char vett[]);

int main(int argc, char * argv [])
{
  int returnValue = 0;
  
  if (argc != 3) {
    cerr << "Usage: ./a.out <input_file> <output_file>" << endl;
    returnValue = 1;
  }
  else {
    fstream infile, outfile;

    infile.open(argv[1], ios::in);
    outfile.open(argv[2], ios::out);
    
    if (infile.fail()) {
      cerr << "Errore in lettura" << endl;
      returnValue = 2;
    }
    else if (outfile.fail()) {
      cerr << "Errore in scrittura" << endl;
      returnValue = 3;
    }
    else {
      char parola[101];
      
      while (infile >> parola) {
	if(conta(parola) > 4) {
	  outfile << parola << " ";
	} 
      }
    }
    infile.close();
    outfile.close();

    }

  return returnValue;
}

int conta(char vett[]) {
  int res = 0;
  while(vett[res] != '\0') {
    res++;
  }
  return res;
}
