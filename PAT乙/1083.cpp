#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int main(){
	int n,a,b,i;
	int arr[10001];
	scanf("%d",&n);
	memset(arr,0,sizeof(arr));
	while(n--){
		i++;
		scanf("%d",&a);
		if (a>i){
			arr[a-i]++;
		}else{
			arr[i-a]++;
		}
	}
	for( i=10000;i>=0;i--){
		if (arr[i]!=0&&arr[i]!=1){
			printf("%d %d\n",i,arr[i]);
		}
	}	
}
