#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

#define maxn 110
struct node{	//Ê÷µÄ¾²Ì¬´æ´¢
	vector<int>children;
}t[maxn];
int maxLevel = -1;
int ithLevel[maxn];
void dfs(int root,int depth){
	if(t[root].children.size() == 0){
		if(maxLevel < depth){
		maxLevel = depth;
		
		}
		ithLevel[depth]++;
		return ;
	}
	for(int i=0;i<t[root].children.size();i++){
		dfs(t[root].children[i],depth+1);
	}
}
int main(){
	int m,n;
	cin >>n>>m;
	memset(ithLevel,0,sizeof(ithLevel));
	for(int i=0;i<m;i++){
		int id,size;
		cin>>id>>size;
		for(int j=0;j<size;j++){
			int child;
			cin >>child;
			t[id].children.push_back(child);
		}
	} 
	dfs(1,0);
	for(int i=0;i<maxLevel;i++){
		cout<<ithLevel[i]<<" ";
	}
	cout<<ithLevel[maxLevel];
} 
