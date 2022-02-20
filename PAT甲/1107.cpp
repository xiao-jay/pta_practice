#include "iostream"
#include "string.h"
#include "algorithm"
using namespace std;

int father[1001],hobby[1001];
int num[1001];
int find(int a){
    while(a != father[a]){
        a = father[a];
    }
    return a;
}

void Union(int a,int b){
    int fa = find(a);
    int fb = find(b);
    if(fa != fb){
        father[fb] = fa;
    }
}
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int n;
    cin >>n;
    memset(hobby, 0 ,sizeof (hobby));
    memset(num, 0 ,sizeof (hobby));
    for(int i=1;i<=n ;i++){
        father[i] = i;
    }
    for(int i=1;i<=n;i++){
        int num1;
        scanf("%d: ",&num1);
        for(int j=0;j < num1; j++){
            int t ;
            cin >>t;
            if( hobby[t] == 0)  hobby[t] = i;
            else {
               Union(hobby[t], i);
           }
        }
    }
    int sum = 0;
    for(int i=1; i<=n; i++){
        int temp = find(i);
        if (i == temp) sum++;
        num[temp]++;
    }
    sort(num,num+1000,cmp);
    cout << sum<<endl;
    for(int i=0;i<sum;i++){
        if(i == 0){
            cout<<num[i];
        }else{
            cout<<" "<<num[i];
        }
    }
}