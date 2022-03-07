#include "iostream"
#include "vector"
#include "string.h"
#include "map"
using namespace std;
#define inf 0x3f3f3f3f
int dis[201][201];
int dest[201];
int vis[201];
vector<int> pre[201],temp,res;
int maxHappy = 0;
struct City{
    int no,happy;
    string name;
};
int m,n;
string start;
map<string, City> mapCity;
map<int, City> mapCityNo;
int pathNumber=0;
void dfs(int v){
    temp.push_back(v);
    if(v == mapCity[start].no){
        pathNumber ++;
        int tempHappy = 0;
        for (int i=0;i<temp.size(); i++){
            tempHappy += mapCityNo[temp[i]].happy;
        }
        if(tempHappy > maxHappy){
            maxHappy = tempHappy;
            res = temp;
        }
        temp.pop_back();
        return ;
    }
    for(int i: pre[v]) dfs(i);
    temp.pop_back();
}
int main(){
    memset(dis,inf, sizeof(dis));
    memset(dest,inf, sizeof(dest));
    memset(vis,0, sizeof(vis));
    cin >>m>>n>>start;
    City city;
    city.no = 0;
    city.name = start;
    city.happy = 0;
    mapCity[start] = city;
    mapCityNo[0] = city;
    for(int i=1;i<m;i++){
        City node;
        cin >>node.name >>node.happy;
        node.no = i;
        mapCity[node.name] = node;
        mapCityNo[node.no] = node;
    }
    for(int i=0; i<n; i++){
        string a,b;
        int c;
        cin >>a>>b>>c;
        dis[mapCity[a].no][mapCity[b].no] =dis[mapCity[b].no][mapCity[a].no]= c;
    }
    dest[0] = 0;
    for(int i=0;i<m; i++){
        int u = -1, minn = inf;
        for(int j=0;j<m;j++){
            if( vis[j] == 0 && dest[j] < minn){
                minn = dest[j];
                u = j;
            }
        }
        if(u == -1) break;
        vis[u] = 1;
        for(int j=0;j<m ; j++){
            if(vis[j] == 0 && dis[u][j] != inf){
                if(dest[j] >dest[u] + dis[u][j]){
                    dest[j] = dest[u] + dis[u][j];
                    pre[j].clear();
                    pre[j].push_back(u);
                }else if(dest[j] == dest[u] + dis[u][j]){
                    pre[j].push_back(u);
                }
            }
        }
    }
    dfs(mapCity["ROM"].no);
    cout << pathNumber<<" "<<dest[mapCity["ROM"].no]<<" "<<maxHappy<<" "<<maxHappy/(res.size()-1)<<endl;
    for(int i=res.size()-1;i >=0 ;i--){
        if(i == res.size()-1){
            cout << mapCityNo[res[i]].name;
        }else{
           cout <<  "->"<< mapCityNo[res[i]].name;
        }
    }
}