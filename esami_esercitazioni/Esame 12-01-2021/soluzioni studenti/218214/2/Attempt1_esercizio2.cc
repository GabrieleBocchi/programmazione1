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
    for (s_s = 0; ((s_s < ms) && (r != -1));) {
        cin >> r;
        if (r != -1) s[s_s++] = r;
    }
}

void get_elements(int* source, int dim_source, int* dest1, int dim_max1, int& dim1, int* dest2, int dim_max2, int& dim2);

void aux(int* source, int dim_source, int index_source, int* dest1, int index1, int* dest2, int index2);

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

void get_elements(int* source, int dim_source, int* dest1, int dim_max1, int& dim1, int* dest2, int dim_max2, int& dim2) {
    aux(source, dim_source, 0, dest1, 0, dest2, 0);
    // MR: NON SI PUO' IN QUESTO CASO USARE SIZEOF PER CALCOLARE
    // DIMENSIONE ARRAY. In questo caso dest1 e' un puntatore che ha
    // (sempre) dimensione 64 bit diviso 32 dimensione degli int
    // ottego due! Erano da calcolare con la ricorsione!
    dim1 = sizeof ( dest1) / sizeof (int);
    dim2 = sizeof ( dest2) / sizeof (int);
}

void aux(int* source, int dim_source, int index_source, int* dest1, int index1, int* dest2, int index2) {
    if ((source[index_source] % 3) == 0 && (index_source % 2) == 0) {
      // MR: Nessun controllo che index1 < sua dim massima
        dest1[index1] = source[index_source];
        index1++;
    } else {
      // MR: Nessun controllo che index2 < sua dim massima
        dest2[index2] = source[index_source];
        index2++;
    }
    if (index_source <= dim_source) {
      // MR: In questo modo nelle chiamate ricorsive accede a memoria
      // non dell'array. Gli indici vanno da 0 a N-1 per un array di
      // dimensione N. Inoltre, qui accederebbe non solo a N ma anche
      // a N+1.
        aux(source, dim_source, index_source + 1, dest1, index1, dest2, index2);
    }
}
