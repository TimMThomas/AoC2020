#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
#include <regex>
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
			fields = 1;
			continue;
		}

		//"tokenize" the line
		istringstream iss(line);
		string str = string{};
		while(iss >> str){
			//if we find cid continue else increase fields
			if(str.find("cid",0)==0){
				continue;
			}else if(str.find("byr",0)==0){
				string val = str.substr(4,str.size()-1);
				if(regex_match(val,regex("[\\d]{4}"))){
					int value = stoi(val);
					if(value >= 1920 && value <= 2002){
						fields++;
					}
				}
			}else if(str.find("iyr",0)==0){
				string val = str.substr(4,str.size()-1);
				if(regex_match(val,regex("[\\d]{4}"))){
					int value = stoi(val);
					if(value >= 2010 && value <= 2020){
						fields++;
					}
				}
			}else if(str.find("eyr",0)==0){
				string val = str.substr(4,str.size()-1);
				if(regex_match(val,regex("[\\d]{4}"))){
					int value = stoi(val);
					if(value >= 2020 && value <= 2030){
						fields++;
					}
				}
			}else if(str.find("hgt",0)==0){
				string mode = str.substr(str.size()-2,str.size());
				if(mode == "cm"){
					int value = stoi(str.substr(4,str.size()-1));
					if(value >= 150 && value <= 193){
						fields++;
					}
				}else if(mode == "in"){
					int value = stoi(str.substr(4,str.size()-1));
					if(value >= 59 && value <= 76){
						fields++;
					}
				}
			}else if(str.find("hcl",0)==0){
				string val = str.substr(4,str.size()-1);
				if(regex_match(val,regex("#[\\d|a-z]{6}"))){
					fields++;
				}
			}else if(str.find("ecl",0)==0){
				string val = str.substr(4,str.size()-1);
				if(val == "amb" || val == "blu" ||val == "brn" ||val == "gry" ||val == "grn" ||val == "hzl" ||val == "oth")
					fields++;

			}else if(str.find("pid",0)==0){
				if(regex_match(str.substr(4,str.size()-1), regex("\\d{9}"))){
					long value = stol(str.substr(4,str.size()-1));
					fields++;
				}
			}
			//in the end there should be 8 fields (including optional cid)
			if(fields == 8){
				valid++;
			}
		}
	}

        infile.close();
        cout << valid << "\n";
	return 0;
}
