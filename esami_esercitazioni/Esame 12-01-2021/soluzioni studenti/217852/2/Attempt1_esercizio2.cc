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

int verificaCaratteri(char s[], char d1[], int md1_s, int d1_s, int i){
  //MR: Indentazione illeggibile!
	char a;

	if(s[i]=='\0' || i==md1_s)
		return d1_s;
	else{

		if(s[i]>='a' && s[i]<='z'){


			a=toupper(s[i]);
			// MR: Questa funzione era espressamente specificato di NON usarla!
			d1[d1_s]=a;
			d1_s++;

		}

		i++;

		return verificaCaratteri(s, d1, md1_s, d1_s, i);

	}

}

int verificaCifre(char s[], char d2[], int md2_s, int &d2_s, int i){
  //MR: Indentazione illeggibile!
	if(s[i]=='\0' || i==md2_s)
		return d2_s;
	else{

		if(isdigit(s[i])){
		  // MR: Questa funzione era espressamente specificato di NON usarla!
		  // Si poteva fare più efficientemente con '9' - (s[i] - '0');
			if(s[i]=='9')
				s[i]='0';
			if(s[i]=='8')
				s[i]='1';
			if(s[i]=='0')
				s[i]='9';
			if(s[i]=='1')
				s[i]='8';

			d2[d2_s]=s[i];
			d2_s++;

		}

		i++;

		return verificaCifre(s, d2, md2_s, d2_s, i);

	}

}

void get_elements(char *, int ,char *, int , int , char *, int , int);
  //MR: Non viene calcolata e propagata informazione al chiamante
  //perchè d1_s e d2_s non sono passati per riferimento!

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

  return 0;

}

void get_elements(char s[], int s_s,char d1[], int md1_s, int d1_s, char d2[], int md2_s, int d2_s){
  //MR: Non viene calcolata e propagata informazione al chiamante perchè d1_s e d2_s non sono passati per riferimento!
	int i=0;

	d1_s=verificaCaratteri(s, d1, md1_s, d1_s, i);

	d2_s=verificaCifre(s, d2, md2_s, d2_s, i);

}
