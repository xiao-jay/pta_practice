#include<stdio.h>
int main(){
	float num[4][4];
	float sum=1;
	int maxj;
	char res[3] = {'W','T','L'};
	for(int i=0;i<3;i++){
		float max=0;
		for(int j=0;j<3;j++){
			scanf("%f",&num[i][j]);
			if(max < num[i][j]){
				max = num[i][j];
				maxj = j;
			}
		}
		sum *=max;
		max = 0;
		printf("%c ",res[maxj]);
	}
	printf("%.2f",(sum*0.65-1)*2);
}
