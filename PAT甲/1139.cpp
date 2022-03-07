#include "iostream"
#include "vector"
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<int, bool> res;
vector<int> v[10000];
struct Node {
    int a,b;
};
bool cmp(Node a,struct Node b){
    return a.a != b.a ? a.a<b.a : a.b<b.b;
}
int main(){
    int m, n = 0;
    cin >>m>>n;
    for(int i=0;i<n;i++){
        string a,b;
        cin >>a>>b;
        if(a.length() == b.length()){
            v[abs(stoi(a))].push_back(abs(stoi(b)));
            v[abs(stoi(b))].push_back(abs(stoi(a)));
        }
        res[abs(stoi(a))*10000 +abs(stoi(b))] = res[abs(stoi(b))*10000 +abs(stoi(a))] = true;
    }
    int p;
    cin >>p;
    for(int i=0; i<p;i++){
        int c,d;
        cin >>c>>d;
        vector<Node> ans;
        for(int j=0;j<v[abs(c)].size();j++){
            for(int k=0 ;k<v[abs(d)].size();k++){
                //是自己
                if (v[abs(c)][j] == abs(d) || abs(c) == v[abs(d)][k]) continue;
                // c和d认识
                if(res[v[abs(c)][j] * 10000 + v[abs(d)][k]]){
                    ans.push_back(Node{.a = v[abs(c)][j],.b = v[abs(d)][k]});
                }
            }
        }
        sort(ans.begin(),ans.end(), cmp);
        cout << ans.size()<<endl;
        for(int j=0;j<ans.size(); j++){
            printf("%04d %04d\n", ans[j].a, ans[j].b);
        }
    }
}