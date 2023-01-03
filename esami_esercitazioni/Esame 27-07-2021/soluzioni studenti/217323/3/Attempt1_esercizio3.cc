#include <iostream>

using namespace std;

//funzioni da implementare, le ho rinominate secondo il file di esamionline
bool *create(int n);
void insert(bool *bloom_filter, int n, char *buffer);
bool control(bool *bloom_filer, int n, char *buffer);
void deinit(bool *bloom_filter);
//funzioni utili per debug
void stampa(bool *v, int dim);
int crea_ascii(char c, int n);

int main(int argc, char *argv[])
{

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool *bloom_filter = create(n);
    //stampa(bloom_filter, n);

    char ciao[] = {'c', 'i', 'a', 'o', '\0'};
    insert(bloom_filter, n, ciao);
    cout << "Ho inserito la parola 'ciao' nel bloom filter" << endl;
    //stampa(bloom_filter, n);

    if (control(bloom_filter, n, ciao))
    {
        cout << "La parola 'ciao' è presente nel bloom filter " << endl;
    }
    else
    {
        cout << "La parola 'ciao' NON è presente nel bloom filter " << endl;
    }

    char volo[] = {'v', 'o', 'l', 'o', '\0'};
    if (control(bloom_filter, n, volo))
    {
        cout << "La parola 'volo' è presente nel bloom filter " << endl;
    }
    else
    {
        cout << "La parola 'volo' NON è presente nel bloom filter " << endl;
    }

    deinit(bloom_filter);

    return 0;
}

//implementazione delle funzioni richieste

// SB: ok
bool *create(int n)
{
    bool *resval = new bool[n]; //alloco dinamicamente la memoria necessaria per l'array
    for (int i = 0; i < n; i++)
    {
        resval[i] = false;
    }
    return resval;
}

void stampa(bool *v, int n)
{ //funzione utile per eventuale debug
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void insert(bool *bloom_filter, int n, char *buffer)
{
    int index = 0; //indice per scorrere il buffer
    while (buffer[index] != '\0')
    {                                   //scorro tutto l'array
        int ascii = crea_ascii(buffer[index],n); //prendo il valore ascii della lettera
        if (bloom_filter[ascii] == false)  //se la cella ha valore true, la devo ignorare e procedere alla prossima lettera
        {
            bloom_filter[ascii] = true; //setto a true la posizione che mi interessa
        }
        index++;        //incremento l'indice per scorrere l'array
    }
}

// SB: ok
bool control(bool *bloom_filer, int n, char *buffer)
{
    bool ok = true;
    int index=0;
    while(buffer[index]!='\0'&&ok){
        //calcolo la posizione che mi serve
        int ascii = crea_ascii(buffer[index],n);
        if(bloom_filer[ascii]==false){  //controllo se una cifra del codice ascii sia false, in quel caso non è stata inserita
            ok=false;
        }
        index++;
    }

    return ok;
}

// SB: ok
void deinit(bool *bloom_filter)
{
    delete[] bloom_filter; //dealloco la memoria allocata con la create
}

int crea_ascii(char c, int n){
    int ascii = (int) c;
    if (ascii > n)
        {                        //controllo che non sia più grande della dimensione dell'array
            int tmp = ascii % n; //calcolo il modulo con la dimensione dell'array
            ascii = tmp;         //setto il nuovo valore
        }
    return ascii;
}