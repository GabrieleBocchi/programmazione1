#include <iostream>
#include <fstream>
using namespace std;
bool controlla(char *v);
int main(int argc, char *argv[])
{

  if (argc < 3)
  {
    cout << "Errore" << endl;
    return 2;
  }
  fstream in, out;
  in.open(argv[1], ios::in);
  out.open(argv[2], ios::out);
  if (in.fail() || out.fail())
  {
    cout << "Errore" << endl;
    return 3;
  }
  char *b = new char[101];

  while (in >> b)
  {
    if (!controlla(b))
    {
      out << b << endl;
    }
    delete[] b;
    b = new char[101];
  }
  delete[] b;
  in.close();
  out.close();
  return 0;
}
int sizeofstring(char *v)
{
  if (*v == '\0')
    return 0;
  return sizeofstring(++v) + 1;
}
int contaI(char *v)
{
  int ni = 0;
  while (*v != '\0')
  {
    if (*v == 'I')
      ni++;
    v++;
    /* code */
  }
  return ni;
  if (*v == '\0')
    return 0;
  int prec = contaI(v + 1);
  return (*v == 'I') ? prec + 1 : prec;
}
bool controllaMI(char *v)
{
  char suc = *(v + 1);
  if (*v == '\0' || suc == '\0')
    return true;
  if (*v == 'M' && suc == 'I')
    return false;
  return controllaMI(v + 1);
}
bool controlla(char *v)
{
  int l = sizeofstring(v);
  char p = *v;
  char u = *(v + l - 1);
  if (p == 'U' && u != 'M')
    return false;
  int ni = contaI(v);
  bool isPari = ni % 2 == 0;
  if (!isPari)
    return false;
  return controllaMI(v);
}