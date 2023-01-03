#include <iostream>
#include <fstream>
using namespace std;

const int MAX_WORDS = 10000;
const int MAX_CHARS = 101;

int strlen (char string[]);

int main(int argc, char * argv [])
{
  if (argc != 3)
  {
    cerr << "Usage: <executable> <input_file> <output_file>\n";
  }

  else
  {
    fstream input, output;
    input.open (argv[1], ios::in);
    if (input.fail())
    {
      cerr << "File inesistente o permessi insufficienti\n";
    }

    else
    {
      output.open (argv[2], ios::out);
      if (output.fail())
      {
        cerr << "Permessi insufficienti in scrittura\n";
      }

      else
      {
        char buffer[MAX_WORDS][MAX_CHARS];
        int i = 0;
        while (input >> buffer[i] && i<MAX_WORDS)
        {
          if (strlen (buffer[i]) > 4)
          {
            i++; //In questo modo la "dimensione effettiva" viene incrementata solo se la lunghezza e' adeguata: in caso contrario la stringa non verra' considerata o sovrascritta
          }
        }
        input.close();
	
	// GDT: è sempre meglio inizializzare la variabile del for.
	// Si rischia di fare confusione e di generare bug nel codice difficili
	// da identificare (ad esempio se un altra persona lavora sul tuo codice).
        for (; i > 0; i--)
        {
          output << buffer[i-1] << " ";
        }
        
        output.close();
        cout << "Operazione completata con successo\n";
      }
    }
  }
  return 0;
}

int strlen (char string[])
{
  int counter;
  for (int i=0; string[i] != '\0' && i<MAX_CHARS; i++)
  {
    counter++;
  }

  return counter;
}
