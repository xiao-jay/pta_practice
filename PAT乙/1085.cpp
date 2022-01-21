#include<stdio.h>
#include<string.h>
#include <iostream>
#include<algorithm>
using namespace std; 
struct Input{
	char id[6];
	double score;
	char school[6];
};
struct Output{
	char id[6];
	double score;
	int num;
	int xuhao;
};
//把所有的学校名都改成小写 
void tolower(char *a){
	for(int i=0;i<6;i++){
		if (a[i]>='A'&&a[i]<='Z'){
			a[i]+=32;
		}
	}
}
//计算分数，记得用double最后再相加 
double Calculate_score(char *id,double score){
    if (strlen(id)>0){
    	if (id[0]=='A'){
			return score;
		}else if (id[0]=='B'){
			return score/1.5;
		}else{
			return score*1.5;
		}
	}
}
bool cmp(struct Output a,struct Output b){
	if(int(a.score)!=int(b.score)){
		return a.score>b.score;
	}else if(a.num!=b.num) {
		return a.num<b.num;
	}else{
		return strcmp(a.id,b.id)<0;
		//别用下面的那个，字符串比较无脑用strcp 
		//return a.id<b.id;
	}
}
bool cmp1(struct Input a,struct Input b) {
	return strcmp(a.school,b.school)<0;
}
int main(){
	int n,i,k=0;
	scanf("%d",&n);
	struct Output output[n];
	struct Input input[n];
	for(i=0;i<n;i++){
		output[i].num=0;
		output[i].score=0;
	}
	i=0;
	//输入数据 
	while(i<n){
		scanf("%s%lf%s",input[i].id,&input[i].score,input[i].school);
		tolower(input[i].school);
		i++;
	}
	sort(input,input+n,cmp1);
//为了测试数据而输出 
//	for(i=0;i<n;i++){
//		printf("%s\n",input[i].school);
//	}
	for(i=0;i<n;i++){
		if(i==0){
			strcpy(output[i].id,input[i].school);
		}else{
			if(strcmp(input[i].school,input[i-1].school)!=0){
				k++;
				strcpy(output[k].id,input[i].school);
			}
		}
		output[k].num++;
		output[k].score+=Calculate_score(input[i].id,input[i].score);	
	}
	k++;
	sort(output,output+k,cmp);
	for(i=0;i<k;i++){
		output[i].xuhao=i+1;
	}
	printf("%d\n",k);
	//输出环节 
	for(i=0;i<k;i++){
		if(i!=0){
			if (int(output[i].score)==int(output[i-1].score)){
				output[i].xuhao=output[i-1].xuhao;
				printf("%d ",output[i-1].xuhao);
			}else{
				printf("%d ",output[i].xuhao);
			}
		}else{
			printf("%d ",output[i].xuhao);
		}
		printf("%s %d %d\n",output[i].id,int(output[i].score),output[i].num);
		//cout <<output[i].id<<" "<<int(output[i].score)<<" "<<output[i].num<<endl;
	}
	return 0;
}
