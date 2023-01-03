#include <cstddef>
#include <iostream>

using namespace std;

void get_elements(char* source, int source_DIM, char* dest1, int dest1_DIM_MAX, int& dest1_DIM, char* dest2, int dest2_DIM_MAX, int& dest2_DIM, int i = 0);

void print(const char a[], const int s, const char* prefix) {
    cout << prefix;
    for (int i = 0; i < s; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void read_elements(char s[], const int ms, int& s_s) {
    char r = '\0';
    for (s_s = 0; ((s_s < ms) && (r != '\n'));) {
        r = cin.get();
        if ((r != '\n') && (r != ' ')) s[s_s++] = r;
    }
}

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

void get_elements(char* source, int source_DIM, char* dest1, int dest1_DIM_MAX, int& dest1_DIM, char* dest2, int dest2_DIM_MAX, int& dest2_DIM, int i) {

    //se non ho raggiunto la fine dell'array source
    if (i < source_DIM) {

        //calcolo dest1
        //controllo se dest1 non è pieno
        if (dest1_DIM <= dest1_DIM_MAX) {
            //controllo che il carattere attuale sia una lettera minuscola dell'alfabeto

	    // MR: dest1_DIM deve essere minore stretto di
	    // dest1_DIM_MAX altrimenti accede a memoria non del
	    // programma.
            if (source[i] >= 'a' && source[i] <= 'z') {
                //salvo la lettera minuscola come lettera maiuscola in dest1
                dest1[dest1_DIM] = source[i] + ('A' - 'a');

                //incremento il contatore dimensione di dest1
                dest1_DIM++;
            }
        }

        //calcolo dest2
        //controllo se dest2 non è pieno
        if (dest1_DIM <= dest1_DIM_MAX) {
            //controllo se il carattere attuale è un numero
	    // MR: dest1_DIM deve essere minore stretto di
	    // dest1_DIM_MAX altrimenti accede a memoria non del
	    // programma.
            if (source[i] >= '0' && source[i] <= '9') {
                //converto il carattere in numero
                int tmp = source[i] - '0';

                //converto il numero secondo la codifica dell'esercizio
                tmp = 9 - tmp;

                //salvo il numero come carattere in dest2
                dest2[dest2_DIM] = tmp + '0';

                //incremento il contatore dimensione di dest1
                dest2_DIM++;
            }
        }

        //chiamata ricorsiva
        get_elements(source, source_DIM, dest1, dest1_DIM_MAX, dest1_DIM, dest2, dest2_DIM_MAX, dest2_DIM, i + 1);
    }
}
