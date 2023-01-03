// GDT: il programma non da il risultato corretto nei casi di test.
// Fare riferimento alla soluzione ufficiale per lo svolgimento.
// Vedere commenti nel codice.

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
using namespace std;
int main(int argc,char* argv[])
{
  fstream input, output;
  char tmp[100];
  int numero_cifre=0,numero_stringhe=0,numero_target=0;
  if (argc != 3)
  {
    cout << "Usage: ./a.out <input> <output>";
    exit(0);
  }

  input.open(argv[1],ios::in);
  if (input.fail()) {
    cerr << "There is a problem in " << argv[1] << " and the process has been closed" << endl;
    exit(1);
  }
  output.open(argv[2], ios::out);
  if (output.fail()) {
    cerr << "There is a problem in " << argv[2] << " and the process has been closed" << endl;
    exit(1);
  }
  input >> tmp;
  while (!input.eof())
  {
    // GDT: l'indentazione qui è un po' traballante. Inoltre, la procedura di
    // controllo è errata:
    // - La stringa per essere corretta deve essere lunga 19 caratteri (1e cifre
    // più 3 delimitatori - )
    for (int i=0; i<16 ; i++) 
      // Questa condizione è sempre falsa. Il carattere non può essere contemporaneamente
      // sia numero che il carattere "-"
      if ((tmp[i]>='0') && (tmp[i]<='9') && (tmp[i] == '-'))
	numero_cifre++;
    if ((numero_cifre==16) && (strlen(tmp)==16))
      numero_stringhe++;
    else numero_stringhe=0;
    numero_cifre=0;
    if (numero_stringhe==16)
    {
	numero_target++;
	numero_stringhe=0;
    }
    input >> tmp;

  }

  output <<  numero_target;
  input.close();
  output.close();
  output.close();
    return(0);
}
