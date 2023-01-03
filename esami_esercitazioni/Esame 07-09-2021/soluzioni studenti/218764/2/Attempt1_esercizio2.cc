#include <iostream>


/* Inserire qui sotto la dichiarazione della funzione extract */
char* extract(char* s);
/* Inserire qui sopra la dichiarazione della funzione extract */

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
void aux_extract(char* s, int i,char* p, int dim_p){
  // MR: p non e´ passato per riferimento, quindi non viene mai modificato!
    int pos=dim_p-1;
    // MR: Cosa succede se dim_p e' 0? pos diventa negativo!
    if(s[i]=='\0'){

        p=new char[dim_p];
        p[pos]='\0';
	// MR: che relazione c'e´ tra pos e dim_p? Forse dovrebbe
	// scrivered in dim_p? Inoltre manca spazio per inserire il
	// terminatore di stringa.
	// Inoltre, non essendo passato per riferimento non viene
	// propagato alle altre chiamatre.
    }else{

        if(s[i]=='$'){
            std::cout <<"!";
            aux_extract(s,i+1,p,dim_p);
        }else{
            dim_p++;
            aux_extract(s,i+1,p,dim_p);
            p[pos]=s[i];
        }
    }
}
char* extract(char* s){
    char* estratto;
    aux_extract(s,0,estratto,1);
    return estratto;
}

/* Inserire qui sopra la definizione della funzione estract */
