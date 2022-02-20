//
// Created by 杰杰 on 2022/1/21.
//

#include "iostream"
#include <cmath>
#include<cstring>
using namespace std;

bool prime(int a ){
    if (a == 1){
        return false;
    }
    for(int i=2;i<= sqrt(a);i++){
        if(a % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int m,n;
    cin>>m>>n;
    while(!prime(m)) m++;
    int num[m];
    memset(num,0,sizeof(num));
    for(int i=0;i<n;i++){
        int a;
        cin >>a;
        if(i == 0){
            cout << a%m;
            num[a % m] = 1;
            continue;
        }
        if(num[a % m] == 0){
            num[a % m] = 1;
            cout <<" "<< a%m;
        }else{
            for(int j = 1;j<=m+1;j++){
                int k = (j*j+a) % m;
                if(num[k] == 0){
                    num[k] = 1;
                    cout <<" "<< k;
                    break;
                }else if (j == m+1){
                    cout << " " << "-";
                    break;
                }
            }

        }
    }
}