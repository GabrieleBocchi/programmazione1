// GDT: il codice non da il risultato corretto per alcuni casi di test.
// Fare riferimeno alla soluzione ufficiale per un possibile svolgimento.
// vedere commenti nel codice

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char * argv [])
{

  // GDT: mancano i controlli sugli argomenti e mancano
  // i controlli sui file di input e output.

  fstream sniffer;
  int count;
  char codice;

  sniffer.open(argv[1], ios::in);

  while(sniffer){
    sniffer.get(codice);
    for(int n; n<=12; n++){
       for(int i=0; i<=4; i++)
	  if(isupper(codice));
       if(codice='-')
	 count++;
    };
  };

  sniffer.close();

  sniffer.open(argv[2], ios::out);
  sniffer<<count;
  sniffer.close();
  return 0;
}
