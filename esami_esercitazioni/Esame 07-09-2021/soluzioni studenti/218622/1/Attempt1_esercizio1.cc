// GDT: l'esercizio va bene, ma c'è una leggera imprecisione nel ciclo while
// Vedere i commenti nel codice.
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char * argv [])
{
  fstream input, output;
  char parola [200];
  bool minuscola = false;

  if (argc != 3)
    cout << "\n Errore." << endl;

  input.open (argv[1], ios::in);
  output.open (argv[2], ios::out);

  input >> parola;
  if (parola[0] > 'Z')
    parola [0] = parola[0] - 'a' + 'A';

  output << parola << " ";
  input >> parola;

  // GDT: quando si utilizza !input.eof(), la sintassi corretta è la seguente.
  // Altrimenti, l'ultima parola viene scritta in output due volte!
  //
  // input >> parola;
  // while (!input.eof ()){
  //  ...
  //  input >> parola;
  // }

  while (!input.eof ()){
    input >> parola;
    if (minuscola && parola[0] <= 'Z')
      parola[0] = parola[0] - 'A' + 'a';

    minuscola = false;

    for (int i = 0; parola[i] != '\0'; i++)
      if (parola [i] == ',' || parola[i] == ':' || parola[i] == ';')
        minuscola = true;

    output << parola << " ";
  }

  input.close();
  output.close();

  return 0;
}
