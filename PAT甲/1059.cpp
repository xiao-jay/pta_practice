#include<stdio.h>
#include<math.h>
#include<iostream>
#include<vector>
using namespace std;

bool isprime(int x)
{
    for( int i = 2; i * i <= x; ++i )
        if( x % i == 0 )
            return false;
    return true;
}

int main(){
	long long int num,tmp;
	
	vector<int> prime;
	scanf("%lld",&num);
	tmp = num;
    if(num == 1){
        printf("1=1");
        return 0;
    }
	while(num != 1){
		for(int i=2;i<=num;i++){
			if(isprime(i) && num % i == 0){
				prime.push_back(i);
				num /= i;
				break;
			}
		}
	}
	printf("%lld=",tmp);
	int count = 1;
	for(int i=0;i<prime.size();i++){
		if(i == 0){
			printf("%d",prime[0]);
		}else{
			if(prime[i] == prime[i-1]){
				count++;
			}else{
				if(count == 1){
					printf("*%d",prime[i]);
				}else{
					printf("^%d*%d",count,prime[i]);
					count = 1;
				}
				
			}
		}
	}
	if(count != 1){
		printf("^%d",count);
	}
	return 0;
} 
