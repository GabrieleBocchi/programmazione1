// Giovanni: soluzione convoluta. Fare riferimento alla soluzione ufficiale per
// un possibile svolgimento. Il codice non ritorna il risultato corretto per alcuni
// casi di test.
//
// Nella funzione appartiene(), il risultato di default dovrebbe essere vero e
// la funzione dovrebbe ritornare falso se e solo se una delle condizioni è violata.

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_LENGTH = 101; //100+'\0'

bool appartieneMIU( char []);
int lunghezza(char []);
int countI(char []);
bool terzaRegola(char []);

int main(int argc, char * argv [])
{
  fstream fileInput, fileOutput;
  char buffer[MAX_LENGTH];
  int numWord = 0;
  int index = 0;
  char ** words;

  if (argc != 3)
  {
    cout << "Usage : " << argv[0] << " <fileInput> <fileOutput>" << endl;
    exit(1);
  }

  fileInput.open(argv[1], ios::in); //aperrtura file per contare numero di parole presenti
  if (fileInput.fail())
  {
    cout << "Impossiibile aprire file " << argv[1] << endl;
    exit(1);
  }
  while (fileInput >> buffer)
  {
    numWord++;
  }
  fileInput.close();

  words = new char *[numWord]; //allocazione della matrice
  for (int i = 0; i < numWord; i++)
  {
    words[i] = new char[MAX_LENGTH];
  }

  fileInput.open(argv[1], ios::in); //apertura file per salvare le parole nella matrice
  if (fileInput.fail())
  {
    cout << "Impossiibile aprire file " << argv[1] << endl;
    exit(1);
  }
  while (index < numWord && fileInput >> words[index])
  {
    index++;
  }
  fileInput.close();

  //apertura file scrittura e controllo regole
  fileOutput.open(argv[2], ios::out);
  if (fileOutput.fail())
  {
    cout << "Impossibile aprire file " << argv[2] << endl;
    exit(1);
  }
  for (int i = 0; i < numWord; i++)
  {
    if (appartieneMIU(words[i]))
    {
      cout << "Word " << words[i] << " valida" << endl;
      fileOutput << words[i] << endl;
    }
  }
  fileOutput.close();

  //deallocazione memoria
  for (int i = 0; i < numWord; i++)
  {
    delete[] words[i];
  }
  delete[] words;

  return 0;
}

bool appartieneMIU(char word[])
{
  bool appartiene = false;
  int last = lunghezza(word)-1;
  if (word[0] == 'U' && word[last] == 'M')
  {
    if (countI(word)%2 == 0)
    {
      appartiene = true;
    }
    else
    {
      appartiene = false;
    }


    if (terzaRegola(word))
    {
      appartiene = true;
    }
    else
    {
      appartiene = false;
    }
  }
  return appartiene;
}

int lunghezza(char word[])
{
  int count = 0;
  while (word[count] != '\0')
    count++;
  return count;
}

int countI(char word[])
{
  int count = 0;
  int i = 0;
  while (word[i] != '\0')
  {
    if (word[i] == 'I')
    {
      count ++;
    }
    i++;
  }
  return count;
}

bool terzaRegola(char word[])
{
  bool valida = true;
  int index = 0;
  while (word[index] != '\0' && valida)
  {
    if (word[index] == 'M')
    {
      while (word[index] != '\0' && valida)
      {
        if (word[index] == 'I')
        {
          valida = false;
        }
        index++;
      }
    }
    index++;
  }
  return valida;
}
