#include<stdio.h>
int main(){
	int k,start = 0,end = 0,max=-99999;
	scanf("%d",&k);
	int num[10002];
	int tmp = 0,res = k-1;
	
	for(int i = 0;i<k; i++){
		scanf("%d",&num[i]);
		res += num[i];
		if(res < 0){
			res = 0;
			tmp = i+1;	
		}else{
			if(res > max){
				max = res;
				end = i;
				start = tmp;
			}
		}
	}
	if(max < 0){
		max = 0;
	}
	printf("%d %d %d",max,num[start],num[end]);
	
}
