#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <iostream>
using namespace std;

int main(){
	string line;
	ifstream infile("rules.txt");
	int valid = 0;
	while(getline(infile, line)){
		auto start = line.begin();
		string lower;
		string upper;
		char rule;
		string pass;


		while(*start != '-'){
			lower += *start;
			start++;
		}
		start++; //skip -
		cout << "lower: " << lower << '\n';
		while(*start != ' '){
			upper += *start;
			start++;
		}
		cout << "upper: " << upper << '\n';
		
		start += 1;
		rule = *start;
		
		cout << "Rule: " << rule << '\n';
		
		start += 3;

		while(start <= line.end()){
			pass += *start;
			start++;
		}
		cout << "Pass: " << pass << '\n';
		//check if lower or upper index is rule:
		
		cout << "First letter: " <<  pass.at(stoi(lower)-1) << " Second letter:" <<  pass.at(stoi(upper)-1) << "\n";
		if( (pass.at(stoi(lower)-1) == rule) != (pass.at(stoi(upper)-1) == rule) ){
			valid++;
			cout << "VALID \n";
		}else{
			cout << "NOTVALID \n";
		}
	}
	infile.close();
	cout << valid << "\n";	
	return 0;
}
