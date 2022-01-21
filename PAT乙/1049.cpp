#include<stdio.h>
#include<string.h>
int main(){
	int n;
	long long sum;
	double a;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf",&a);
		sum+=(long long)(a*1000)*i*(n-i+1);
	} 
	printf("%.2lf\n",sum/1000.0);
	return 0; 
}
