#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void toUpCase(char& c){
	if(c>='a'&&c<='z'){
		c=c-'a'+'A';
	}
}
void toLowerCase(char& c){
	if(c>='A'&&c<='Z'){
		c=c-'A'+'a';
	}
}

int main(int argc, char* argv[]) {
	
	if(argc!=3){
		cerr<<"n parametri errati"<<endl;
		exit(-1);
	}
	
	ifstream input;
	input.open(argv[1],ios::in);
	
	if(input.fail()){
		cerr<<argv[1]<<" non aperto"<<endl;
		exit(-2);
	}
	
	ofstream output;
	output.open(argv[2],ios::out);
	
	if(output.fail()){
		cerr<<argv[2]<<" non aperto"<<endl;
		exit(-3);
	}
	
	char c;
	char prec;
	char prec2;
	
	input.get(c);
	toUpCase(c);
	output<<c;
	prec=c;
	
	
	while(input.get(c)){
		if(prec2==','|prec2==':'|prec2==';'){
			//cout<<prec2<<' '<<c<<endl;
			toLowerCase(c);
		}
		output<<c;
		
		prec2=prec;
		prec=c;
		
	}
	
	
	
	output.close();
	input.close();
	return 0;
}
