// Giovanni: condizione check1 errata. Il codice nei test di output non funziona
// correttamente.

#include <iostream>
#include <fstream>
using namespace std;

const int DIM_PAROLA = 101;

bool check_first(char * word,int len);
bool check_second(char *word ,int len);
bool check_third(char *word ,int len);
int strlen(char * word);

int main(int argc, char * argv [])
{
  if(argc != 3){
    cout << "Using: a.out <input_file> <output_file>" << endl;;
    exit(1);
  }

  fstream input,output;
  input.open(argv[1],ios::in);
  output.open(argv[2],ios::out);

  if (input.fail() || output.fail()){
    cout << "Error opening file!" << endl;
    exit(1);
  }

  char word[DIM_PAROLA];
  int len;
  //int index = 0;
  while(input >> word){
    len = strlen(word);
    if (check_first(word,len) && check_second(word,len) && check_third(word,len)){
      output << word << "\n";
    }
  }


  return 0;
}

bool check_first(char * word,int len){
  bool check = false;
  if(word[0] == 'U' && word[len-1] == 'M'){
    check = true;
  }else{
    check = false;
  }



  return check;
}

bool check_second(char *word,int len){
  bool check = true;
  int count_i = 0;
  for(int i = 0; i < len;i++){
    if (word[i] == 'I'){
      count_i++;
    }
  }
  if(count_i == 0 || (count_i % 2) == 0){
    check = true;
  }else{
    check = false;
  }
  return check;
}

bool check_third(char *word,int len){
  bool check = true;
  for(int i = 0;i < len;i++){
    if (word[i] == 'M'){
      if (word[i+1] != 'I'){
        check = true;
      }else{
        check = false;
      }
    }
  }
  return check;
}


int strlen(char * word){
  int i = 0;
  while(word[i] != '\0'){
    i++;
  }
  return i;
}
