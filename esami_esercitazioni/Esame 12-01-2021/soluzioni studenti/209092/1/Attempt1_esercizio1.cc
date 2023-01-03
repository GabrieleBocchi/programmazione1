// GDT: fare riferimento alla soluzione ufficiale per un possibile svolgimento.

#include <iostream>
#include <fstream>
using namespace std;

const int DIM1 = 1000;
const int DIM2 = 101;

int main(int argc, char * argv [])
{
  if (argc != 3)
    {
      cout << "gli argomenti devono essere 2 + ./a.out" << endl;
      exit(0);
    }
  fstream myin, myout;
  char parola[DIM2];
  char ar_parola[DIM1][DIM2];
  myin.open(argv[1],ios::in);
  if(myin.fail())
    {
      cerr << "il file " << argv[1] << " non esiste" << endl;
      exit(0);
    }
  myout.open(argv[2],ios::out);
  int i = 0;
  int num_cr;
  char cr;
  myin >> parola;
  i += 1;
  cr = ' ';
  num_cr= 0;
  for(int j = 0 ; cr != '\0'; j++)
    {
      cr = parola[j];
      cout << cr << " ";
      num_cr +=1;
    }
  if(num_cr <= 5)
    {
      for(int k = 0; k < num_cr; k++)
	{
	  ar_parola[i-1][k]= cr;
	}
    }
  while((myin >> parola) && (i < 1000))
    {
      i+=1;
      cr = ' ';
      num_cr= 0;
      for(int j = 0 ; cr != '\0'; j++)
	{
	  cr = parola[j];
	  cout << cr << " ";
	  num_cr +=1;
	}
      if(num_cr <= 5)
	{
	  for(int k = 0; k < num_cr; k++)
	    {
	      ar_parola[i-1][k]= cr;
	      cout << cr;
	    }
	}
    }
  for (int h = i; i > 0; i--)
    {
      myout << ar_parola[h] << " ";
    }


  myout.close();
  myin.close();
  return 0;
}
