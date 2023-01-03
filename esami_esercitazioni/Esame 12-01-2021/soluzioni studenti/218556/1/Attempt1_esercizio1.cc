// GDT: il codice non rispetta le specifiche della consegna.
// Fare riferimento alla soluzione ufficiale per un possibile svolgimento. 

#include <iostream>
#include <fstream>
using namespace std;

const int maxLenght = 100;

int main(int argc, char *argv[])
{
  fstream input, output;
  input.open("input.txt");
  output.open("output.txt");
  if (input.is_open() && output.is_open())
  {

    while (!input.eof())
    {

      char word[maxLenght];
      char n;

      int counter = 0;
      for (int i = 0; i < maxLenght; i++)
      {
        input.get(n);
        if (n == ' ' || input.eof())
        {
          i = maxLenght;
        }
        else
        {
          word[i] = n;
          counter++;
        }
      }
      if (counter % 2 == 1)
      {
        for (int i = 0; i < counter; i++)
        {
          output << word[i];
        }

        output << ' ';
      }
    }

    input.close();
    output.close();
  }
  return 0;
}
