#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

struct node{
	char data;
	int next;
}word[100002];


int main(){
	int flags[100002];
	memset(flags, 0 ,sizeof(flags));
	int start1,start2,n;
	int flag = 0;
	cin >>start1>>start2>>n;
	for(int i=0;i<n;i++){
		int address; 
		cin >>address;
		cin>>word[address].data>>word[address].next;
	}
	if(start1 == start2){
		printf("%05d",start1);
		return 0;
	}
	while(start1 != -1){
		flags[start1] = 1;
		start1 = word[start1].next;
	}
	while(start2 != -1){
		if(flags[start2] == 1){
			printf("%05d",start2);
			flag = 1;
			break;
		}
		start2 = word[start2].next;
	}
	if(flag == 0){
		printf("-1");
	}
	return 0;
} 
