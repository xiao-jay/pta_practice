#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<string>s(10002);
bool flag=false;

bool cmp(string a,string b){
	return a+b<b+a;
}

void print(string a){
	int i=0;
	while(a[i]=='0' && i<a.length()){
		i++;
	}
	if(i < a.length()){
		flag = true;
		for(int j=i;i<a.length();i++){
			cout<<a[i];
		}
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s.begin(),s.begin()+n,cmp);
	for(int i=0;i<n;i++){
		if(!flag) print(s[i]);
		else cout<<s[i];
	}
	if(!flag){
		cout<<0; 
	}
	return 0;
} 
