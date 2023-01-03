// GDT: il codice compila, però non genera correttamente il file in output.
// Il problema sta nel ciclo while di lettura. La condizione dovrebbe essere !input.eof().

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_PAR=1000;
const int MAX_CAR=101;

bool quattrocar(char parola []);

int main(int argc, char * argv [])
{
  if(argc!=3)
    {
      cerr << "Usage: ./a.out <fileinput> <fileoutput>" << endl;
      exit(0);
    }

  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  if (input.fail())
    {
      cerr << "Il file di input non esiste"<< endl;
      exit(1);
    }
  if(output.fail())
    {
      cerr << "Il file non è scrivibile"<< endl;
      exit(2);
    }

  char buffer[MAX_CAR];
  char parole[MAX_PAR][MAX_CAR];
  int n=0;
  
  input >> parole[n];
  n++;
  while(input.eof())
    {
      input>>parole[n];
      cout << parole[n];
      n++;
    }

  input.close();
  
  for(int i=n-1; i>=0; i--)
    {
      if (quattrocar(parole[i]))
	output << parole[i] << " ";
    }
      

  output.close();
  
  return 0;
}

bool quattrocar(char parola [])
{
  int conta=0;
  char c=parola[0];
  while((c!='\0')&&(conta<=4))
    {
      conta++;
      c=parola[conta];
    }
  return(conta<=4);
}
      
