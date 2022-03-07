#include "iostream"
#include "string.h"
using  namespace std;


int rela[201][201];
int main(){
    int m,n,k;
    int head[201];
    cin >>m>>n;
    memset(rela,0,sizeof(rela));
    for(int i=0;i<n;i++){
        int a,b;
        cin >>a>>b;
        rela[a][b] = rela[b][a] = 1;
    }
    cin >>k;
    int index = 0;
    while(k--){
        index++;
        int p;
        bool flag = false;
        memset(head, 0 ,sizeof (head));
        cin >>p;
        int num[p+1];
        for(int i=0;i<p;i++){
            cin >>num[i];
            head[num[i]] = 1;
        }
        // 开始暴力模拟
        for(int i=0;i<p && !flag;i++){
            for(int j=i+1;j<p;j++){
                if(rela[num[i]][num[j]] != 1){
                    cout << "Area "<< index<<" needs help. "<<endl;
                    flag = true;
                    break;
                }
            }
        }
        if (flag ) continue;
        else{
            // 开始判断是否有额外的数字可以加入
            for(int i=1;i<=m;i++){
                if(head[i] != 1){
                    for (int j=0; j<p;j++){
                        if(rela[num[j]][i] != 1){
                            flag = true;
                            break;
                        }
                    }
                    if(!flag){
                        cout <<"Area "<< index<<" may invite more people, such as "<<i<<"."<<endl;
                        flag = true;
                        break;
                    }else{
                        flag = false;
                    }
                }
            }
            if(!flag){
                cout << "Area "<< index<<" is OK."<<endl;
            }
        }
    }
}