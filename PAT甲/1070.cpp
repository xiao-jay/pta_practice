#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	float weight;
	float price;
	float avg;
}mooncake[100002];
bool cmp(node a,node b){
	return a.avg>b.avg;
}
int main(){
	float m;
	int n;
	cin >>n>>m;
	float sum;
	for(int i=0;i<n;i++){
		cin >>mooncake[i].weight;
	}
	for(int i=0;i<n;i++){
		cin>>mooncake[i].price;
		mooncake[i].avg = mooncake[i].price/mooncake[i].weight;
	}
	sort(mooncake,mooncake+n,cmp);
	int i=0;
	while(m && i<n){
		if(m-mooncake[i].weight >0){
			sum+=mooncake[i].price;
			m -= mooncake[i].weight;
		}else{
			sum +=  (m/mooncake[i].weight) * mooncake[i].price;
			m =0 ;
		}
		i++;
	}
	printf("%.2f",sum);
} 
