#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_WORD_SIZE = 101; 
const int SERIAL_CODE_SIZE = 19; 

bool is_upper(char c)
{
  if(c >= 'A' && c <= 'Z')
    return true; 
  else 
    return false; 
}

bool is_serial_code(char const* word)
{
  bool valid = true;
  int letter_count = 0; 
  int i; 
  for(i = 0; i < MAX_WORD_SIZE && word[i] != '\0' && valid; ++i)
  {
    if(i >= SERIAL_CODE_SIZE)
      valid = false; 
    else if(!( (isupper(word[i]) && letter_count < 4) || (word[i] == '-' && letter_count == 4)))
      valid = false; 
    else 
    {
      if(word[i] == '-')
        letter_count = 0; 
      else 
        ++letter_count; 
    }
  } 
  if(valid && i != SERIAL_CODE_SIZE)
    valid = false; 
  
  return valid; 
}

bool valid_file(bool fail, char const* filename)
{
  if(fail)
  {
    std::cerr << "non e' stato possibile aprire " << filename
      << std::endl; 
    return false; 
  }
  return true; 
}

int main(int argc, char * argv [])
{
  if(argc != 3)
  {
    std::cerr << "uso: " << argv[0] << " <file_input> <file_output>" 
      << std::endl; 
    return -1; 
  }
  
  fstream in_file; 
  in_file.open(argv[1], ios::in); 
  if(!valid_file(in_file.fail(), argv[1]))
      return -1; 


  fstream out_file; 
  out_file.open(argv[2], ios::out); 
  if(!valid_file(out_file.fail(), argv[2]))
    return -1; 

  char buffer[MAX_WORD_SIZE]; 
  int serial_count = 0; 
  while(in_file >> buffer)
    if(is_serial_code(buffer))
      ++serial_count; 
  
  out_file << serial_count << endl; 

  in_file.close(); 
  out_file.close(); 

  return 0;
}
