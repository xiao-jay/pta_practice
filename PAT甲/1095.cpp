#include "iostream"
#include "vector"
#include "algorithm"
#include "map"
#include "string.h"
using namespace  std;


struct Node{
    string name;
    int time;
    int flag ;
};


bool cmp1(struct Node a,struct Node b){
    if(a.name.compare(b.name) == 0){
        return a.time <b.time;
    } else{
        return a.name.compare(b.name)< 0;
    }
};

bool cmp2(struct Node a,struct Node b){
    return a.time<b.time;
}
int main(){
    int m,n;
    int a,b,c;

    cin >>m>>n;
    vector<Node> car,record(m);
    for(int i=0; i<m; i++){

        char temp[5];
        cin >>record[i].name;
        scanf("%d:%d:%d %s\n",&a,&b,&c,&temp);

        record[i].flag = strcmp(temp, "in") == 0 ? 1 : -1;

        record[i].time = a*3600+b*60+c;

    }
    sort(record.begin(),record.end(),cmp1);
    map<string,int> mapp;
    int maxTime = 0;
    for (int i=0;i<m-1;i++){
        if(record[i].name.compare(record[i+1].name)==0 && record[i].flag == 1 && record[i+1].flag == -1){
            car.push_back(record[i]);
            car.push_back(record[i+1]);
            mapp[record[i].name] += (record[i+1].time-record[i].time);
            if(maxTime < record[i+1].time-record[i].time){
                maxTime = record[i+1].time-record[i].time;
            }
        }
    }
    //根据时间排序
    sort(car.begin(), car.end(),cmp2);
    vector<int> cnt(car.size());
    for (int i=0;i<car.size();i++){
        if(i == 0){
            cnt[i] += car[i].flag;
        }else{
            cnt[i] = cnt[i-1]+car[i].flag;
        };
    }
    // 下面输入查询内容
    int tempindex = 0;
    for(int i=0;i<n;i++){
        scanf("%d:%d:%d",&a,&b,&c);
        int time = a*3600+b*60+c;
        int j=0;
        for(j = tempindex; j < car.size(); j++) {
            if(car[j].time>time){
                cout<<cnt[j-1]<<endl;
                break;
            }else if(j==car.size()-1)//最后一辆车还是小于给定时间是无法输出的
                cout<<cnt[j]<<endl;

        }
        tempindex = j;
    }
    for(map<string, int>::iterator it = mapp.begin(); it != mapp.end(); it++) {
        if(it->second == maxTime)
            printf("%s ", it->first.c_str());
    }
    printf("%02d:%02d:%02d\n",maxTime/3600,(maxTime %3600)/60,maxTime %60);
    return 0;
}