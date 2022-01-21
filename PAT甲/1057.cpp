#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
 
using namespace std;
typedef long long ll;
const int MAXN = 101000;
 
char s[10];
int a[MAXN],num;
int tree[MAXN];
 
void Invalid(){
    printf("Invalid\n");
}
 
void add(int i,int x){
	
    while(i < MAXN){
        tree[i] += x;
        i += i&-i;
    }
}
 
int read(int pos)
{
    int sum = 0;
    while(pos > 0){
        sum += tree[pos];
        pos -= pos & -pos;
    }
    return sum;
}
int _Binary(int pos){
    int L = 0,R = MAXN;
    while(L <= R)
    {
        int mid = (L+R) >> 1;
        int num = read(mid);
        if(num > pos)
            R = mid - 1;
        else if(num <= pos)
            L = mid + 1;
    }
    return L;
}
int main()
{
    int _end = 0;
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i ++)
    {
        scanf("%s",s);
        if(strcmp(s,"Pop") == 0)
        {
            if(_end == 0)
                Invalid();
            else
                printf("%d\n",a[--_end]),add(a[_end],-1);
        }
        else if(strcmp(s,"PeekMedian") == 0)
        {
            if(_end == 0)
                Invalid();
            else{
                printf("%d\n",_Binary((_end+1)/2-1));   //寻找节点前有(_end+1)/2-1 个数字比当前小的点
            }
        }
        else
        {
            scanf("%d",&num);
            a[_end++] = num;
            add(num,1);
        }
    }
}
