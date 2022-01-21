#include<bits/stdc++.h>

using namespace std;
int n,l;
const int N=1e3+10;
vector<int>vec[N];
int num=0;
struct node
{
    int to;
    int step;
    node(int _to=0,int _step=0):to(_to),step(_step){}
};
bool vis[N];

void bfs(int v){
	vis[v] = true;
	queue<node> Q;
	Q.push(node(v,0));
	
	while(!Q.empty()){
		node u = Q.front();
		if(u.step >l) return ;
		Q.pop();
		int to = u.to;
		num ++;
		for(int i=0;i<vec[to].size();i++){
			if(!vis[vec[to][i]]){
				 Q.push(node(vec[to][i],u.step+1));
                vis[vec[to][i]]=true;
			}
		}
	}
} 

int main()
{
    scanf("%d %d",&n,&l);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            int x;
            scanf("%d",&x);
            vec[x].push_back(i);
        }
    }
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int x;
        fill(vis,vis+N,false);
        num=0;
        scanf("%d",&x);
        bfs(x);
        printf("%d\n",num-1);
    }
    return 0;
}
