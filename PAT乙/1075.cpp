#include<stdio.h>
#include<vector>
#include<iostream>
#include<string.h>
using namespace std;
struct list{
	int data;
	int next;
}l[100002];
vector<int> v[3];
int main(){
	
	int first,n,k,a,flag;
	scanf("%d%d%d",&first,&n,&k);
	while(n--){
		scanf("%d",&a);
		scanf("%d%d",&l[a].data,&l[a].next);
	}
	//分3个部分，把每个部分的地址传进去 
	for(int i=first;i!=-1;i=l[i].next){
		if (l[i].data<0){
			v[0].push_back(i);
		}else if (l[i].data>k){
			v[2].push_back(i) ;
		}else{
			v[1].push_back(i);
		}
	}
    flag=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<v[i].size();j++){
			if (flag==0){
				printf("%05d %d ",v[i][j],l[v[i][j]].data);
				flag=1;
			}else{
				printf("%05d\n%05d %d ",v[i][j],v[i][j],l[v[i][j]].data);
			}
		}
	}
	printf("-1\n");
}
