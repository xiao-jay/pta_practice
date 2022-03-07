#include "iostream"

using namespace std;
int main(){
    int n,a,b,c,d;
    cin >>n;
    while(n--){
        // 思路先用a尽力填c和填b，再a自己补充自己
        int res=0;
        cin >>a>>b>>c>>d;
        int temp = min(a,c);
        res += temp;
        a-=temp;c-=temp;
        temp = min(a/2,b);
        res += temp;
        a-=temp*2;b-=temp;
        res += b/2;b=0;
        res += a/4;

        cout << res+d<<endl;
    }
}