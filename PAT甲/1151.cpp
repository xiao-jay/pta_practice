#include "iostream"
#include "map"
#include "string.h"
using namespace std;

int m,n;

struct Node{
    int num;
    Node * left,*right, *father;
};
map<int,Node *> map_;
int find(int inorder[], int num){
    for(int i=0;i< n; i++){
        if(num == inorder[i]){
            return i;
        }
    }
}

Node * build(int inorder[], int preorder[],int size){
    if(size <= 0 || size >n){
        return nullptr;
    }
    Node * root = (Node *) malloc(sizeof(Node));
    int index = find(inorder, preorder[0]);
    root->num = preorder[0];
    root->left = build(inorder, preorder+1, index);
    if (root->left != nullptr){
        root->left->father = root;
    }
    root->right = build(inorder+index+1, preorder+index+1, size-index-1);
    if(root->right != nullptr){
        root->right->father = root;
    }
    map_[root->num] = root;
    return root;
}

int main(){
    int vis[20000];
    cin >>m>>n;
    int preorder[10002], inorder[10002];
    for(int i=0;i<n;i++){
        cin >> inorder[i];
    }
    for(int i=0;i<n;i++){
        cin >>preorder[i];
    }
    Node * root = build(inorder, preorder, n);
    for (int i=0; i<m;i++){
        int a,b;
        cin >>a>>b;
        memset(vis, 0 ,sizeof (vis));
        // 看看数字存不存在
        if( map_[a] == nullptr || map_[b] == nullptr){
            if(map_[a] == nullptr && map_[b] == nullptr){
                cout <<"ERROR: "<< a<<" and "<<b<<" are not found."<<endl;
            }else if(map_[a] == nullptr){
                cout << "ERROR: "<<a<<" is not found."<<endl;
            }else{
                cout << "ERROR: "<<b<<" is not found."<<endl;
            }
            continue;
        }
        Node * temp = map_[a];
        while(temp != nullptr){
            vis[temp->num] = 1;
            temp = temp->father;
        }
        if (vis[b] == 1){
            cout << b<<" is an ancestor of "<<a<<"."<<endl;
            continue;
        }
        temp  = map_[b];
        while(vis[temp->num] != 1 ){
            temp = temp->father;
        }
        if(temp->num == a){
            cout << a<<" is an ancestor of "<<b<<"."<<endl;
            continue;
        }
        cout << "LCA of "<<a<<" and "<<b<<" is "<<temp->num<<"."<<endl;
    }
}