#include <iostream>
#include <fstream>
using namespace std;

const int DIM_PAROLA = 100;

void copia_stringa (char stOut [], char stIn [])
{
  for (int i=0; stIn[i]!='\0'; i++)
    stOut[i] = stIn[i];
}


int main(int argc, char * argv[]) {
  
  fstream file_input, file_output;

  if (argc != 3) {
    cerr << "Scrivi ./a.out <filesorgente> <filefinale>"<< endl;
    exit(1);
  }

  file_input.open(argv[1], ios::in);
 
  if (file_input.fail()) {
    cerr << "Il file " << argv[1] << " non esiste, crealo prima di avviare il programma\n";
    exit(1);
  }
  
  
  char parola[DIM_PAROLA];
  int numero_parole = 1;
  
  
  file_input >> parola;
  while(!file_input.eof()) {
    numero_parole++;
    file_input >> parola;
  }
  
  
  file_input.close();
  file_input.open(argv[1], ios::in);
  
  char** parole = new char* [numero_parole];
  
  
  for(int i = 0; i < numero_parole; i++) {
  file_input >> parola;
  
  
  parole[i] = new char[100];
  copia_stringa(parole[i], parola);
  }
  
  file_input.close();
  file_output.open(argv[2], ios::out);
  
  for(int i = numero_parole - 1; i >= 0; i--) {
  file_output << parole[i] << " ";
  }
  
  file_output.close();
  return 0;
}