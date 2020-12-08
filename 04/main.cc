#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

int main(){
        ifstream infile;
        infile.open("passports.txt");
        string line;
        int valid = 0;
	int fields = 1;
	//get line from file
	while(getline(infile, line)){
		//if the file is only '\n' reset die amount of fields and skip to next line
		if(line.size() == 0){
			cout << '\n';
			if(fields == 8){
				cout << "VALID; \n";
				valid++;
			}
			fields = 1;
			continue;
		}

		//"tokenize" the line
		istringstream iss(line);
		string str = string{};
		while(iss >> str){
			
			//if we find cid continue else increase fields
			if(str.find("cid",0)==0){
				cout << str << " fields: " << fields  << '\n';
				continue;
			}
			fields++;
			cout << str << " fields: " << fields  << '\n';
		}
		
		//in the end there should be 8 fields (including optional cid)
		
	}
	if(fields == 8){
		cout << "VALID; \n";
		valid++;
	}
	cout << valid << '\n';
        infile.close();
        return 0;
}
