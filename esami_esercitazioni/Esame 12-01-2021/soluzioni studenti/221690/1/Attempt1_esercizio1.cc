// GDT: il codice � corretto, per� tutti questi if innestati lo rendondo difficile
// da leggere. Inoltre, � complicato capire il flusso di esecuzione. Fare riferimento
// alla soluzione ufficiale per un possibile svolgimento con meno istruzioni condizionali.
 
#include <iostream>
#include <fstream>

using namespace std;

int string_len(char*);

int main(int argc, char* argv[]) {
	int retval = 0;

	if (argc != 3) {
		cout << "uso corretto del programma: ./a.out input_file output_file" << endl;
		retval = 1;
	}
	else {
		fstream in, out;
		in.open(argv[1], ios::in);
		if (in.fail()) {
			cout << "non � stato possibile aprire il fine in input" << endl;
			retval = 2;
		}
		else {
			out.open(argv[2], ios::out);
			if (out.fail()) {
				cout << "non � stato possibile aprire il fine di output" << endl;
				in.close();
				retval = 2;
			}
			else {
				char pfile[10000][101];
				int i = 0;
				while (!in.eof()) {
					in >> pfile[i];
					if (string_len(pfile[i]) > 4) {
						i++;
					}
				}
				i -= 1;
				for (i; i >= 0; i--) {
					out << pfile[i] << " ";
				}
				in.close();
				out.close();
			}
		}
	}
	return(retval);
}

int string_len(char* c) {
	int i = 0;
	while (c[i++] != '\0');
	return(i - 1);
}
