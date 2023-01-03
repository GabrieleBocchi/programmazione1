#include <iostream>
#include <fstream>
using namespace std;

bool chechodd(char * word);  // return true if the word has an odd number of letters
void  outwrite(char ** text, char * outfile);
char ** inread(char * infile);

int main(int argc, char * argv [])
{

  if(argc != 3)
    cout<<"ERROR: main"<<endl;
  else
    outwrite(inread(argv[1]),argv[2]);  

  return 0;
}

bool checkodd(char * word)
{
  int index = 0;
  for(int i=0; word[i]!='\0'; i++)
    index++;

  return index%2;
}

char ** inread(char * infile)
{
  ifstream input;
  input.open(infile, ios::in);
  
  char ** intext  = new  char*[10000];
  for(int i = 0; i<10000; i++)
      intext[i] = new char[100];


  if(!input.is_open()){
    cout<<"ERROR: inread"<<endl;
  }
  else
  {
    char * buffer;

    input>>buffer;

    int i=0;

    intext[i] = buffer;    
    while(input>>buffer)
    {
      i++;
      intext[i] = buffer;      
    }   
  }

  input.close();

  return intext;
  
}


void outwrite (char ** text, char * outfile)
{
  ofstream output;
  output.open(outfile, ios::out);

  int dim = 0;
  char * buffer = text[dim];

  while(buffer!="")
  {
    dim++;
    buffer = text[dim];
  }

  delete [] buffer;

  if(!output.is_open())
    cout<<"ERROR: outwrite";
  else
  {
    for(int i = dim-1 ; i>=0; i--)
    {
      if(checkodd(text[i]))
	output<<text[i]<<" ";	
    }
  }

  output.close();
    
}
