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

void get_elements_rec(char s[],int s_s, char d1[],int d1_s,char d2[],int d2_s, int cs)
{
  if(cs<s_s)
  {
    if(s[cs]>='a'&&s[cs]<='z')
      {
      d1[d1_s]=s[cs];
      d1[d1_s]=('A'-'a')+d1[d1_s];
      d1_s++;
      }
    else if(s[cs]>='A'&&s[cs]<='Z')
    {
      d2[d2_s]=s[cs];
      d2[d2_s]=('a'-'A')+d2[d2_s];
      d2_s++;  
    }

    cs++;
    return get_elements_rec(s, s_s,d1,d1_s,d2,d2_s,cs);
  }
  
}

void get_elements(char s[],int s_s, char d1[],int md1_s,int d1_s,char d2[],int md2_s,int d2_s)
{
  return get_elements_rec(s, s_s,d1,d1_s,d2,d2_s,0);
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
