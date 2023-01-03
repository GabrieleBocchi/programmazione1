#include <iostream>

using namespace std;

bool init(int n);
void add(bool * bloom_filter,int n,char string[]);
bool check(bool * bloom_filter,int n,char string[]);
void destroy(bool * bloom_filter);


int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare il codice originale
    int n = 255;

    bool* bloom_filter = init(n);

    char ciao[] = { 'c', 'i', 'a', 'o', '\0' };     
    add(bloom_filter, n, ciao);
    cout << "Ho inserito la parola 'ciao' nel bloom filter" << endl;
    
    if (check(bloom_filter, n, ciao)) {
        cout << "La parola 'ciao' è presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'ciao' NON è presente nel bloom filter " << endl;
    }

    char volo[] = { 'v', 'o', 'l', 'o', '\0' }; 
    if (check(bloom_filter, n, volo)) {
        cout << "La parola 'volo' è presente nel bloom filter " << endl;
    } else {
        cout << "La parola 'volo' NON è presente nel bloom filter " << endl;
    }

    destroy(bloom_filter);

    return 0;
}

bool init(int n);
{
	
}

void add(bool * bloom_filter,int n,char string[])
{
	
}

bool check(bool * bloom_filter,int n,char string[])
{
	int contatore = 0;
	do{
		int c = string[contatore];
		contatore++;
	}while(string[contatore] != '\0')
	return false;
}

void destroy(bool * bloom_filter)
{
	delete [] bloom_filter;
}