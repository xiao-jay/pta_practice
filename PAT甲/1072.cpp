#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define inf 99999
#define maxn 1011
int m,n,k,maxd;
int graph[maxn][maxn];
int mark[maxn],dis[maxn];
 struct node{
	int id;
	float sum;
	int min;
};

bool cmp(int a,int b){
	return a<b;
}

bool cmp1(node a,node b){
	if(a.min == b.min){
		if(a.sum == b.sum){
			return a.id < b.id;
		}
		return a.sum < b.sum;
	}
	return a.min > b.sum;
}

vector<node> vec;
void dijstra(int start){
	dis[start] = 0;
	for(int i=1; i<=n+m;i++){
		int min = inf;
		int pos = -1;
		for(int j=1;j<=n+m;j++){
			if(mark[j] ==0 && min> dis[j]){
				min = dis[j];
				pos = j;
			}
		}
		if(pos == -1) return ;
		mark[pos] = 1;
		for(int j=1;j<=m+n;j++){
			if(mark[j] == 0){
				if(graph[pos][j] +dis[pos] < dis[j]){
					dis[j] = graph[pos][j] +dis[pos];
				}
			}
		} 
	}
}
void print(int i,int n){
	cout <<"G"<<vec[i].id-n<<endl;
		printf("%d.0 %.1f",vec[i].min,vec[i].sum/n);
} 
int get_one(){
    int u=0;
    string p;
    cin>>p;//输入不能用char，可能会出现G11，199这样的数字
    if(p[0]=='G'){
        for(int j=1;j<p.length();j++){
            u=u*10+p[j]-'0';
        }
        u+=n;
    }else{
        for(int j=0;j<p.length();j++){
            u=u*10+p[j]-'0';
        }
    }
    return u;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&maxd);
	
	for(int i=1;i<maxn;i++){
		for(int j=1; j<maxn; j++){
			graph[i][j] = inf;
		}
	}
		
			
	for(int i=1; i<=k; i++){
		char a[5], b[5];
		int d,e,f;
		e = get_one();
		f = get_one();
		cin >>d;
		graph[e][f] = d;
		graph[f][e] = d;
	}	
	for(int i=n+1;i<=m+n;i++){
		for(int j=1;j<=m+n;j++){
			mark[j] = 0;
			dis[j] = inf;
		}
		dijstra(i);
		
		sort(dis+1,dis+n+1,cmp);
		if(dis[n] > maxd){
		}else{
			node info;
			info.id = i;
			info.min = dis[1];
			float sum = 0;
			for(int k=1;k<=n;k++){
				sum +=dis[k];
			}
			info.sum = sum;
			vec.push_back(info);
		}
	}
	// 如果一个也没有 
	if(vec.size()==0){
		cout << "No Solution"<<endl;
	}else{
		sort(vec.begin(),vec.end(),cmp1);
		print(0,n);
	}
	
	
}
