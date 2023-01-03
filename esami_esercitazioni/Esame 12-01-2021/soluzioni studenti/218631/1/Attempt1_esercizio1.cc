#include <iostream>
#include <fstream>

using namespace std;

// GDT: il codice di per se non rispetta le consegne. Fare riferimento alla soluzione ufficiale
// per lo svolgimento.

void readFile(char* fileName);
void changeWords(char* array);
void writeFile(char* fileName);

int main(int argc, char * argv []) {
	char fileNameIn[100];
	char fileNameOut[100];
	
	cout << "Inserire il nome del file (input): ";
	cin >> fileNameIn;
	
	cout << "Inserire il nome del file (output): ";
	cin >> fileNameOut;
	
	readFile(fileNameIn);

	return 0;
}

void readFile(char* fileName) {
	ifstream file(fileName);
	char word[100];
	
	while(file >> word) {
		if(sizeof(word) %2 == 0) {
			cout << word << endl;
		}
	}
	
	file.close();
}

void changeWords(char* array, int dim) {
	char temp[100];
	
	for(int i = 0; i < dim; i++) {
		//for(int j = 0; i < )
		temp[i] = array[dim-i];
		//array[i] = 
	}
}

void writeFile(char* fileName, char* output) {	
	ofstream file(fileName);
	
	for(int i = 0; i < 12; i++) {
		file << output[i];
	}
	
	file.close();
}
