#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a,int b){
	return a<b;
}
int main(){
	int n,m;
	cin >>n>>m;
	int flag =0;
	int num[100002];
	for(int i=0;i<n;i++){
		cin >>num[i];
	} 
	sort(num,num+n,cmp);

	int l=0,r=n-1;
	while(l<r){
		if(num[l] +num[r] == m){
			flag =1;
			printf("%d %d\n",num[l],num[r]);
			break;
		}else if(num[l] +num[r] < m){
			l++;
		}else{
			r--;
		}
	}
	if(flag == 0) printf("No Solution");
} 
