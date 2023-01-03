#include <iostream>
#include <cstddef>
using namespace std;

void get_elements_aux(char s[], int s_s, char d1[], int md1_s, int &d1_s, char d2[], int md2_s, int &d2_s, int i)
{
    if (i == s_s)
        return;
    else if (s[i] >= 'a' && s[i] <= 'z')
    {
        d1[d1_s] = (s[i] - 32);
        d1_s++;
    }
    else if (s[i] >= '0' && s[i] <= '9')
    {
        d2[d2_s] = (57 - s[i] + 48);
        d2_s++;
    }
    get_elements_aux(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, ++i);
    return;
}

void get_elements(char s[], int s_s, char d1[], int md1_s, int &d1_s, char d2[], int md2_s, int &d2_s)
{
    get_elements_aux(s, s_s, d1, md1_s, d1_s, d2, md2_s, d2_s, 0);
}

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
    return 0;
}