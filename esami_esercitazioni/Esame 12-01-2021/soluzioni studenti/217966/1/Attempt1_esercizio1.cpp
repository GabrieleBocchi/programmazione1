// GDT: fare riferimento alla soluzione ufficiale per un esempio di svolgimento.

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){

    if(argc!=3){

        cout <<"Usage: a.out <file_input> <file_output>" <<endl;

    }
    else
    {
        fstream input, output;
        input.open(argv[1], ios::in);
        output.open(argv[2], ios::out);

        input >> noskipws;

        char testo[10000], parola[100+1];
        int counter=0,j=0,i=0;

        /*while(input >> parola[counter]){

            if(parola[counter]==' '){

                if(counter%2==0){
                    for(int i=0; i<counter; i++){
                        output <<parola[i];
                    }
                    output <<" ";
                }
                
                counter=-1;
            }
            counter ++;

        }*/

        while(input >> parola[counter]){

            if(parola[counter]==' '){

                if(counter%2==0){
                    for(i=0; i<counter; i++){
                        testo[j]=parola[i];
                        j++;
                    }
                    testo[j]=' ';
                    j++;
                }
                
                counter=-1;
            }
            counter ++;

        }   //All'interno di testo ho tutte le parole da rovesciare (j=contatore ultimo carattere di testo)

        cout <<testo;

        i=0;
        counter=0;
        int pos;
        
        do{

            pos=j-i;;
            //cout <<"pos: " <<pos <<endl;
            counter=0;
            if(testo[pos]==' '){

                while(testo[pos+counter]!=' '){

                    parola[counter]=testo[pos+counter];
                    j++;

                }
                cout <<parola;
                output <<parola;

            }
            
            i++;        

        }while(i<=j);

    } 

}
