#include <iostream>
#include <iomanip>
using namespace std;
/* Inserimento di un elemento x nella posizione p, aumentando
   dimensione virtuale d array che ha dimensione massima N  */
void addElement(int arr[], int &d, const int x, const int p, const int N) {
  cout << "===========================" << endl;
  cout << "Adding " << x << " at position " << p << endl;
  if (p >= 0 && p <= d && d < N) {
    for(int i = d; i > p; i--) {
      arr[i] = arr[i-1];
    }
    arr[p] = x;
    d++;
  }
}

void print(const int a[], const int d) {
  for(int i = 0; i < d; i++)
    cout << "a[" << setw(2) << i << "] ";
  cout << endl;
  for(int i = 0; i < d; i++)
    cout  << setw(5) << a[i] << " ";
  cout << endl;
}

int main() {
  int arr[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  int N = sizeof(arr)/sizeof(int);
  int dim = 9;

  print(arr, dim);
  addElement(arr, dim, -1, 0, N);
  cout << "===========================" << endl;
  print(arr, dim);
  addElement(arr, dim, -1, 4, N);
  cout << "===========================" << endl;
  print(arr, dim);
  addElement(arr, dim, -1, 11, N);
  cout << "===========================" << endl;
  print(arr, dim);
  addElement(arr, dim, -1, dim, N);
  cout << "===========================" << endl;
  print(arr, dim);
  addElement(arr, dim, -1, 13, N);
  cout << "===========================" << endl;
  print(arr, dim);
  addElement(arr, dim, -1, 15, N);
  cout << "===========================" << endl;
  print(arr, dim);
  addElement(arr, dim, -1, -1, N);
  cout << "===========================" << endl;
  print(arr, dim);
}
