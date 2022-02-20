#include<stdio.h>
#include<iostream>
using namespace std;
//求最大公因数 
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
} 
//最大公约数 
int gcm(int a,int b){
	int c=gcd(a,b);
	return a*b/c; 
}
int main(){
	int a,b,c,e,d,j=0;
	int num[1000];
	scanf("%d/%d%d/%d%d",&a,&b,&c,&d,&e);
	int t=gcm(b,d);
	int t1=gcm(t,e);
	int g=t1/e;
	int first=t1/b*a;
	int last = t1/d*c;
	if (first>last){
		swap(first,last);
	}
	for(int i=first+1;i<last;i++){
		if (i%g==0){
			if(gcd(i/g,e)==1){
				num[j++]=i/g;
			}
		}
	}
	for(int i=0;i<j;i++){
		if(i==0){
			printf("%d/%d",num[i],e);
		}else{
			printf(" %d/%d",num[i],e);
		}
	}
	return 0;
}
