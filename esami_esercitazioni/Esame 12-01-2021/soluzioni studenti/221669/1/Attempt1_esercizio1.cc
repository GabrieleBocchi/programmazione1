#include <iostream>
#include <fstream>
using namespace std;

void leggiParole(char* file ,char* array[]);
int lunghezzaParola(char* parola);
void scriviParola(char* parola, char* array[], int indice);
void scriviArray(char* file, char* array[], int DIM);

int main(int argc, char * argv [])
{
  if(argc != 3)
  {
    cout << "problema negli argomenti inseriti nella liena di comando" << endl;
  }
  else
  {
    int DIM = 10000;
    char * arrayParole[DIM];
    leggiParole(argv[1], arrayParole);
    //scriviArray(argv[2], arrayParole, DIM);
  }
  
  return 0;
}


void leggiParole(char* file ,char* array[])
{
  fstream input;
  input.open(file, ios::in);
  if(!input.fail())
  {
    if(!input.eof())
    {
      char parola[100];
      int indice = 0;
      while(input >> parola)
      {
        if(lunghezzaParola(parola) <= 4)
        {
          //scriviParola(parola, array,indice);
          indice++;
        }
      }
    }
  }
  else
  {
    cout << "problemi con l'apertura del file" << endl;
  }
  input.close();
}

void scriviParola(char* parola, char* array[], int indice)
{
  int i = 0;
  while(parola[i] != '\0')
  {
    array[indice][i] = parola[i];
    i++;
  }
  
}

void scriviArray(char* file, char* array[], int DIM)
{
  fstream output;
  output.open(file, ios::out);
  int i = 0;
  while(i < DIM-1)
  {
    output << array[i];
    i++;
  }
  output.close();
}

int lunghezzaParola(char* parola)
{
  int i = 0;
  while (*(parola + i) != '\0')
  {
    i++;
  }
  return i;
}
