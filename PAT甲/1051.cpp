#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;

stack<int> s;
int main(){
	int m,n,k;
	cin >> m>>n>>k;
	int num[n];

	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			cin>>num[j];
		}
		int sequence = 1;
		int xiabiao = 0;
		s.push(0);
		while(s.size()<=m+1&&xiabiao < n){
			//printf("%d\n",s.top());
			if(s.top() != num[xiabiao]){
				s.push(sequence++);
			}else{
				s.pop();
				xiabiao++;
				
			}
		}
		if(xiabiao == n){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
		while(!s.empty()){
			s.pop();
		}
	}
	return 0;
} 
