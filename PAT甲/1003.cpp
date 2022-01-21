#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

#define maxn 505
#define inf 1e8

int n,m,start;
int end1;
					//mark为标记是否算最近路径点 
int graph[maxn][maxn],weight[maxn],dis[maxn],mark[maxn],cnt=0,maxW =0;
vector<vector<int> > pre;
vector<int> temp;

void dijkstra(int start){
	dis[start] = 0;
	for(int i=0;i<n;i++){
		int pos = -1,min = inf;
		//找到最临近的点 
		for(int j=0;j<n;j++){
			if(mark[j] == 0 && dis[j] < min){
				min = dis[j];
				pos = j;
			}
		}
		if(pos == -1) return ;
		mark[pos] = 1;
		for(int j=0;j<n;j++){
			if(mark[j] == 0){
				if(graph[pos][j]+dis[pos] <dis[j]){
					pre[j].clear();
					pre[j].push_back(pos);
					dis[j] = dis[pos] + graph[pos][j];
				}
				else if (graph[pos][j] + dis[pos] == dis[j])
					pre[j].push_back(pos);
			}
		}
	}
}

void dfs(int e){
	if(e == start){
		temp.push_back(e);
		cnt++;
		int sumW = 0;
		for(int i=0; i < temp.size();i++){
			sumW += weight[temp[i]];
		}
		maxW = (maxW > sumW) ?maxW :sumW;
		temp.pop_back();
		return;
	}
	temp.push_back(e); 
	for(int i=0;i<pre[e].size();i++){
		cout << pre[e][i] <<endl;
		dfs(pre[e][i]);
	}
	temp.pop_back();
}
int main(){
	
	scanf("%d%d%d%d",&n,&m,&start,&end1);
	pre.resize(n);
	for(int i=0;i<n;i++){
		dis[i] = inf;
		mark[i] = 0;
		//把临近都初始化为不可及 
		for(int j=0;j<n;j++) graph[i][j] = inf;
	}
	for(int i=0;i<n; i++) scanf("%d",&weight[i]);
	for(int i=0; i<m; i++){
		int row,col,dist;
		scanf("%d%d%d",&row,&col,&dist);
		graph[row][col] = dist;
		graph[col][row] = dist;
	}
	dijkstra(start);
	dfs(end1);
	cout << cnt << " " <<maxW <<endl; 
	
} 
