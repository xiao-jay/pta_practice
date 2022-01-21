#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
	
	int n,n2;
	scanf("%d",&n);
	long long int num1[n];
	for(int i=0;i<n;i++){
		scanf("%lld",&num1[i]);
	}
	cin >> n2;
	long long int num2[n2];
	for(int i=0;i<n2;i++){
		scanf("%lld",&num2[i]);
	}
	int n3 = n+n2;
	int i=0,j=0,flag =0;
	while(i+j!=(n3%2+n3/2) && i<n && j<n2){
		if(num1[i] < num2[j]){
			i++;
			flag =0;
		}else{
			j++;
			flag =1;
		}
	}
	if(i+j == (n3%2+n3/2)){
		if(flag == 0){
			printf("%d",num1[i-1]);
		}else{
			printf("%d",num2[j-1]);
		}
	}else if(i == n){
		printf("%d",num2[n3/2-i]);
	}else{
		printf("%d",num1[n3/2-j]);
	}
}
