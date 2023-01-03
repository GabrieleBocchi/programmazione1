#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// Dichiarazione della funzione
void StampaFrazioneEgizia(const int nr, const int dr);

int main(int argc, char **argv)
{
  if (argc != 3)
  {
    cout << "Formato accettato: " << argv[0] << " <numero_positivo> <numero_positivo> " << endl;
    exit(1);
  }
  int nr = atoi(argv[1]);
  int dr = atoi(argv[2]);
  if ((nr < 0) || (dr < 0))
  {
    cout << "Formato accettato: " << argv[0] << " <numero_positivo> <numero_positivo> " << endl;
  }

  cout << "Frazione iniziale: " << nr << "/" << dr << endl;
  cout << "Frazione egizia:   ";
  StampaFrazioneEgizia(nr, dr);
  cout << endl;
}

// Inizio definizione della funzione StampaFrazioneEgizia
// ADD YOUR SOLUTION HERE

void StampaFrazioneEgizia(const int nr, const int dr)
{
  if (dr == 0 || nr == 0)
    return;

  if (dr % nr == 0)
  {
    cout << "1/" << dr / nr;
    return;
  }

  if (nr % dr == 0)
  {
    cout << nr / dr;
    return;
  }

  if (nr > dr)
  {
    cout << nr / dr << " + ";
    StampaFrazioneEgizia(nr % dr, dr);
    return;
  }
  int n = dr / nr + 1;
  cout << "1/" << n << " + ";

  StampaFrazioneEgizia(nr * n - dr, dr * n);
}

// Fine definizione della funzione StampaFrazioneEgizia
