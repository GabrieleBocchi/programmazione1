#include <iostream>
#include <cstddef>

using namespace std;

const int lowerToUpper = 'Z' - 'z';

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

void get_elements(const char source[], const int dimSource,
                  char dest1[], const int dimDest1, int & dim1,
                  char dest2[], const int dimDest2, int & dim2);

void get_elements_rec(const char source[], const int dimSource, int j,
                      char dest1[], const int dimDest1, int & dim1,
                      char dest2[], const int dimDest2, int & dim2);

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

bool isLower(char c){
    return ( c<='z' && c>='a' );
}

bool isNumber(char c){
    int num = atoi(& c);
    return ( num <= 9 && num >= 0 );
}

void get_elements_rec(const char source[], const int dimSource, int j,
                      char dest1[], const int dimDest1, int & dim1,
                      char dest2[], const int dimDest2, int & dim2){
    if (j < dimSource){
        char c = source[j];
        
        if (isLower(c)){
            dest1[dim1] = c + lowerToUpper;
            dim1++;
        }
        else if (isNumber(c)){
            switch (c) {
                case '0' :
                    c = 9 ;
                    break;
                case '1' :
                    c = 8 ;
                    break;
                case '2' :
                    c = 7;
                    break;
                case '3' :
                    c = 6;
                    break;
                case '4' :
                    c = 5;
                    break;
                case '5' :
                    c = 4;
                    break;
                case '6' :
                    c = 3;
                    break;
                case '7' :
                    c = 2;
                    break;
                case '8' :
                    c = 1;
                    break;
                case '9' :
                    c = 0;
                    break;
                default :
                    cout << "something went wrong" << endl;
                    
            }
            dest2[dim2] = c;
            dim2++;
        }
        j++;
        get_elements_rec(source, dimSource, j, dest1, dimDest1, dim1,
                        dest2, dimDest2, dim2);
    }
}


void get_elements(const char source[], const int dimSource,
                  char dest1[], const int dimDest1, int & dim1,
                  char dest2[], const int dimDest2, int & dim2){
    
    int j = 0;
        
    get_elements_rec(source, dimSource, j, dest1, dimDest1, dim1,
                     dest2, dimDest2, dim2);
    dim1++;
    dim2++;
}
