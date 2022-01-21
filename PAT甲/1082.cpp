#include<stdio.h>
#include<iostream>
#include<vector>
#include<sstream>
#include <algorithm>
using namespace std;

int main(){
	string str;
	cin >> str; 
	vector<string> vec;
	string a[]={"","yi","er","san","si","wu","liu","qi","ba","jiu"};
    string b[] = { "", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi" };
	for(int i=str.size()-1,k=0; i>=0; i--, k++){
		if(str[i] == '0'){
			if(k == 4){
				//判断是否需要加“Wan”,比如一亿 
				string s = str.substr(0, i+1);
				int n;
				stringstream ss;
				ss << s;
				ss >> n;
				if(n < 0){
					n = -n;
				}
				 if(n % 10000){
				 	vec.push_back("Wan");
				 }
			}
			if (vec.empty() || vec[vec.size()-1]== "ling" || vec[vec.size()-1] == "Wan"){
				continue;
			}
			vec.push_back("ling");
			continue;
		}
		
		if(str[i] == '-'){
			vec.push_back("Fu");
			break;
		}
		if(k){
			vec.push_back(b[k]);
		}
		vec.push_back(a[str[i] - '0']);
	}
	
	for(int i=vec.size()-1;i>=0;i--){
		cout<<vec[i];
		if(i != 0)
			cout<<" "; 
	}
	if(vec.size() == 0){
		cout << "ling";
	}
	return 0;
} 
