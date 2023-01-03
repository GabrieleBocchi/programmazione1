#include <iostream>
#include <cstddef>

using namespace std;

void print(const int a[], const int s, const char * prefix) {
	cout << prefix;
	for (int i = 0; i < s; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void read_elements(int s[], const int ms, int & s_s) {
	int r = 0;
	for (s_s = 0; ((s_s < ms) && (r != -1)); ) {
		cin >> r;
		if (r != -1) s[s_s++] = r;
	}
}

void get_elements(int* source, int sourceDim, int* dest1, int dest1MaxDim,
					int dest1Dim, int* dest2, int dest2MaxDim, int dest2Dim) {
  // MR: NON ACCETTABILE. L'esercizio richiedeva "Scrivere nel file
  // esercizio2.cc la dichiarazione e la definizione della funzione
  // ricorsiva get_elements che..." e nel terzo punto della nota "La
  // funzione get_elements deve essere ricorsiva ed al suo interno non
  // ci possono essere cicli o chiamate a funzioni contenenti
  // cicli. Si può però fare uso di eventuali funzioni ricorsive
  // ausiliarie all’interno di questa funzione.". Consiglio di leggere
  // con attenzione TUTTO il testo!
	for(int i = 0; i < sourceDim; i++) {
		if(source[i] %3 == 0 && source[i] %2 == 0) {
			int temp = source[i];
			dest1[i] = temp * 2;
			dest1Dim++;
		} else {
			int temp = source[i];
			dest2[i] = temp * 3;
			dest2Dim++;
		}
	}
}

int main() {
	const int maxdim = 10;

	const int md1_s = maxdim;
	int d1[md1_s];
	int d1_s = 0;

	const int md2_s = maxdim;
	int d2[md2_s];
	int d2_s = 0;

	const int ms = maxdim;
	int s[ms];
	int s_s = 0;

	read_elements(s, ms, s_s);

	get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);
	print(s, s_s, "Source = ");
	print(d1, d1_s, "D1     = ");
	print(d2, d2_s, "D2     = ");

}
