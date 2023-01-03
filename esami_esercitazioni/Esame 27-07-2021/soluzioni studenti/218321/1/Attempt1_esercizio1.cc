#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
  if( argc != 3)
    {
      cout << "Usage: " << argv[0] << " <inputfile.txt> <outputfile.txt>"<< endl;
      exit(1);
    }

  int counter = 0, CI = 0;

  fstream file, output;
  file.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  if(file.fail())
    {
      cout << "Your <inputfile.txt> does not exist!" << endl;
      exit(1);
    }

  char l, temp = ' ';
  file.get(l);

  while(!file.eof())
    {
      if( (temp == ' ' && counter == 0) || (temp != ' ' && counter != 0) )
	{
	  if( counter == 16 )
	    {
	      CI++;
	      counter = 0;
	    }
	  else if( counter >= 4 )
	    {
	      if( l >= '0' && l <= '9')
		counter++;
	    }
	  else if( l >= 'A' && l <= 'Z' )
	    counter++;
	  else
	    counter = 0;
	}

      temp = l;
	
      file.get(l);
    }

  file.close();
  
  output << CI;

  output.close();
  
  return 0;
}
