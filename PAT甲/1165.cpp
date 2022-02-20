#include<iostream>
#include<vector>
using namespace std;
struct node{
    int id,dat,next;
};
int main(){
    int begin, n, k;
    scanf("%d%d%d",&begin,&n,&k);
    node a[100010];     //特别注意数组大小
    vector<node> v, ans;
    int s,d,e;
    for(int i=0; i<n; i++){
        scanf("%d%d%d",&s,&d,&e);
        a[s]={s,d,e};
    }
    for(; begin!=-1; begin=a[begin].next){
        v.push_back(a[begin]);
    }
    int num=n/k;
    if(n%k) num++;
    int len=v.size();
    for(int i=num-1; i>=0; i--){
        for(int j=0; j<k; j++){
            int t=i*k+j;
            if(t<len) ans.push_back(v[t]);//注意插入的写法
        }
    }
    int i;
    for(i=0; i<ans.size()-1; i++){
        printf("%05d %d %05d\n", ans[i].id, ans[i].dat, ans[i+1].id);
    }
    printf("%05d %d -1\n", ans[i].id, ans[i].dat);
    return 0;
}
