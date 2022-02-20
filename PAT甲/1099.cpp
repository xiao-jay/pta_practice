#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct node {
    int data, left, right;
}tree[99999];
int ele[99999], N, l, r, ele_i = 0, start = true;
void inorder(int root) {
    if(tree[root].left !=  -1) inorder(tree[root].left);
    tree[root].data = ele[ele_i++];
    if(tree[root].right !=  -1) inorder(tree[root].right);
}
void levelorder(int root) {
    queue<int> que;
    que.push(root);
    while(!que.empty()) {
        node n = tree[que.front()];
        if(start) printf("%d", n.data);
        else printf(" %d", n.data);
        start = false;
        que.pop();
        if(n.left != -1) que.push(n.left);
        if(n.right != -1) que.push(n.right);
    }
}
int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d%d", &tree[i].left, &tree[i].right);
    for(int i = 0; i < N; i++) scanf("%d", &ele[i]);
    sort(ele, ele + N);
    inorder(0);
    levelorder(0);
    return 0;
}
