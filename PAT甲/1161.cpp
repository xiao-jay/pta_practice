//pat 1161
#include "iostream"
#include "vector"
using namespace std;

const int maxn = 1e5+10;
int begin1, begin2, n;

struct node{
    int add, data, next;
}a[maxn];
vector<node> L1, L2, res;

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> begin1 >> begin2 >> n;
    for(int i = 1; i <= n; i ++ ){
        int address, data, next;
        cin >> address >> data >> next;
        a[address].add = address;
        a[address].data = data;
        a[address].next = next;
    }

    for(int p = begin1; p != -1; p = a[p].next){
        L1.push_back(a[p]);
    }
    for(int p = begin2; p != -1; p = a[p].next){
        L2.push_back(a[p]);
    }

    int head;	//res的头
    if(L1.size() > L2.size()) head = begin1;
    else{
        head = begin2;
        L2 = L1;	//L2作为短链表 长链表L1根据head在a[]中得到
    }

    int k = 0;	//控制每2个插入一个
    while (head != -1){
        res.push_back(a[head]);
        ++k;
        if (k % 2 == 0 && !L2.empty()){	//每两个中间插一个 
            res.push_back(L2.back());
            L2.pop_back();
        }
        head = a[head].next;
    }

    //输出 
    for (int i = 0; i < res.size() - 1; ++i)
        printf("%05d %d %05d\n", res[i].add, res[i].data, res[i+1].add);
    printf("%05d %d -1", res[res.size()-1].add, res[res.size()-1].data);

    return 0;
}

