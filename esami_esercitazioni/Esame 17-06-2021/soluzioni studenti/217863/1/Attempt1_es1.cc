// Giovanni: il programma non ritorna il risultato corretto per certi casi di test.
// Questo è causato dal fatto che, il programma assume che solo le parole che VERIFICANO
// tutte e tre le condizioni appartengono a MIU, quando in realtà non è vero.
// Ad esempio, per la descrizione dell'esercizio UUUU appartiene a MIU. 

#include <iostream>
#include <fstream>

using namespace std;
const int MAX_LENGHT = 100 + 1;

int getLenght(char *array)
{
  int res = 0;
  while (array[res] != '\0')
  {
    res += 1;
  }
  return res;
}

int get(char val, char *array)
{
  int res = 0;
  int index = 0;
  while (array[index] != '\0')
  {
    if (array[index] == val)
      res += 1;
    index += 1;
  }
  return res;
}

int main(int argc, char *argv[])
{
  if (argc < 3)
  {
    cout << "Parametri mancanti" << endl;
    exit(1);
  }
  else
  {
    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    if (input.fail() || output.fail())
    {
      cout << "errore apertura del file" << endl;
      exit(1);
    }

    char buffer[MAX_LENGHT];
    while (input >> buffer)
    {
      bool addToOutput[] = {false, false, false};
      int size = getLenght(buffer);
      //regola 1
      if (buffer[0] == 'M' && buffer[size - 1] == 'U')
        addToOutput[0] = true;
      //regola 2
      if ((get('I', buffer) % 2) == 1 || get('I', buffer) == 0)
        addToOutput[1] = true;
      //regola 3
      int index = 0;
      bool flag = true;
      while (buffer[index] != '\0')
      {
        if (buffer[index] == 'M' && index > 1)
        {
          if (buffer[index-1] == 'I')
            flag = false;
        }
        index += 1;
      }
      addToOutput[2] = flag;

      //controllo tutto
      if (addToOutput[0] && addToOutput[1] && addToOutput[2])
      {
        //output
        output << buffer << endl;
      }
    }
    input.close();
    output.close();
  }
  return 0;
}
