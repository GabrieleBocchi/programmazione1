#include <iostream>
#include <fstream>
using namespace std;

int lunghezzaParola(char * parola);

int main(int argc, char * argv [])
{
  if(argc != 3)
  {
    cerr << "Usage: <nome programma> <file in input> <file in output>" << endl;
    exit(1);
  }

  fstream input, output;

  input.open(argv[1], ios::in);

  if(input.fail())
  {
    cerr << "Errore in lettura." << endl;
    input.close();
    exit(1);
  }

  char parole[10000][101];

  int quanteParole = 0;

  while(input >> parole[quanteParole]){
    quanteParole++;
  }

  input.close();

  output.open(argv[2], ios::out);

  if(output.fail())
  {
    cerr << "Errore in scrittura." << endl;
    output.close();
    exit(1);
  }

  for (int i = quanteParole-1; i >=0; i--)
  {
    if(lunghezzaParola(parole[i]) <= 4)
      output << parole[i] << " ";
  }
  
  output.close();

  return 0;
}

int lunghezzaParola(char * parola){
  int l = 0;

  while(parola[l]!='\0')
   l++;

  return l;
}
