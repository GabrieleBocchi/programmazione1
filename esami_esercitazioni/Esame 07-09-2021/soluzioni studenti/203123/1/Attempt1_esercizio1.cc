// GDT: il codice non riporta il risultato corretto in alcuni casi di test.
// Vedi commenti nel codice

#include <iostream>
#include <fstream>
#include <cstring>
#define MAX_WORDLEN 200
using namespace std;

bool checkLowercase(char letter);
char correctChar(char letter);

int main(int argc, char * argv [])
{
	if(argc != 3){
		cout << "Wrong arguments, correct usage: " << "esercizio1" << argv[1] << " " << argv[2] << endl;
		exit(1);
	}
	ifstream input;
	ofstream output;
	input.open(argv[1], ios::in);
	output.open(argv[2], ios::out);
	if(input.fail() || output.fail()){
		cout << "Errore apertura file";
		input.close();
		output.close();
		exit(1);
	}
	char buffer[MAX_WORDLEN];
	bool checkNext = false;
	bool isStart = true;
	while(input >> buffer){
		if(isStart == true){
			if(checkLowercase(buffer[0])){
				int value = (int)buffer[0];
				buffer[0] = value +32;
			}
			isStart = false;
		}
		if(checkNext == true){
			buffer[0] = correctChar(buffer[0]);
			checkNext = false;
		}
		int len = strlen(buffer);
		if(buffer[len-1] == ',' || buffer[len] == ':' || buffer[len] == ';'){
			checkNext = true;
			output << endl;
		}
		output << buffer << " ";
	}
	input.close();
	output.close();
  return 0;
}

// GDT: per fare il controllo da maiuscolo a minuscolo stai usando direttamente i
// codici ASCII, ed è errato (visto che così il codice non potrebbe funzionare
// su una macchina con codifica differente.)
// Infatti, il file in output generato contiene dei caratteri illeggibili.
// Fare riferimento alla soluzione ufficiale per un possibile svolgimento.
bool checkLowercase(char letter){
	int value = letter;
	if(!((value <= 90 && value >= 65) || (value <= 122 && value >= 97))){
		cout << "not a letter" << endl;
		return true;
	}
	return (value <= 122 && value >= 97 ? true : false);
}

char correctChar(char letter){
	int value = letter;
	if(!checkLowercase(letter)){
		return value + 32;
	}
	return value;
}
