#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int part_a(vector<int>& num){
	int multiplied;
	for(vector<int>::iterator i = num.begin(); i != num.end(); ++i){
		for( vector<int>::iterator j = num.begin(); j != num.end(); ++j){
			if((*i)+(*j) == 2020){
				multiplied = (*i)*(*j);
			}
		}
	}
	return multiplied;
}


int part_b(vector<int>& num){
	int multiplied;
	for( vector<int>::iterator i = num.begin(); i != num.end(); ++i){
		for( vector<int>::iterator j = num.begin(); j != num.end(); ++j){
			for( vector<int>::iterator k = num.begin(); k != num.end(); ++k){
				if((*i)+(*j)+(*k) == 2020){
					multiplied = (*i)*(*j)*(*k); 	
				}
			}
		}
	}
	return multiplied;
}

int main(){
	//get le numbers
	string line;
	vector<int> numbers;
	ifstream infile("numbers.txt");
	while(getline(infile, line)){
		istringstream iss(line);
		int a;
		if(!(iss>>a)) {break;}
		numbers.push_back(a);
	}
	infile.close();
	
	//idea: 2 nested loops. Check if first index + second index is together 2020
	//runtime? worstcase o(n^2)
	//better idea? ! Yes: use hashmap and take advantage of a-2020=b!
	int a_sol = part_a(numbers);
	int b_sol = part_b(numbers); 
	cout << "Part A Solution: " << a_sol << "\n";	
	cout << "Part B Solution: " << b_sol << "\n";

	//solution using hashmap/unorderedmap

	return 0;
}


