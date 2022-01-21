#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

bool check(int num[],int n){
	for(int i=0;i<n/2;i++){
		if(num[i] != num[n-i-1]){
			return false;
		} 
	}
	return true;
}
int main(){
	int n,i=0;
	int radix;
	int num[10002];
	cin >>n>>radix;
	
	memset(num, 0, sizeof(num));
	while(n!=0){
		num[i++] = n % radix;
		n /= radix;
	}
	if (check(num,i)){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	for(int j = i-1;j >= 0;j--){
		if(j == 0){
			printf("%d",num[j]);
		}else{
			printf("%d ",num[j]);
		}
	}
} 
