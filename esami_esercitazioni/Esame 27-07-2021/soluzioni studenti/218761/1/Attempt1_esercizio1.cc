#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_LEN = 101;

bool is_format (char str []){
int lun = strlen(str);

bool correct = true;

  if(lun == 19){
    
    for(int i = 0; i < lun && correct; i++){
      
      if(i == 4 || i == 9 || i == 14){
        if (str[i] != '-'){
          correct = false;
        }   
      }
      else if (str[i] < 'A' || str[i] > 'Z'){
        correct = false;
      }
    }

  }
  else{
    correct = false;
  }

  return correct;
}

int main(int argc, char * argv [])
{
  if(argc != 3){
    cout << "Error! Missing files\n";
    exit(1);
  }

  fstream in, out;
  in.open(argv[1], ios::in);
  out.open(argv[2], ios::out);

  if(in.fail() || out.fail()){
    cout << "Error! File not found\n";
    exit(1);
  }

  char word [MAX_LEN];
  int format_counter = 0;

  while (in >> word){
    if(is_format(word)){
      format_counter++;
    }
  }

  out << format_counter;

  in.close();
  out.close();

  return 0;
}
