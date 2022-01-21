#include<stdio.h>
int main(){
	int n,a,b,c;
	scanf("%d",&n);
	char name[n][15];
	int start[n];
	int end[n];
	int firstStart = 3600*24,firstStarti=0;
	int lastEnd = 0,lastEndi = 0;
	for(int i=0; i<n; i++){
		scanf("%s",name[i]);
		scanf("%d:%d:%d",&a,&b,&c);
		start[i] = a*3600+b*60+c;
		if(firstStart>start[i]){
			firstStarti = i;
			firstStart = start[i];
		}
		scanf("%d:%d:%d",&a,&b,&c);
		end[i] = a*3600+b*60+c;
		if(lastEnd < end[i]){
			lastEndi = i;
			lastEnd = end[i];
		}
	}
	printf("%s %s",name[firstStarti], name[lastEndi]);
}
