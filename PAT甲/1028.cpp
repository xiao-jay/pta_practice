#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

struct Student{
	int id;
	string name;
	int grade;
}stu[100002];

bool cmp(Student a, Student b){
	return a.id<b.id;
}

bool cmp2(Student a, Student b){
	if(a.name == b.name){
		return a.id < b.id;
	}else{
		return a.name < b.name;
	}
}

bool cmp3(Student a, Student b){
	if(a.grade == b.grade){
		return a.id < b.id;
	}else{
		return a.grade < b.grade;
	}
}
int main(){
	int n,c;
	cin >>n>>c;
	for(int i=0;i<n;i++){
		cin>>stu[i].id>>stu[i].name>>stu[i].grade;
	}
	if(c ==1){
		sort(stu,stu+n,cmp);
	}else if(c ==2){
		sort(stu,stu+n,cmp2);
	}else{
		sort(stu,stu+n,cmp3);
	}
	for(int i=0;i<n;i++){
		printf("%06d ",stu[i].id);
		cout << stu[i].name;
		printf(" %d\n",stu[i].grade);
	}
} 
