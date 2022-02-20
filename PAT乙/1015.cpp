#include<stdio.h>
#include<iostream>
#include <algorithm>
using namespace std;
struct Info{
	int id;
	int de ;
	int cai ;
	int total ;
};
bool cmp(Info a,Info b){
	if (a.total!=b.total){
		return a.total>b.total;
	}else if (a.de!=b.de){
		return a.de>b.de;
	} else{
		return a.id<b.id;
	}
} 
int main(){
	int num,a,b,c,d,m,n;
	scanf("%d%d%d",&num,&m,&n);
	struct Info info[num];
	struct Info first[num];
	struct Info second[num];
	struct Info third[num];
	struct Info forth[num];
	int i=0;
	a=0;b=0;c=0;d=0;
	while(num--){
		scanf("%d%d%d",&info[i].id,&info[i].de,&info[i].cai);
		info[i].total=info[i].cai+info[i].de;
		if (info[i].cai>=n&&info[i].de>=n){
			first[a++]=info[i];
		}else if(info[i].de>=n&&info[i].cai>=m){
			second[b++]=info[i];
		}else if(info[i].de>=m&&info[i].cai>=m&&info[i].de>=info[i].cai){
			third[c++]=info[i];
		}else if(info[i].de>=m&&info[i].cai>=m){
			forth[d++]=info[i];
		}
		i++;
	}
	//½øÐÐÅÅÐò
	sort(first,first+a,cmp);
	sort(second,second+b,cmp);
	sort(third,third+c,cmp);
	sort(forth,forth+d,cmp);
	printf("%d\n",a+b+c+d);
	i=0;
	while(a--){
		printf("%d %d %d\n",first[i].id,first[i].de,first[i].cai);
		i++;
	}
	i=0;
	while(b--){
		printf("%d %d %d\n",second[i].id,second[i].de,second[i].cai);
		i++;
	}
	i=0;
	while(c--){
		printf("%d %d %d\n",third[i].id,third[i].de,third[i].cai);
		i++;
	}
	i=0;
	while(d--){
		printf("%d %d %d\n",forth[i].id,forth[i].de,forth[i].cai);
		i++;
	}	
	return 0;
}
