#include<stdio.h>
#include<string.h>
int main(){
	char a;
	int count=1,k=0;
	scanf("%s\n",&a);
	char b[100002];
	char c[100002];
	gets(b);

	getchar();
	if (a=='C'){
			for(int i=0;i<strlen(b);i++){
				if(b[i]==b[i+1]){
					count++;
				}else{
					if (count==1){
						printf("%c",b[i]);
					}else{
						printf("%d%c",count,b[i]);
						count=1;
					}
				}
			}
		printf("\n");
	}else if (a=='D'){
		count=0;
		while(k<strlen(b)){
			if(b[k]>='0'&&b[k]<='9'){
				while(b[k]>='0'&&b[k]<='9'){
					count=count*10+(b[k]-'0');
					k++;
				}
				for(int j=0;j<count;j++){
					printf("%c",b[k]);
				}
				count=0;
				k=k+1;
			}else{
				printf("%c",b[k]);
				k++;
			}
		}
		printf("\n");
	}	
	return 0;
} 
