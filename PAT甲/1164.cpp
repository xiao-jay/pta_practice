#include "iostream"

using namespace std;

struct Node {
    char s[7][5];
};
int main(){
    Node node[26];
    for(int i=0;i<26;i++){
        for(int j=0;j<7;j++){
            for(int k=0;k<5;k++){
                cin>>node[i].s[j][k];
            }
        }
    }
    int i=0;
    string s1,s2;
    getchar();
    getline(cin,s1);
    bool flag = false; // 是否是第一次输出
    // 去掉开头的非字母符号
    while(i <s1.length()){
        if ((s1[i] < 'A' || s1[i] >'Z' ) && !s2.empty()){
            if (flag){
                cout <<endl;
            }else flag = true;
            for(int j=0;j<7;j++){
                for(int k=0;k<s2.length();k++){
                    for(int p=0;p<5;p++){
                        cout <<node[s2[k]-'A'].s[j][p];
                        if(k == s2.length()-1 && p == 4){
                            cout <<endl;
                        }else if(p == 4) cout <<" ";
                    }
                };
            }
            s2 = "";
        }else s2 += s1[i];
        i++;
    }
    if(!s2.empty()){
        if (flag)
            cout <<endl;
        for(int j=0;j<7;j++){
            for(int k=0;k<s2.length();k++){
                for(int p=0;p<5;p++){
                    cout <<node[s2[k]-'A'].s[j][p];
                    if(k == s2.length()-1 && p == 4){
                        cout <<endl;
                    }else if(p == 4) cout <<" ";
                }
            };
        }
    }
}