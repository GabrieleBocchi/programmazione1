#include <iostream>
using namespace std;
  
int main()
{
    cout << "#include <iostream>" << endl;
    cout << "using namespace std;" << endl << endl;
    cout << "int main()" << endl;
    cout << "{" << endl;
    cout << "   int x = 5;" << endl;
    cout << "   int *y = &x;" << endl;
    cout << "   int **k = &y;" << endl;
    cout << "   cout << x << " " << &x << endl;" << endl;
    cout << "   cout << (*y) << " " << &y << endl;" << endl;
    cout << "   cout << (*k) << " " << &k << endl;" << endl;
    cout << "   cout << *(*k) << endl;" << endl;
    cout << "   return 0;" << endl;
    cout << "}" << endl << endl;

    int x, eX, astY, eY, astK, eK, astAstK;
    cout << "Indovina l'output di questo programma (per indicare \"Indirizzo di memoria\" inserire -1)!" << endl;
    cout << "x: ";
    cin >> x;
    cout << "&x: ";
    cin >> eX;
    cout << "*y: ";
    cin >> astY;
    cout << "&y: ";
    cin >> eY;
    cout << "*k: ";
    cin >> astK;
    cout << "&k: ";
    cin >> eK;
    cout << "**k: ";
    cin >> astAstK;
    if (x == 5 && eX == -1 && astY == 5 && eY == -1 && astK == -1 && eK == -1 && astAstK == 5)
        cout << "Risposta corretta, complimenti" << endl;
    else
        cout << "Risposta errata, riprova" << endl;
    return 0;
}