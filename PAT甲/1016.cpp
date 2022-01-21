#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

struct node{
	string name;
	int d;
	int h;
	int m;
	string state;
}a[1005];
float monthPay[24];

bool cmp(node &x,node &y){
    if(x.name==y.name){
        if(x.d==y.d){
            if(x.h==y.h){
                return x.m<y.m;
            }else{
                return x.h<y.h;
            }
        }else{
            return x.d<y.d;
        }
    }else{
        return x.name<y.name;
    }
}
int main(){
	int month;
	double sum = 0;
	for(int i=0;i<24;i++){
		scanf("%f",&monthPay[i]);
		monthPay[i] /= 100;
		sum +=monthPay[i] *60;
	}
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
        cin>>a[i].name;
        scanf("%2d:%2d:%2d:%2d",&month,&a[i].d,&a[i].h,&a[i].m);
        cin>>a[i].state;
    }
		  
	
	sort(a,a+n,cmp);
	node last;
	int is_out = 0;
	double totel = 0;
	for(int i=1; i<n; i++){
		if(a[i-1].name == a[i].name ){
			if(a[i-1].state == "on-line"&& a[i].state == "off-line"){
				if(is_out == 0){
					cout<<a[i].name<<" ";
                    printf("%02d\n",month);
                    is_out = 1;
				}
				int t = a[i].d-a[i-1].d;
				
				int t1 = t*60*24;
				int t2 = (a[i].h-a[i-1].h)*60;
				int t3 = a[i].m - a[i-1].m;
				double money = 0;
				money += sum*t;
				if(a[i].h> a[i-1].h){
					for(int j = a[i-1].h;j<a[i].h;j++){
						money += monthPay[j]*60; 
					}
				}else{
					for(int j = a[i-1].h-1;j>=a[i].h;j--){
						money -= monthPay[j]*60; 
					}
				}
				money -= a[i-1].m*monthPay[a[i-1].h];
				money += a[i].m*monthPay[a[i].h];	
				printf("%02d:%02d:%02d %02d:%02d:%02d ",a[i-1].d,a[i-1].h,a[i-1].m,a[i].d,a[i].h,a[i].m);
                printf("%d $%.2lf\n",t1+t2+t3,money);
                totel+=money;	
			}
		}else{
			if(is_out==1){
				printf("Total amount: $%.2lf\n",totel);
                totel=0; 
			}
			is_out = 0; 
		}
	
	}
	if(is_out==1){
		printf("Total amount: $%.2lf\n",totel);
        totel=0; 
	}
}

