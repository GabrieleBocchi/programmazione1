//
// Created by me on 17/06/2021.
//
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// Dichiarazione della funzione
void StampaFrazioneEgizia(const int nr, const int dr);


int main(int argc, char ** argv) {
    if (argc != 3) {
        cout << "Formato accettato: " << argv[0] << " <numero_positivo> <numero_positivo> " << endl;
        exit(1);
    }
    int nr = atoi(argv[1]);
    int dr = atoi(argv[2]);
    if ((nr < 0) || (dr < 0)) {
        cout << "Formato accettato: " << argv[0] << " <numero_positivo> <numero_positivo> " << endl;
    }

    cout << "Frazione iniziale: " << nr << "/" << dr << endl;
    cout << "Frazione egizia:   ";
    StampaFrazioneEgizia(nr, dr);
    cout << endl;
}

// Inizio definizione della funzione StampaFrazioneEgizia
bool isMultiple(int n, int d){
    return n%d == 0;
}

void StampaFrazioneEgizia(const int nr, const int dr){
    if(nr != 0 && dr !=0){
        if(isMultiple(nr, dr)) {
            cout << "1/" << nr / dr;
        }else if(isMultiple(dr, nr)){
            cout << "1/" << dr / nr;
        }else if(nr > dr){
            cout << nr/dr <<" + ";
            StampaFrazioneEgizia(nr%dr, dr);
        }else{
            int x = dr/nr + 1;
            cout << "1/" << x << " + ";
            StampaFrazioneEgizia(nr*x - dr, dr * x);
        }
    }
}
// Fine definizione della funzione StampaFrazioneEgizia
