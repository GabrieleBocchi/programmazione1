// GDT: di norma non si dovrebbero lasciare variabili non usate,
// ma è una cosa minore.
// Il numero di caratteri dovrebbe essere 101. 100 caratteri di testo più il terminatore di stringa.

#include <iostream>
#include <fstream>
using namespace std;

void leggiFile(char*,char*);
int lunghezza(char*);
int main(int argc, char * argv []){

    char tmp[40];
    
    if(argc==3){
        leggiFile(argv[1],argv[2]);
    }else{
        cout << "paramentri passati insufficenti"<<endl;
    }
    
    return 0;
}


void leggiFile(char* file, char* file2){
    
    fstream in(file,ios::in);
    fstream out(file2,ios::out);
    
    if(in.is_open() && out.is_open()){
        
        char** matrice=new char*[10000];
        
        for(int i=0;i<10000;i++){
            matrice[i]=new char[100];
        }
        int indice=0;
        in>>matrice[indice];
        
        while(!in.eof() && indice<10000){
            
            
            if(lunghezza(matrice[indice])>4){
                indice++;
            }
            in>>matrice[indice];
            
        }
        
        while(indice>=0){
            out << matrice[indice]<<" ";
            indice--;
        }
        in.close();
        out.close();
        
        for(int i=0;i<10000;i++){
            delete[] matrice[i];
        }
        delete[] matrice;
        
        
    }else{
        cout<< "errore file non aperti"<<endl;
    }
    
}


int lunghezza(char* parola){
    
    int i=0;
    bool controllo=false;
    
    while(!controllo){
        if(parola[i]!='\0'){
            i++;
        }else{
            controllo=true;
        }
    }
    return i;
}
