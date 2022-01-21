#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;
vector<int> v;
vector<vector<int> > mymap;
int vis[10002];
int mm;
set <int> s;
void dfs(int x,int step){
	vis[x]= 1;
	if(step > mm){
		mm = step;
		v.clear();
		v.push_back(x);
	}else if(step == mm){
		v.push_back(x);
	}
	
	for(int i=0;i<mymap[x].size();i++){
		if(!vis[mymap[x][i]]){
			dfs(mymap[x][i], step+1);
		}
	}
}


int main(){
	int n;
	cin >> n;
	int a,b;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n-1;i++){
		
		cin>>a>>b;
		mymap[a].push_back(b);
		mymap[b].push_back(a);
	}
	int k=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i,0);
			k++;
		}
		
	}
	if(k ==1){
		v.clear();
		for(int i=1;i<=n;i++){
			memset(vis, 0, sizeof(vis));
			dfs(i,0);
		}
		for(int i=0;i<v.size();i++){//set保证不会重复
            s.insert(v[i]);
        }
        set<int>::iterator It;
        for(It=s.begin();It!=s.end();It++){
            printf("%d\n",*It);
        }

	}else{
		printf("Error: %d components\n",k );
	}
	return 0;
} 
