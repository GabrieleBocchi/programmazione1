#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <ctype.h>

using namespace std;

int main(int argc, char * argv[])
{
	if(argc != 3)
	{
		cout << "Usage: ./a.out <input.txt> <output.txt>" << endl;
		exit(1);
	}
	
	fstream input,output;
	input.open(argv[1],ios::in);
	output.open(argv[2],ios::out);
	
	if(input.fail())
	{
		cout << "Errore nella apertura del file" << endl;
		input.close();
		output.close();
		exit(1);
	}
	
	char buffer[256];
	int contatore = 0;
	bool guardia = false;
	while(input >> buffer)
	{
		guardia = true;
		//controllo la lunghezza della scritta, deve essere di 16
		if(strlen(buffer) == 16)
		{
			for(int i = 0; i < strlen(buffer); i++)
			{
				if(i <= 11)
				{	
					//controllo se i primi 12 elementi sono numeri interi
					if(!isdigit(buffer[i]))
					{
						guardia = false;
					}
					
				}
				else
				{
					//controllo se gli ultimi 4 caratteri sono maiuscoli
					if(buffer[i] > 90 or buffer[i] < 65)
					{
						guardia = false;
					}
				}
			}	
		}else{
			guardia = false;
		}
		
		if(guardia == true)
			contatore++;
	}
	
	output << contatore;
	
	input.close();
	output.close();
	return 0;
}