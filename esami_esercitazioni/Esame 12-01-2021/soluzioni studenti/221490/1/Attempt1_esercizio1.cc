// GDT: la soluzione proposta è forse un po' troppo complicata.// Il codice esegue parzialmente e non riporta risultati corretti.
// Fare riferimento alla soluzione ufficiale per un possibile svolgimento dell'esercizio.

#include <iostream>
#include <fstream>
using namespace std;

struct nodo
{
  char *value;
  nodo *next;
};
typedef nodo *Pila;

Pila pila;

bool vuota();
void push(char c[]);
char *pop();

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    cout << "Errore nell'usura del programma; usage: ./a.out <file input> <file output>";
    exit(1);
  }
  else
  {
    ifstream file_in;
    ofstream file_out;
    pila = NULL;

    file_in.open(argv[1], ios::in);
    file_out.open(argv[2], ios::out);

    char c[255];
    if (!file_in.is_open())
    {
      cout << "Il file passanto in input come primo parametro non esiste!" << endl;
      exit(1);
    }
    if (!file_out.is_open())
    {
      cout << "Il file passanto in input come secondo parametro non esiste!" << endl;
      exit(1);
    }

    while (file_in >> c)
    {
      cout << c << endl;
      push(c);
    }
    char *parola;
    while (!vuota())
    {
      parola = pop();
      file_out << parola << endl;
      cin.ignore();
    }
    file_in.close();
    file_out.close();
  }

  return 0;
}

bool vuota()
{
  return (pila == NULL);
}
void push(char c[])
{
  Pila nuovo_nodo = new nodo;
  nuovo_nodo->value = c;
  cout << nuovo_nodo->value << endl;
  nuovo_nodo->next = pila;
  pila = nuovo_nodo;
}
char *pop()
{
  if (vuota())
  {
    char *n = new char[255];
    for (int i = 0; i < 255; i++)
      n[i] = '\0';
    Pila primo_nodo = pila;
    n = primo_nodo->value;
    cout << n << endl;
    pila = primo_nodo->next;
    delete primo_nodo;
    return n;
  }
}
