#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_DIM = 101;
bool controlla(char array[]);

int main(int argc, char * argv [])
{
  if(argc != 3){
    cout<< "usage esercizio1 input.txt output.txt";
    exit(1);
  }

  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);
  if(input.fail() || output.fail()){
    cout << "non è stato possibile aprire gli stream";
    input.close();
    output.close();
    exit(1);
  }
  
  int contatore = 0;
  char buffer[MAX_DIM];
  if(!input.eof()){
    while(input >> buffer){
      if(strlen(buffer) == 16){
        if(controlla(buffer)){
          contatore++;
        }
      }
    }
  }
  
  output << contatore;

  input.close();
  output.close();
  return 0;
}

bool controlla(char array[]){
  bool returnValue;
  int contaLettere = 0;
  int contaNumeri = 0;

  for (int i = 0; i < 16; i++) //posso mettere 16 perchè ho precedentemente controllato con strlen che la dimensione sia quella
  {
    if(i >= 0 && i < 12 && array[i] >= '0' && array[i] <= '9'){
      contaNumeri++;
    }
    else if(i>= 12 && i < 16 && array[i] >= 'A' && array[i] <= 'Z'){
      contaLettere++;
    }
  }

  if(contaNumeri == 12 && contaLettere == 4){
    returnValue = true;
  }
  else{
    returnValue = false;
  }

  return returnValue;
}