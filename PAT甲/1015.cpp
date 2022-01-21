#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

bool prime(int num){
    if (num ==2){
        return true;
    }
    if (num == 1){
        return false;
    }
	for(int i=2;i<=sqrt(num);i++){
		if(num % i ==0){
			return false;
		}
	}
	return true;
}


int main(){
	int num,radix;
	while(scanf("%d",&num)!=NULL){
		if(num <0) break;
		cin>>radix;
		if(prime(num) == 0){
			printf("No\n");
		}else{
		int m=1,eve[105],cnt=0;
		while(num){
			eve[cnt++]=num%radix;
			num/=radix;
		}
		for(int i=cnt-1;i>=0;i--){
			num+=m*eve[i];
			m*=radix;
		}
			if(prime(num)==1){
				printf("Yes\n");
			}else{
				printf("No\n");
			}
		}
	}	
}

