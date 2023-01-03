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

Studente *riempiDatabase(fstream &file, int DIM);
Studente genera_studente(char nome[], char cognome[], int matricola, float media_ponderata);
void stampa_studente(const Studente & S);
int cerca_matricola(Studente * database, int matricola, int DIM);
int cerca_nome_e_cognome(Studente * database, char * nome, char * cognome, int DIM);
int studente_top_media(Studente * database, int DIM);

int main()
{
    Studente *database;
    int scelta, DIM;
    cout << "Database degli studenti!" << endl << endl;
    cout << "Inserire 1 se si vuole caricare gli studenti da un file esterno" << endl;
    cout << "Inserire 2 se si vuole aggiungere gli studenti manualmente" << endl;
    cout << "Scegliere: ";
    cin >> scelta;
    if (scelta == 1)
    {
        char nomeFile[32];
        cout << endl << "Inserire il nome del file compresa l'enstensione: ";
        cin >> nomeFile;
        cout << "Inserire da quante righe e' composto il file: ";
        cin >> DIM;
        if (DIM > 100)
        {
            cout << endl << "Il numero massimo di studenti che si possono inserire e' 100" << endl;
            return 0;
        }
        fstream file;
        file.open(nomeFile, ios::in);
        if (file.fail())
        {
            cout << endl << "Il file non esiste" << endl;
            return 0;
        }
        database = riempiDatabase(file, DIM);
        cout << endl << "Studenti caricati correttamente" << endl << endl;
        cout << "Premere invio per continuare...";
        cin.ignore();
        cin.get();
        file.close();
    }
    else if (scelta == 2)
    {
        char nome[16], cognome[16];
        int matricola;
        float media_ponderata;
        cout << endl << "Inserire il numero di studenti che si desidera aggiungere al database: ";
        cin >> DIM;
        if (DIM > 100)
        {
            cout << endl << "Il numero massimo di studenti che si possono inserire e' 100" << endl;
            return 0;
        }
        database = new Studente [DIM];
        for (int i = 0; i < DIM; i++)
        {
            cout << endl << "Studente n. " << i + 1 << endl << endl;
            cout << "Inserire il nome: ";
            cin >> nome;
            cout << "Inserire il cognome: ";
            cin >> cognome;
            cout << "Inserire il numero di matricola: ";
            cin >> matricola;
            cout << "Inserire la media ponderata: ";
            cin >> media_ponderata;
            database[i] = genera_studente(nome, cognome, matricola, media_ponderata);
        }
        cout << endl << "Studenti caricati correttamente" << endl << endl;
        cout << "Premere invio per continuare...";
        cin.ignore();
        cin.get();
    }
    else
    {
        cout << endl << "Numero inserito errato" << endl;
        return 0;
    }
    int indice;
    do
    {
        system("clear");
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
            indice = cerca_matricola(database, matricola, DIM);
            break;
            case 2:
            char nome[16], cognome[16];
            cout << endl << "Inserire il nome: ";
            cin >> nome;
            cout << endl << "Inserire il cognome: ";
            cin >> cognome;
            indice = cerca_nome_e_cognome(database, nome, cognome, DIM);
            break;
            case 3:
            indice = studente_top_media(database, DIM);
            break;
            default:
            cout << endl << "Numero inserito errato" << endl;
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
            cout << "---------------------------" << endl;
        }
        cout << endl << "Se si vuole ricercare un altro studente inserire 1, altrimenti inserire un altro numero per uscire: ";
        cin >> scelta;
    } while (scelta == 1);
    delete [] database;
    return 0;
}

Studente *riempiDatabase(fstream &file, int DIM)
{
    Studente *database = new Studente [DIM];
    char nome[16];
    char cognome[16];
    int matricola;
    float media_ponderata;
    for (int i = 0; i < DIM; i++)
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