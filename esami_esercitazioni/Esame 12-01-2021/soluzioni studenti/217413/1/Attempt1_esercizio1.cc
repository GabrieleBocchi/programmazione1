// GDT: guardare le soluzioni ufficiali per lo svolgimento

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_PAROLE = 10000;
const int DIM_PAROLA = 100;


int main(int argc, char * argv [])
{

  if (argc != 3) {
    cout << "Sintassi: ./a.out input_A.txt output.txt\n";
  	exit(0);
  }


	fstream input, output;

	input.open(argv[1], ios::in);
	output.open(argv[2], ios::out);

  if (input.fail()) {
      cerr << "Il file " << argv[1] << " non esiste o non è accessibile.\n";
      exit(-1);
  }

	char buffer[MAX_PAROLE];
	input >> buffer;


	while(!input.eof()) {
		output << buffer << " ";
    input >> buffer;

	}
	output << endl;

	input.close();
	output.close();

  return 0;
}
