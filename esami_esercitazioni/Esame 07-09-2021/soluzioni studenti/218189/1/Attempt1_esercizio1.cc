// GDT: il codice non riporta il risultato corretto in alcuni casi di test.
// Vedi commenti nel codice
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void controllo_frase(char *s);

int main(int argc, char * argv [])
{
  // GDT: controllo errato, dovrebbe essere !=
  if(argc=!3)
    {
      cout<<"Errore nel lancio del programma, utilizzare: <./a.out> <input.txt> <output.txt>"<<endl;
      exit(0);
    }
  fstream fin;
  fin.open(argv[1],ios::in);
  if(fin.fail())
    {
      cout<<"Errore file"<<endl;
      exit(0);
    }
  char frase[500];
  fin.getline(frase,500);
  fin.close();

  controllo_frase(frase);

  fstream fout;
  fout.open(argv[2],ios::out);
  fout<<frase<<endl;
  fout.close();
  return 0;
}

// GDT: per fare il controllo da maiuscolo a minuscolo stai usando direttamente i
// codici ASCII, ed è errato (visto che così il codice non potrebbe funzionare
// su una macchina con codifica differente)
// Infatti, il file in output generato contiene dei caratteri illeggibili.
// Fare riferimento alla soluzione ufficiale per un possibile svolgimento.
void controllo_frase(char s[])
{
  for(int i=0;i<(int)strlen(s);i++)
    {
      if(s[i-1]==' ')
	{
	  if(s[i]>96 ||s[i]<124)//da minuscolo a maiuscolo
	    s[i]-=32;
	}
    }
   for(int i=0;i<(int)strlen(s);i++)
    {
      if(s[i-1]==','||s[i-1]==':' || s[i-1]==';')
	{
	  if(s[i]>64 ||s[i]<92)//da maiuscolo a minuscolo
	    s[i]+=32;
	}
    }
}
