#include <iostream>
#include <fstream>
#include <ctype.h>


using namespace std;


int main(int argc, char * argv [])
{

	// Controllo se il numero degli argomenti è corretto
	if (argc != 3){
	
		cout << "Usage: esercizio1 <input_file> <output_file>" << endl;
		exit(1);
	}

	// Creo i miei stream
	fstream input, output;
	input.open(argv[1], ios::in);
	output.open(argv[2], ios::out);


	// Controllo se riesco ad aprire il file di input
	if (input.fail() || output.fail()){
	
		cout << "Non trovo uno dei file di I/O" << argv[1]  << " " << argv[2] << endl;
		input.close();
		output.close();
		exit(1);
	}

	char tmp [200];

	input>>tmp;

	int flag=0;
	int flag_first=1;

	while (!input.eof()){

		//Se la parola prima ha un punto e questa di ora è minuscola va messa la maiuscola. 



		if(flag_first==1 && (tmp[0]>='a' && tmp[0]<='z')){

			tmp[0]=toupper(tmp[0]);

			} 

		
		flag_first=0;
//sicu

		if(flag==1 && flag_first==0 && tmp[0]>='A' && tmp[0]<='Z'){

			tmp[0]=tolower(tmp[0]);

			} 



		int e=0;
		
		while (tmp[e]!='\0')
		{
			e++;
		}
		

		int dim=e-1;

		if(tmp[dim]==',' || tmp[dim]==':' || tmp[dim]==';')
		flag=1;
		else flag =0;

		output << tmp << " "; 

		input >> tmp; 

	}

	



	//chiusura degli stream
	input.close();
	output.close();


return(0);
}
