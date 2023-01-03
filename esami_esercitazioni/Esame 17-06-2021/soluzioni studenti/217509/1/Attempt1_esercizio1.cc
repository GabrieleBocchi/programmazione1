// Giovanni: il programma ritorna risultato errato su alcuni casi di test.
// Fare riferimento alla soluzione ufficiale per un possibile svolgimento.
// Vedere commenti nel codice.

#include <iostream>
#include <fstream>
using namespace std;

const int MAX_WORD_SIZE = 101;

bool is_miu(char word[])
{
  bool valid = true;
  int I_count = 0;

  // Giovanni: qui il ciclo dovrebbe andare da 0 a len(word)-2. Infatti,
  // per la condizione 3, è necessario controllare solo fino alla penultima
  // lettera. Qui, se l'ultima lettera della parola è una M, il codice setta
  // valid a false e quindi causa una risposta errata. 
  int i = 0;
  while(word[i] != '\0' && valid)
  {
    if(word[i] == 'I')
      ++I_count;
    else if(word[i] == 'M')
      valid = word[i+1] != 'I';
    ++i;
  }
  valid = (word[0] == 'U') && (word[i-1] == 'M');
  valid = (I_count % 2) == 0;
  return valid;
}

int main(int argc, char * argv [])
{
  if(argc != 3)
  {
    cerr << "uso: " << argv[0]  << " <file_input> <file_output>"
      << endl;
    return -1;
  }

  ifstream input_file;
  input_file.open(argv[1]);
  if(input_file.fail())
  {
    cerr << "non è stato possibile aprire il file " << argv[1]
      << endl;
    return -1;
  }
  ofstream out_file;
  out_file.open(argv[2], ios::out);
  if(out_file.fail())
  {
    cerr << "non è stato possibile aprire il file " << argv[2]
      << endl;
    return -1;
  }

  char word[MAX_WORD_SIZE];
  while(input_file >> word)
  {
    if(is_miu(word))
      out_file << word << '\n';
  }

  // Giovanni: manca la chiusura degli stream

  return 0;
}
