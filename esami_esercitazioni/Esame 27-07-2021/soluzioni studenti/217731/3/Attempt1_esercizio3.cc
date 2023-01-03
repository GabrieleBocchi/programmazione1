#include <iostream>

using namespace std;

bool *init(int n);
void destroy(bool *arr);
void add(bool *arr, int n, char *car);
bool check(bool *arr, int n, char *car);

int main(int argc, char *argv[])
{

  // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
  int n = 255;

  bool *bloom_filter = init(n);

  char ciao[] = {'c', 'i', 'a', 'o', '\0'};
  add(bloom_filter, n, ciao);
  cout << "Ho inserito la parola 'ciao' nel bloom filter" << endl;

  if (check(bloom_filter, n, ciao))
  {
    cout << "La parola 'ciao' è presente nel bloom filter " << endl;
  }
  else
  {
    cout << "La parola 'ciao' NON è presente nel bloom filter " << endl;
  }

  char volo[] = {'v', 'o', 'l', 'o', '\0'};
  if (check(bloom_filter, n, volo))
  {
    cout << "La parola 'volo' è presente nel bloom filter " << endl;
  }
  else
  {
    cout << "La parola 'volo' NON è presente nel bloom filter " << endl;
  }

  destroy(bloom_filter);

  return 0;
}

// SB: ok
bool *init(int n)
{
  if (n >= 0)
  {
    bool *arr = new bool[n];
    for (int i = 0; i < n; i++)
      arr[i] = false;
    return arr;
  }
  else
    exit(1);
}

// SB: ok
void destroy(bool *arr)
{
  delete[] arr;
}

// SB: ok
void add(bool *arr, int n, char *car)
{
  for (int i = 0; car[i] != '\0'; i++)
  {
    int code_ascii = car[i];
    if (code_ascii > n)
      code_ascii = code_ascii % n;
    if (arr[code_ascii] != true)
      arr[code_ascii] = true;
  }
}

// SB: ok
bool check(bool *arr, int n, char *car)
{
  bool present = true;
  for (int i = 0; car[i] != '\0' && present; i++)
  {
    int code_ascii = car[i];
    if (code_ascii > n)
      code_ascii = code_ascii % n;
    if (arr[code_ascii] != true)
      present = false;
  }
  return present;
}