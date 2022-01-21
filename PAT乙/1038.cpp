#include<stdio.h>
#include<string.h>
int main(){
	int n,a;
	int sco[101],flag=0;
	memset(sco,0,sizeof(sco));
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		sco[a]++;
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		if (flag==0){
			printf("%d",sco[a]);
			flag=1;
		}else{
			printf(" %d",sco[a]);
		}
		
	}
	printf("\n");
	return 0;
}
