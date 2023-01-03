#include <iostream>
#include <fstream>
using namespace std;

#define MAX_WORD 101

int main(int argc, char * argv [])
{
  if(argc != 3){
    cout << "Error! Usage: ./a.out <input_file> <output_file>" << endl;
    exit(0);
  }

  fstream in, out;
  in.open(argv[1], ios::in);
  out.open(argv[2], ios::out);

  if(in.fail() || out.fail()){
    cout << "An error has occured while opening the files, check the input file exists and you have the permissions to open the output file in the" << endl;
    in.close(); out.close();
    exit(0);
  }

  char buffer[MAX_WORD];
  bool miu = true;
  bool check_M = false;
  int i_count = 0; // It counts the 'I's
  int i = 0;
  while(in >> buffer){
    miu = true;
    i_count = 0;
    check_M = false;

    if(buffer[0] == 'M') check_M = true;
    i = 0;
    for(; buffer[i] != '\0'; i++){
      if(buffer[i] == 'I') i_count++;
      if(buffer[i] == 'I' && buffer[i+1] == 'M') miu = false;
    }

    if(check_M && buffer[i-1] != 'U') miu = false;
    if(!(i_count%2 != 0 || i_count == 0)) miu = false;
    if(miu) out << buffer << endl;
  }

  in.close();
  out.close();
  return 0;
}
