#include<iostream>
using namespace std;

int main(){
    string s1,s2;
    cin >>s1>>s2;
    int t=0,a=0;
    for(int i=0;i<s1.size();i++){
        if(s1[i] == 'T' && s2[i] == 'A'){
            t++;
        }
        if(s1[i] == 'A' && s2[i] == 'T'){
            a++;
        }
    }
    cout << min(t,a)+abs(t-a)<<endl;
}