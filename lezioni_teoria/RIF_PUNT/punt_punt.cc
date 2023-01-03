#include <iostream>
using namespace std;

int main () {
       int a, *pa, ** ppa;
       a = 2; pa = &a; ppa = &pa;
       cout << "Ind. di a = " << &a << " valore di a = " << a << endl;
       cout << "Ind. di di pa = " << &pa << " valore di pa = " <<  pa << endl;
       cout << "Ind. di ppa = " << &ppa << " valore di ppa = " << ppa << endl;
     }
