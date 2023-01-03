#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Studente
{
    char nome[16];
    char cognome[16];
    int matricola;
    float media_ponderata;
};

Studente *riempiDatabase(fstream &file, int righe);
Studente genera_studente(char nome[], char cognome[], int matricola, float media_ponderata);
void stampa_studente(const Studente & S);
int cerca_matricola(Studente * database, int matricola, int DIM);
int cerca_nome_e_cognome(Studente * database, char * nome, char * cognome, int DIM);
int studente_top_media(Studente * database, int DIM);

int main(int argc, char *argv [])
{
    if (argc != 3)
    {
        cout << "Numero di argomenti inseriti errato" << endl;
        return 0;
    }
    fstream file;
    file.open(argv[1], ios::in);
    if (file.fail())
    {
        cout << "Il file non esiste" << endl;
        return 0;
    }
    int righe = atoi(argv[2]);
    Studente *database = riempiDatabase(file, righe);
    int scelta, indice;
    cout << "Database degli studenti!" << endl << endl;
    cout << "Inserire 1 se si vuole ricercare uno studente per numero di matricola" << endl;
    cout << "Inserire 2 se si vuole ricercare uno studente per nome e cognome" << endl;
    cout << "Inserire 3 se si vuole ricercare lo studente con la media ponderata piu' alta" << endl;
    cout << "Scegliere: ";
    cin >> scelta;
    switch (scelta)
    {
        case 1:
        int matricola;
        cout << endl << "Inserire la matricola: ";
        cin >> matricola;
        indice = cerca_matricola(database, matricola, righe);
        break;
        case 2:
        char nome[16], cognome[16];
        cout << endl << "Inserire il nome: ";
        cin >> nome;
        cout << endl << "Inserire il cognome: ";
        cin >> cognome;
        indice = cerca_nome_e_cognome(database, nome, cognome, righe);
        break;
        case 3:
        indice = studente_top_media(database, righe);
        break;
        default:
        cout << "Numero inserito errato" << endl;
        return 0;
    }
    if (indice == -1)
        cout << endl << "Nessun risultato" << endl;
    else
    {
        cout << endl << "---------------------------" << endl;
        cout << endl << "Risultato della ricerca: " << endl << endl;
        cout << "Studente n. " << indice + 1 << endl << endl;
        stampa_studente(database[indice]);
    }
    file.close();
    delete [] database;
    return 0;
}

Studente *riempiDatabase(fstream &file, int righe)
{
    Studente *database = new Studente [righe];
    char nome[16];
    char cognome[16];
    int matricola;
    float media_ponderata;
    for (int i = 0; i < righe; i++)
    {
        file >> nome;
        file >> cognome;
        file >> matricola;
        file >> media_ponderata;
        database[i] = genera_studente(nome, cognome, matricola, media_ponderata);
    }
    return database;
}

Studente genera_studente(char nome[], char cognome[], int matricola, float media_ponderata)
{
    Studente s;
    strcpy(s.nome, nome);
    strcpy(s.cognome, cognome);
    s.matricola = matricola;
    s.media_ponderata = media_ponderata;
    return s;
}

void stampa_studente(const Studente & S)
{
    cout << "Nome: " << S.nome << endl;
    cout << "Cognome: " << S.cognome << endl;
    cout << "Matricola: " << S.matricola << endl;
    cout << "Media Ponderata: " << S.media_ponderata << endl << endl;
    return;
}

int cerca_matricola(Studente * database, int matricola, int DIM)
{
    for (int i = 0; i < DIM; i++)
        if (database[i].matricola == matricola)
            return i;
    return -1;
}

int cerca_nome_e_cognome(Studente * database, char * nome, char * cognome, int DIM)
{
    for (int i = 0; i < DIM; i++)
        if (strcmp(database[i].nome, nome) == 0 && strcmp(database[i].cognome, cognome) == 0)
            return i;
    return -1;
}

int studente_top_media(Studente * database, int DIM)
{
    int max = -1;
    int indice;
    for (int i = 0; i < DIM; i++)
        if (database[i].media_ponderata > max)
        {
            max = database[i].media_ponderata;
            indice = i;
        }
    return indice;
}