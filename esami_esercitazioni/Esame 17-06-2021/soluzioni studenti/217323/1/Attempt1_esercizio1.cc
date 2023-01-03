#include <iostream>
#include <fstream>
using namespace std;

const int MAXDIM = 100 + 1; //+1 per il terminatore di stringa

int length(char *s);
bool numero_lettere_i(char *s);
bool controllo_inizio_fine(char *s);
bool controllo_sequenza_mi(char *s);

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    cerr << "Errore nell'utilizzo: <./a.out> <input.txt> <output.txt>" << endl;
    exit(1);
  }
  fstream input, output;
  input.open(argv[1], ios::in);
  if (input.fail())
  {
    cerr << "Errore nell'apertura del file di input" << endl;
    input.close();
    exit(2);
  }
  output.open(argv[2], ios::out);
  if (output.fail())
  {
    cerr << "Errore nell'apertura del file di oputput" << endl;
    input.close();
    output.close();
    exit(2);
  }
  char buffer[MAXDIM];
  while (!input.eof())
  {
    input>>buffer;
    cout<<buffer<< " ";
    if (numero_lettere_i(buffer) && controllo_inizio_fine(buffer) && controllo_sequenza_mi(buffer))
    { //stampo se e solo se le funzioni tornano true
      output << buffer << endl;
    }
  }

  input.close();
  output.close();
  return 0;
}

int length(char *s)
{
  int i = 0;
  while (s[i] != '\0')
  {
    i++;
  }
  return i;
}

bool controllo_inizio_fine(char *s)
{ //funzione che controlla se la prima parola è U allora l'ultima deve essere M
  bool resval = true;
  cout<<s[0]<< " "<<s[length(s)-1]<<endl;
  if (s[0] == 'U')
  {
    
    if (s[length(s)-1] != 'M')
    {
      resval = false;
    }
  }
  return resval;
}

bool numero_lettere_i(char *s)
{
  bool resval = false;
  int counter_i = 0; //conta quante sono le lettere 'I' nella parola
  int index = 0;     //serve per scorrere la stringa
  while (s[index] != '\0')
  {
    if (s[index] == 'I')
    {
      counter_i++;
    }
    index++;
  }
  if ((counter_i % 2) == 0)
  {                //la parola rientra nello standard solo se il numero di I è pari o nullo. nel caso di 0%2 ritorna
    resval = true; //comunque 0 e va bene
  }
  return resval;
}

bool controllo_sequenza_mi(char *s)
{
  bool resval = true;
  int index = 0;
  int prossimo = 1;
  while (prossimo < length(s) && resval)
  { //mi interessa solo che arrivi alla fine della parola
    if (s[index] == 'M')
    {
      if (s[prossimo] == 'I')
      {                 //se la lettera precedente è una M allora la prossima DEVE essere diversa da I
        resval = false; //se una volta accade che la sequenza sia del tipo "MI" allora esco dal ciclo
      }
    }
    index++;
    prossimo++;
  }
  return resval;
}