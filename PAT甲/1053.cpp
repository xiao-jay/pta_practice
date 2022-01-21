#include<stdio.h>
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
	int weight;
	vector<int> next;
}nodes[102];
int n,m,res;
vector<int> temp;

bool cmp(int a,int b){//让权值大的子节点排到前边，以便于遍历时先被选出
    return nodes[a].weight>nodes[b].weight;
}

void dfs(int index, int sum){
	if(sum == res){
		if(nodes[index].next.size()!=0)  return;
		for(int i=0;i<temp.size();i++){
			if(i<temp.size()-1) cout<<temp[i]<<" ";
			else cout << temp[i]<<endl;
		}
	}
	if(index >=n || sum>res) return;
	for(int i=0;i<nodes[index].next.size();i++){
		temp.push_back(nodes[nodes[index].next[i]].weight);
		dfs(nodes[index].next[i],sum+nodes[nodes[index].next[i]].weight);
		temp.pop_back();
	}
}
int main(){
	
	cin>>n>>m>>res;
	for(int i=0;i<n;i++){
		cin >> nodes[i].weight;
	} 
	for(int i=0;i<m;i++){
		int a,num;
		cin>>a>>num;
		while(num--){
			int b;
			cin >>b;
			nodes[a].next.push_back(b);
		}
		sort(nodes[a].next.begin(),nodes[a].next.end(),cmp);
	}
	temp.push_back(nodes[0].weight);
	dfs(0,nodes[0].weight);
} 
