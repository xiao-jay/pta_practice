#include "iostream"
#include "vector"
#include "queue"
using namespace std;

struct Node {
    Node * left,*right;
    int num;
};


Node *buildNode(int a){
    Node* node = (Node *)malloc(sizeof(Node));
    node->num = a;
    node->right = nullptr;
    node->left = nullptr;
    return node;
};
Node *build(Node * root, int a){
    if(root == nullptr){
        return buildNode(a);
    }
    if(a > root->num) root->right = build(root->right, a);
    else  root->left = build(root->left, a);
    return root;
}
int main(){
    int n = 0;
    cin >> n ;
    Node * root = nullptr;
    while(n--){
        int a;
        cin >>a;
        root = build(root, a);
    }
    vector<int> level;
    queue<Node *> que1,que2;
    que1.push(root);
    while(!que1.empty()  ){
        int levels = 0;
        while(!que1.empty()){
            Node* node = que1.front();
            levels++;
            que1.pop();
            if(node->left != nullptr){
                que2.push(node->left);
            }
            if(node->right != nullptr){
                que2.push(node->right);
            }
        }
        level.push_back(levels);
        que1 = que2;
        while(!que2.empty()) que2.pop();
    }
    cout<< level[level.size()-1]<<" + "<<level[level.size()-2]<<" = "<<level[level.size()-1]+level[level.size()-2]<<endl;
}