#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool check(string s);

int main(int argc, char * argv [])
{
	
	if(argc!=3)
	{
		cout<<"numero di argomenti non conforme"<<endl;
		return 1;
	}
	
	ifstream infile;
	infile.open(argv[1], ios::in);
	
	string buffer;
	
	infile>>buffer;
	
	int count = 0;
	
	if(check(buffer)) count++;
	
	while(infile>>buffer)
	{
		if(check(buffer)) count++;
	}
	
	infile.close();
	
	ofstream outfile;
	outfile.open(argv[2], ios::out);
	
	outfile<<count<<endl;
	
	outfile.close();
	
    return 0;
}

bool check(string s)
{
	if(s.length()!=19)
	{
		return false;
	}
	else
	{
		for(int i=0; i<19; i++)
		{
			if(i==4 or i==9 or i==14)
			{
				if(s.at(i)!='-') return false;
			}
			else
			{
				if(s.at(i)<'A' or s.at(i)>'Z') return false;
			}
        }
	}
	
	return true;
}
















