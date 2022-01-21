#include<iostream>
#include<algorithm>
using namespace std;

struct student{
	string name;
	string sex;
	string id;
	int grade;
}stu[10002];

int cmp(student a, student b){
	if(a.sex == b.sex){
		if(a.sex == "F"){
			return a.grade > b.grade;
		}else{
			return a.grade < b.grade;
		}
	}else{
		return a.sex < b.sex;
	}
}
int main(){
	int n;
	cin >>n;
	int m_num,f_num = 0;
	for(int i=0; i<n;i++){
		cin>>stu[i].name>>stu[i].sex>>stu[i].id>>stu[i].grade;
		if(stu[i].sex == "M"){
			m_num++;
		}else{
			f_num ++;
		}
	}
	sort(stu,stu+n,cmp);
	if(f_num ==0){
		cout <<"Absent" <<endl;
		cout <<stu[0].name <<" "<<stu[0].id<<endl;
		cout <<"NA" <<endl;
	}else if(f_num == n){
		cout <<stu[0].name <<" "<<stu[0].id<<endl;
		cout <<"Absent" <<endl;
		cout <<"NA" <<endl;
	}else{
			cout <<stu[0].name <<" "<<stu[0].id<<endl;
			cout <<stu[f_num].name <<" "<<stu[f_num].id<<endl;
			cout << stu[0].grade-stu[f_num].grade<<endl;
	}

	
}
