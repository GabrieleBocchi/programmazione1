#include <iostream>
#include <cstddef>

using namespace std;

void print(const char a[], const int s, const char * prefix) {
  cout << prefix;
  for (int i = 0; i < s; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void read_elements(char s[], const int ms, int & s_s) {
  char r = '\0';
  for (s_s = 0; ((s_s < ms) && (r != '\n')); ) {
    r = cin.get();
    if ((r != '\n') && (r != ' ')) s[s_s++] = r;
  }
}
void get_elements(char*,int,char*,int,int&,char*,int,int&);
char* get_letter(char*,int,int, char*,int&,int);
char* get_number(char*,int,int, char*,int&,int);
int main() {
  const int maxdim = 10;

  const int md1_s = maxdim;
  char d1[md1_s];
  int d1_s = 0;

  const int md2_s = maxdim;
  char d2[md2_s];
  int d2_s = 0;

  const int ms = maxdim;
  char s[ms];
  int s_s = 0;

  read_elements(s, ms, s_s);

  get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);

  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}

void get_elements(char* source, int indiceS, char* dest1, int dim1,int& indice1,char* dest2, int dim2,int& indice2){

    int cont=0;
    dest1=get_letter(source,cont,indiceS,dest1,indice1,dim1);
    dest2=get_number(source,cont,indiceS,dest2,indice2,dim2);
    // MR: e' parzialmente corretto, ma molto inefficiente, infatti fa
    // numero doppio di chiamate ricorsive rispetto a quelle che
    // sarebbero state necessarie. Infatti, le due funzioni fanno
    // quasi le stesse cose, e si potevano quindi mettere degli if per
    // discernere in quale dei due casi si era!
}

char* get_letter(char* source, int cont, int indiceS, char* dest1,int& indice1,int dim1){
  // MR: Ricordo che questa funzione cosi' come scritta ritorna
  // indirizzo di primo elemento dell'array!
    if(cont>indiceS || indice1==dim1){
      // MR: indiceS e' dimensione dell'array source. Gli indici vanno
      // quindi da 0 a indiceS - 1, se mette solo >, allora quando
      // cont e' uguale ad indiceS accede a memoria non del programma
      // nel caso else qui sotto!
        return dest1;
    }else{
        if(source[cont]>='a' && source[cont]<='z'){

            int tmp=source[cont]-'a';
            int tmp2='A'+tmp;
            dest1[indice1]=tmp2;
            indice1++;
        }
        cont++;
        return get_letter(source,cont,indiceS,dest1,indice1,dim1);

    }

}

char* get_number(char* source, int cont, int indiceS, char* dest2,int& indice2,int dim2){
  // MR: Ricordo che questa funzione cosi' come scritta ritorna
  // indirizzo di primo elemento dell'array!
    if(cont>indiceS || indice2==dim2){
        return dest2;
      // MR: indiceS e' dimensione dell'array source. Gli indici vanno
      // quindi da 0 a indiceS - 1, se mette solo >, allora quando
      // cont e' uguale ad indiceS accede a memoria non del programma
      // nel caso else qui sotto!
    }else{
        if(source[cont]>='0' && source[cont]<='9'){


            dest2[indice2]=source[cont];
	    // MR: Manca la conversione
            indice2++;
        }
        cont++;
        return get_number(source,cont,indiceS,dest2,indice2,dim2);

    }

}
