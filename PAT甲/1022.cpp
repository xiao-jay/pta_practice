#include<stdio.h>
#include<iostream>
#include<map>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
map<string,set<int> > title, author, key, pub, year;

void query(map<string,set<int> >&mp, string &str){//ȡ���������һ�����������ᳬʱ
    if(mp.find(str) != mp.end()){
        for(set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++){ //ע��������ĸ�ʽ������map //Ҳ���� auto c++11����PAT֧��
            printf("%07d\n",*it);//*��ȷ����ȣ�����������
        }
    }
    else printf("Not Found\n");
}

int main(){
	int n,id;
	scanf("%d",&n);
	string _title,_author,_key,_pub,_year;
    for(int i = 0; i < n; i++){
        scanf("%d",&id);
        getchar();//* ����ֱ��scanf("%d\n",&id);
        getline(cin,_title); title[_title].insert(id);
        getline(cin,_author); author[_author].insert(id);
        while(cin >> _key){ //*
           key[_key].insert(id);
           if(getchar()=='\n') break;
        }
        getline(cin,_pub); pub[_pub].insert(id);
        getline(cin, _year); year[_year].insert(id);
    }
	scanf("%d",&n);
	int num;
	while(n--){
		scanf("%d: ",&num);
		string str;
		getline(cin,str);
		cout << num << ": " << str << "\n";
		if(num ==1) query(title,str);
		else if (num == 2) query(author,str);
		else if (num == 3) query(key,str);
		else if (num == 4) query(pub,str);
		else if (num == 5) query(year,str);
	}
}
