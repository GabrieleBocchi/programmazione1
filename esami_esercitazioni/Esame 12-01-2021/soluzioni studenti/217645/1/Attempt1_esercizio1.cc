// GDT: il codice non rispetta le specifiche dell'esercizio (l'output generato è
// errato). Fare riferimento alla soluzione ufficiale per un possibile svolgimento.

#include <iostream>
#include <fstream>
using namespace std;

void invert(char * inputFile, char * outputFile);
int wordLenght(char * word);

int main(int argc, char * argv [])
{

    if(argc != 3){
      cout << "argumnets error" << endl;
    }
    else
    {
      invert(argv[1], argv[2]);
    }
    


  return 0;
}

void invert(char * inputFile, char * outputFile){
  ifstream input;
  ofstream output;

  char buffer[256];

  char ** wordList;
  int listSize = 0;


  input.open(inputFile);
  output.open(outputFile);

  if(input.fail() || output.fail()){
    cout << "file not found" << endl;
  }
  else{

    while(!input.eof()){

      input >> buffer;

      if(wordLenght(buffer) <= 4){
        output << buffer << " ";
      }
    }
  } 

  input.close();
  output.close();
}

int wordLenght(char word[]){

  int i = 0;
  while(word[i] != '\0'){
    i++;
  }

  return i;
}

