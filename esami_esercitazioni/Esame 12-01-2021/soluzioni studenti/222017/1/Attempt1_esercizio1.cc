#include <iostream>
#include <fstream>
using namespace std;

const int maxdim = 10000;

int lenght(char c[]);

int main(int argc, char * argv[]){

  if (argc != 3){
    cout << "Usage: ./a.out <input_file> <output_file>" << endl;;
    exit(0);
  }

  fstream input, output;
  //Controllo che non ci siano errori nell'apertura dei file
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  if (input.fail() || output.fail()){
    cout << "Errore nell'apertura del file di input o output" << endl;
    exit(1);
  }
  output.close();

  char buffer[101];
  char matrix[maxdim][101];
  int len, row = 0;

  while (input >> buffer && row < maxdim){
    len = lenght(buffer);
    if (len > 4){
      for (int j = 0; buffer[j] != '\0'; j++){
        matrix[row][j] = buffer[j];
      }
    }
    row++;
  }
  input.close();

  output.open(argv[2], ios::out);
  
  for (int i = row-1; i >= 0; i--){                                                                                               
    for (int j = 0; matrix[i][j] != '\0'; j++){
      output << matrix[i][j];
    } 
    output << " ";                                                       
  }         
  output.close();

  return 0;
}

int lenght(char c[]){
  int i;
  while (c[i] != '\0'){
    i++;
  }
  return i;
}
