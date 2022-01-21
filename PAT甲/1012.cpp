#include<iostream>
#include <algorithm>
#include<map>
using namespace std;

struct st{
	string id;
	int c,m,e,a;
	int cc,mm,ee,aa;
}s[2002];
int w = 1;
//bool cmp(st s1,st s2){
//	if(w ==1){
//		if(s1.c > s2.c) return false;
//	}else if (w ==2){
//		if(s1.m > s2.m) return false;
//	}else if(w ==3){
//		if(s1.e > s2.e) return false;
//	}else{
//		if(s1.a > s2.a) return false;
//	}
//}
bool cmp(st a,st b)
{
    if(w==1)return a.c>b.c;
    else if(w==2)return a.m>b.m;
    else if(w==3)return a.e>b.e;
    else return a.a>b.a;
}
void print(st a)
{
    char ch='A';
    int b=a.aa;
    if(b>a.cc)b=a.cc,ch='C';
    if(b>a.mm)b=a.mm,ch='M';
    if(b>a.ee)b=a.ee,ch='E';
    cout<<b<<" "<<ch<<endl;
}

int main(){
	map<string,int> p;
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>s[i].id>>s[i].c>>s[i].m>>s[i].e;
		s[i].a = (s[i].c+s[i].e+s[i].m);
	}
	
	sort(s,s+m,cmp);
	for(int i=0;i<m;i++){
		if(i>0 && s[i].c == s[i-1].c){
			s[i].cc = s[i-1].cc;
		}else{
			s[i].cc = i+1;
		}
	}
	
	w = 2; 
	sort(s,s+m,cmp);
	for(int i=0;i<m;i++){
		if(i>0 && s[i].m == s[i-1].m){
			s[i].mm = s[i-1].mm;
		}else{
			s[i].mm = i+1;
		}
	}
	
	w = 3;
	sort(s,s+m,cmp);
	for(int i=0;i<m;i++){
		if(i>0 && s[i].e == s[i-1].e){
			s[i].ee = s[i-1].ee;
		}else{
			s[i].ee = i+1;
		}
	}
	w = 4;
	sort(s,s+m,cmp);
	for(int i=0;i<m;i++){
		if(i>0 && s[i].a == s[i-1].a){
			s[i].aa = s[i-1].aa;
		}else{
			s[i].aa = i+1;
		}
		p[s[i].id] = i+1;
	}
	for(int i=0; i<n;i++){
		string num;
		cin>>num;
		if(p[num]) print(s[p[num]-1]);
		else cout<<"N/A"<<endl;
	}
	return 0;
}
