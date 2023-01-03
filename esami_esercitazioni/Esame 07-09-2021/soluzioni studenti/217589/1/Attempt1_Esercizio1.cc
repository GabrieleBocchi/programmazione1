// GDT: il codice non riporta il risultato corretto in alcuni casi di test.
// Vedi commenti nel codice

#include <iostream>
#include <fstream>



using namespace std;

const int MAX_DIM=256;
//suppongo che il valore massimo di una parola sia 256

int main(int argc, char *argv[]){
  fstream input, output;

  char buffer[MAX_DIM];

  if (argc != 3) {
    cerr << "Usage: ./a.out <input> <output>" << endl;
    exit(1);
  }
  input.open(argv[1], ios::in);
  if (input.fail()) {
    cerr << "There is a problem in " << argv[1] << " and the process has been closed" << endl;
    input.close();
    exit(0);
  }
  output.open(argv[2], ios::out);
  if (output.fail()) {
  cerr << "There is a problem in " << argv[2] << " and the process has been closed" << endl;
    output.close();
    exit(0);
  }

  while (!input.eof())
  {
    // GDT: quando usi eof(), input >> buffer() deve essere usato una volta
    //prima dell'inizio del ciclo. In caso contrario, andrai a scrivere due
    // volte l'ultima parola letta.
    input >> buffer;

    for (int i=0; buffer[i] != '\0' &&  buffer[i] != '\n'; i++)
      {
        if (!(buffer[0] >= 'A' && buffer[0] <= 'Z'))
	  {
      // GDT: fare riferimento alla soluzione ufficiale per un possibile
      // svolgimento
	    buffer[0] = buffer[0] + ('A'-'a');

	  }
      }
    output << buffer << " ";
    cout << buffer << " ";
  }

 input.close();
 output.close();

  return 0;
}
