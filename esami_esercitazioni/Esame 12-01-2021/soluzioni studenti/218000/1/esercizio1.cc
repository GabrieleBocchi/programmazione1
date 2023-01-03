// GDT: manca deallocazione della matrice mat. Nella funzione controlla_parola(), il controllo del carattere
// ASCII non è corretto. Non puoi sapere se le lettere maiuscole vengano prima delle lettere maiuscole o viceversa.
// Dipende dalla codifica e il tuo codice deve funzionare indipendentemente dalla codifica usata. Inoltre, per la
// consegna dell'esercizio, nel conteggio dei caratteri, vanno considerati anche i segni di punteggiatura (e.g. esempio! ha
// 8 caratteri). 
//
// Manca la deallocazione della matrice mat.

using namespace std;
#include <iostream>
#include <fstream>

bool controlla_parola(char parola[]);
void strcopy(char parola1[], char parola2[]);
const int max_caratteri = 100;
const int max_parole = 10000;
int main(int argc, char * argv[])
{
  if(argc != 3)
    {
      cout << "Usage: temp <filein> <fileout>" << endl;
      exit(0);
    }

  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  if(input.fail() || output.fail())
    {
      cout << "File non presenti" << endl;
      exit(0);
    }

  char **mat;
  mat = new char *[max_parole];
  for(int i = 0; i < max_parole; i++)
    {
      mat[i] = new char[max_caratteri];
    }
  
  char buffer[max_caratteri];
  int contatore_parola = 0;
  input >> buffer;
  while(!input.eof())
    {
      if(controlla_parola(buffer) && (contatore_parola < max_parole))
	{
	  strcopy(mat[contatore_parola], buffer);
	  contatore_parola++;	  
	}
      input >> buffer;
    }

  for(int i = contatore_parola-1; i >= 0; i--)
    {
      output << mat[i] << " ";
    }
  cout << endl;
  
  


  return 0;
}

bool controlla_parola(char parola[])
{
  int contatore_caratteri = 0;
  bool dispari = false;
  while((parola[contatore_caratteri] > 'A') && (parola[contatore_caratteri] < 'z'))
  {
    contatore_caratteri++;    
  }

  if(contatore_caratteri % 2 != 0)
    dispari = true;

  return dispari;
  
}

void strcopy(char parola1[], char parola2[])
{
  int i = 0;
  while((parola2[i] > 'A') && (parola2[i] < 'z'))
    {
      parola1[i] = parola2[i];
      i++;
    }
}
