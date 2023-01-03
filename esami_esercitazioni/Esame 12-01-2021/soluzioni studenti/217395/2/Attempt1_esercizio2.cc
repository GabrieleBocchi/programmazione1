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


void get_elements_aux(int* source, const int dimSource, int* dest1, const int dimMax1,int &dimD1, int*dest2, const int dimMax2, int &dimD2, int index){
  if(index < dimSource){
    if(*(source) %3 == 0 && index%2 == 0){
      if(dimD1 < dimMax1){
        *dest1 = *source;
        dimD1++;
        get_elements_aux(++source, dimSource, ++dest1, dimMax1, dimD1, dest2, dimMax2, dimD2, ++index);
      }
    }else{
      if(dimD2 < dimMax2){
        *dest2 = *source;
        dimD2++;
        get_elements_aux(++source, dimSource, dest1, dimMax1, dimD1, ++dest2, dimMax2, dimD2, ++index);
      }
    }
  }
}

void get_elements(int* source, const int dimSource, int* dest1, const int dimMax1,int &dimD1, int*dest2, const int dimMax2, int &dimD2){
  get_elements_aux(source, dimSource, dest1, dimMax1, dimD1, dest2, dimMax2, dimD2,0);
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

  for(int i = 0; i < ms; i++){
    cout << s[i] << " ";
  }

  get_elements(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s);

  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}
