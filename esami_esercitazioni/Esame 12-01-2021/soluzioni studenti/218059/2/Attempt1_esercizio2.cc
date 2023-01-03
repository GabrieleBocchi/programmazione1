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

void get_elements(int * source,int size_source,int * dest1,int  dest1_MaxSize,int & dest1_size,int * dest2,int dest2_MaxSize,int & dest2_size);

void change(int * source, int index);

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

  get_elements(s, s_s, d1, md1_s,  d1_s, d2, md2_s, d2_s);

  print(s, s_s, "Source = ");
  print(d1, d1_s, "D1     = ");
  print(d2, d2_s, "D2     = ");

}
void change(int * source,int source_size,int  index,int * dest1,int & indexDest1,int * dest2, int & indexDest2){

if(index<source_size){
 cout << "index - "<< index<<endl;
  

  if(((index%2==0) ||(index==0)) && source[index]%3==0){
  
    dest1[indexDest1]=source[index];
    indexDest1++;
     
  }else{
    dest2[indexDest2]=source[index];
    indexDest2++;
  }
  index++;
  cout << "source_size"<< source_size <<endl;
  cout <<"index1 "<< indexDest1 <<endl;
  cout  <<"index2 "<< indexDest2 <<endl;

change(source,source_size,index,dest1,indexDest1,dest2,indexDest2);
}
}

void get_elements(int * source,int size_source,int * dest1,int  dest1_MaxSize,int & dest1_size,int * dest2,int dest2_MaxSize,int & dest2_size){

  
   change(source,size_source,0,dest1,dest1_size,dest2,dest2_size);

   }



