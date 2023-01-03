// GDT: la variabile FILE_MAX dovrebbe essere uguale a 10000. Attenzione alla consegna dell'esercizio.
// Anche la variabile WORD_MAX dovrebbe essere uguale a 101 (100 caratteri + 1 terminatore).

#include <iostream>
#include <fstream>
using namespace std;

const int WORD_MAX = 100; 
const int FILE_MAX = 1000; 

int strlen(char s[]){
  int counter = 0; 
  while(s[counter] != '\0'){
    counter += 1; 
  }
  return counter; 
}

int main(int argc, char * argv [])
{
  if(argc < 3){
    cerr << "uso: " << argv[0] << " <file_input> <file_output>" 
      << endl; 
    return -1; 
  }
  
  fstream input, output; 
  input.open(argv[1], ios::in); 
  if(input.fail()){
    cerr << "non è stato possibile aprire " << argv[1] 
      << endl; 
    return -1; 
  }
  output.open(argv[2], ios::out);
  if(output.fail()){
    cerr << "non è stato possibile aprire " << argv[2]
      << endl; 
    return -1; 
  }

  char inputText[FILE_MAX][WORD_MAX]; 
  int wordIndex = 0; 
  while(input >> inputText[wordIndex]){
    wordIndex += 1; 
  }

  while(wordIndex >= 0){
    if(strlen(inputText[wordIndex])%2 != 0){
      output << inputText[wordIndex] << ' '; 
    }
    wordIndex -= 1; 
  }

  input.close(); 
  output.close();
  return 0;
}
