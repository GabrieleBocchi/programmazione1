// Giovanni: il programma ritorna risultato errato su alcuni casi di test.
// Fare riferimento alla soluzione ufficiale per un possibile svolgimento.
// Vedere commenti nel codice.
#include <iostream>
#include <fstream>
using namespace std;
int countChar(const char word[], char c);
bool checkWord(const char word[]);


int main(int argc, char * argv [])
{

    if(argc < 3){
        cout << "Usage: /a.out input_file output_file" << endl;
        exit(1);
    }

    fstream input, output;

    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    // CHECK FILE
    if(input.fail() || output.fail()){
        cout << "Errore. Impossibile aprire i file" << endl;
        exit(1);
    }

    char buffer[100];
    while(!input.eof()){
        input >> buffer;

        if(!checkWord(buffer)){
            output << buffer << "\n";
        }
    }

    input.close();
    output.close();

    return 0;
}

int strlen(const char str[]){
    int i = 0;
    while(str[i] != '\0')i++;
    return i;
}

int countChar(const char word[], char c){
    int i = 0;
    int count = 0;
    while(word[i] != '\0')
        count += word[i++] == c ? 1: 0;
    return count;

}

bool checkWord(const char word[]){
    bool res = true;
    int len = strlen(word);
    if(len != 0){

        res &= (word[0] == 'M' && len >=2 && word[len-1] =='U');
        res &= countChar(word, 'I') % 2 == 1 || countChar(word, 'I') == 0;

        // Giovanni: il controllo dovrebbe essere fatto fino alla penultima
        // lettera della parola. Inoltre, quando fai word[++i], vai anche
        // ad incrementare la variabile i, cosa che crea problemi nel ciclo,
        // visto che i di fatto viene aumentata due volte. 
        for(int i=0;i<len;i++){
            if(word[i] == 'I'){
                res &=  word[++i] != 'M';
            }
        }
    }
    return res;
}
