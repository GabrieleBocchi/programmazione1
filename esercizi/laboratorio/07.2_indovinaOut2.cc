#include <iostream>
using namespace std;
  
int main()
{
    cout << "#include <iostream>" << endl;
    cout << "using namespace std;" << endl << endl;
    cout << "int main()" << endl;
    cout << "{" << endl;
    cout << "   int i = 20;" << endl;
    cout << "   int *ptr = &i;" << endl;
    cout << "   (*ptr)++;" << endl;
    cout << "   int j = 15;" << endl;
    cout << "   ptr = &j;" << endl;
    cout << "   (*ptr)++;" << endl;
    cout << "   cout << i << endl;" << endl;
    cout << "   return 0;" << endl;
    cout << "}" << endl << endl;

    int i;
    cout << "Indovina l'output di questo programma (per indicare \"Indirizzo di memoria\" inserire -1)!" << endl;
    cout << "i: ";
    cin >> i;
    if (i == 21)
        cout << "Risposta corretta, complimenti" << endl;
    else
        cout << "Risposta errata, riprova" << endl;
    return 0;
}