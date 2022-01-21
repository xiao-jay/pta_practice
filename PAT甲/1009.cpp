#include<stdio.h>
#include<string.h>
int main(){
	int count = 0;
	//读取第一行 
	int n1;
	scanf("%d",&n1);
	int poly1[n1];
	float num1[n1];
	for(int i=0;i<n1;i++){
		scanf("%d%f",&poly1[i], &num1[i]);
	}
	//读取第二行 
	int n2;
	scanf("%d",&n2);
	int poly2[n2];
	float num2[n2];
	for(int i=0;i<n2;i++){
		scanf("%d%f",&poly2[i], &num2[i]);
	}
	
	float num3[2002];
	memset(num3, 0, sizeof(num3));
	for(int i=0;i<n1; i++){
		for(int j = 0; j< n2; j++){
			num3[poly1[i]+poly2[j]] += num1[i]*num2[j];
		}
	} 
	for(int i=2000;i>=0; i--){
		if(num3[i]!= 0){
			count++;
		}
	}
	printf("%d",count);
	for(int i=2000;i>=0; i--){
		if(num3[i]!= 0){
			printf(" %d %.1f",i,num3[i]);
		}
	}
}
