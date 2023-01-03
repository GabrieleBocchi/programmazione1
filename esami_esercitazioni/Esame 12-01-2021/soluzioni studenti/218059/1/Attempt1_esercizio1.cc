#include <iostream>
#include <fstream>
using namespace std;



void copy(char * a, char * tmp, int dim_tmp);

int main(int argc, char * argv [])
{

if(argc!=3){
  cout<<"error"<<endl;
}else{

  fstream in, out;

  in.open(argv[1], ios::in);
  out.open(argv[2], ios::out);

if(in.fail()){
  cout<<"errore"<<endl;
}else{
   char parole[10000][100];
   int index=0;
   
   char tmp[100];

   in >> tmp;
   int dim_tmp=sizeof(tmp)/sizeof(char);
 
   while(!in.eof())
   {
     copy(parole[index],tmp,dim_tmp);
    
     index++;
     in >> tmp;
     dim_tmp=sizeof(tmp)/sizeof(char);
   }


 for (int i = index; i >= 0; i--) {
   char tmp='a';
   int j=0;
   while(tmp!='\0') {
     j++;
     tmp=parole[i][j];
    
   }
   if(j<=4){
   out << parole[i];
   out << " ";
  }
    
  }

  in.close();
  out.close();
  
}

}

  return 0;
}

void copy(char * a, char * tmp,int dim_tmp){

for (int i = 0; i < dim_tmp; i++)
{
 a[i]=tmp[i];
}


}
