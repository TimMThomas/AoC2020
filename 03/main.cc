#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int check_slope(vector<string> area, int right, int down){
	int i = 0;
	int j = 0;
	int trees = 0;
	while(j < area.size()){
		if(area[j][i] == '#'){
			trees++;
		}
		i += right;
	 	
		i %= area[j].size();
		
		j += down;
	}
	return trees;
}

int main(){
	ifstream infile;
	infile.open("trees.txt");
	vector<string> area;
	string line;
	while(infile >> line){
		area.push_back(line);		
	}
	infile.close();
	long res = 1;	
       	res *= check_slope(area, 1, 1);
	res *= check_slope(area, 3, 1);
	res *= check_slope(area, 5, 1);
	res *= check_slope(area, 7, 1);
	res *= check_slope(area, 1, 2);
	cout << res << '\n';
	return 0;
}
