#include "iostream"
#include "vector"
#include "math.h"
using namespace std;
int n,p,k;
vector<int> res,temp,fac;
int indexSum = -9999;
void dfs(int index, int nowK,int sum, int facSum){
    if(nowK > k || sum >n) return ;
    if (sum == n && nowK == k){
        if(facSum > indexSum ){
            indexSum = facSum;
            res = temp;
        }
        return ;
    }
    if (index >=1){
        temp.push_back(index);
        dfs(index, nowK+1, sum+fac[index], facSum+index);
        temp.pop_back();
        dfs(index-1, nowK, sum , facSum );
    }

}
int main(){
    cin >> n>>k>>p;

    int tmp =0;
    int j = 1;
    while(tmp <= n){
        fac.push_back(tmp);
        tmp = int(pow(j++,p));
    }
    dfs(fac.size()-1, 0,0,0);
    for(int i=0;i<res.size(); i++){
        if(i == 0){
            cout << n<<" = ";
            cout << res[i] <<"^"<<p;
        }else
            cout <<" + " << res[i] <<"^"<<p;
    }
    if(indexSum == -9999){
        cout << "Impossible"<<endl;
    }
    return 0;
}