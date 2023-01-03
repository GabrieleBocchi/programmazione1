#include <iostream>
using namespace std;
  
int main()
{
    cout << "#include <iostream>" << endl;
    cout << "using namespace std;" << endl << endl;
    cout << "int main()" << endl;
    cout << "{" << endl;
    cout << "   int a = 32;" << endl;
    cout << "   int *ptr = &a;" << endl;
    cout << "   int b = 14;" << endl;
    cout << "   int & ref = b;" << endl;
    cout << "   a += b;" << endl;
    cout << "   *ptr += b;" << endl;
    cout << "   cout << a << \", \" << b << endl;" << endl;
    cout << "   return 0;" << endl;
    cout << "}" << endl << endl;

    int a, b;
    cout << "Indovina l'output di questo programma (per indicare \"Indirizzo di memoria\" inserire -1)!" << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    if (a == 60 && b == 14)
        cout << "Risposta corretta, complimenti" << endl;
    else
        cout << "Risposta errata, riprova" << endl;
    return 0;
}