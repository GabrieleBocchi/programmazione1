#include <iostream>
#include <cstddef>

using namespace std;

void get_elements1(int s[],int s_s, int d1[], int md1_s, int & d1_s, int d2[], int md2_s, int & d2_s, int num);

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
void get_elements(int s[],int s_s, int d1[], int md1_s, int & d1_s, int d2[], int md2_s, int & d2_s)
{
  get_elements1(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, 0);
}
void get_elements1(int s[],int s_s, int d1[], int md1_s, int & d1_s, int d2[], int md2_s, int & d2_s, int num)
{
  if (num >= s_s)
    {
      cout << endl;
      // MR: Non richiesto!
    }
  else
    {
      if(((num == 0)||((num % 2)==0 ))&&((s[num] % 3) == 0 ))
	{
	  // MR: Mancano controlli che d1_s sia < di md1_s
	  d1[d1_s]= s[num];
	  d1_s += 1;
	}
      else
	{
	  // MR: Mancano controlli che d2_s sia < di md2_s
	  d2[d2_s]= s[num];
	  d2_s += 1;
	}
      get_elements1(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, num+1);
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
