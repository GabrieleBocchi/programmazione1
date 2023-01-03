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
void StampaFrazioneEgizia(const int nr, int dr) {
  // Caso base
  if (dr == 0 || nr == 0)
    return;

  // nr e' multiplo di dr, allora stampo nr/dr
  if (nr%dr == 0) {
      cout << nr/dr;
      return;
  }

  // dr e' multiplo di nr, allora 1/(dr/nr)
  if (dr%nr == 0) {
      cout << "1/" << dr/nr;
      return;
  }

  // nr e' maggiore di dr, stampo nr/dr + e risultato ricorsione su
  // parte rimanente
  if (nr > dr) {
    cout << nr/dr << " + ";
    StampaFrazioneEgizia(nr%dr, dr);
    return;
  }

  int x = dr/nr + 1;
  cout << "1/" << x << " + ";
  StampaFrazioneEgizia(nr*x-dr,dr*x);
}
// Fine definizione della funzione StampaFrazioneEgizia
