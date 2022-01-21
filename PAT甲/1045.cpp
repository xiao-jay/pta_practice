#include<stdio.h>
#include<vector>
#include<iostream>
#include<string.h>
using namespace std;

int main(){
	int n,m,k;
	cin >>n;
	cin>>m;
	vector<int> v1,v2;
	v1.push_back(0);
	v2.push_back(0);
	for(int i=0;i<m;i++){
		int a;
		cin>>a;
		if(a<=n){
			v1.push_back(a);
		}
	}
	cin >>k;
	
	for(int i=0;i<k;i++){
		int a;
		cin>>a;
		if(a<=n){
			v2.push_back(a);
		}
	}
	int arr[v1.size()+1][v2.size()+1];
	memset(arr,0,sizeof(arr));
	for(int i=1;i<=v1.size();i++){
		for(int j=1;j<=v2.size();j++){
			if(i ==  0 ){
				if(v2[j] == v1[i]){
					arr[i][j] = arr[i][j-1] + 1;
				}else{
					arr[i][j] = arr[i][j-1];
				}
			}else{
				if(v2[j] == v1[i]){
					arr[i][j] = max(arr[i-1][j], arr[i][j-1]+1);
				}else{
					arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
				}
				
			}
		}
	}
//	for(int i=1;i<=v1.size();i++){
//		for(int j=1;j<=v2.size();j++){
//			printf("%d ",arr[i][j]);
//		}
//		printf("\n");
//	}
	printf("%d",arr[v1.size()-1][v2.size()-1]);
}
