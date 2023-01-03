#include <iostream>
#include <fstream>
using namespace std;

//funzione principale, legge i file
int leggiFile(char file_input[], char file_output[]);

//stessa funzione di strlen di cstring
int contaCaratteri(char stringa[]);

//stessa funzione di strcpy di cstring
void copiaStringa(char stringa1[], char stringa2[], int stringa2_dim);

int main(int argc, char * argv [])
{
  //controllo l'input da main
  if (argc != 3) {
    cout << "File usage: ./a.out <file_input> <file_output>.\n";
  }
  else {
    //x variabile di controllo: 1 = errore file input, 2 = errore file output, 0 = successo.
    int x = leggiFile(argv[1], argv[2]);
    if (x == 1) {
      cout << "File di input inesistente.\n";
    }
    else if (x == 2) {
      cout << "Il file di output non e' scrivibile.\n";
    }
    else {
      cout << "Operazione avvenuta con successo.\n";
    }
  }
  return 0;
}

int leggiFile(char file_input[], char file_output[]) {
  //x variabile di controllo
  int x = 0;
  fstream input, output;
  input.open(file_input, ios::in);
  output.open(file_output, ios::out);
  //effettuo i controlli
  if (input.fail()) x = 1;
  else if (output.fail()) x = 2;

  //se ho successo, esegui il resto del programma
  else {
    //inizializzo matrice che conterra' tutti i valori corretti del file input, 
    //ed un buffer che conterra' tutte le parole passate dall'fstream
    char matrice[10000][101], buffer[101];

    //i numero delle parole giudste, strlen lunghezza del buffer in analisi
    int i = 0, strlen = 0;
    while (input >> buffer) {
      strlen = contaCaratteri(buffer);
      if (strlen <= 4) {
        copiaStringa(matrice[i], buffer, strlen);
        i++;
      }
    }
    //scorro la matrice al contrario e ne stampo i valori nel file di output
    for (int j=i-1; j>=0; j--) output << matrice[j] << " ";

    //chiudo gli stream e ritorno il valore di controllo
    input.close();
    output.close();
  }
  return x;
}

int contaCaratteri(char stringa[]) {
  int strlen = 0;
  for (; stringa[strlen] != '\0'; strlen++) {}
  return strlen;
}

void copiaStringa(char stringa1[], char stringa2[], int stringa2_dim) {
  for (int i=0; i<stringa2_dim; i++) {
    stringa1[i] = stringa2[i];
  }
}