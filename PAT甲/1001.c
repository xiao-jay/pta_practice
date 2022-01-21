#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int main(){
    int a,b;
    int flag = 0;
    scanf("%d%d",&a,&b);
    int c = a+b;
    char  s[100];
   	
	if(c <0){
		c = -c;
		printf("-");
	}
	sprintf(s,"%d",c);
   	for(int i=0; i<strlen(s); i++){
   		printf("%c", s[i]);
   		if(i!=strlen(s)-1 && (i+1)%3==strlen(s)%3){
   			printf(",");	
		} 
	}
    return 0;
}
