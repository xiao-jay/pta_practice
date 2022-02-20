#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
int m,n,k;
struct Stu{
    int no;
    float score;
    int ge;

    int pre_sch[6];
};

bool cmp(struct Stu a, struct Stu b){
    if(a.score == b.score){
        return a.ge > b.ge;
    }
    return a.score > b.score;
}
int main(){

    cin >>m>>n>>k;
    int a,b;
    struct Stu stu[m+1];
    int sch[n];
    vector<vector<int>> sch_grad;
    // 输入学校的容量
    for (int i=0;i<n;i++){
        cin >>sch[i];
        vector<int> c;
        sch_grad.push_back(c);
    }
    for (int i=0;i<m; i++){
        cin >>a>>b;
        stu[i].ge = a;
        stu[i].score = float (a+b)/2;
        for(int j=0; j<k; j++){
            cin >>stu[i].pre_sch[j];
        }
        stu[i].no = i;
    }
    sort(stu, stu+m, cmp);
    for(int i=0; i<m; i++){
        for(int j=0;j<k;j++){
            //找到一个符合的学校
            if(sch[stu[i].pre_sch[j]] >0){
                // 把合适的节点加入
                sch_grad[stu[i].pre_sch[j]].push_back(stu[i].no);
                sch[stu[i].pre_sch[j]]--;
                if(i<m-1 &&stu[i].score == stu[i+1].score && stu[i].ge == stu[i+1].ge){
                    bool flag = true;
                    for(int p=0;p<k;p++){
                        if(stu[i].pre_sch[p] != stu[i+1].pre_sch[p] ){
                            flag = false;
                            break;
                        }
                    }
                    // 和后一个成绩和意愿都一样
                    if (flag){
                        if(sch[stu[i].pre_sch[j]] == 0){
                            sch[stu[i].pre_sch[j]]++;
                        }
                    }
                }
                break;
            }
        }
    }
    for (int i=0; i<n;i++){
        sort(sch_grad[i].begin(),sch_grad[i].end() );
        for(int j=0;j<sch_grad[i].size(); j++){
            if(j == 0){
                cout << sch_grad[i][j];
            }else{
                cout <<" " <<sch_grad[i][j];
            }
        }
        cout<<endl;
    }
}