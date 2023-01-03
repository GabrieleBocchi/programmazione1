#include <iostream>
#include <cstdlib>


/* Inserire qui sotto la dichiarazione della funzione extract */
char * extract (char stringa[]);
/* Inserire qui sopra la dichiarazione della funzione extract */

char * copiastringhe(char stringa[],int indice,char nuovastringa[]);
char * estraicaratteri(char stringa[],char nuovaStringa[],int indice,int dimensione);

/* Solo di esempio, non fate assunzioni su questo valore */
const int DIM = 255;

int main(int argc, char ** argv) {
  char input_string[DIM+1];
  char * extracted;
  char answer;

  do {
    std::cout << "Inserire la stringa da controllare: ";
    std::cin >> input_string;

    extracted = extract(input_string);
    std::cout << "La stringa estratta e': " << extracted << std::endl;

    delete [] extracted;
    std::cout << "Si vuole inserire un'altra stringa? [*/n]";
    std::cin >> answer;
  } while (answer != '\0' && answer != 'N' && answer != 'n');
  return 0;
}

/* Inserire qui sotto la definizione della funzione estract */
char * extract (char stringa[])
{
    char nuovaStringa[256];
    //  MR: Dove era specificato che la lunghezza massima della
    //  stringa doveva essere 256? Inoltre, non fa alloc, e quindi
    //  quando nel main si chiama la delete si verifica una eccezione!
    return estraicaratteri(stringa,nuovaStringa,0,0);
}
/* Inserire qui sopra la definizione della funzione estract */

char * estraicaratteri(char stringa[],char nuovaStringa[],int indice,int dimensione)
{
    if(stringa[indice]=='$')
    {
        return estraicaratteri(stringa,nuovaStringa,indice+1,dimensione);
        std::cout<<stringa[indice];
    }

    else if(stringa[indice]!='\0')
    {
        nuovaStringa[dimensione]=stringa[indice];
        dimensione++;
        estraicaratteri(stringa,nuovaStringa,indice+1,dimensione);
	// MR: Manca return?
    }
    else
    {
        return nuovaStringa;
	// MR: Manca inserimento del terminatore di stringa!
    }

}
