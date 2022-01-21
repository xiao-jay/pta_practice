#include<stdio.h>
#include<string>
#include<string.h>
int main(){
	int n,max=-999,min=9999,flag=0,num=0;
	arr[10002],arr2[10002],arr3[100002],arr4[102000];
	memset(arr2,0,sizeof(arr2));
	memset(arr3,0,sizeof(arr3));
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&arr[i]);
		if(max<arr[i]){
			max = arr[i];
			arr2[arr[i]]=1;
		}
	}
	for(int i=n-1;i>=0;i--){
		if(min>arr[i]){
			min=arr[i];
			arr3[arr[i]]=1;
		}
	}
	for(int i=0;i<=max;i++){
		if(arr2[i]==1&&arr3[i]==1){
			arr4[num++]=i;
		}
	}
	printf("%d\n",num);
	for(int i=0;i<num;i++){
		if(i==0){
			printf("%lld",arr4[i]);
		}else{
			printf(" %lld",arr4[i]);
		}
	}
	return 0;
}
