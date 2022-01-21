#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int vis[1002];
int m,n,k;
int graph[1001][1001];
int dfs(int num){
	for(int i=1;i<=m;i++){
		if(graph[num][i]&&vis[i]==0){
			vis[i] = 1;
			dfs(i);
		}
	}
}
int main(){
	
	int a,b,cnt=0;
	cin >>m>>n>>k;
	memset(graph,0,sizeof(graph));
	while(n--){
		cin>>a>>b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}	
	while(k--){
		memset(vis,0 ,sizeof(vis));
		cin>>a;
		cnt = 0;
		vis[a] = 1;
		for(int i=1;i<=m;i++){
			if(!vis[i]){
				dfs(i);
				cnt++;
			}
		}
		cout<<cnt-1<<endl;
	}
}
