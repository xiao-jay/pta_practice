#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int m,n,sum=0;
vector<int> vec,res;
vector<int> num;
void dfs(int index,int sum, int& flag){
	if(sum >m || flag ==1){
		return ;
	}
	if(sum == m && flag ==0){
		flag = 1;
		res = vec;
		return;
	} 
	for(int i=index;i<=n;i++){
		vec.push_back(num[i]);
		dfs(i+1,sum + num[i],flag);
		vec.pop_back();
	}
} 
int main(){
	int total=0;
	cin>>n>>m;
	int a;
 	num.push_back(0);
	for(int i=0;i<n;i++){
		cin>>a;
		num.push_back(a);
		total+=a;
	}
	if(m>total){
		printf("No Solution");
		return 0; 
	}
	sort(num.begin(),num.end());
	int flag = 0;
	
	dfs(1,0,flag);
	
	if(flag){
		for(int i=0;i<res.size();i++)
  			printf("%d%s",res[i],i==res.size()-1?"":" ");
	}else{
		printf("No Solution");
	}
}
