// Giovanni: mancano le chiusure dei vari stream

#include <iostream>
#include <fstream>
using namespace std;

bool isMIU(char str[])
{
  bool retval = true;
  bool enforce_last_M = (str[0] == 'U');
  bool enforce_not_next_I = false;
  int I_counter = 0;
  int i;
  for (i=0; retval && str[i]!='\0'; i++)
  {
    if (enforce_not_next_I)
    {
      retval = (str[i] != 'I');
      enforce_not_next_I = false;
    }
    if (str[i]=='I') I_counter++;
    else if (str[i]=='M') enforce_not_next_I = true;
  }

  if (enforce_last_M)
    retval = retval && (str[i-1] == 'M');
  retval = retval && (I_counter %2 == 0);

  return retval;

}

int main(int argc, char * argv [])
{
  if (argc != 3)
  {
    cout << "Usage: <exec> <input file> <output file>\n";
  }
  else
  {
    fstream read, write;
    read.open(argv[1], ios::in);
    write.open(argv[2], ios::out);

    if (read.fail())
    {
      cout << "Nonexistent input file\n";
    }
    else if (write.fail())
    {
      cout << "Insufficient permission to write\n";
    }
    else
    {
      char buffer[101];
      while (read >> buffer)
      {
        if (!isMIU(buffer))
        {
          write << buffer << "\n";
        }
      }
    }
  }

  return 0;
}
