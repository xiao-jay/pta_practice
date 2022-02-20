#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,count,flag=0;
	int arr[100002];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n,cmp);
	for(int i=n;i>=1;i--){
		if(arr[i-1]>i){
			printf("%d\n",i);
            flag=1;
			break;
		}
	}
    if (flag!=1){
        printf("0\n");
    }
    
	return 0;
}
