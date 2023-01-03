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
void StampaFrazioneEgizia(const int nr, const int dr){
  if(nr != 0 & dr !=0){
    // MR: Qui ci voleva &&, considero potenziale errore!
    if(dr % nr == 0 || dr % nr == 0){
      //multipli
      if(dr>nr){
        cout<<"1/"<<dr/nr;
      }else{
        cout<<nr/dr<<"/1";
      }
    }
    else{
      if(nr>dr){
        cout<<nr/dr<<" ";
        if(nr%dr != 0) cout<<"+ ";
        StampaFrazioneEgizia(nr%dr,dr); //stampo '+' solo se sono certo che ci sarà una qualche ricorsione al prox giro
      }else{
        int x = (dr/nr)+1;
        cout<<"1/"<<x<<" ";
        int nr_n = nr*x - dr;
        int dr_n =  dr * x;
        if(nr_n != 0 && dr_n != 0) cout<<"+ "; //stampo '+' solo se sono certo che ci sarà una qualche ricorsione al prox giro
        StampaFrazioneEgizia(nr_n,dr_n);
      }
    }
  }
}
// Fine definizione della funzione StampaFrazioneEgizia
