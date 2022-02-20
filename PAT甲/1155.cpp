#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

struct Node {
    int num;
    struct Node *left;
    struct Node *right;
};
int num[1002];
int n;
bool maxFlag = false, minFlag = false,validFlag= false;

Node *NewNode(int idx) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->num = num[idx];
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

bool check(vector<struct Node> res){
    if(minFlag){
        for(int i=1;i<res.size();i++){
            if(res[i].num < res[i-1].num){
                return false;
            }
        }
    }else if (maxFlag){
        for(int i=1;i<res.size();i++){
            if(res[i].num > res[i-1].num){
                return false;
            }
        }
    }
    return true;
}
Node *build(int idx) {
    if (idx >= n) {
        return nullptr;
    }
    Node *root = NewNode(idx);
    root->left = build(idx * 2 + 1);
    root->right = build((idx * 2 + 2));
    return root;
}


void dfs(Node *root, vector<struct Node> res) {
    if (root == nullptr) {
        return;
    }
    res.push_back(*root);
    dfs(root->right, res);
    dfs(root->left, res);
    if (root->left == nullptr && root->right == nullptr) {
        for (int i = 0; i < res.size(); i++) {
            if (i == 0) {
                cout << res[i].num;
            } else {
                cout << " " << res[i].num;
            }
        }
        cout << endl;
        if(!check(res)){
            validFlag = true;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    if (n == 1) {
        cout << num[0] << endl;
        cout << "Not Heap" << endl;
        return 0;
    }
    Node *root = build(0);
    if (num[0] > num[1]) {
        maxFlag = true;
    } else {
        minFlag = true;
    }
    vector<struct Node> res;
    dfs(root, res);
    if(validFlag){
        cout << "Not Heap" << endl;
    } else if (maxFlag){
        cout << "Max Heap" <<endl;
    }else if (minFlag){
        cout << "Min Heap" <<endl;
    }
}

