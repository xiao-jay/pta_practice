#include<stdio.h>
struct list{
	int add;
	int data;
	int next;
}l[100002],l1[100002],l2[100002];
int main(){
	int first,n,k,a,flag,num;
	scanf("%d%d%d",&first,&n,&k);
	int m=0;
	while(m<n){
		scanf("%d",&a);
		scanf("%d%d",&l[a].data,&l[a].next);
		l[a].add=a;
		m++;
	}
	int linshi=first;
	m=0;
	//ʹ������ 
	while(l[linshi].next!=-1){
		l1[m]=l[linshi];
		m++;
		linshi=l[linshi].next;
		num++;
	}
	l1[m] = l[linshi];
	//Ϊ�����һ�����Ե㣬��Ϊ���һ�����Ե��ǲ����������� 
	n=num+1;
	//��������ݸ�l2 
	for(int i=0;i<n/k;i++){
		for(int j=i*k;j<i*k+k;j++){
			int y=i*k+k-(j-i*k)-1;
			l2[y]=l1[j];
		}  
	} 
	//��� 
	for(int i=0;i<n-(n%k);i++){
		if (i==0){
			printf("%05d %d ",l2[i].add,l2[i].data);
		}else{
			printf("%05d\n%05d %d ",l2[i].add,l2[i].add,l2[i].data);
		}
	}
	for(int i=n-(n%k);i<n;i++){
		printf("%05d\n%05d %d ",l1[i].add,l1[i].add,l1[i].data);
	}
	
	printf("-1\n");
    return 0;
}

