#include <iostream>
#include <map>
using namespace std;
map<string, int> stringToInt;
map<int, string> intToString;
map<string, int> ans;
int G[2010][2010], weight[2010];
bool vis[2010];
int stringId=1;
int creatId(string a){
    if(stringToInt.find(a) != stringToInt.end()){
        return stringToInt[a];
    }
    intToString[stringId] = a;
    stringToInt[a] = stringId;
    return stringId++;
}

void dfs(int u,int &head,int &membernum,int &totalweight){
    vis[u] = true;
    if(weight[head] < weight[u]) head = u;
    membernum++;
    for(int i=1;i<stringId;i++){
        if(G[i][u] >0 ){
            totalweight += G[u][i];
            G[u][i] = G[i][u] = 0;
            if(!vis[i]){
                dfs(i,head,membernum,totalweight);
            }

        }
    }
}

int main(){
    int m,n;
    string a,b;
    int time;
    cin >>m>>n;

    int cnt = 0;
    while(m--){
        cin >>a >>b>>time;
        int id1 = creatId(a);
        int id2 = creatId(b);
        weight[id1] += time;
        weight[id2] += time;
        G[id1][id2] = time;
        G[id2][id1] = time;
    }

   for(int i=1;i<stringId;i++){
       if(vis[i] == false){
           int head = i,membernum = 0,totalweight = 0;
           dfs(i,head,membernum,totalweight);
           if(totalweight > n && membernum >2){
               ans[intToString[head]] = membernum;
           }
       }
   }
   cout << ans.size()<<endl;
   for( auto i = ans.begin();i!= ans.end();i++){
       if(i != ans.begin()) cout <<endl;
       cout << i->first<<" "<<i->second;
   }
    return 0;
}
