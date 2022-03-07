#include "iostream"
#include "string.h"
#include "vector"

#define inf 0x3f3f3f
using  namespace std;
int dest[501][501];
vector<int> pre[501];
vector<int>temp, res;
int costs[501][501];
int vis[501];
int dis[501];
int n,m,s,d;
int minCost = inf;
// 得到最短距离结果之后从后往前遍历最小花费
void dfs(int v){
    temp.push_back(v);
    if(v == s){
        int tempCost = 0;
        for(int i=1;i<temp.size(); i++){
            tempCost += costs[temp[i-1]][temp[i]];
        }
        if(minCost > tempCost){
            res = temp;
            minCost = tempCost;
        }
        temp.pop_back();
        return ;
    }
    for(int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
    temp.pop_back();
}
int main(){
    memset(dis,inf, sizeof (dis));
    fill(dest[0],dest[0]+501*501, inf);
    cin >>n>>m>>s>>d;

    memset(vis,0, sizeof(vis));
    int a,b,distance,cost;
    while(m--){
        cin >>a>>b>>distance>>cost;
        dest[a][b] = dest[b][a] = distance;
        costs[a][b] = costs[b][a] = cost;
    }
    dis[s] = 0;
   for(int i=0;i<n ;i++){
       int u = -1,minn = inf;
       for (int j=0; j<n; j++){
           if(vis[j] == 0 && ( minn > dis[j])){
               minn = dis[j];
               u = j;
           }
       }
       if(u == -1) break;
       vis[u] = 1;
       for(int j=0; j<n;j++){
           if( !vis[j] && dest[u][j] != inf){
               if (dis[j] > dis[u] + dest[u][j]){
                   dis[j] = dis[u] + dest[u][j];
                   pre[j].clear();
                   pre[j].push_back(u);
               }else if (dis[j] == dis[u] + dest[u][j]){
                   pre[j].push_back(u);
               }
           }
       }
   }
    dfs(d);
   for(int i=res.size()-1;i>=0;i--){
       if(i == res.size()-1) cout <<res[i];
       else cout <<" "<<res[i];
   }
   cout <<" "<<dis[d]<<" "<<minCost;
}