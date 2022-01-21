#include<stdio.h>
#include<iostream>
using namespace std;
long long int getNum(string str, long long int radix){
	long long int sum = 0;
	for(int i =0;i < str.length(); i++){
		if(str[i] <= '9') sum = sum*radix +str[i] - '0';
		else if (str[i] <= 'z') sum = sum*radix+(str[i]-'a'+10);
		
	}
	return sum;
}
long long int getRadix(long long int num1, string str,long long int start,long long int end){
	
}
int main(){
	string str1, str2;
	int tag;
	long long int radix;
	cin >>str1>>str2>>tag>>radix;
	long long int num1;
	if(tag ==1){
		num1 = getNum(str1,radix);
	}else{
		num1 = getNum(str2,radix);
	}
	
}
