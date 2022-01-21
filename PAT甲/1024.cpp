#include <iostream>
#include <algorithm>
using namespace std;
string add(string a){
    string ans=a;
    reverse(a.begin(),a.end());
    int i=a.length()-1,add=0;
    while(i>=0){
        int tmp=a[i]-'0'+ans[i]-'0';
        ans[i]=(add+tmp)%10+'0';
        add=(tmp+add)/10;
        i--;
    }
    if(add) ans.insert(0,"1");
    return ans;
}
int main(){
    string s;
    int k;
    cin>>s>>k;
    string tmp=s;
    reverse(tmp.begin(),tmp.end());
    if(tmp==s) cout<<tmp<<endl<<0;
    else{
        int i=0;
        while(i<k){
            s=add(tmp);
            i++;
            tmp=s;
            reverse(tmp.begin(),tmp.end());
            if(tmp==s) break;
        }
        cout<<s<<endl<<i;
    } 
    return 0;
}

