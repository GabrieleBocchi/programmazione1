#include <iostream>
#include <cstddef>

using namespace std;

void print(const char a[], const int s, const char * prefix)
{
    cout << prefix;
    for (int i = 0; i < s; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void read_elements(char s[], const int ms, int & s_s)
{
    char r = '\0';
    for (s_s = 0; ((s_s < ms) && (r != '\n')); )
    {
        r = cin.get();
        if ((r != '\n') && (r != ' ')) s[s_s++] = r;
    }
}

void get_elements(char source[], int dimSource, char * dest1, int dimDest1, int &calcDest1, char * dest2, int dimDest2, int &calcDest2, int iS = 0){
    char inizioMin = 'a';
    char fineMin = 'z';
    int toMaiuscole = 'a' - 'A';
    char zero = '0';
    char nove = '9';
    int cambiaNumero[10] = {9,8,7,6,5,4,3,2,1,0};
    // MR: Queste variabili sembrano inutili, hanno un impatto
    // notevole sullo stack, si potevano usare direttamente le
    // costanti corrispondenti.

    int numero;
    if(iS != dimSource && calcDest1 != dimDest1 && calcDest2 != dimDest2){
      // MR: Non puo' usare !=
        if (source[iS] >= inizioMin && source[iS] <= fineMin){
            dest1[calcDest1] = (char) (source[iS] - toMaiuscole);
            calcDest1++;
        }
        if (source[iS] >= zero && source[iS] <= nove){
          numero = (int) source[iS] - zero;
	  // MR: Qui source e zero sono char non chiaro perche' cast a
	  // int di source[iS].
          numero = cambiaNumero[numero];
          dest2[calcDest2] = (char) (numero + zero);
          cout << dest2[calcDest2] << " ";
	  // MR: La stampa non era richiesta ;-)
          calcDest2++;
        }
        iS++;
        get_elements(source, dimSource, dest1, dimDest1, calcDest1, dest2, dimDest2, calcDest2, iS);
    }

}

int main()
{
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
