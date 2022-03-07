#include "iostream"
#include "string.h"
using namespace std;
#define Inf 0x3f3f3f
#define size 1002
int dis[size][size];
int ans[size];
int m,n,k;

bool check(){
    int used[size] = {0},dist[size] = {0};
    memset(dist,0x3f,sizeof (dist));
    dist[ans[1]] = 0;
    for (int i=1;i<=m;i++){
        int u = -1;
        // 先找到最小值
        for(int j=1; j<= m;j++){
            if( !used[j] && (u==-1 || dist[u] > dist[j]) ) u = j;
        }
        if (dist[u] != dist[ans[i]]){
            return false;
        }
        for(int j=1; j<=m; j++){
            if (j == u) continue;
            dist[j] = min(dist[j], dist[u] + dis[u][j]);
        }
        used[u] = 1;
    }
    return true;
}


int main(){

    cin >>m>>n;
    int a,b,c;
    memset(dis,Inf, sizeof(dis));
    while(n--){
        cin >>a>>b>>c;
        dis[a][b] = dis[b][a] = c;
    }
    cin >>k;
    while(k--){
        for(int i=1;i<=m;i++){
            cin >>ans[i];
        }
        if (check()){
            cout <<"Yes"<<endl;
        }else{
            cout <<"No" <<endl;
        }
    }
    return 0;
}