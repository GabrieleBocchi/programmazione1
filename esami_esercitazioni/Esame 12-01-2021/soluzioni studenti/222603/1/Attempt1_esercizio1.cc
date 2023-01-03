#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv [])
{
  if(argc != 3){
    cout << "Usage ./a.out <file.txt> <file1.txt>" << endl;
    exit(1);
  }

  fstream input, output;
  char parola[101];
  char ** parole = new char * [1000];
  int i=0;

  input.open(argv[1], ios::in);

  if(input.fail()){
    cout << "Errore nell'apertura del file." << endl;
    exit(1);
  }

  while(input >> parola){
    parole[i] = new char[101];
    parole[i] = parola;
    i++;
  
  }

  input.close();

  output.open(argv[2], ios::out);

  int cont=0;

  for(int j=1000; j<0; j--){
    int num=0;
    while(parole[j][num] != '\0'){
      cont++;
      num++;
    }
    if(cont%2 != 0){
      output << parola << " ";
    }

  }
  
  output.close();

  for(int k=0; k<10000; k++){
    delete [] parole[k];
  }
  delete [] parole;

  return 0;
}
