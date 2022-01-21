#include<stdio.h>
#include<string.h>
int main(){
	int k,a,account=0;
	float b;
	float num[1001];
	memset(num,0,sizeof(num));
	for(int i=0;i<=1;i++){
		scanf("%d",&k);
		for(int j=0; j<k; j++){
			scanf("%d%f",&a,&b);
			num[a]+=b;
		}
	}
	for(int i=0;i<=1000;i++){
		if(num[i]!=0){
			account++;
		}
	}
	printf("%d",account);
	for(int i=1000;i>=0;i--){
		if(num[i]!=0){
			printf(" %d %.1f",i,num[i]);
		}
	}
	return 0;
} 
