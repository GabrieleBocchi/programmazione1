#include <iostream>
#include <fstream>
using namespace std;

int strlen(char a[]){
  int i = 0;
  int len = 0;
  while(a[i]!='\0'){
    len++;
    i++;
  }
  return len;
}

int main(int argc, char * argv []){
  char buffer_parola[100];

  if(argc != 3){
    cout << "Usage: ./a.out <input_file> <output_file>" << endl;
    exit(1);
  }

  fstream input,output;
  input.open(argv[1],ios::in);
  output.open(argv[2],ios::out);
  if(input.fail()){
    cout << "Errore nell'apertura del file" << endl;
    exit(1);
  }

  while(input >> buffer_parola){
    int lunghezza_parola = strlen(buffer_parola);
    int countI = 0;
    int count = 0;
    for(int i = 0;i < lunghezza_parola;i++){
      if(count == 0){
        if(buffer_parola[0] == 'M'){
          if(buffer_parola[lunghezza_parola-1] != 'U'){
            count++;
            output << buffer_parola << endl;
          }
        }
        if(buffer_parola[i] == 'I'){
          countI++;
          if(buffer_parola[i+1] == 'M'){
            count++;
            output << buffer_parola << endl;
          }
        }
      }
    }
    if(countI%2 == 0 && countI != 0 && count == 0){
      output << buffer_parola << endl;
    }
  }

  return 0;
}
