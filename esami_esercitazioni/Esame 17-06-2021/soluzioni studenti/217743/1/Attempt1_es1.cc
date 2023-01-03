// Giovanni: alcune condizioni sono errate. Ad esempio, la condizione 1 indica che,
// se la parola inizia con la lettera U, allora deve per forza terminare con la lettera M.
// Però, se la parola non inizia con la lettera U, allora quella condizione non si
// applica. Vedi commenti nel codice.

#include <iostream>
#include <fstream>
using namespace std;

int length(char *s, int i)
{
    int res;
    if (s[i] != '\0')
    {
        i++;
        res = length(s, i);
    }
    else
    {
        res = i;
    }
    return res;
}

// Giovanni: di default,res dovrebbe essere true (e dovresti cambiarlo a false
// se una condizione NON è verificata). Infatti, parole come MMM sono comunque
// valide, ma la funzione check ritorna falso.
bool check(char *p){
    int size = length(p,0);
    bool res = false;
    bool ok = true;
    int totalI = 0;
    if (p[0]=='U' && p[size-1]=='M' && ok){
        for (int i=1; i<size-1; i++){
            if (p[i]=='I'){
                totalI++;
            }
            if(p[i]=='M' && p[i+1]== 'I' && (i+1)<size){
                ok = false;
                res = false;
            }

        }
        if (totalI % 2 == 0 && ok){
            res = true;
        }
    }
    else {
        res = false;
    }
    return res;
}

int main(int argc, char *argv[])
{

    fstream in, out;
    char parola[100+1];
    if (argc != 3)
    {
        cout << "Usage: ./a.out <input.txt> <output.txt>" << endl;
        exit(0);
    }
    in.open(argv[1], ios::in);
    if (in.fail())
    {
        cout << "Error: could not open input file" << endl;
        exit(1);
    }
    out.open(argv[2], ios::out);
    if (out.fail())
    {
        cout << "Error: could not open output file" << endl;
        exit(1);
    }

    in >> parola;
    while(!in.eof()){
        if (check(parola)){
            out << parola << endl;
        }
        in >> parola;
    }

    in.close();
    out.close();

    return 0;
}
