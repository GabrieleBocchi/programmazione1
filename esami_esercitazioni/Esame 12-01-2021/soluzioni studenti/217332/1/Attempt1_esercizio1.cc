// GDT: il codice esegue correttamente. La penalizzazione è data dal fatto
// che la funzione print_reverse è definita ricorsiva. Se il file è troppo grande
// questo potrebbe portare a dei problemi di memoria (crei troppe chiamate a funzione
// innestate che raggiungono il limite imposto dal sistema operativo). 
// In generale, la ricorsione va usata con parsimonia e solo in casi speciali. Se si può
// fare con un ciclo (while, do...while) meglio usare un ciclo. 

#include <iostream>
#include <fstream>
using namespace std;

void print_reverse(fstream& in, fstream& out);

int main(int argc, char * argv [])
{
    if(argc!=3){
        cout << "Usage: <./a.out> <input.txt> <output.txt>" << endl;
    }else{
        fstream in, out;
        in.open(argv[1],ios::in);
        if(in.fail()){
            cout << "errore del file in lettura del file" << endl;
        }else{
            out.open(argv[2],ios::out);
            print_reverse(in,out);
            in.close();
            out.close();
        }
    }
  return 0;
}
void print_reverse(fstream & in, fstream & out){
    char parola[100];
    if(!in.eof()){
        in >> parola;
        print_reverse(in,out);
        int i=0;
        for(; parola[i]!='\0'; i++);
        if(i%2!=0){
            out << parola << " ";
            i=0;
        }else{
            i=0;
        }
    }
}
