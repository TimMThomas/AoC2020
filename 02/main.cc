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
		string rule;
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
		
		start += 2;

		while(start <= line.end()){
			pass += *start;
			start++;
		}
		cout << "Pass: " << pass << '\n';
		//count amount of rule chars in pass:
		int cnt = 0;
		for(char const &c: pass){
			if(c == rule[0]){
				cnt++;
			}
		}
		cout << "Count: " << cnt << "\n"; 
		//check if count is in bounds
		if(cnt >= stoi(lower) && cnt <= stoi(upper)){
			cout << "WAS VALID \n";
			valid++;	
		}
	}
	infile.close();
	cout << valid << "\n";	
	return 0;
}
