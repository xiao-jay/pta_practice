#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int j=0;
int arr[10002];
int res[10002];
bool cmp(int a,int b){
	return a<b;
}

void inorder(int i){
	if(i <n){
		inorder(i*2+1);
	}else{
		return ;
	}
	res[i] = arr[j++];
	if( i<n){
		inorder(i*2+2);
	} else
		return ;
	
}
int main(){	
	cin >>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n,cmp);
	inorder(0);
	for(int i=0;i<n;i++){
		if(i == n-1){
			cout <<res[i];
		}else
			cout <<res[i]<<" ";
	} 
} 
