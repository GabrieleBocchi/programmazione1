#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    cout << "sintassi: ./a.out <file_input> <file_output> " << endl;
    return 0;
  }
  fstream input, output;

  input.open(argv[1], ios::in);
  if (input.fail())
  {
    cout << "il file di input inserito non è corretto" << endl;
    input.close();
    return 0;
  }

  output.open(argv[2], ios::out);
  if (output.fail())
  {
    cout << "il file di output inserito non è corretto" << endl;
    output.close();
    return 0;
  }
  char parola[100];
  char **parole = new char *[1000];
  int i, j;
  j = 0;
  // Alla fine del file, ogni tanto viene aggiunta doppia l'ultima parola
  // che vai a leggere. Questo capita poichè vai a chiamare input >> parola
  // come prima istruzione del ciclo while. In realtà, dovresti aggiungerlo
  // solo nei posti [1] e [2] perchè funzioni correttamente:
  // [1] input >> parola;
  while (!input.eof())
  {
    input >> parola;
    i = 0;
    while (parola[i] != '\0')
      i++;
    if (i % 2 == 0)
    {
      cout << parola << endl;
      parole[j] = new char[i + 1];
      for (int k = 0; k <= i + 1; k++)
        parole[j][k] = parola[k];
      j++;
    }
    // [2] input >> parola;
  }

  for (int k = j - 1; k >= 0; k--)
  {
    output << parole[k] << " ";
    delete[] parole[k];
  }
  delete[] parole;
  input.close();
  output.close();
  return 0;
}
