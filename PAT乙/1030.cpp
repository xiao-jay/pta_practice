#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	int n,i,temp;
	long long p;
	scanf("%d %lld",&n,&p);
	long long num[n+1];
	i=0;
	while(i<n){
		scanf("%lld",&num[i]);
		i++;
	}
	int result=0;
	sort(num,num+n,cmp);	
	for(i=0;i<n;i++){
		for(int j=i+result;j<n;j++){
			if(num[i]*p>=num[j]){
				temp=j-i+1;
				if(temp>result){
					result = temp;
				}
			}else{
				break;
			}
		}
	} 
	printf("%d\n",result);
	return 0;
}
