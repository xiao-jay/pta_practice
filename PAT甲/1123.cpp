#include "iostream"
#include "vector"
#include "queue"
using namespace std;
int n;

struct Node {
    Node *left, *right;
    int num;
};

int getHeight(Node *tree) {
    if (tree == nullptr) return 0;
    int l = getHeight(tree->left);
    int r = getHeight(tree->right);
    return max(l, r) + 1;
}

bool isBalanced(Node *left, Node *right) {
    return abs(getHeight(left) - getHeight(right)) < 2;

}

Node * LeftLeft(Node* t){
    Node * x = t->right;
    Node * y = x->left;
    x->left = t;
    t->right = y;
    return x;
}

Node * RightRight(Node* t){
    Node * x = t->left;
    Node * y = x->right;
    x->right = t;
    t->left = y;
    return x;
}


Node * LeftRight(Node *t){
    t->left = LeftLeft(t->left);
    return RightRight(t);
}

Node * RightLeft(Node *t){
    t->right = RightRight(t->right);
    return LeftLeft(t);
}
Node *buildNode(int num) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->left = node->right = nullptr;
    node->num = num;
    return node;
}

Node *buildAvl(Node *root, int num) {
    if (root == nullptr) {
        return buildNode(num);
    }
    if (num > root->num) {
        root->right = buildAvl(root->right, num);
        if(!isBalanced(root->left, root->right)){
            if(num > root->right->num){
                root = LeftLeft(root);
            }else{
                root = RightLeft(root);
            }
        }
    } else {
        root->left = buildAvl(root->left, num);
        if(!isBalanced(root->left, root->right)){
            if (num < root->left->num){
                root = RightRight(root);
            }else{
                root = LeftRight(root);
            }
        }
    }
    return root;
}

int main() {
    cin >> n;
    Node *root = nullptr;
    while (n--) {
        int a;
        cin >> a;
        root = buildAvl(root, a);
    }
    queue<Node *> queue;
    queue.push(root);
    int flag = 0;
    int treeComplete = 1;
    int after = 0;
    while(!queue.empty()){
        Node * node = queue.front();
        queue.pop();
        if(!flag){
            cout << node->num;
            flag = 1;
        } else{
            cout <<" "<< node->num;
        }
        //if((node->right != nullptr && node->left == nullptr) || (node->right == nullptr && node->left != nullptr)) treeComplete = 0;
        if(node->left != nullptr){
            queue.push(node->left);
            if(after) treeComplete = 0;
        }else{
            after = 1;
        }
        if(node->right != nullptr){
            queue.push(node->right);
            if(after) treeComplete = 0;
        }else{
            after = 1;
        }
    }
    cout <<endl;
    if(treeComplete) cout << "YES"<<endl;
    else cout <<"NO"<<endl;
    return 0;
}