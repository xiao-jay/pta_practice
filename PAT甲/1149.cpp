#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>
#include<string.h>
using namespace std;

int main(){
	map<int,vector<int> > d;
	int k,n,t;
	cin >>k>>n;
	while(k--){
		int a,b;
		cin>>a>>b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	while(n--){
		int flag[100000] = {0};
		cin>>t;
		int flag1 = 1;
		vector<int>v(t);
		for(int i=0;i<t;i++){
			cin>>v[i];
			flag[v[i]] = 1;
		}
		for(int i=0;i<t;i++)
			for(int j=0;j<d[v[i]].size();j++){
				if(flag[d[v[i]][j]] == 1){
					flag1 = 0;
				} 
			} 	
		if(flag1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
} 
