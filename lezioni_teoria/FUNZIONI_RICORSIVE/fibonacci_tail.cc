#include <iostream>

using namespace std;

long long fibit(int n) {
  long long fn,fnmenouno,fnmenodue;
  int i;

  if (n==0||n==1)
    fn = 1;  // Se n == 0, fib(0) = 1;
                // se n == 1, fib(1) = 1;
  else {
    fnmenodue=1;
    fnmenouno=1;
    for (i=2;i<=n;i++){
      fn = fnmenouno+fnmenodue;
      fnmenodue = fnmenouno;
      fnmenouno = fn;
    }
  }
  return fn;
}

long long fibntr(int n) {
  long long res;
  if (n == 0 || n == 1) {
    res = 1;
  }
  else {
    res = fibntr(n-1) + fibntr(n-2);
  }
  return res;
}

long long fibtr1(int n, long int a = 1, long int b = 1)
{
  long long res;
  if (n == 0)
    res = a;
  else if (n == 1)
    res = b;
  else
    res = fibtr1(n - 1, b, a + b);
  return res;
}


long long fibtr(int n, long long fnmenouno = 0, long long fnmenodue = 1) {
  long long res;
  if (n == 0 || n == 1) {
    res = fnmenodue+fnmenouno;
  }
  else {
    // Iniziamo con (fnmenouno = 0, fnmenodue = 1)
    // all'iterazione i esima:
    //    (fnmenouno, fnmenodue) = (fnmenodue, fnmenouno + fnmenodue)
    res = fibtr(n-1, fnmenodue, fnmenouno + fnmenodue);
  }
  return res;
}


int main() {
  int n;
  cout << "Metti un numero: "; cin >> n;

  cout << "fibit(" << n << ")  = " << fibit(n) << endl;
  cout << "fibtr(" << n << ")  = " << fibtr(n) << endl;
  cout << "fibtr1(" << n << ") = " << fibtr1(n) << endl;
  cout << "fibntr(" << n << ") = " << fibntr(n) << endl;
}
