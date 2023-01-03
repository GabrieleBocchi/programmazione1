using namespace std;
#include <iostream>
#include <cassert>

const int DIM = 100;
double a[DIM], target;
int  found, loc, n;

int linear_search_rec(const double a[], int size, double target);
int linear_search_rec(const double a[], int l, int r, double target);

int bin_search_rec(const double a[], int n, double target);
int bin_search_rec(const double a[], int left, int right, double target);

void ReadArray(double [], int&);
void printArray(const double a[], int n);

int main()
{
  ReadArray(a,n);
  do {
    printArray(a,n);
    cout << "Target: ";
    cin >> target;
    loc = bin_search_rec(a,n,target);
    int loc1 = linear_search_rec(a, n, target);
    assert(loc1 == loc);
    if (loc>=0)
      cout << target << " is at a[" << loc << "].\n\n";
    else
      cout << target << " was not found.\n\n";
  } while (target >= 0.0);
  return 0;
}

// ricerca elemento in array non ordinato a[l..r]
int linear_search_rec(const double a[], int l,
		      int r, double target)
{
  // casi base
  if (r < l)
    return -1;
  if (a[l] == target)
    return l;
  if (a[r] == target)
    return r;
  // chiamata ricorsiva
  return linear_search_rec(a, l + 1, r - 1, target);
}

int linear_search_rec(const double a[], int size, double target) {
  // Attenzione: qui come nel loop devo passare size-1
  return linear_search_rec(a, 0, size-1, target);
}

//  Binary Search:
int bin_search_rec(const double a[], int n, double target) {
  return bin_search_rec(a, 0, n-1, target);
}

int bin_search_rec(const double a[], int left, int right, double target)
{
  int res,pivot = (left + right)/2;
  if (left > right)
    res = -1;
  else if (target == a[pivot])
    res = pivot;
  else if (target < a[pivot])
    res = bin_search_rec(a, left, pivot-1, target);
  else // (target > a[pivot])
    res = bin_search_rec(a, pivot+1, right, target);
  return res;
}


void ReadArray(double a[], int& n)
{
  cout << "Quanti elementi?: ";
        cin >> n;
  for (int i = 0; i < n; i++) {
    cout << "a[" << i << "]: ";
    cin >> a[i];
  };
}

void printArray(const double a[], int n)
{
   for (int i = 0; i < n; i++)
           cout << '\t' << "a[" << i << "]: " << a[i] << endl;
}
