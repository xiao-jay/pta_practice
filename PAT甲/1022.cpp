#include<stdio.h>
#include<iostream>
#include<map>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
map<string,set<int> > title, author, key, pub, year;

void query(map<string,set<int> >&mp, string &str){//取消引用最后一个测试用例会超时
    if(mp.find(str) != mp.end()){
        for(set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++){ //注意迭代器的格式，不是map //也可用 auto c++11特性PAT支持
            printf("%07d\n",*it);//*不确定宽度，错两个样例
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
        getchar();//* 或者直接scanf("%d\n",&id);
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
