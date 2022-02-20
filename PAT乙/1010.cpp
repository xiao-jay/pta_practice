#include<stdio.h>

int main() {
    int a,b; 
        scanf("%d%d",&a,&b);
        if (b==0){
            printf("0 0");
            return 0;
        }else{
            printf("%d %d",a*b,b-1);
        }
        while(scanf("%d%d",&a,&b)!=EOF){
            if (b==0){
                break;
            }else{
                printf(" %d %d",a*b,b-1);
            }
        }
        return 0;
}
