#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

struct time{
	int sum,p;
}people[10002];

bool cmp(struct time a, struct time b){
	return a.sum<b.sum;
}
bool cmp1(int a,int b){
	return a<b;
}
int main(){
	int n,k;
	double waitTime = 0;
	int waitNum = 0;
	cin >>n>>k;
	int arr[k]; 
	for(int i=0;i<k;i++){
		arr[i] = 28800;
	}
	for(int i=0;i<n;i++){
		int a,b,c;
		scanf("%02d:%02d:%02d%d",&a, &b, &c, &people[i].p);
		people[i].sum = a*3600+b*60+c;
	}
	sort(people, people+n, cmp);
	for(int i=0; i<n;i++){
		if(people[i].sum/3600 < 8){
			waitNum++;
			waitTime += (arr[0]-people[i].sum);
			arr[0] += people[i].p*60; 
		}else if(people[i].sum/3600<17){
			waitNum++;
			//ÎÞÐèµÈ´ý 
			if(arr[0] < people[i].sum){
				arr[0] = people[i].sum+people[i].p*60;
			} else{
				waitTime += (arr[0] - people[i].sum);
				arr[0] += people[i].p*60;
			}
			
		}
		sort(arr,arr+k,cmp1);
	} 
	printf("%.1lf",waitTime/60/waitNum);
	return 0;
}
