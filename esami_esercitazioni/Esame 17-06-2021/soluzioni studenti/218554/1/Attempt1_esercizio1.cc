// Giovanni: soluzione convoluta. Fai riferimento alle soluzioni ufficiali per
// un possibile svolgimento.

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_DIM = 101;

int strlen(char array[]){
  int contatore = 0;
  while(array[contatore] != '\0'){
    contatore++;
  }
  return contatore;
}

int main(int argc, char * argv [])
{

  if(argc != 3){
    cout << "Usage: a.out <input> <output>" << endl;
    exit(1);
  }

  fstream input, output;

  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  if(input.fail() || output.fail()){
    cout << "problema apertura file" << endl;
    exit(1);
  }

  char buffer[MAX_DIM];
  int contatore = 0;

  while(input.getline(buffer, MAX_DIM)){
    contatore++;
  }

  input.close();
  input.open(argv[1], ios::in);

  char parole[contatore][MAX_DIM];

  int i = 0;
  while(input.getline(buffer, MAX_DIM)){
    // Giovanni: non è possibile assegnare le stringhe in questo modo. Bisogna
    // usare strcpy oppure direttamente input >> parole[i]
    parole[i][MAX_DIM] = buffer[i];
    cout << buffer[i] << endl;
    i++;
  }

  input.close();

  for(int j = 0; j<i; j++){
    int lunghezza = strlen(parole[j]);
    bool valida = true;

    if((parole[j][0] == 'U') && (parole[j][lunghezza] == 'M')){
      valida = false;
    }

    int contatore_i = 0;
    for(int y = 0; y<lunghezza; y++){
      if(parole[j][y] == 'I'){
	contatore_i++;
      }
    }

    if((contatore_i%2==0) || (contatore_i==0)){
      valida = false;
    }

    for(int g = 0; g<lunghezza-1; g++){
      if((parole[j][g] == 'M') && (parole[j][g+1] == 'I')){
	valida = false;
      }
    }

    if(valida == true){
      output << parole[j] << endl;
    }

  }

  output.close();

  return 0;
}
