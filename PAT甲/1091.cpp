#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
int maze[60][1286][128];
int vis[60][1286][128];
int n,m,l,t;
int nxt[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
struct node
{
    int x,y,z;
};
int cnt = 0;
int total = 0;
void BFS(int i,int j,int k)
{
    int cnt = 0;
    queue<node>qu;
    node s = {i,j,k};
    qu.push(s);
    vis[i][j][k] = true;
    while(!qu.empty())
    {
        node tmp = qu.front();
        qu.pop();
        node endd;
        cnt++;
        for(int i = 0 ; i < 6; i++)
        {
            endd.x = tmp.x + nxt[i][0];
            endd.y = tmp.y + nxt[i][1];
            endd.z = tmp.z + nxt[i][2];
            if(endd.x >=0 && endd.x < l && endd.y >= 0 && endd.y < n && endd.z >= 0 && endd.z < m
               && vis[endd.x][endd.y][endd.z] == false  && maze[endd.x][endd.y][endd.z] == 1)
            {
                vis[endd.x][endd.y][endd.z] = true;
                qu.push(endd);
            }
        }
    }
    if(cnt >= t)
        total += cnt;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&l,&t);
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < m; k++)
                scanf("%d",&maze[i][j][k]);
        }
    }//表示输入

    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < m; k++)
            {
                node s = {i,j,k};
                if(maze[i][j][k] == 1 && !vis[i][j][k])//首先这个东西是1? 其次还没有走过它
                    BFS(i,j,k);
            }
        }
    }
    printf("%d\n",total);
    return 0;
}