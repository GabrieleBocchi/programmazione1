// GDT: il codice è corretto, però non esegue e non genera output.
// Il problema nasce dal fatto che, quando controlli di aver aperto correttamente
// il file in output, utilizzi ancora la variabile del file in input (fin invece che
// fout). Ovviamente, una volta chiuso lo stream, fin.fail() da come risultato true
// e quindi da un errore. Questo purtroppo risulta in una penalizzazione.

#include <iostream>
#include <fstream>

#define MAX_PAROLE 10000
#define PAROLA_LEN 100

using namespace std;

bool isLenPari( char* buffer );

int main(int argc, char ** argv) {
	fstream fin;
	char ** parole;


	if( argc != 3 ){
		cout << "Usage: <executable> <file_input> <file_output>" << endl;
		exit(1); //Using error code 1 for incorrect parameters
	}else{
		fin.open(argv[1], ios::in);

		if( fin.fail() ){
			cout << "IO Error: file not found !" << endl;
			exit(2);
		}else{
			int dim = 0;
			char * buffer;
			parole = new char* [MAX_PAROLE];
			
			//Lettura
			buffer = new char [PAROLA_LEN];
			fin >> buffer;		
			while( !fin.eof() ){
				if( isLenPari(buffer) )
					parole[dim++] = buffer;
				else
					delete [] buffer;
				buffer = new char [PAROLA_LEN];
				fin >> buffer;
			}
			delete [] buffer;
			fin.close();

			//Elaborazione
			fstream fout;
			fout.open(argv[2], ios::out);
			
			if( fin.fail() ){
				cout << "IO Error: file creation error !" << endl;
				exit(3);
			}else{
				for( int i = dim-1; i >= 0 ; i-- )
					fout << parole[i] << " ";
				
				fout.close();

				//Deallocazione
				dim-=1;
				while(dim >= 0)
					delete [] parole[dim--];
				delete [] parole;
			} 
		}
	}
	return 0;
}

bool isLenPari( char* buffer ){
	int i = 0;
	for( ; buffer[i] != '\0' ; i++ );

	if ( i % 2 == 0)
		return true;
	else
		return false;
}
