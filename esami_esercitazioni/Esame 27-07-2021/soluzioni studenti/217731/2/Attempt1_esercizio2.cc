#include <iostream>
#include <cstdlib>

using namespace std;

// Scrivere qui sotto la dichiarazione e definizione della funzione "f"
int f(int);
// Scrivere qui sopra la dichiarazione e definizione della funzione "f"

//wrapping
void f_wrap(int n, int start, int end, int &tot);
int get_number_len(int n);

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cout << "Usage: " << argv[0] << " <positivenum> " << std::endl;
    exit(1);
  }
  int n = atoi(argv[1]);
  std::cout << "The read string is: " << argv[1] << std::endl;
  std::cout << "The converted value is: " << n << std::endl;
  std::cout << "function(" << n << ") = " << f(n) << std::endl;
}

int f(int n)
{
  int res = 0;
  if (n < 0)
    res = 0;
  else
  {
    int len = get_number_len(n);
    f_wrap(n, 0, len - 1, res); // len - 1 -> controllo "i" e "i - 1"
  }
  return res;
}

//prendo la "lunghezza" del numero
int get_number_len(int n)
{
  if (n % 10 == n)
    return 1;
  else
    return 1 + get_number_len(n / 10);
}

//parto dal'ultima cifra e controllo se questa (n%10) e quella prima ((n/10) %10) sono diverse
void f_wrap(int n, int start, int end, int &tot)
{
  if (start < end)
  {
    //cout << n % 10 << " *" << (n / 10) % 10 << endl;
    if (n % 10 != (n / 10) % 10)
      tot++;
    f_wrap(n / 10, start + 1, end, tot);
  }
}